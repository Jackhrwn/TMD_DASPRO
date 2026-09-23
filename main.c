#include "header.h"
#include "string.h"
/*
Saya Jaka Permana Herawan dengan NIM 2509371 sebagai manusia yang berTuhan, saya mengerjakan evaluasi Tugas Masa Depan 
dalam mata kuliah Dasar-dasar Pemrograman untuk keberkahanNya maka saya tidak melakukan 
kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
int main(){
    //BERI NAMA BUNGKUSAN MAHASISWA DENGAN datapribadi(MAHASISWA),listcomplate(DATA SUDAH DI JOIN),tempbaru1(MENGEDIT DATA)
    mahasiswa datapribadi[51],listcomplate[51],tempbaru1[1];
    //BERI NAMA BUNGKUSAN DESKRIPSI DENGAN skill(SKILL),lomba(LOMBA),curang(CURANG),tempbaru2(MENGEDIT DATA)
    deskripsi skill[51],lomba[51],curang[51],tempbaru2[1];
    //INISIALISASI m(JUMLAH DATA MAHASISWA),idx1(JUMLAH DATA SKILL),idx2(JUMLAH DATA LOMBA),idx3(JUMLAH DATA CURANG)
    int m=0,idx1=0,idx2=0,idx3=0;   
    //MULAI MEMBACA FILE
    bacafile1(&m,datapribadi,"dataMahasiswa.txt");
    bacafile2(&idx1,skill,"skill.txt");
    bacafile2(&idx2,lomba,"lomba.txt");
    bacafile2(&idx3,curang,"kecurangan.txt");
    judul();        //TAMPILKAN INTRO
    panduan();      //TAMPILKAN PANDUAN
    printf("\n");
    printf(CYAN"SILAKAN UNTUK MELAKUKAN PERINTAH:\n"RESET);
    int lanjut=1;   //INISIALISASI LANJUT UNTUK LOOPING
    char pita[501];//DEKLARASI PITA
    do{
        dbms();
        scanf("%500[^\n]s",pita);//MEMINTA INPUT MASUKAN
        getchar();//MENGHAPUS \n
        int adapagar=getadapagar(pita);//AMBIL NILAI ADA PAGAR ATAU TIDAK
        if(adapagar==1){//JIKA ADA
            START(pita);//MULAI MESIN KATA
            if(strcmp(getcw(),"INPUT")==0){//JIKA KATA SEKARANG ITU INPUT
                input(datapribadi,tempbaru1,tempbaru2,skill,lomba,curang,pita,&m,&idx1,&idx2,&idx3);//TAMPILKAN HASIL CEK INPUT
            }else if(strcmp(getcw(),"UPDATE")==0){//JIKA KATA SEKARANG ITU UPDATE
                update(datapribadi,tempbaru1,tempbaru2,skill,lomba,curang,pita,m,idx1,idx2,idx3);//TAMPILKAN HASIL CEK UPDATE
            }else if(strcmp(getcw(),"DEL")==0){//JIKA KATA SEKARANG ITU DEL
                del(datapribadi,tempbaru1,tempbaru2,skill,lomba,curang,pita,&m,&idx1,&idx2,&idx3);//TAMPILKAN HASIL CEK DEL
            }else if(strcmp(getcw(),"SHOW")==0){//JIKA KATA SEKARANG ITU SHOW
                show(datapribadi,listcomplate,skill,lomba,curang,pita,m,idx1,idx2,idx3);//TAMPILKAN HASIL CEK SHOW
            }else if(strcmp(getcw(),"BANTU")==0){//JIKA KATA SEKARANG ITU BANTU
                if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                    INC(pita);//majukan kata
                    if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                        inputlebih();//tampilkan pesan error
                    }else{//jika tidak
                        if(strcmp(getcw(),"INPUT")==0){//JIKA KATA SEKARANG ITU INPUT
                            bantuinput();//TAMPILKAN PANDUAN INPUT
                        }else if(strcmp(getcw(),"UPDATE")==0){//JIKA KATA SEKARANG ITU UPDATE
                            bantuupdate();//TAMPILKAN PANDUAN UPDATE
                        }else if(strcmp(getcw(),"DEL")==0){//JIKA KATA SEKARANG ITU DEL
                            bantudel();//TAMPILKAN PANDUAN DEL
                        }else if(strcmp(getcw(),"SHOW")==0){//JIKA KATA SEKARANG ITU SHOW
                            bantushow();//TAMPILKAN PANDUAN SHOW
                        }else{//JIKA KATA SEKARANG ITU BUKAN SEMUANYA
                            inputankedua();//tampilkan pesan error
                        }
                    }
                }else{
                    inputkurang();//tampilkan pesan error
                }
            }else if(strcmp(getcw(),"EXIT")==0){//JIKA KATA SEKARANG ITU EXIT
                keluar(pita,&lanjut);//TAMPILKAN HASIL CEK EXIT
            }else{//JIKA TIDAK SEMUANYA
                printf(RED);//TAMPILKAN PESAN ERROR
                printf("=============================ERROR=============================\n");
                printf("|--------------MAAF MASUKAN PERTAMA TIDAK SESUAI--------------|\n");
                printf("|------------SILAKAN BACA PANDUAN TERLEBIH DAHULU-------------|\n");
                printf("=============================ERROR=============================\n");
                printf(RESET);
            }
        }else{//JIKA TIDAK ADA
            printf(RED);//TAMPILKAN PESAN ERROR
            printf("=============================ERROR=============================\n");
            printf("|---------MAAF MASUKAN HARUS DIAKHIRI DENGAN PAGAR(#)---------|\n");
            printf("=============================ERROR=============================\n");
            printf(RESET);
        }
    }while(lanjut==1);  //SELAMA LANJUT ITU 1 MAKA AKAN TERUS LOOPING
    return 0;
}