#include<stdio.h>
#include <string.h>
#include<conio.h>
#include<stdlib.h>

int d,m,y;
int d1,m1,y1;

void varis_noktasi();
void roma();
void paris();
void londra();
void berlin();
void newyork();
void tokyo();
void istanbul();
void print_details();
void print_ticket(int [],int);
void input(int,int );
int check(int);
void flights(int );
void hotels();
int menu();

struct info
{
	int yas;
	int maliyet;
	int gunler;
	char hname[30];
	char varis_noktasi[15];
	char isim[30];
	char cinsiyet;
	float zaman;
	char fname[30];
	char shift[2];
} i;


void print_details()
{
	system("cls");
	int id,no,flag=0;
	printf("\n\t GEZI DETAYLARI :\n");
	printf(" \nKIMLIGINIZI GIRIN :  ");
	scanf("%d", &id);
		FILE *f;
  	f=fopen("info.txt", "r");
	while (!feof(f))
	{
			fscanf(f,"%d %s %d %c %d %s %s %f %s  %d %d %d %d %d %d %s",&no,&i.isim,&i.yas,&i.cinsiyet,&i.maliyet,&i.varis_noktasi,&i.fname,&i.zaman,&i.shift,&d,&m,&y,&d1,&m1,&y1,&i.hname);

		if(id==no)
		{
		printf("\n\n\tKIMLIK : %d",no);
		printf("\n\tISIM : %s\t\t HOTEL NAME : %s ", i.isim,i.hname);
		printf("\n\tYAS : \t%d\t\t CHECKIN : %d/%d/%d ",i.yas,d,m,y);
		printf("\n\tCINSIYET : %c\t \t CHECKOUT : %d/%d/%d", i.cinsiyet,d1,m1,y1);
        printf("\n\tVaris Noktasi: %s",i.varis_noktasi);
        printf("\n\tUCUS ADI : %s",i.fname);
        printf("\n\tKALKIS SAATI : %f %s",i.zaman,i.shift);
        printf("\nDevam etmek icin enter'a basin .....");
	flag=1;
		}
     if(flag==1)
     break;
           }
	fclose(f);
	if(flag==0)
	{
		printf("\nFatura mevcut degil.");
		printf("\nDevam etmek icin enter'a basin .....");

	}
}


void print_ticket(int a[],int cnt)
{
	system("cls");
	int z,no,flag;
		FILE *f;
  		printf("\n\n\t BILETINIZ:");
  for(z=0;z<cnt;++z)
  {   flag=0;
  f=fopen("info.txt", "r");
	while (!feof(f))
	{
		fscanf(f,"%d %s %d %c %d %s %s %f %s  %d %d %d %d %d %d %s",&no,&i.isim,&i.yas,&i.cinsiyet,&i.maliyet,&i.varis_noktasi,&i.fname,&i.zaman,&i.shift,&d,&m,&y,&d1,&m1,&y1,&i.hname);
			if(a[z]==no)
		{
		printf("\n\n\tID : %d",no);
		printf("\n\tNAME : %s\t\t HOTEL ISMI : %s ", i.isim,i.hname);
		printf("\n\tYAS : \t%d\t\t CHECKIN : %d/%d/%d ",i.yas,d,m,y);
		printf("\n\tGENDER : %c\t \t CHECKOUT : %d/%d/%d", i.cinsiyet,d1,m1,y1);
        printf("\n\tVaris Noktasi : %s",i.varis_noktasi);
        printf("\n\tUCUS ADI : %s",i.fname);
        printf("\n\tHAREKET SAATI : %f %s",i.zaman,i.shift);
       flag=1;
			}
     if(flag==1)
     break;
           }
  fclose(f);
  }
   printf("\n\n\t\tTOTAL MALIYET : %ld",i.maliyet);
printf("\n\n\t\tREZERVASYON BASARÝLÝ");
   printf("\n\n\t\t   ana menüye gitmek için enter'a basýn .....");
     getchar();
menu();
}


int check(int id)
{
   int fi;
	 FILE *f1;

        f1=fopen("checkid.txt","w");

fclose(f1);

 FILE *f;
	f=fopen("checkid.txt","r+");
   while(!feof(f))
{
	fscanf(f,"%d",&fi);
	if(fi==id)
	{
	printf("\n\t KIMLIK ZATEN VAR!) !\n\t BASKA BIR KIMLIK SECIN :\n");
	return 1;
	}
}
fclose(f);
return 0;
}


