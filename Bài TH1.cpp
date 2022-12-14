#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <iostream>
using namespace  std;
class PhanSo
{
//public:
private:
	int Tuso;
	int Mauso;
public:
	//Ham dung
	PhanSo();
	PhanSo(int, int);
	PhanSo(const PhanSo&);
	void Nhap();
	void Xuat();
	
	int Uscln(int a, int b);
	void RutGon();
	float GiatriPS();
	
	
	//Phuong thuc tinh toan
	PhanSo Cong(PhanSo ps);
	PhanSo Tru(PhanSo ps);
	PhanSo Nhan(PhanSo ps);
	PhanSo Chia(PhanSo ps);
	
	//Nhap - Xuat bang luong
	//friend istream& operator >> (istream &is, PhanSo &p);
	//friend ostream& operator << (ostream &os, PhanSo &p);
	
	//Toan tu gan 
	//PhanSo operator= (PhanSo &p);
	
	//Cac phep toan dung Toan tu
	PhanSo operator+(PhanSo);
	PhanSo operator-(PhanSo);
	PhanSo operator*(PhanSo);
	PhanSo operator/(PhanSo);
	
	//Toan tu So sanh
	int operator > (PhanSo);
	int operator < (PhanSo);
	int operator >= (PhanSo);
	int operator <= (PhanSo);
	int operator == (PhanSo);
	int operator != (PhanSo);
	
};

int main()
{
	PhanSo a, b, c, psTong, psHieu, psTich, psThuong;
	
	
	cout<<"\n Nhap phan so A "; 
	a.Nhap();
	cout<<"\n Phan so vua nhap "; 
	a.Xuat();
	cout<<"\n Nhap phan so B "; 
	b.Nhap();
	cout<<"\n Phan so vua nhap "; 
	b.Xuat();
	
	a.RutGon(); b.RutGon();
	
	cout<<"\n A sau khi toi gian "; 
	a.Xuat();
	cout<<"\n B sau khi toi gian "; 
	b.Xuat();
	
	cout<<endl;
	
	psTong=a.Cong(b);
	cout<<"\nTong la: ";
	psTong.Xuat();
	
	psHieu=a.Tru(b);
	cout<<"\nHieu la: ";
	psHieu.Xuat();
	
	psTich=a.Nhan(b);
	cout<<"\nTich la: ";
	psTich.Xuat();
	
	psThuong=a.Chia(b);
	cout<<"\nThuong la: ";
	psThuong.Xuat();
	
	if(a.GiatriPS()>b.GiatriPS())
	   cout<<"\n Phan so A lon hon phan so B.";
	else
	   if(a.GiatriPS()<b.GiatriPS())
	      cout<<"\n Phan so A nho hon phan so B.";
	    else
	       if(a.GiatriPS()>=b.GiatriPS())
	          cout<<"\n Phan so A lon hon hoac bang phan so B.";
	        else
	           if(a.GiatriPS()<=b.GiatriPS())
	              cout<<"\n Phan so A nho hon hoac bang phan so B.";
	            else
	               if(a.GiatriPS()==b.GiatriPS())
	                  cout<<"\n Phan so A bang phan so B.";
	                else
	                   cout<<"\n Phan so A khac phan so B.";
	
	
	
	//...them code
	
	getch();
	return 1;
}

PhanSo::PhanSo()
{
	Tuso = 0;	Mauso = 1;
}

PhanSo::PhanSo(const PhanSo &p)
{
	Tuso = p.Tuso;	Mauso = p.Mauso;
}

PhanSo::PhanSo(int t, int m)
{
	Tuso = t; Mauso = m;
}


void PhanSo::Nhap()
{
	cout<<"\n Nhap Tu so "; cin>>Tuso;
	cout<<"\n Nhap Mau so "; cin>>Mauso;
	while(Mauso==0)
	{
		cout<<"\n Mau so phai khac 0 - Nhap lai Mau so : ";cin>>Mauso;
	};
}

void PhanSo::Xuat()
{
	cout<<Tuso<<"/"<<Mauso<<" ";
}

float PhanSo::GiatriPS()
{
	return (float) (Tuso)/(float)(Mauso);
}

PhanSo PhanSo::Cong(PhanSo ps)
{
	PhanSo tam;
	tam.Tuso=Tuso*ps.Mauso+Mauso*ps.Tuso;
	tam.Mauso=Mauso*ps.Mauso;
	tam.RutGon();
	return tam;
}

PhanSo PhanSo::Tru(PhanSo ps)
{
	PhanSo tam;
	tam.Tuso=Tuso*ps.Mauso-Mauso*ps.Tuso;
	tam.Mauso=Mauso*ps.Mauso;
	tam.RutGon();
	return tam;
}

PhanSo PhanSo::Nhan(PhanSo ps)
{
	PhanSo tam;
	tam.Tuso=Tuso*ps.Tuso;
	tam.Mauso=Mauso*ps.Mauso;
	tam.RutGon();
	return tam;
}

PhanSo PhanSo::Chia(PhanSo ps)
{
	PhanSo tam;
	tam.Tuso=Tuso*ps.Mauso;
	tam.Mauso=Mauso*ps.Tuso;
	tam.RutGon();
	return tam;
}

//int k= Uscln(Tuso,Mauso);
int PhanSo::Uscln(int a, int b)
{
	a=abs(a);
	b=abs(b);
	if (a == b) return a;
	else
	{
		while(a!=0 && b!=0)
		{
			if (a>b) 
					a-=b;
			else b-=a;
		}
		if(a==0) 
			return b;
		else 
			return a;
	}
}


void PhanSo::RutGon()
{
	int k = Uscln(Tuso,Mauso);
	Tuso = Tuso/k;
	Mauso = Mauso/k;
}


PhanSo PhanSo::operator + (PhanSo p)
{
	PhanSo tam;
	tam.Tuso = Tuso*p.Mauso+Mauso*p.Tuso;
	tam.Mauso = Mauso*p.Mauso;
	tam.RutGon();
	return tam;
}

PhanSo PhanSo::operator - (PhanSo p)
{
	PhanSo tam;
	tam.Tuso = Tuso*p.Mauso-Mauso*p.Tuso;
	tam.Mauso = Mauso*p.Mauso;
	tam.RutGon();
	return tam;
}

PhanSo PhanSo::operator * (PhanSo p)
{
	PhanSo tam;
	tam.Tuso = Tuso*p.Tuso;
	tam.Mauso = Mauso*p.Mauso;
	tam.RutGon();
	return tam;
}

PhanSo PhanSo::operator / (PhanSo p)
{
	PhanSo tam;
	tam.Tuso = Tuso*p.Mauso;
	tam.Mauso = Mauso*p.Tuso;
	tam.RutGon();
	return tam;
}





