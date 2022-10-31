//V01 -Tam Giac duoc tao boi 3 dinh A, B va C
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iomanip>
#include <iostream>
using namespace std;

class Diem
{
	protected:
		int x;
		int y;
	public:
		Diem();
		Diem(int h, int t);
		void Nhap();
		void Xuat();
		int getX();
		int getY();
		
		float KhoangCach(Diem);
};

class TamGiac:public Diem
{
	protected:
		Diem A,B,C;
		
	public:
		TamGiac();
		void Nhap();
		void Xuat();
		TamGiac(Diem a, Diem b, Diem c);
		
		float KiemTra();
		void KC();
		void TT();
		float CV();
		float DT();
		//..bo sung method	
	
};


int main()
{
	TamGiac tg;

	tg.Nhap();
	tg.Xuat();
	cout<<"\n Khoang cach giua cac diem A, B va C: ";
	tg.KC();

	cout<<"\n Trong tam tam giac A, B, C: ";
	tg.TT();
	cout<<"\nChu vi tam giac A, B, C: " << tg.CV() << endl;
	
	cout<<"\nDien tich tam giac A, B, C: " << tg.DT() << endl;


	//cout<<"Co trong tam la "; tg.TrongTam().Xuat();
	getch(); //Dung xem KQ
	return 1; //hoac return 0;
}

Diem::Diem()
{
	x=y=0;
}
Diem::Diem(int h, int t)
{
	x=h; y=t;
}

void Diem::Nhap()
{
	cout<<("\nNhap hoanh do x:"); cin>>x;
	cout<<("Nhap tung do y: "); cin>>y;
}

void Diem::Xuat()
{
	cout<<"("<<x<<","<<y<<")"; //(3,5)
}

float Diem::KhoangCach(Diem P)
{
	return sqrt((x-P.x)*(x-P.x)+(y-P.y)*(y-P.y));
}



int Diem::getX()
{
	return x;
}

int Diem::getY()
{
	return y;
}

//Tam giac
TamGiac::TamGiac()
{
	Diem A(0,0), B(0,0), C(0,0);
	
}

TamGiac::TamGiac(Diem a, Diem b, Diem c){
	A=a;
	B=b;
	C=c;
	}

float TamGiac::KiemTra()
{
	float a= (B.getX() - A.getX()) * (C.getY() - A.getY());
	float b= (C.getX() - A.getX()) * (B.getY() - A.getY());
	if( a==b )
	   return 1;
	return 0;
}
	
void TamGiac::Nhap()
{
	do {
	cout<<"\nNhap dinh thu nhat: "; A.Nhap();
	cout<<"\nNhap dinh thu hai: "; B.Nhap();
	cout<<"\nNhap dinh thu ba: "; C.Nhap();
	if(KiemTra()) {
		cout<<"\nDiem A B C thang hang. Khong hop le.";
		}
	}while(KiemTra());

}

void TamGiac::Xuat()
{
    cout<<"\nDinh thu nhat: "; A.Xuat();
    cout<<"\nDinh thu hai: "; B.Xuat();
    cout<<"\nDinh thu ba: "; C.Xuat();
	
}

void TamGiac::KC() {
	cout<<"\nKhoang cach giua hai diem A va B: " << A.KhoangCach(B) << endl;
	cout<<"\nKhoang cach giua hai diem B va C: " << B.KhoangCach(C) << endl;
	cout<<"\nKhoang cach giua hai diem C va A: " << C.KhoangCach(A) << endl;
}

void TamGiac::TT(){
	TamGiac tt;
	tt.x= (A.getX() + B.getX() + C.getX()) / 3;
	tt.y= (A.getY() + B.getY() + C.getY()) / 3;
	cout<< "(" << tt.x << ";" << tt.y << ")";
	}

float TamGiac::CV(){
	float a,b,c;
	a= A.KhoangCach(B);
	b= B.KhoangCach(C);
	c= C.KhoangCach(A);
	return a+b+c;
	}
	
float TamGiac::DT(){
	float a,b,c;
	a= A.KhoangCach(B);
	b= B.KhoangCach(C);
	c= C.KhoangCach(A);
	float v= CV() / 2;
	return sqrt(v * (v-a) * (v-b) * (v-c));
	}