void input(int cnt,int cno)
{
	int a[cnt];
	int pos=0,res;
	switch(cno)
	{
		case 1:strcpy(i.varis_noktasi,     "ROMA");break;
		case 2:strcpy(i.varis_noktasi,     "PARIS");break;
		case 3:strcpy(i.varis_noktasi,     "LONDRA");break;
		case 4:strcpy(i.varis_noktasi,    "BERLIN" );break;
		case 5:strcpy(i.varis_noktasi,     "NEW_YORK");break;
		case 6:strcpy(i.varis_noktasi,     "TOKYO");break;
		case 7:strcpy(i.varis_noktasi,    "ISTANBUL" );break;
	}
	int x=0,id;
	while(x<cnt)
		{
		system("cls");
			printf("\n\t\t KISI AYRINTILARINI GIRIN %d",x+1);
		a:
		printf("\n\n\t     SEYAHAT ID SECIN (1-100) : ");
	scanf("%d",&id);
	res=check(id);
	if(res==1)
	goto a;
	printf("\n\t      ISIM , YAS , CINSIYET (E/K)  :\n\n");
	FILE *f;
	f=fopen("info.txt","a+");
	printf("\t    ");
	scanf("%s", &i.isim);
	printf("\t    ");
	scanf("%d",&i.yas);
	printf("\t    ");
	getchar();
    i.cinsiyet=getchar();
    printf("\n\n\t\t   devam etmek icin enter'a basýn .....");
     getchar();
	getchar();
	flights(id);
	hotels();
	fprintf(f,"%d %s %d %c %d %s %s %f %s ",id,i.isim,i.yas,i.cinsiyet,i.maliyet,i.varis_noktasi,i.fname,i.zaman,i.shift);
	fprintf(f," %d %d %d %d %d %d %s\n",d,m,y,d1,m1,y1,i.hname);
      fclose(f);
      a[x]=id;
      ++x;
		}
	print_ticket(a,cnt);
}


void hotels()
{
	int n;

  system("cls");
	printf("\n\t\t HOTELLER :");
	printf("\n\n\t1. HOTEL ARTEMIDE\t FIYAT : 20,000 PER DAY");
	printf("\n\n\t2. LAN RESERVE\t       FIYAT : 19,500 PER DAY");
	printf("\n\n\t3. HILTON BERLIN\t FIYAT : 17,000 PER DAY");
	printf("\n\n\t4. ROYAL MALWANE\t FIYAT : 20,500 PER DAY");
	printf("\n\n\t5. AMANZOE\t    FIYAT : 18,000 PER DAY");
	printf("\n\n\t SECIMINIZI GIRIN :  ");
	scanf("%d", &n);
	printf("\n\n\t GUN SAYISI GIRIN : ");
	scanf("%d",&i.gunler);
		switch (n)
	{
case 1: i.maliyet+=i.gunler*20000;
strcpy(i.hname,"HOTEL_ARTEMIDE");break;
case 2: i.maliyet+=i.gunler*19500;
strcpy(i.hname,"LAN_RESERVE");break;
case 3: i.maliyet+=i.gunler*17000;
strcpy(i.hname,"HILTON_BERLIN");break;
case 4: i.maliyet+=i.gunler*20500;
strcpy(i.hname,"ROYAL_MALWANE");break;
case 5: i.maliyet+=i.gunler*18000;
strcpy(i.hname,"AMANZOE");break;
	}
	printf("\n\t GIRIS TARIHINI GIRIN : ");
	scanf("%d",&d);
	printf("\n\t GIRIS AYINI GIRIN : ");
	scanf("%d",&m);
	printf("\n\t GIRIS YILINI GIRIN : ");
	scanf("%d",&y);

	d1=d+i.gunler;
	m1=m;
	y1=y;
	if(d1>31)
	{
		d1=d1-31;
		m1+=1;
		if(m1>12)
		{
			m1=m1-12;
			y1+=1;
		}
	}
printf("\n\n\t\t   devam etmek icin enter'a basin .....");
	getchar();
	getchar();
}



