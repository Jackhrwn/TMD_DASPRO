#include <stdio.h>
#include <string.h>
/*
Saya Jaka Permana Herawan dengan NIM 2509371 sebagai manusia yang berTuhan, saya mengerjakan evaluasi Tugas Masa Depan 
dalam mata kuliah Dasar-dasar Pemrograman untuk keberkahanNya maka saya tidak melakukan 
kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

//===============================DEKLARASI MAKRO==================================//
#define RESET			"\033[0m"   //reset warna ke awal
#define GREEN           "\033[32m"  //teks hijau 
#define BLUE            "\033[34m"  //teks biru 
#define RED             "\033[31m"  //teks merah 
#define YELLOW          "\033[33m"  //teks kuning
#define CYAN            "\033[36m"  //teks cyan
#define WHITE           "\033[37m"  //teks putih 
#define BRIGHT_YELLOW   "\033[33m"  //teks kuning terang
#define BRIGHT_BLUE     "\033[32m"  //teks biru terang
//==============================DEKLARASI BUNGKUSAN================================//
typedef struct{
    char id[5];
    char nama[51];
    char nim[51];
    char idskill[51];
    char idlomba[51];
    char idcurang[51];
}mahasiswa;

typedef struct{
    char id[5];
    char atribut[51];
}deskripsi;
//======================DEKLARASI PROSEDUR MENGECEK MASUKAN===========================//
void input(mahasiswa datapribadi[],mahasiswa temp1[],deskripsi temp2[],deskripsi a[],deskripsi b[],deskripsi c[],char pita[],int *m,int *idx1,int *idx2,int *idx3);
void update(mahasiswa datapribadi[],mahasiswa temp1[],deskripsi temp2[],deskripsi a[],deskripsi b[],deskripsi c[],char pita[],int m,int idx1,int idx2,int idx3);
void del(mahasiswa datapribadi[],mahasiswa temp1[],deskripsi temp2[],deskripsi a[],deskripsi b[],deskripsi c[],char pita[],int *m,int *idx1,int *idx2,int *idx3);
void show(mahasiswa datapribadi[],mahasiswa complate[],deskripsi a[],deskripsi b[],deskripsi c[],char pita[],int m,int idx1,int idx2,int idx3);
void keluar(char pita[],int *lanjut);
//==========================DEKLARASI PROSEDUR PANDUAN===============================//
void judul();       //PROSEDUR MENAMPILKAN INTRO AWAL
void dbms();        //PROSEDUR MENAMPILKAN DBMS BERWARNA
void panduan();     //PROSEDUR MENAMPILKAN PANDUAN AWAL
void bantuinput();  //PROSEDUR MENAMPILKAN PANDUAN INPUT
void bantuupdate(); //PROSEDUR MENAMPILKAN PANDUAN UPDATE
void bantudel();    //PROSEDUR MENAMPILKAN PANDUAN DEL
void bantushow();   //PROSEDUR MENAMPILKAN PANDUAN DHOW
//=========================DEKLARASI PROSEDUR PESAN ERROR=============================//
void inputkurang(); //PROSEDUR MENAMPILKAN PESAN ERROR INPUT KURANG
void inputlebih();  //PROSEDUR MENAMPILKAN PESAN ERROR INPUT LEBIH
void inputankedua();//PROSEDUR MENAMPILKAN PESAN ERROR INPUT KEDUA TIDAK SESUAI
void idskill();     //PROSEDUR MENAMPILKAN PESAN ERROR IDSKILL TIDAK ADA
void idlomba();     //PROSEDUR MENAMPILKAN PESAN ERROR IDLOMBA TIDAK ADA
void idcurang();    //PROSEDUR MENAMPILKAN PESAN ERROR IDCURANG TIDAK ADA
void pesanexit();   //PROSEDUR MENAMPILKAN PESAN ERROR KODE RAHASIA TIDAK VALID
//===================DEKLARASI PROSEDUR READ FILE DAN WRITE FILE=======================//
void bacafile1(int *n, mahasiswa cari[],char file[]);       //BACA FILE MAHASIWA 
void bacafile2(int *n,deskripsi cari[],char file[]);        //BACA FILE SKILL,LOMBA DAN CURANG
void tulisfile1(int n, mahasiswa tulis[], char filename[]); //MENULIS KE FILE MAHASISWA
void tulisfile2(int n, deskripsi tulis[], char filename[]); //MENULIS KE FILE SKILL,LOMBA DAN CURANG
//========================DEKLARASI PROSEDUR MENCETAK TABEL============================//
void cetaktabelmahasiswa(mahasiswa cek[],int m);    //MENAMPILKAN TABEL MAHASISWA
void cetaktabelcomplate(mahasiswa cek[],int m);     //MENAMPILKAN TABEL MAHASISWA YANG TELAH DI JOIN
void cetaktabelskill(deskripsi cek[], int idx);     //MENAMPILKAN TABEL SKILL
void cetaktabellomba(deskripsi cek[], int idx);     //MENAMPILKAN TABEL LOMBA
void cetaktabelcurang(deskripsi cek[], int idx);    //MENAMPILKAN TABEL CURANG
//====================DEKLARASI PROSEDUR MENGUBAH FOREGIN TABEL=======================//
void join1(mahasiswa data[],deskripsi a[],deskripsi  b[],deskripsi c[]);  //MENGUBAH KE NAMA
void join2(mahasiswa data[],deskripsi a[],deskripsi  b[],deskripsi c[]);  //MENGUBAH KE ID
//=============================DEKLARASI VARIABEL GLOBAL==============================//
extern int idx;         //variabel global idx2 untuk mesin kata
extern char cw[51];     //variabel global current word mesin kata
extern int wlen;        //variabel global panjang kata pada mesin kata
//==============================BAGIAN FUNGSI MESIN KATA==============================//
void INC(char pita[]);  //tombol memajukan satu kata dan mendapatkan jumlah tiap huruf
void START(char pita[]);//tombol mulai mesin kata
int EOP(char pita[]);   //tombol cek eop untuk mesin kata
char* getcw();          //tombol mendapatkan current word 
int getlen();           //tombol mendapatkan panjang string di current word
int getadapagar(char pita[]); //tombol mengecek ada pagar atau tidak

