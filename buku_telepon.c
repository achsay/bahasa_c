/*
	program ini untuk kecepatan data yang di gunakan untuk meyimpan 
	tergantung loading pc atau laptop jadi dalam menampilkan datanya agak lemot
	salam blogger kediri www.sayfudinblogz.blogspot.com :) LUNTAS ILMU	
	
	* boleh edit source tapi jangan hapus credit developer jika tidak dikatakan plagiat*
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void header();
void input();
void tampil();
void indtoing();
void ingtoind();
void hapus();
void keluar();
FILE *kamus,*temp;
struct{char nama[35],telp[35];}data; //deklarasi struct untuk inisialisasi nama field  
char kar;

main()
{
	char pil;
	do{
		system("cls");
		header();
		puts("\n\n\n  *------MENU PILIHAN------*\n");
		printf("1. Input Data Telepon.\n");
		printf("2. Tampilkan Data Buku Telepon.\n");
		printf("3. Cari nama -> telepon.\n");
		printf("4. Cari telepon -> nama.\n");
		printf("5. Hapus kata dalam kamus.\n");
		printf("6. Keluar\n\n");
		printf(" Masukan pilihan anda = ");
		pil=getche();
		puts("");

	switch(pil)
{
	case '1':
		input();
		break;
	case '2':
		tampil();
		break;
	case '3':
		indtoing();
		break;
	case '4':
		ingtoind();
		break;
	case '5':
		hapus();
		break;
	case '6':
		keluar();
		break;
	}
	printf(" Kembali ke menu awal (y/n) => ");
	kar=getche();
	}while((kar=='Y')||(kar=='y'));
}



void header()
{
	puts("             ========================================");
	puts("             |                                      |");
	puts("             |            *BUKU TELEPON *           |");
	puts("             |             Created by :             |");
	puts("             |            06 achmad sayfudin        |");
	puts("             ========================================");
}

/*input kata*/
void input()
{ 
	char pil;
	do{
		system("cls");

	if((kamus=fopen("kamus.txt","a+"))==NULL)
	{
		printf("data gagal buka ");
		exit(1);
	}
	header();
	puts(" \n\t\t\t-----------------\n");
	puts(" \t\t\t INPUT DATA BARU\n");
	puts(" \t\t\t-----------------\n");
	fflush(stdin);
	printf("Nama => ");
	gets(data.nama); //untuk input data.nama 
	printf("No Telepon => ");
	gets(data.telp); // untuk input data.telp
	fflush(stdin);
	
	fwrite(&data,sizeof(data), 1, kamus);
	printf("\n input data lagi (y/n)");
	pil=getche();
	}
	while((pil=='Y')||(pil=='y'));
	puts("");
}


void tampil()
{
	system("cls");
	fflush(stdin);

if((kamus=fopen("kamus.txt","r"))==NULL)
{
	printf("data gagal di baca ");
	exit(1);
}
	header();
	puts(" \n\t\t\t------------------------\n");
	puts(" \t\t\tDaftar Data Kontak Telepon\n");
	puts(" \t\t\t--------------------------\n");
	printf("\n%-30s %-30s","Nama       ","Telepon      ");
	printf("\n%-30s %-30s","-----------","-----------\n");

	while(fread(&data, sizeof(data), 1, kamus)==1) //membaca data dari file
	printf("\n%-30s %-30s",data.nama,data.telp);
	puts("\n");
	fclose(kamus);
}


void indtoing()
{
	char cari[35],op;
	int i=1;

do{
	system("cls");
	if((kamus=fopen("kamus.txt","r"))==NULL)
	{
		printf("data tidak dapat dibuka ");
		exit(1);
	}
	header();
	puts(" \n\t\t\t-----------------\n");
	puts(" \t\t\tNAMA - TELEPON\n");
	puts(" \t\t\t-----------------\n");
	printf("masukan nama => ");
	fflush(stdin);
	gets(cari);
	fflush(stdin);

	while(fread(&data,sizeof(data),1, kamus)==i)
	{
		if(strcmp(cari,data.nama)==0)//membandingkan data antara cari dengan data.nama
	{
		printf("%s = %s ",data.nama,data.telp);
		i+=1;
	}
	}
	if(i==0)
	{
		printf(" kata \"%s\" tidak ditemukan ",cari);
	}
	fclose(kamus);
	printf("\n\n Ingin Cari lagi (y/n) => ");
	op=getche();
	}while(op=='Y'||op=='y');
	puts("\n");
}

void ingtoind()
{
	int i=1;
	char cari[35],op;
	do{
		system("cls");
		if((kamus=fopen("kamus.txt","r"))==NULL)
		{
			printf("file tidak dapat dibuka");
			exit(1);
		}
		header();
		puts(" \n\t\t\t-----------------\n");
		puts(" \t\t\t TELEPON - NAMA    \n");
		puts(" \t\t\t-------------------\n");
		printf("masukkan no Telepon => ");
		fflush(stdin);
		gets(cari);
		fflush(stdin); //untuk menghapus data yang ada di buffer
	
		while(fread(&data, sizeof data, 1, kamus)==1)
		{
			if(strcmp(cari , data.telp)==0)
			{
				printf("%s = %s", data.nama , data.telp);
				i+=1;
			}
			else if(i==0)
				printf("no telepon \"%s\" tak terdaftar", cari);
		}

		fclose(kamus);
		printf("\n\n Apakah Ingin Mencari lagi (y/n) => ");
		op=getche();
	}	while(op=='Y'||op=='y');
		puts("\n");
}


void hapus()
{
	int i=1;
	char del[35],op;
do{
	system("cls");
if((kamus=fopen("kamus.txt","r"))==NULL)
{
	printf("tidak dapat di hapus");
	exit(1);
}
	header();
	puts(" \n\t\t\t-----------------\n");
	puts(" \t\t\t    HAPUS DATA     \n");
	puts(" \t\t\t-------------------\n");

	printf("hapus data =>");
	fflush(stdin);
	gets(del);
	fflush(stdin);

while(fread(&data,sizeof(data),1, kamus)==1)
{	if(strcmp(del,data.nama)!=0) //jika tidak sama
	{
		if((temp=fopen("temp.txt","a"))==NULL)
		{ 	printf("File tidak bisa diakses"); }
	else
	{ 	fwrite(&data, sizeof(data), 1, temp); }
		fclose(temp);
	}
	else
	{
		printf("\"%s = %s\"\n berhasil dihapus",data.nama,data.telp);
		i+=1;
	}
}

if(i==0)
{ 	printf("Kata \"%s\" tidak ditemukan",del); }
	fclose(kamus);
	remove("kamus.txt");
	rename("temp.txt","kamus.txt");

	printf("\n\nhapus lagi (y/n) => ");
	op=getche();
}while(op=='Y'||op=='y');
	puts("\n");
}

void keluar()
{
exit(1);}