void flights(int id)
	{
		int choice;
	printf("\n\n\t\t MEVCUT UCUSLAR : ");
	printf("\n\n    1. THY:       DEPARTURE : 6.00 AM  PRICE : 68,000 RS");
	printf("\n    2. JET AIRWAYS:     DEPARTURE : 9.00 AM  PRICE : 40,000 RS");
			printf("\n    3. EMIRATES AIRWAYS :  DEPARTURE : 1.00 PM  PRICE : 55,000 RS");
		printf("\n    4. CORENDON:        DEPARTURE : 5.00 PM  PRICE : 75,000 RS");
		printf("\n    5. AIR ASIA :       DEPARTURE : 9.00 PM  PRICE : 42,000 RS");
		printf("\n\n\t SECIMINIZ :  ");
		scanf("%d",&choice);
		switch(choice)
		{
case 1: i.maliyet+=68000;
i.zaman=6.00;
strcpy(i.shift,"AM");
strcpy(i.fname,"THY");break;
case 2: i.maliyet+=40000;
i.zaman=9.00;
strcpy(i.shift,"AM");
strcpy(i.fname,"JET_AIRWAYS");break;
case 3: i.maliyet+=55000;
i.zaman=1.00;
strcpy(i.shift,"PM");
strcpy(i.fname,"EMIRATES_AIRWAYS");break;
case 4: i.maliyet+=75000;
i.zaman=5.00;
strcpy(i.shift,"PM");
strcpy(i.fname,"CORENDON");break;
case 5: i.maliyet+=42000;
i.zaman=9.00;
strcpy(i.shift,"PM");
strcpy(i.fname,"AIR_ASIA");break;
}
	  FILE *p;
       p=fopen("checkid.txt","a+");      fprintf(p,"%d \n",id);
        fclose(p);
        printf("\n\n\t\t   press enter to continue .....");
	getchar();
	getchar();

}


void varis_noktasi()
{
	system("cls");
	int n;
	printf("\n\t Varis Noktasi :");
	printf("\n\n\t 1. ROMA");
	printf("\n\n\t 2. PARIS");
	printf("\n\n\t 3. LONDRA");	printf("\n\n\t 4. BERLIN");
	printf("\n\n\t 5. NEW YORK");
	printf("\n\n\t 6. TOKYO");
	printf("\n\n\t 7. ISTANBUL");
		printf("\n\n\t ENTER CHOICE :  ");
	scanf("%d", &n);
	switch (n)
	{
	case 1:roma();break;
	case 2:paris();break;
	case 3:londra();break;
	case 4:berlin();break;
	case 5:newyork();break;
	case 6:tokyo();break;
	case 7:istanbul();break;
	}
}


void roma()
{
	int cnt;
	system("cls");
	printf("\n\t\tROMA TURIZME HOSGELDINIZ  !!!\n");
printf("\n\t\t    KISI SAYISI GIRIN ");
    scanf("%d",&cnt);
	input(cnt,1);
}

void paris()
{
	int  cnt;
	system("cls");
	printf("\n\t\tPARIS TURIZME HOSGELDINIZ   !!!\n");
printf("\n\t\t    KISI SAYISI GIRIN ");
    scanf("%d",&cnt);
	input(cnt,2);
}

void londra()
{
	int  cnt;
	system("cls");
	printf("\n\t\tLONDRA TURIZME HOSGELDINIZ   !!!\n");
printf("\n\t\t    KISI SAYISI GIRIN ");
    scanf("%d",&cnt);
	input(cnt,3);
}

void berlin()
{
	int  cnt;
	system("cls");
	printf("\n\t\tBERLIN TURIZME HOSGELDINIZ  !!!\n");
printf("\n\t\t    KISI SAYISI GIRIN ");
    scanf("%d",&cnt);
	input(cnt,4);
}

void newyork()
{
	int  cnt;
	system("cls");
	printf("\n\t\tNEW YORK TURIZME HOSGELDINIZ   !!!\n");
printf("\n\t\t    KISI SAYISI GIRIN ");
    scanf("%d",&cnt);
	input(cnt,5);
}

void tokyo()
{
	int  cnt;
system("cls");
	printf("\n\t\tTOKYO TURIZME HOSGELDINIZ   !!!\n");
printf("\n\t\t    KISI SAYISI GIRIN ");
    scanf("%d",&cnt);
	input(cnt,6);
}

void istanbul()
{
	int  cnt;
	system("cls");
	printf("\n\t\tISTANBUL TURIZME HOSGELDINIZ   !!!\n");
printf("\n\t\t    KISI SAYISI GIRIN ");
    scanf("%d",&cnt);
	input(cnt,7);
}


int menu()
{
	int n;
system("cls");
	printf("\n\tMENU :");
	printf("\n\n\t1. Varis Noktasi Secin \n\n\t2. FATURA OLUSTUR\n\n\t3. CIKIS\n\tSECIMINIZI GIRIN :  ");
	scanf("\n%d", &n);
	switch (n)
	{
	case 1:varis_noktasi();break;
	case 2:print_details();break;
	case 3: return 0;
}
getch();
menu();
return 0;
}


int main()
{
		system("cls");
	printf("\n\n\n\n\n\n\t\t\t   HOSGELDINIZ \n\n\t\t      YNR SEYAHAT ACENTESI");
	printf("\n\n\t\t   devam etmek icin enter'a basin .....");
	getchar();
	menu();
	return 0;
}
