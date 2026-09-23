#include "header.h"
#include "string.h"
/*
Saya Jaka Permana Herawan dengan NIM 2509371 sebagai manusia yang berTuhan, saya mengerjakan evaluasi Tugas Masa Depan 
dalam mata kuliah Dasar-dasar Pemrograman untuk keberkahanNya maka saya tidak melakukan 
kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

//DEKLARASI VARIABEL GLOBAL
int idx;        //deklarasi ulang variabel global index mesin kata
int wlen;       //panjang current word
char cw[51];    //deklarasi ulang variabel global current word

//FUNGSI MEMERIKSA PESAN AKHIR MESIN KATA
int EOP(char pita[]){
    if(pita[idx] == '#'){//jika '#' return 1
        return 1;
    }
    else{//jika bukan '#'
        return 0;//kembalikan 0
    }
}

//PROSEDUR MEMULAI MESIN KATA
void START(char pita[]){
    // set index dan panjang kata menjadi 0
    idx = 0;
    wlen = 0;
    while(pita[idx] == ' '){//ignore blank
        idx++;
    }
    //ambil kata masukkan dalam current word
    while((pita[idx] != ' ') && (EOP(pita) == 0)){
        cw[wlen] = pita[idx];//huruf pita ke-idx2 dimasukan ke current word
        wlen++;//panjang current word bertambah
        idx++;//maju ke indeks berikutnya
    }
    cw[wlen] = '\0';//akhiri dengan null terminator
    
}

//PROSEDUR PINDAH KE KATA BERIKUTNYA
void INC(char pita[]){
    wlen = 0;//inisialisasi panjang kata jadi 0 
    while(pita[idx] == ' '){//ignore blank
        idx++;
    }
    //masukkan kata baru
    while((pita[idx] != ' ') && (EOP(pita) == 0)){
        cw[wlen] = pita[idx];//huruf pita ke-idx2 dimasukan ke current word
        wlen++;//panjang current word bertambah
        idx++;//maju ke indeks berikutnya
    }
    cw[wlen] = '\0';//akhiri lagi dengan null terminator
}

//MENGEMBALIKAN CURRENT WORD SAAT INI
char* getcw(){
    return cw;
}

//MENGEMBALIKAN PANJANG CURRENT WORD SAAT INI
int getlen(){
    return wlen;
}

//MENGEMBALIKAN NILAI ADA PAGAR ATAU TIDAK
int getadapagar(char pita[]){
    int len=strlen(pita);
    if((pita[len-1]=='#') && (len>0)){
        return 1;
    }
    return 0;
}

//PROSEDUR UNTUK MEMBACA FILE
void bacafile1(int *n, mahasiswa cari[],char file[]){
    FILE *temp;//deklarasi tipe data FILE dengan temp(harus pointer) untuk tempat sementara bagi file dalam program
    temp=fopen(file,"r");//fungsi untuk membuka/mengakses file tersebut secara read
    //pindai data baris pertama dari isi file
    int returnval=fscanf(temp,"%s %s %s %s %s %s",cari[*n].id,cari[*n].nama,cari[*n].nim,cari[*n].idskill,cari[*n].idlomba,cari[*n].idcurang);
    //jika data yang di pindai baris pertamanya EOF
    if((strcmp(cari[*n].id,"####")==0) || (returnval == EOF)){
        printf("file kosong\n");//maka tampilkan file kosong
    }else{//jika bukan EOF
        while(strcmp(cari[*n].id,"####") !=0){//selama bukan EOF
            *n=*n+1;//pindai ke index berikutnya
            //pindai semua data ke-*n dan tampung di dalam arraynya
            fscanf(temp,"%s %s %s %s %s %s",cari[*n].id,cari[*n].nama,cari[*n].nim,cari[*n].idskill,cari[*n].idlomba,cari[*n].idcurang);
        }  
    }
    fclose(temp);//tutup file
}
void bacafile2(int *n,deskripsi cari[],char file[]){
    FILE *temp;//deklarasi tipe data FILE dengan temp(harus pointer) untuk tempat sementara bagi file dalam program
    temp=fopen(file,"r");//fungsi untuk membuka/mengakses file tersebut secara read
    //pindai data baris pertama dari isi file
    int returnval=fscanf(temp,"%s %s",cari[*n].id,cari[*n].atribut);
    //jika data yang di pindai baris pertamanya EOF
    if((strcmp(cari[*n].id,"####")==0) || (returnval == EOF)){
        printf("file kosong\n");//maka tampilkan file kosong
    }else{//jika bukan EOF 
        while(strcmp(cari[*n].id,"####") !=0){//selama bukan EOF
            *n=*n+1;//pindai ke index berikutnya
            //pindai semua data ke-*n dan tampung di dalam arraynya
            fscanf(temp,"%s %s",cari[*n].id,cari[*n].atribut);
        }  
    }
    fclose(temp);//tutup file
}

//PROSEDUR UNTUK MENULIS KE DALAM FILE
void tulisfile1(int n, mahasiswa tulis[], char filename[]){
    FILE *temp;//deklarasi tipe data FILE dengan temp(harus pointer) untuk tempat sementara bagi file dalam program
    temp = fopen(filename, "w");//buka file dengan operator write to file
    for(int i = 0; i < n; i++){
        fprintf(temp, "%s %s %s %s %s %s\n",tulis[i].id,tulis[i].nama,tulis[i].nim,tulis[i].idskill,tulis[i].idlomba,tulis[i].idcurang);//write data ke dalam file sebanyak n
    }
    fprintf(temp, "%s %s %s %s %s %s\n", "####","####","####","####","####", "####");//write data EOF setelah bikin data dalam file
    fclose(temp);//tutup file   
}
void tulisfile2(int n, deskripsi tulis[], char filename[]){
    FILE *temp;//deklarasi tipe data FILE dengan temp(harus pointer) untuk tempat sementara bagi file dalam program
    temp = fopen(filename, "w");//buka file dengan operator write to file
    for(int i = 0; i < n; i++){
        fprintf(temp, "%s %s \n",tulis[i].id,tulis[i].atribut);//write data ke dalam file sebanyak n
    }
    fprintf(temp, "%s %s\n", "####","####");//write data EOF setelah bikin data dalam file
    fclose(temp);//tutup file
}

//BAGIAN PROSEDUR UNTUK MENGUBAH FOREGIN MENJADI NAMA DAN SEBALIKNYA
void join1(mahasiswa data[],deskripsi a[],deskripsi  b[],deskripsi c[]){
    int i=0;//inisialisasi nilai awal i untuk index
    while(strcmp(data[i].id,"####") !=0){//selama index ke-i nya bukan data damy
        int j=0;//inisialisasi nilai awal j untuk index Skillnya
        int ketemu=0;//inisialisasi nilai awal ketemu untuk mengetahui bahwa data yang sama sudah ketemu 
        while((strcmp(a[j].id,"####")!=0) && (ketemu==0)){//selama primari data Skillnya tidak damy dan ketemu masih 0
            if(strcmp(data[i].idskill,a[j].id)==0){//jika data kode primari Skill itu sama dengan foregin dari data IdSkill mahasiswa
                strcpy(data[i].idskill,a[j].atribut);//maka copy data nama sesuai primari Skill ke data foregin Skill dataer
                ketemu=1;//maka ubah ketemu menjadi 1 
            }
            j++;//index j akan bertambah jika masih belum ketemu primari yang sama
        }
        j=0;//inisialisasi ulang nilai awal j untuk index asalnya
        ketemu=0;//inisialisasi nilai awal ketemu untuk mengetahui bahwa data yang sama sudah ketemu
        while((strcmp(b[j].id,"####")!=0) && (ketemu==0)){//selama primari data Lombanya tidak damy dan ketemu masih 0
            if(strcmp(data[i].idlomba,b[j].id)==0){//jika data kode primari Lomba itu sama dengan foregin dari data IdLomba mahasiswa
                strcpy(data[i].idlomba,b[j].atribut);//maka copy data nama sesuai primari Lomba ke data foregin IdLomba mahasiswa
                ketemu=1;//maka ubah ketemu menjadi 1 
            }
            j++;//index j akan bertambah jika masih belum ketemu primari yang sama
        }
        j=0;//inisialisasi ulang nilai awal j untuk index timnya
        ketemu=0;//inisialisasi nilai awal ketemu untuk mengetahui bahwa data yang sama sudah ketemu 
        while((strcmp(c[j].id,"####")!=0) && (ketemu==0)){//selama primari data Curangnya tidak damy dan ketemu masih 0
            if(strcmp(data[i].idcurang,c[j].id)==0){//jika data kode primari Curang itu sama dengan foregin dari data IdCurang mahasiswa 
                strcpy(data[i].idcurang,c[j].atribut);//maka copy data nama sesuai primari Curang ke data foregin IdCurang mahasiswa
                ketemu=1;//maka ubah ketemu menjadi 1 
            }
            j++;//index j akan bertambah jika masih belum ketemu primari yang sama
        }
        i++;//setelah semua selesai lanjut ke indeks ke-i berikutnya 
    }
}
void join2(mahasiswa data[],deskripsi a[],deskripsi  b[],deskripsi c[]){
    int i=0;//inisialisasi nilai awal i untuk index
    while(strcmp(data[i].id,"####") !=0){//selama index ke-i nya bukan data damy
        int j=0;//inisialisasi nilai awal j untuk index Skillnya
        int ketemu=0;//inisialisasi nilai awal ketemu untuk mengetahui bahwa data yang sama sudah ketemu 
        while((strcmp(a[j].id,"####")!=0) && (ketemu==0)){//selama primari data Skillnya tidak damy dan ketemu masih 0
            if(strcmp(data[i].idskill,a[j].atribut)==0){//jika data namaSkill itu sama dengan foregin dari data IdSkill mahasiswa
                strcpy(data[i].idskill,a[j].id);//maka copy data primari Skill ke data foregin Skill dataer
                ketemu=1;//maka ubah ketemu menjadi 1 
            }
            j++;//index j akan bertambah jika masih belum ketemu primari yang sama
        }
        j=0;//inisialisasi ulang nilai awal j untuk index asalnya
        ketemu=0;//inisialisasi nilai awal ketemu untuk mengetahui bahwa data yang sama sudah ketemu
        while((strcmp(b[j].id,"####")!=0) && (ketemu==0)){//selama primari data Lombanya tidak damy dan ketemu masih 0
            if(strcmp(data[i].idlomba,b[j].atribut)==0){//jika data nama Lomba itu sama dengan foregin dari data IdLomba mahasiswa
                strcpy(data[i].idlomba,b[j].id);//maka copy data primari Lomba ke data foregin IdLomba mahasiswa
                ketemu=1;//maka ubah ketemu menjadi 1 
            }
            j++;//index j akan bertambah jika masih belum ketemu primari yang sama
        }
        j=0;//inisialisasi ulang nilai awal j untuk index timnya
        ketemu=0;//inisialisasi nilai awal ketemu untuk mengetahui bahwa data yang sama sudah ketemu 
        while((strcmp(c[j].id,"####")!=0) && (ketemu==0)){//selama primari data Curangnya tidak damy dan ketemu masih 0
            if(strcmp(data[i].idcurang,c[j].atribut)==0){//jika data nama Curang itu sama dengan foregin dari data IdCurang mahasiswa 
                strcpy(data[i].idcurang,c[j].id);//maka copy data primari Curang ke data foregin IdCurang mahasiswa
                ketemu=1;//maka ubah ketemu menjadi 1 
            }
            j++;//index j akan bertambah jika masih belum ketemu primari yang sama
        }
        i++;//setelah semua selesai lanjut ke indeks ke-i berikutnya 
    }
}

//BAGIAN FUNGSI UNTUK MENCARI NAMA TERPANJANG
int panjangdariid(mahasiswa cek[],int m){
    int i;//deklarasi i untuk for loop
    int maksimal=0;//inisialisasi maksimal untuk menampung kode primari terpanjang
    for(i=0;i<m;i++){//for loop untuk mengecek data kode primari terpanjang
        int panjang=strlen(cek[i].id);//masukan data panjang kode primari ke-i ke dalam variabel panjang
        if(panjang>maksimal){//jika panjang lebih besar dari maksimal
            maksimal=panjang;//maka maksimal akan sama degan panjang
        }
    }
    return maksimal;//kembalikan nilai ke maksimal
}
int panjangdarinama(mahasiswa cek[],int m){
    int i;//deklarasi i untuk for loop
    int maksimal=0;//inisialisasi maksimal untuk menampung nama mahasiswa terpanjang
    for(i=0;i<m;i++){//for loop untuk mengecek data nama mahasiswa terpanjang
        int panjang=strlen(cek[i].nama);//masukan data panjang nama  ke-i ke dalam variabel panjang
        if(panjang>maksimal){//jika panjang lebih besar dari maksimal
            maksimal=panjang;//maka maksimal akan sama degan panjang
        }
    }
    return maksimal;//kembalikan nilai ke maksimal
}
int panjangdarinim(mahasiswa cek[],int m){
    int i;//deklarasi i untuk for loop
    int maksimal=0;//inisialisasi maksimal untuk menampung nim terpanjang
    for(i=0;i<m;i++){//for loop untuk mengecek data nim terpanjang
        int panjang=strlen(cek[i].nim);//masukan data panjang nim ke-i ke dalam variabel panjang
        if(panjang>maksimal){//jika panjang lebih besar dari maksimal
            maksimal=panjang;//maka maksimal akan sama degan panjang
        }
    }
    return maksimal;//kembalikan nilai ke maksimal
}
int panjangdariskill(mahasiswa cek[],int m){
    int i;//deklarasi i untuk for loop
    int maksimal=0;//inisialisasi maksimal untuk menampung nama skill terpanjang
    for(i=0;i<m;i++){//for loop untuk mengecek data nama skill terpanjang
        int panjang=strlen(cek[i].idskill);//masukan data panjang nama skill ke-i ke dalam variabel panjang
        if(panjang>maksimal){//jika panjang lebih besar dari maksimal
            maksimal=panjang;//maka maksimal akan sama degan panjang
        }
    }
    return maksimal;//kembalikan nilai ke maksimal
}
int panjangdarilomba(mahasiswa cek[],int m){
    int i;//deklarasi i untuk for loop
    int maksimal=0;//inisialisasi maksimal untuk menampung nama lomba terpanjang
    for(i=0;i<m;i++){//for loop untuk mengecek data nama lomba terpanjang
        int panjang=strlen(cek[i].idlomba);//masukan data panjang nama lomba ke-i ke dalam variabel panjang
        if(panjang>maksimal){//jika panjang lebih besar dari maksimal
            maksimal=panjang;//maka maksimal akan sama degan panjang
        }
    }
    return maksimal;//kembalikan nilai ke maksimal
}
int panjangdaricurang(mahasiswa cek[],int m){
    int i;//deklarasi i untuk for loop
    int maksimal=0;//inisialisasi maksimal untuk menampung nama curang terpanjang
    for(i=0;i<m;i++){//for loop untuk mengecek data nama curang terpanjang
        int panjang=strlen(cek[i].idcurang);//masukan data panjang nama curang ke-i ke dalam variabel panjang
        if(panjang>maksimal){//jika panjang lebih besar dari maksimal
            maksimal=panjang;//maka maksimal akan sama degan panjang
        }
    }
    return maksimal;//kembalikan nilai ke maksimal
}
int panjangdarikode(deskripsi cek[],int idx){
    int i;//deklarasi i untuk for loop
    int maksimal=0;//inisialisasi maksimal untuk menampung kode primari terpanjang
    for(i=0;i<idx;i++){//for loop untuk mengecek data kode primari terpanjang
        int panjang=strlen(cek[i].id);//masukan data panjang kode primari ke-i ke dalam variabel panjang
        if(panjang>maksimal){//jika panjang lebih besar dari maksimal
            maksimal=panjang;//maka maksimal akan sama degan panjang
        }
    }
    return maksimal;//kembalikan nilai ke maksimal
}
int panjangdariatribut(deskripsi cek[],int idx){
    int i;//deklarasi i untuk for loop
    int maksimal=0;//inisialisasi maksimal untuk menampung nama atribut terpanjang
    for(i=0;i<idx;i++){//for loop untuk mengecek data nama atribut terpanjang
        int panjang=strlen(cek[i].atribut);//masukan data panjang nama atribut ke-i ke dalam variabel panjang
        if(panjang>maksimal){//jika panjang lebih besar dari maksimal
            maksimal=panjang;//maka maksimal akan sama degan panjang
        }
    }
    return maksimal;//kembalikan nilai ke maksimal
}

//BAGIAN PROSEDUR MENAMPILKAN TABEL
void cetaktabelmahasiswa(mahasiswa cek[],int m){
    int i,j;//deklarasi i dan j untuk for loop
    int panjangid=panjangdariid(cek,m);//panggil fungsi data kode primari terpanjang ke variabel panjangid
    int panjangnama=panjangdarinama(cek,m);//panggil fungsi data nama fighter terpanjang ke variabel panjangnama
    int panjangnim=panjangdarinim(cek,m);//panggil fungsi data digit power terpanjang ke variabel panjangnim
    int panjangskill=panjangdariskill(cek,m);//panggil fungsi data nama ras terpanjang ke variabel panjangskill
    int panjanglomba=panjangdarilomba(cek,m);//panggil fungsi data nama lomba terpanjang ke variabel panjanglomba
    int panjangcurang=panjangdaricurang(cek,m);//panggil fungsi data nama tim terpanjang ke variabel panjangcurang
    if(panjangid<2){//jika panjangid kurang dari 2(panjang "ID")
        panjangid=2;//maka panjangid sama dengan 2
    }
    if(panjangnama<4){//jika panjangnama kurang dari 4(panjang "Nama")
        panjangnama=4;//maka panjangnama sama dengan 4
    }
    if(panjangnim<3){//jika panjangnim kurang dari 3(panjang "NIM")
        panjangnim=3;//maka panjangnim sama dengan 3
    }
    if(panjangskill<7){//jika panjangskill kurang dari 7(panjang "IdSkill")
        panjangskill=7;//maka panjangskill sama dengan 7
    }

    if(panjanglomba<7){//jika panjanglomba kurang dari 7(panjang "IdLomba")
        panjanglomba=7;//maka panjanglomba sama dengan 7
    }
    if(panjangcurang<12){//jika panjangcurang kurang dari 12(panjang "IdKecurangan")
        panjangcurang=12;//maka panjangcurang sama dengan 12
    }
    
    char code[2]="ID";//inisialisasi array char code untuk kata "ID" sebanyak panjangnya
    char name[4]="Nama";//inisialisasi array char name untuk kata "Nama" sebanyak panjangnya
    char nim[3]="NIM";//inisialisasi array char kekuatan untuk kata "NIM" sebanyak panjangny
    char skill[7]="IdSkill";//inisialisasi array Skill code untuk kata "IdSkill" sebanyak panjangnya
    char lomba[7]="IdLomba";//inisialisasi array char Lomba untuk kata "IdLomba" sebanyak panjangnya
    char curang[12]="IdKecurangan";//inisialisasi array char curang untuk kata "IdKecurangan" sebanyak panjangnya
    //bagian garis atas judul sesuai panjang masing-masing kolom 
    printf("*");
    for(i=0;i<panjangid+2;i++){//for loop garis sesuai panjangid ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangnama+2;i++){//for loop garis sesuai panjangnama ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangnim+2;i++){//for loop garis sesuai panjangnim ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangskill+2;i++){//for loop garis sesuai panjangskill ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjanglomba+2;i++){//for loop garis sesuai panjanglomba ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangcurang+2;i++){//for loop garis sesuai panjangcurang ditambah 2 untuk spasi
        printf("-");
    }
    printf("*\n");
    //bagian judul data fighter sesuai dengan panjang dari masing-masing kolom
    printf("| "); //menampilkan garis sisi tabel
    for(i=0;i<panjangid;i++){//for loop untuk menampilkan judul "ID" sesuai panjang id terpanjang
        if(i<2){//jika i itu kurang dari panjang kata "ID"
            printf("%c",code[i]);//maka tampilkan katanya satu satu 
        }else{//jika sudah enggak
            printf(" ");//tampilkan spasi
        }
    }
    printf(" | "); //menampilkan garis sisi tabel
    for(i=0;i<panjangnama;i++){//for loop untuk menampilkan judul "Nama" sesuai panjang nama terpanjang
        if(i<4){//jika i itu kurang dari panjang kata "Nama"
            printf("%c",name[i]);//maka tampilkan katanya satu satu 
        }else{//jika sudah enggak
            printf(" ");//tampilkan spasi
        }
    }
    printf(" | "); //menampilkan garis sisi tabel
    for(i=0;i<panjangnim;i++){//for loop untuk menampilkan judul "NIM" sesuai panjang nim terpanjang
        if(i<3){//jika i itu kurang dari panjang kata "NIM"
            printf("%c",nim[i]);//maka tampilkan katanya satu satu 
        }else{//jika sudah enggak
            printf(" ");//tampilkan spasi
        }
    }
    printf(" | "); //menampilkan garis sisi tabel
    for(i=0;i<panjangskill;i++){//for loop untuk menampilkan judul "Skill" sesuai panjang nama skill terpanjang
        if(i<7){//jika i itu kurang dari panjang kata "Skill"
            printf("%c",skill[i]);//maka tampilkan katanya satu satu 
        }else{//jika sudah enggak
            printf(" ");//tampilkan spasi
        }
    }
    printf(" | "); //menampilkan garis sisi tabel
    for(i=0;i<panjanglomba;i++){//for loop untuk menampilkan judul "Lomba" sesuai panjang nama lomba terpanjang
        if(i<7){//jika i itu kurang dari panjang kata "Lomba"
            printf("%c",lomba[i]);//maka tampilkan katanya satu satu 
        }else{//jika sudah enggak
            printf(" ");//tampilkan spasi
        }
    }
    printf(" | "); //menampilkan garis sisi tabel
    for(i=0;i<panjangcurang;i++){//for loop untuk menampilkan judul "Kecurangan" sesuai panjang nama curang terpanjang
        if(i<12){//jika i itu kurang dari panjang kata "Kecurangan"
            printf("%c",curang[i]);//maka tampilkan katanya satu satu 
        }else{//jika sudah enggak
            printf(" ");//tampilkan spasi
        }
    }
    printf(" |"); //menampilkan garis sisi tabel
    printf("\n");//membuat baris baru
    printf("*");
    //Bagian garis bawah judul sesuai panjang masing-masing kolom
    for(i=0;i<panjangid+2;i++){//for loop garis sesuai panjangid ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangnama+2;i++){//for loop garis sesuai panjangnama ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangnim+2;i++){//for loop garis sesuai panjangnim ditambah 2 untuk spasi
        printf("-");
    }       
    printf("*");
    for(i=0;i<panjangskill+2;i++){//for loop garis sesuai panjangskill ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjanglomba+2;i++){//for loop garis sesuai panjanglomba ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangcurang+2;i++){//for loop garis sesuai panjangcurang ditambah 2 untuk spasi
        printf("-");
    }
    printf("*\n");
    //bagian untuk menampilkan semua data fighter sesuai panjang masing-masing kolom
    for(i=0;i<m;i++){//for loop untuk menampilkan data fighter sebanyak jumlahnya
        int len1=strlen(cek[i].id);//simpan panjang kode primari ke-i ke dalam len1
        int len2=strlen(cek[i].nama);//simpan panjang nama mahasiswa  ke-i ke dalam len2
        int len3=strlen(cek[i].idskill);//simpan panjang nama skill ke-i ke dalam len3
        int len4=strlen(cek[i].idlomba);//simpan panjang nama lomba ke-i ke dalam len4
        int len5=strlen(cek[i].idcurang);//simpan panjang nama curang ke-i ke dalam len5
        int len6=strlen(cek[i].nim);//simpan panjang nim ke-i ke dalam len6
        printf("| "); //menampilkan garis sisi tabel
        for(j=0;j<panjangid;j++){//for loop untuk menampilkan data kode primari sesuai panjang nama terpanjangnya
            if(j<len1){//jika j itu kurang dari len1(panjang data kode primari)
                printf("%c",cek[i].id[j]);//maka tampilkan katanya satu satu 
            }else{//jika sudah enggak
                printf(" ");//tampilkan spasi
            }
        }
        printf(" | "); //menampilkan garis sisi tabel
        for(j=0;j<panjangnama;j++){//for loop untuk menampilkan data nama mahasiswa sesuai panjang nama terpanjangnya
            if(j<len2){//jika j itu kurang dari len2(panjang data nama mahasiswa)
                printf("%c",cek[i].nama[j]);//maka tampilkan katanya satu satu 
            }else{//jika sudah enggak
                printf(" ");//tampilkan spasi
            }
        }
        printf(" | "); //menampilkan garis sisi tabel
        for(j=0;j<panjangnim;j++){//for loop untuk menampilkan data nim sesuai panjang terpanjangnya
            if(j<len6){//jika j itu kurang dari len6(panjang data nim)
                printf("%c",cek[i].nim[j]);//maka tampilkan katanya satu satu 
            }else{//jika sudah enggak
                printf(" ");//tampilkan spasi
            }
        }
        printf(" | "); //menampilkan garis sisi tabel
        for(j=0;j<panjangskill;j++){//for loop untuk menampilkan data nama skill sesuai panjang nama terpanjangnya
            if(j<len3){//jika j itu kurang dari len3(panjang data nama skill)
                printf("%c",cek[i].idskill[j]);//maka tampilkan katanya satu satu 
            }else{//jika sudah enggak
                printf(" ");//tampilkan spasi
            }
        }
        printf(" | "); //menampilkan garis sisi tabel
        for(j=0;j<panjanglomba;j++){//for loop untuk menampilkan data nama lomba sesuai panjang nama terpanjangnya
            if(j<len4){//jika j itu kurang dari len4(panjang data nama lomba)
                printf("%c",cek[i].idlomba[j]);//maka tampilkan katanya satu satu 
            }else{//jika sudah enggak
                printf(" ");//tampilkan spasi
            }
        }
        printf(" | "); //menampilkan garis sisi tabel
        for(j=0;j<panjangcurang;j++){//for loop untuk menampilkan data nama kecurangan sesuai panjang nama terpanjangnya
            if(j<len5){//jika j itu kurang dari len5(panjang data nama kecurangan)
                printf("%c",cek[i].idcurang[j]);//maka tampilkan katanya satu satu 
            }else{//jika sudah enggak
                printf(" ");//tampilkan spasi
            }
        }
        printf(" |");//menampilkan garis sisi tabel
        printf("\n");//membuat baris baru 
    }
    //bagian garis bawah dari data fighter
    printf("*");
    for(i=0;i<panjangid+2;i++){//for loop garis sesuai panjangid ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangnama+2;i++){//for loop garis sesuai panjangnama ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangnim+2;i++){//for loop garis sesuai panjangnim ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangskill+2;i++){//for loop garis sesuai panjangskill ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjanglomba+2;i++){//for loop garis sesuai panjanglomba ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangcurang+2;i++){//for loop garis sesuai panjangcurang ditambah 2 untuk spasi
        printf("-");
    }
    printf("*\n");
}
void cetaktabelcomplate(mahasiswa cek[],int m){
    int i,j;//deklarasi i dan j untuk for loop
    int panjangid=panjangdariid(cek,m);//panggil fungsi data kode primari terpanjang ke variabel panjangid
    int panjangnama=panjangdarinama(cek,m);//panggil fungsi data nama fighter terpanjang ke variabel panjangnama
    int panjangnim=panjangdarinim(cek,m);//panggil fungsi data digit power terpanjang ke variabel panjangnim
    int panjangskill=panjangdariskill(cek,m);//panggil fungsi data nama ras terpanjang ke variabel panjangskill
    int panjanglomba=panjangdarilomba(cek,m);//panggil fungsi data nama lomba terpanjang ke variabel panjanglomba
    int panjangcurang=panjangdaricurang(cek,m);//panggil fungsi data nama tim terpanjang ke variabel panjangcurang
    if(panjangid<2){//jika panjangid kurang dari 2(panjang "ID")
        panjangid=2;//maka panjangid sama dengan 2
    }
    if(panjangnama<4){//jika panjangnama kurang dari 4(panjang "Nama")
        panjangnama=4;//maka panjangnama sama dengan 4
    }
    if(panjangnim<3){//jika panjangnim kurang dari 3(panjang "NIM")
        panjangnim=3;//maka panjangnim sama dengan 3
    }
    if(panjangskill<5){//jika panjangskill kurang dari 5(panjang "Skill")
        panjangskill=5;//maka panjangskill sama dengan 5
    }

    if(panjanglomba<5){//jika panjanglomba kurang dari 5(panjang "Lomba")
        panjanglomba=5;//maka panjanglomba sama dengan 5
    }
    if(panjangcurang<10){//jika panjangcurang kurang dari 10(panjang "Kecurangan")
        panjangcurang=10;//maka panjangcurang sama dengan 10
    }
    
    char code[2]="ID";//inisialisasi array char code untuk kata "ID" sebanyak panjangnya
    char name[4]="Nama";//inisialisasi array char name untuk kata "Nama" sebanyak panjangnya
    char nim[3]="NIM";//inisialisasi array char kekuatan untuk kata "NIM" sebanyak panjangny
    char skill[5]="Skill";//inisialisasi array Skill code untuk kata "IdSkill" sebanyak panjangnya
    char lomba[5]="Lomba";//inisialisasi array char Lomba untuk kata "IdLomba" sebanyak panjangnya
    char curang[10]="Kecurangan";//inisialisasi array char curang untuk kata "IdKecurangan" sebanyak panjangnya
    //bagian garis atas judul sesuai panjang masing-masing kolom 
    printf("*");
    for(i=0;i<panjangid+2;i++){//for loop garis sesuai panjangid ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangnama+2;i++){//for loop garis sesuai panjangnama ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangnim+2;i++){//for loop garis sesuai panjangnim ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangskill+2;i++){//for loop garis sesuai panjangskill ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjanglomba+2;i++){//for loop garis sesuai panjanglomba ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangcurang+2;i++){//for loop garis sesuai panjangcurang ditambah 2 untuk spasi
        printf("-");
    }
    printf("*\n");
    //bagian judul data fighter sesuai dengan panjang dari masing-masing kolom
    printf("| "); //menampilkan garis sisi tabel
    for(i=0;i<panjangid;i++){//for loop untuk menampilkan judul "ID" sesuai panjang id terpanjang
        if(i<2){//jika i itu kurang dari panjang kata "ID"
            printf("%c",code[i]);//maka tampilkan katanya satu satu 
        }else{//jika sudah enggak
            printf(" ");//tampilkan spasi
        }
    }
    printf(" | "); //menampilkan garis sisi tabel
    for(i=0;i<panjangnama;i++){//for loop untuk menampilkan judul "Nama" sesuai panjang nama terpanjang
        if(i<4){//jika i itu kurang dari panjang kata "Nama"
            printf("%c",name[i]);//maka tampilkan katanya satu satu 
        }else{//jika sudah enggak
            printf(" ");//tampilkan spasi
        }
    }
    printf(" | "); //menampilkan garis sisi tabel
    for(i=0;i<panjangnim;i++){//for loop untuk menampilkan judul "NIM" sesuai panjang nim terpanjang
        if(i<3){//jika i itu kurang dari panjang kata "NIM"
            printf("%c",nim[i]);//maka tampilkan katanya satu satu 
        }else{//jika sudah enggak
            printf(" ");//tampilkan spasi
        }
    }
    printf(" | "); //menampilkan garis sisi tabel
    for(i=0;i<panjangskill;i++){//for loop untuk menampilkan judul "Skill" sesuai panjang nama skill terpanjang
        if(i<5){//jika i itu kurang dari panjang kata "Skill"
            printf("%c",skill[i]);//maka tampilkan katanya satu satu 
        }else{//jika sudah enggak
            printf(" ");//tampilkan spasi
        }
    }
    printf(" | "); //menampilkan garis sisi tabel
    for(i=0;i<panjanglomba;i++){//for loop untuk menampilkan judul "Lomba" sesuai panjang nama lomba terpanjang
        if(i<5){//jika i itu kurang dari panjang kata "Lomba"
            printf("%c",lomba[i]);//maka tampilkan katanya satu satu 
        }else{//jika sudah enggak
            printf(" ");//tampilkan spasi
        }
    }
    printf(" | "); //menampilkan garis sisi tabel
    for(i=0;i<panjangcurang;i++){//for loop untuk menampilkan judul "Kecurangan" sesuai panjang nama curang terpanjang
        if(i<10){//jika i itu kurang dari panjang kata "Kecurangan"
            printf("%c",curang[i]);//maka tampilkan katanya satu satu 
        }else{//jika sudah enggak
            printf(" ");//tampilkan spasi
        }
    }
    printf(" |"); //menampilkan garis sisi tabel
    printf("\n");//membuat baris baru
    printf("*");
    //Bagian garis bawah judul sesuai panjang masing-masing kolom
    for(i=0;i<panjangid+2;i++){//for loop garis sesuai panjangid ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangnama+2;i++){//for loop garis sesuai panjangnama ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangnim+2;i++){//for loop garis sesuai panjangnim ditambah 2 untuk spasi
        printf("-");
    }       
    printf("*");
    for(i=0;i<panjangskill+2;i++){//for loop garis sesuai panjangskill ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjanglomba+2;i++){//for loop garis sesuai panjanglomba ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangcurang+2;i++){//for loop garis sesuai panjangcurang ditambah 2 untuk spasi
        printf("-");
    }
    printf("*\n");
    //bagian untuk menampilkan semua data fighter sesuai panjang masing-masing kolom
    for(i=0;i<m;i++){//for loop untuk menampilkan data fighter sebanyak jumlahnya
        int len1=strlen(cek[i].id);//simpan panjang kode primari ke-i ke dalam len1
        int len2=strlen(cek[i].nama);//simpan panjang nama mahasiswa  ke-i ke dalam len2
        int len3=strlen(cek[i].idskill);//simpan panjang nama skill ke-i ke dalam len3
        int len4=strlen(cek[i].idlomba);//simpan panjang nama lomba ke-i ke dalam len4
        int len5=strlen(cek[i].idcurang);//simpan panjang nama curang ke-i ke dalam len5
        int len6=strlen(cek[i].nim);//simpan panjang nim ke-i ke dalam len5
        printf("| "); //menampilkan garis sisi tabel
        for(j=0;j<panjangid;j++){//for loop untuk menampilkan data kode primari sesuai panjang nama terpanjangnya
            if(j<len1){//jika j itu kurang dari len1(panjang data kode primari)
                printf("%c",cek[i].id[j]);//maka tampilkan katanya satu satu 
            }else{//jika sudah enggak
                printf(" ");//tampilkan spasi
            }
        }
        printf(" | "); //menampilkan garis sisi tabel
        for(j=0;j<panjangnama;j++){//for loop untuk menampilkan data nama mahasiswa sesuai panjang nama terpanjangnya
            if(j<len2){//jika j itu kurang dari len2(panjangdata nama mahasiswa)
                printf("%c",cek[i].nama[j]);//maka tampilkan katanya satu satu 
            }else{//jika sudah enggak
                printf(" ");//tampilkan spasi
            }
        }
        printf(" | "); //menampilkan garis sisi tabel
        for(j=0;j<panjangnim;j++){//for loop untuk menampilkan data nim sesuai panjang nama terpanjangnya
            if(j<len6){//jika j itu kurang dari len2(panjangdata nama nim)
                printf("%c",cek[i].nim[j]);//maka tampilkan katanya satu satu 
            }else{//jika sudah enggak
                printf(" ");//tampilkan spasi
            }
        }
        printf(" | "); //menampilkan garis sisi tabel
        for(j=0;j<panjangskill;j++){//for loop untuk menampilkan data nama skill sesuai panjang nama terpanjangnya
            if(j<len3){//jika j itu kurang dari len3(panjang data nama skill)
                printf("%c",cek[i].idskill[j]);//maka tampilkan katanya satu satu 
            }else{//jika sudah enggak
                printf(" ");//tampilkan spasi
            }
        }
        printf(" | "); //menampilkan garis sisi tabel
        for(j=0;j<panjanglomba;j++){//for loop untuk menampilkan data nama lomba sesuai panjang nama terpanjangnya
            if(j<len4){//jika j itu kurang dari len4(panjang data nama lomba)
                printf("%c",cek[i].idlomba[j]);//maka tampilkan katanya satu satu 
            }else{//jika sudah enggak
                printf(" ");//tampilkan spasi
            }
        }
        printf(" | "); //menampilkan garis sisi tabel
        for(j=0;j<panjangcurang;j++){//for loop untuk menampilkan data nama kecurangan sesuai panjang nama terpanjangnya
            if(j<len5){//jika j itu kurang dari len5(panjang data nama kecurangan)
                printf("%c",cek[i].idcurang[j]);//maka tampilkan katanya satu satu 
            }else{//jika sudah enggak
                printf(" ");//tampilkan spasi
            }
        }
        printf(" |");//menampilkan garis sisi tabel
        printf("\n");//membuat baris baru 
    }
    //bagian garis bawah dari data fighter
    printf("*");
    for(i=0;i<panjangid+2;i++){//for loop garis sesuai panjangid ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangnama+2;i++){//for loop garis sesuai panjangnama ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangnim+2;i++){//for loop garis sesuai panjangnim ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangskill+2;i++){//for loop garis sesuai panjangskill ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjanglomba+2;i++){//for loop garis sesuai panjanglomba ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangcurang+2;i++){//for loop garis sesuai panjangcurang ditambah 2 untuk spasi
        printf("-");
    }
    printf("*\n");
}
void cetaktabelskill(deskripsi cek[], int idx){
    int i,j;//deklarasi i dan j untuk for loop
    int panjangkode=panjangdarikode(cek,idx);//panggil fungsi data kode primari terpanjang ke variabel panjangkode
    int panjangatribut=panjangdariatribut(cek,idx);//panggil fungsi data nama atribut terpanjang ke variabel panjangatribut
    if(panjangkode<2){//jika panjangkode kurang dari 2(panjang "ID")
        panjangkode=2;//maka panjangkode sama dengan 2
    }
    if(panjangatribut<5){//jika panjangatribut kurang dari 5(panjang "Skill")
        panjangatribut=5;//maka panjangatribut sama dengan 5
    }
    char code[2]="ID";//inisialisasi array char code untuk kata "ID" sebanyak panjangnya
    char name[5]="Skill";//inisialisasi array char name untuk kata "Skill" sebanyak panjangnya
    //bagian garis atas judul sesuai panjang masing-masing kolom 
    printf("*");
    for(i=0;i<panjangkode+2;i++){//for loop garis sesuai panjangkode ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangatribut+2;i++){//for loop garis sesuai panjangatribut ditambah 2 untuk spasi
        printf("-");
    }
    printf("*\n");
    printf("| "); //menampilkan garis sisi tabel
    for(i=0;i<panjangkode;i++){//for loop untuk menampilkan judul "ID" sesuai panjang kode primari terpanjang
        if(i<2){//jika i itu kurang dari panjang kata "ID"
            printf("%c",code[i]);//maka tampilkan katanya satu satu 
        }else{//jika sudah enggak
            printf(" ");//tampilkan spasi
        }
    }
    printf(" | "); //menampilkan garis sisi tabel
    for(i=0;i<panjangatribut;i++){//for loop untuk menampilkan judul "Skill" sesuai panjang atribut terpanjang
        if(i<5){//jika i itu kurang dari panjang kata "Lomba"
            printf("%c",name[i]);//maka tampilkan katanya satu satu 
        }else{//jika sudah enggak
            printf(" ");//tampilkan spasi
        }
    }
    printf(" |"); //menampilkan garis sisi tabel
    printf("\n");//membuat baris baru
    //bagian garis bawah judul sesuai panjang masing-masing kolom 
    printf("*");
    for(i=0;i<panjangkode+2;i++){//for loop garis sesuai panjangkode ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangatribut+2;i++){//for loop garis sesuai panjangatribut ditambah 2 untuk spasi
        printf("-");
    }
    printf("*\n");
    //bagian untuk menampilkan semua data kode primari dan atributnya sesuai panjang masing-masing kolom
    for(i=0;i<idx;i++){//for loop untuk menampilkan semua data kode primari dan atributnya sebanyak jumlahnya
        int len1=strlen(cek[i].id);//simpan panjang kode primari ke-i ke dalam len1
        int len2=strlen(cek[i].atribut);
        printf("| ");//menampilkan garis sisi tabel
        for(j=0;j<panjangkode;j++){//for loop untuk menampilkan data kode primari sesuai panjang nama terpanjangnya
            if(j<len1){//jika j itu kurang dari len1(panjang data kode primari)
                printf("%c",cek[i].id[j]);//maka tampilkan katanya satu satu 
            }else{//jika sudah enggak
                printf(" ");//tampilkan spasi
            }
        }
        printf(" | "); //menampilkan garis sisi tabel
        for(j=0;j<panjangatribut;j++){//for loop untuk menampilkan data nama atribut sesuai panjang nama terpanjangnya
            if(j<len2){//jika j itu kurang dari len2(panjang data nama atribut)
                printf("%c",cek[i].atribut[j]);//maka tampilkan katanya satu satu 
            }else{//jika sudah enggak
                printf(" ");//tampilkan spasi
            }
        }
        printf(" |");//menampilkan garis sisi tabel
        printf("\n");//membuat baris baru
    }
    //bagian garis bawah dari data kode primari dan atributnya
    printf("*");
    for(i=0;i<panjangkode+2;i++){//for loop garis sesuai panjangkode ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangatribut+2;i++){//for loop garis sesuai panjangatribut ditambah 2 untuk spasi
        printf("-");
    }
    printf("*\n");
}
void cetaktabellomba(deskripsi cek[], int idx){
    int i,j;//deklarasi i dan j untuk for loop
    int panjangkode=panjangdarikode(cek,idx);//panggil fungsi data kode primari terpanjang ke variabel panjangkode
    int panjangatribut=panjangdariatribut(cek,idx);//panggil fungsi data nama atribut terpanjang ke variabel panjangatribut
    if(panjangkode<2){//jika panjangkode kurang dari 2(panjang "ID")
        panjangkode=2;//maka panjangkode sama dengan 2
    }
    if(panjangatribut<5){//jika panjangatribut kurang dari 5(panjang "Lomba")
        panjangatribut=5;//maka panjangatribut sama dengan 5
    }
    char code[2]="ID";//inisialisasi array char code untuk kata "ID" sebanyak panjangnya
    char name[5]="Lomba";//inisialisasi array char name untuk kata "Lomba" sebanyak panjangnya
    //bagian garis atas judul sesuai panjang masing-masing kolom 
    printf("*");
    for(i=0;i<panjangkode+2;i++){//for loop garis sesuai panjangkode ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangatribut+2;i++){//for loop garis sesuai panjangatribut ditambah 2 untuk spasi
        printf("-");
    }
    printf("*\n");
    printf("| "); //menampilkan garis sisi tabel
    for(i=0;i<panjangkode;i++){//for loop untuk menampilkan judul "ID" sesuai panjang kode primari terpanjang
        if(i<2){//jika i itu kurang dari panjang kata "ID"
            printf("%c",code[i]);//maka tampilkan katanya satu satu 
        }else{//jika sudah enggak
            printf(" ");//tampilkan spasi
        }
    }
    printf(" | "); //menampilkan garis sisi tabel
    for(i=0;i<panjangatribut;i++){//for loop untuk menampilkan judul "Lomba" sesuai panjang atribut terpanjang
        if(i<5){//jika i itu kurang dari panjang kata "Lomba"
            printf("%c",name[i]);//maka tampilkan katanya satu satu 
        }else{//jika sudah enggak
            printf(" ");//tampilkan spasi
        }
    }
    printf(" |"); //menampilkan garis sisi tabel
    printf("\n");//membuat baris baru
    //bagian garis bawah judul sesuai panjang masing-masing kolom 
    printf("*");
    for(i=0;i<panjangkode+2;i++){//for loop garis sesuai panjangkode ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangatribut+2;i++){//for loop garis sesuai panjangatribut ditambah 2 untuk spasi
        printf("-");
    }
    printf("*\n");
    //bagian untuk menampilkan semua data kode primari dan atributnya sesuai panjang masing-masing kolom
    for(i=0;i<idx;i++){//for loop untuk menampilkan semua data kode primari dan atributnya sebanyak jumlahnya
        int len1=strlen(cek[i].id);//simpan panjang kode primari ke-i ke dalam len1
        int len2=strlen(cek[i].atribut);
        printf("| ");//menampilkan garis sisi tabel
        for(j=0;j<panjangkode;j++){//for loop untuk menampilkan data kode primari sesuai panjang nama terpanjangnya
            if(j<len1){//jika j itu kurang dari len1(panjang data kode primari)
                printf("%c",cek[i].id[j]);//maka tampilkan katanya satu satu 
            }else{//jika sudah enggak
                printf(" ");//tampilkan spasi
            }
        }
        printf(" | "); //menampilkan garis sisi tabel
        for(j=0;j<panjangatribut;j++){//for loop untuk menampilkan data nama atribut sesuai panjang nama terpanjangnya
            if(j<len2){//jika j itu kurang dari len2(panjang data nama atribut)
                printf("%c",cek[i].atribut[j]);//maka tampilkan katanya satu satu 
            }else{//jika sudah enggak
                printf(" ");//tampilkan spasi
            }
        }
        printf(" |");//menampilkan garis sisi tabel
        printf("\n");//membuat baris baru
    }
    //bagian garis bawah dari data kode primari dan atributnya
    printf("*");
    for(i=0;i<panjangkode+2;i++){//for loop garis sesuai panjangkode ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangatribut+2;i++){//for loop garis sesuai panjangatribut ditambah 2 untuk spasi
        printf("-");
    }
    printf("*\n");
}
void cetaktabelcurang(deskripsi cek[], int idx){
    int i,j;//deklarasi i dan j untuk for loop
    int panjangkode=panjangdarikode(cek,idx);//panggil fungsi data kode primari terpanjang ke variabel panjangkode
    int panjangatribut=panjangdariatribut(cek,idx);//panggil fungsi data nama atribut terpanjang ke variabel panjangatribut
    if(panjangkode<2){//jika panjangkode kurang dari 2(panjang "ID")
        panjangkode=2;//maka panjangkode sama dengan 2
    }
    if(panjangatribut<10){//jika panjangatribut kurang dari 5(panjang "Kecurangan")
        panjangatribut=10;//maka panjangatribut sama dengan 5
    }
    char code[2]="ID";//inisialisasi array char code untuk kata "ID" sebanyak panjangnya
    char name[10]="Kecurangan";//inisialisasi array char name untuk kata "Kecurangan" sebanyak panjangnya
    //bagian garis atas judul sesuai panjang masing-masing kolom 
    printf("*");
    for(i=0;i<panjangkode+2;i++){//for loop garis sesuai panjangkode ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangatribut+2;i++){//for loop garis sesuai panjangatribut ditambah 2 untuk spasi
        printf("-");
    }
    printf("*\n");
    printf("| "); //menampilkan garis sisi tabel
    for(i=0;i<panjangkode;i++){//for loop untuk menampilkan judul "ID" sesuai panjang kode primari terpanjang
        if(i<2){//jika i itu kurang dari panjang kata "ID"
            printf("%c",code[i]);//maka tampilkan katanya satu satu 
        }else{//jika sudah enggak
            printf(" ");//tampilkan spasi
        }
    }
    printf(" | "); //menampilkan garis sisi tabel
    for(i=0;i<panjangatribut;i++){//for loop untuk menampilkan judul "Kecurangan" sesuai panjang atribut terpanjang
        if(i<10){//jika i itu kurang dari panjang kata "Kecurangan"
            printf("%c",name[i]);//maka tampilkan katanya satu satu 
        }else{//jika sudah enggak
            printf(" ");//tampilkan spasi
        }
    }
    printf(" |"); //menampilkan garis sisi tabel
    printf("\n");//membuat baris baru
    //bagian garis bawah judul sesuai panjang masing-masing kolom 
    printf("*");
    for(i=0;i<panjangkode+2;i++){//for loop garis sesuai panjangkode ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangatribut+2;i++){//for loop garis sesuai panjangatribut ditambah 2 untuk spasi
        printf("-");
    }
    printf("*\n");
    //bagian untuk menampilkan semua data kode primari dan atributnya sesuai panjang masing-masing kolom
    for(i=0;i<idx;i++){//for loop untuk menampilkan semua data kode primari dan atributnya sebanyak jumlahnya
        int len1=strlen(cek[i].id);//simpan panjang kode primari ke-i ke dalam len1
        int len2=strlen(cek[i].atribut);
        printf("| ");//menampilkan garis sisi tabel
        for(j=0;j<panjangkode;j++){//for loop untuk menampilkan data kode primari sesuai panjang nama terpanjangnya
            if(j<len1){//jika j itu kurang dari len1(panjang data kode primari)
                printf("%c",cek[i].id[j]);//maka tampilkan katanya satu satu 
            }else{//jika sudah enggak
                printf(" ");//tampilkan spasi
            }
        }
        printf(" | "); //menampilkan garis sisi tabel
        for(j=0;j<panjangatribut;j++){//for loop untuk menampilkan data nama atribut sesuai panjang nama terpanjangnya
            if(j<len2){//jika j itu kurang dari len2(panjang data nama atribut)
                printf("%c",cek[i].atribut[j]);//maka tampilkan katanya satu satu 
            }else{//jika sudah enggak
                printf(" ");//tampilkan spasi
            }
        }
        printf(" |");//menampilkan garis sisi tabel
        printf("\n");//membuat baris baru
    }
    //bagian garis bawah dari data kode primari dan atributnya
    printf("*");
    for(i=0;i<panjangkode+2;i++){//for loop garis sesuai panjangkode ditambah 2 untuk spasi
        printf("-");
    }
    printf("*");
    for(i=0;i<panjangatribut+2;i++){//for loop garis sesuai panjangatribut ditambah 2 untuk spasi
        printf("-");
    }
    printf("*\n");
}

//BAGIAN MENAMPILKAN INTRO/JUDUL
void judul(){
    printf(BLUE"\n==============================================================================\n"RESET);
    printf(GREEN);
    printf("           .---.             __________________________________________ \n");
    printf("          | ()()|           |                                          |\n");
    printf("           \\  ^ /           |         SELAMAT DATANG DI JACK           |\n");
    printf("            |||||           |        ____  ____  __  __ ____           |\n");
    printf("         ___/   \\___        |        |  _ \\| __ )|  \\/  / ___|         |\n");
    printf("        /           \\       |        | | | |  _ \\| |\\/| \\___ \\         |\n");
    printf("        \\____   ____/       |        | |_| | |_) | |  | |___)|         |\n");
    printf("             | |            |        |____/|____/|_|  |_|____/         |\n");
    printf("             |_|            |      --- REAL COMPETITION 2025 ---       |\n");
    printf("                            |__________________________________________|\n");
    printf("                                                                        \n");
    printf(RESET);
    printf(BLUE"==============================================================================\n\n"RESET);

}
void dbms(){
    printf(BRIGHT_BLUE"dbms "RESET);
    printf(YELLOW"Jack >> "RESET);
}

//BAGIAN PROSEDUR UNTUK MENAMPILKAN PANDUAN
void panduan(){
    printf(BRIGHT_YELLOW "------------------------------------------------------------------------------\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"                     [PADUAN YANG DAPAT DIGUNAKAN]                       "BRIGHT_YELLOW"||\n"RESET);
    printf(BRIGHT_YELLOW "||                                                                          ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "CYAN"1. KETERANGAN MENGENAI QUERY:                                           "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"INPUT  "WHITE": MENAMBAHKAN DATA                                               "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"UPDATE "WHITE": MENGUBAH DATA                                                  "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"DEL    "WHITE": MENGHAPUS DATA                                                 "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"SHOW   "WHITE": MENAMPILKAN DATA                                               "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||                                                                          ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "CYAN"2. KETERANGAN DATA FILE YANG ADA:                                       "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"MAHASISWA                                                               "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"SKILL                                                                   "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"LOMBA                                                                   "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"CURANG                                                                  "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"COMPLATE                                                                "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||                                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "CYAN"3. KETERANGAN PERINTAH:                                                 "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"EXIT  "WHITE": KELUAR DARI PROGRAM                                             "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"BANTU "WHITE": MENAMPILKAN PANDUAN QUERY                                       "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||                                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "CYAN"4. KETERANGAN INPUT:                                                    "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "BLUE"A.FORMAT MASUKAN FILE MAHASISWA:                                        "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"INPUT [NAMAFILE] [PRIMARI] [NAMA] [NIM] [IDSKILL] [IDLOMBA] [IDCURANG]  "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "BLUE"B.FORMAT MASUKAN FILE SKILL,LOMBA DAN CURANG                            "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"INPUT [NAMAFILE] [PRIMARI] [NAMA]                                       "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "BLUE"C.CONTOH:                                                               "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| INPUT MAHASISWA D011 JACK 2509371 S001 L001 K005#                       "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"CATATAN "WHITE": 1.JANGAN LUPA UNTUK INPUTAN SELALU DIAKHIRI DENGAN PAGAR(#)   "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 2.INPUTAN TIDAK BOLEH LEBIH DAN KURANG                        "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 3.PRIMARI HARUS BELUM ADA DALAM FILE                          "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 4.IDSKILL,IDLOMBA DAN IDCURANG HARUS ADA DALAM FILE           "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 5.NAMA FILE HARUS SESUAI DENGAN DATA YANG ADA                 "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 6.TIDAK BISA MELAKUKAN INPUT DI FILE COMPLATE                 "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 7.MASUKAN QUERY DAN NAMA FILE HARUS HURUF BESAR               "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 8.JIKA INGIN LEBIH DARI DUA KATA DIPISAHKAN OLEH UNDERSCORE(_)"BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 9.UNTUK NIM TIDAK BOLEH LEBIH/KURANG DARI 7 PANJANG DIGITNYA  "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 10.IDMAHASISWA DI AWALI HURUF 'D' DAN TIDAK BOLEH LEBIH DARI 4"BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 11.IDSKILL DI AWALI HURUF 'S' DAN TIDAK BOLEH LEBIH DARI 4    "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 12.IDLOMBA DI AWALI HURUF 'L' DAN TIDAK BOLEH LEBIH DARI 4    "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 13.IDCURANG DI AWALI HURUF 'K' DAN TIDAK BOLEH LEBIH DARI 4   "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 14.TIDAK BOLEH ADA NAMA DAN NIM YANG SAMA                     "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 15.URUTAN MASUKAN HARUS SESUAI FORMATNYA                      "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||                                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "CYAN"5. KETERANGAN UPDATE:                                                   "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "BLUE"A.FORMAT MASUKAN FILE MAHASISWA:                                        "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"UPDATE [NAMAFILE] [PRIMARI] [NAMA] [NIM] [IDSKILL] [IDLOMBA] [IDCURANG] "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "BLUE"B.FORMAT MASUKAN FILE SKILL,LOMBA DAN CURANG                            "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"UPDATE [NAMAFILE] [PRIMARI] [NAMA]                                      "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "BLUE"C.CONTOH:                                                               "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| UPDATE MAHASISWA D002 JACK 2509371 S001 L001 K005#                      "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"CATATAN "WHITE": 1.JANGAN LUPA UNTUK INPUTAN SELALU DIAKHIRI DENGAN PAGAR(#)   "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 2.INPUTAN TIDAK BOLEH LEBIH DAN KURANG                        "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 3.PRIMARI HARUS ADA DALAM FILE                                "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 4.IDSKILL,IDLOMBA DAN IDCURANG HARUS ADA DALAM FILE           "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 5.NAMA FILE HARUS SESUAI DENGAN DATA YANG ADA                 "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 6.TIDAK BISA MELAKUKAN UPDATE DI FILE COMPLATE                "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 7.MASUKAN QUERY DAN NAMA FILE HARUS HURUF BESAR               "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 8.JIKA INGIN LEBIH DARI DUA KATA DIPISAHKAN OLEH UNDERSC0RE(_)"BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 9.UNTUK NIM TIDAK BOLEH LEBIH/KURANG DARI 7 PANJANG DIGITNYA  "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 10.IDMAHASISWA DI AWALI HURUF 'D' DAN TIDAK BOLEH LEBIH DARI 4"BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 11.IDSKILL DI AWALI HURUF 'S' DAN TIDAK BOLEH LEBIH DARI 4    "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 12.IDLOMBA DI AWALI HURUF 'L' DAN TIDAK BOLEH LEBIH DARI 4    "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 13.IDCURANG DI AWALI HURUF 'K' DAN TIDAK BOLEH LEBIH DARI 4   "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 14.TIDAK BOLEH ADA NAMA DAN NIM YANG SAMA                     "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 15.URUTAN MASUKAN HARUS SESUAI FORMATNYA                      "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||                                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "CYAN"6. KETERANGAN DEL:                                                      "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "BLUE"A.FORMAT MASUKAN FILE MAHASISWA,SKILL,LOMBA DAN CURANG:                 "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"DEL [NAMAFILE] [PRIMARI]                                                "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "BLUE"B.CONTOH:                                                               "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| DEL MAHASISWA D002#                                                     "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"CATATAN "WHITE": 1.JANGAN LUPA UNTUK INPUTAN SELALU DIAKHIRI DENGAN PAGAR(#)   "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 2.INPUTAN TIDAK BOLEH LEBIH DAN KURANG                        "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 3.PRIMARI HARUS ADA DALAM FILE                                "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 4.NAMA FILE HARUS SESUAI DENGAN DATA YANG ADA                 "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 5.TIDAK BISA MELAKUKAN DEL DI FILE COMPLATE                   "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 6.UNTUK DEL INPUT PRIMARINYA SAJA                             "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 7.MASUKAN QUERY DAN NAMA FILE HARUS HURUF BESAR               "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 8.IDMAHASISWA DI AWALI HURUF 'D' DAN TIDAK BOLEH LEBIH DARI 4 "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 9.IDSKILL DI AWALI HURUF 'S' DAN TIDAK BOLEH LEBIH DARI 4     "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 11.IDLOMBA DI AWALI HURUF 'L' DAN TIDAK BOLEH LEBIH DARI 4    "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 11.IDCURANG DI AWALI HURUF 'K' DAN TIDAK BOLEH LEBIH DARI 4   "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 12.URUTAN MASUKAN HARUS SESUAI FORMATNYA                      "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||                                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "CYAN"7. KETERANGAN SHOW:                                                     "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "BLUE"A.FORMAT MASUKAN FILE MAHASISWA,SKILL,LOMBA,CURANG DAN COMPLATE:        "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"SHOW [NAMAFILE]                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "BLUE"B.CONTOH:                                                               "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| SHOW MAHASISWA#                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"CATATAN "WHITE": 1.JANGAN LUPA UNTUK INPUTAN SELALU DIAKHIRI DENGAN PAGAR(#)   "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 2.INPUTAN TIDAK BOLEH LEBIH DAN KURANG                        "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 3.NAMA FILE HARUS SESUAI DENGAN DATA YANG ADA                 "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 4.UNTUK SHOW INPUT NAMA FILENYA SAJA                          "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 5.MASUKAN QUERY DAN NAMA FILE HARUS HURUF BESAR               "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 6.URUTAN MASUKAN HARUS SESUAI FORMATNYA                       "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||                                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "CYAN"8. KETERANGAN BANTU:                                                    "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "BLUE"FORMAT MASUKAN:                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"BANTU [NAMAQUERY]                                                       "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "BLUE"CONTOH:                                                                 "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| BANTU UPDATE#                                                           "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"CATATAN "WHITE": 1.JANGAN LUPA UNTUK INPUTAN SELALU DIAKHIRI DENGAN PAGAR(#)   "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 2.INPUTAN TIDAK BOLEH LEBIH DAN KURANG                        "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 3.NAMA FILE HARUS SESUAI DENGAN DATA YANG ADA                 "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 4.UNTUK BANTU INPUT NAMA FILENYA SAJA                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 5.MASUKAN PERINTAH DAN QUERY HARUS HURUF BESAR                "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 6.URUTAN MASUKAN HARUS SESUAI FORMATNYA                       "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||                                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "CYAN"9. KETERANGAN EXIT:                                                     "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "BLUE"FORMAT MASUKAN:                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"EXIT [NAMAKODERAHASIA]                                                  "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "BLUE"KODERAHASIA:                                                            "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| JANGAN LUPA TERTAWA WALAUPUN TERLUKA                                    "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"CATATAN "WHITE": 1.JANGAN LUPA UNTUK INPUTAN SELALU DIAKHIRI DENGAN PAGAR(#)   "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 2.INPUTAN TIDAK BOLEH LEBIH DAN KURANG                        "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 3.NAMA FILE HARUS SESUAI DENGAN DATA YANG ADA                 "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 4.MASUKAN KODE RAHASIA HARUS SESUAI                           "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 5.URUTAN MASUKAN HARUS SESUAI FORMATNYA                       "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||                                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "------------------------------------------------------------------------------\n"RESET);
}
void bantuinput(){
    printf(BRIGHT_YELLOW "------------------------------------------------------------------------------\n"RESET);
    printf(BRIGHT_YELLOW "||                                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "CYAN"                          [KETERANGAN INPUT]                            "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||                                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "BLUE"A.FORMAT MASUKAN FILE MAHASISWA:                                        "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"INPUT [NAMAFILE] [PRIMARI] [NAMA] [NIM] [IDSKILL] [IDLOMBA] [IDCURANG]  "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "BLUE"B.FORMAT MASUKAN FILE SKILL,LOMBA DAN CURANG                            "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"INPUT [NAMAFILE] [PRIMARI] [NAMA]                                       "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "BLUE"C.CONTOH:                                                               "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| INPUT MAHASISWA D011 JACK 2509371 S001 L001 K005#                       "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"CATATAN "WHITE": 1.JANGAN LUPA UNTUK INPUTAN SELALU DIAKHIRI DENGAN PAGAR(#)   "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 2.INPUTAN TIDAK BOLEH LEBIH DAN KURANG                        "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 3.PRIMARI HARUS BELUM ADA DALAM FILE                          "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 4.IDSKILL,IDLOMBA DAN IDCURANG HARUS ADA DALAM FILE           "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 5.NAMA FILE HARUS SESUAI DENGAN DATA YANG ADA                 "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 6.TIDAK BISA MELAKUKAN INPUT DI FILE COMPLATE                 "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 7.MASUKAN QUERY DAN NAMA FILE HARUS HURUF BESAR               "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 8.JIKA INGIN LEBIH DARI DUA KATA DIPISAHKAN OLEH UNDERSCORE(_)"BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 9.UNTUK NIM TIDAK BOLEH LEBIH/KURANG DARI 7 PANJANG DIGITNY   "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 10.IDMAHASISWA DI AWALI HURUF 'D' DAN TIDAK BOLEH LEBIH DARI 4"BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 11.IDSKILL DI AWALI HURUF 'S' DAN TIDAK BOLEH LEBIH DARI 4    "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 12.IDLOMBA DI AWALI HURUF 'L' DAN TIDAK BOLEH LEBIH DARI 4    "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 13.IDCURANG DI AWALI HURUF 'K' DAN TIDAK BOLEH LEBIH DARI 4   "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 14.TIDAK BOLEH ADA NAMA DAN NIM YANG SAMA                     "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 15.URUTAN MASUKAN HARUS SESUAI FORMATNYA                      "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||                                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "------------------------------------------------------------------------------\n"RESET);
}
void bantuupdate(){
    printf(BRIGHT_YELLOW "------------------------------------------------------------------------------\n"RESET);
    printf(BRIGHT_YELLOW "||                                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "CYAN"                         [KETERANGAN UPDATE]                            "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||                                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "BLUE"A.FORMAT MASUKAN FILE MAHASISWA:                                        "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"UPDATE [NAMAFILE] [PRIMARI] [NAMA] [NIM] [IDSKILL] [IDLOMBA] [IDCURANG] "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "BLUE"B.FORMAT MASUKAN FILE SKILL,LOMBA DAN CURANG                            "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"UPDATE [NAMAFILE] [PRIMARI] [NAMA]                                      "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "BLUE"C.CONTOH:                                                               "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| UPDATE MAHASISWA D002 JACK 2509371 S001 L001 K005#                      "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"CATATAN "WHITE": 1.JANGAN LUPA UNTUK INPUTAN SELALU DIAKHIRI DENGAN PAGAR(#)   "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 2.INPUTAN TIDAK BOLEH LEBIH DAN KURANG                        "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 3.PRIMARI HARUS ADA DALAM FILE                                "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 4.IDSKILL,IDLOMBA DAN IDCURANG HARUS ADA DALAM FILE           "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 5.NAMA FILE HARUS SESUAI DENGAN DATA YANG ADA                 "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 6.TIDAK BISA MELAKUKAN UPDATE DI FILE COMPLATE                "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 7.MASUKAN QUERY DAN NAMA FILE HARUS HURUF BESAR               "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 8.JIKA INGIN LEBIH DARI DUA KATA DIPISAHKAN OLEH UNDERSCORE(_)"BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 9.UNTUK NIM TIDAK BOLEH LEBIH/KURANG DARI 7 PANJANG DIGITNYA  "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 10.IDMAHASISWA DI AWALI HURUF 'D' DAN TIDAK BOLEH LEBIH DARI 4"BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 11.IDSKILL DI AWALI HURUF 'S' DAN TIDAK BOLEH LEBIH DARI 4    "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 12.IDLOMBA DI AWALI HURUF 'L' DAN TIDAK BOLEH LEBIH DARI 4    "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 13.IDCURANG DI AWALI HURUF 'K' DAN TIDAK BOLEH LEBIH DARI 4   "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 14.TIDAK BOLEH ADA NAMA DAN NIM YANG SAMA                     "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 15.URUTAN MASUKAN HARUS SESUAI FORMATNYA                      "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||                                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "------------------------------------------------------------------------------\n"RESET);
}
void bantudel(){
    printf(BRIGHT_YELLOW "------------------------------------------------------------------------------\n"RESET);
    printf(BRIGHT_YELLOW "||                                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "CYAN"                         [KETERANGAN DEL]                               "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||                                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "BLUE"A.FORMAT MASUKAN FILE MAHASISWA,SKILL,LOMBA DAN CURANG:                 "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"DEL [NAMAFILE] [PRIMARI]                                                "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "BLUE"B.CONTOH:                                                               "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| DEL MAHASISWA D002#                                                     "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"CATATAN "WHITE": 1.JANGAN LUPA UNTUK INPUTAN SELALU DIAKHIRI DENGAN PAGAR(#)   "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 2.INPUTAN TIDAK BOLEH LEBIH DAN KURANG                        "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 3.PRIMARI HARUS ADA DALAM FILE                                "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 4.NAMA FILE HARUS SESUAI DENGAN DATA YANG ADA                 "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 5.TIDAK BISA MELAKUKAN DEL DI FILE COMPLATE                   "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 6.UNTUK DEL INPUT PRIMARINYA SAJA                             "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 7.MASUKAN QUERY DAN NAMA FILE HARUS HURUF BESAR               "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 8.IDMAHASISWA DI AWALI HURUF 'D' DAN TIDAK BOLEH LEBIH DARI 4 "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 9.IDSKILL DI AWALI HURUF 'S' DAN TIDAK BOLEH LEBIH DARI 4     "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 10.IDLOMBA DI AWALI HURUF 'L' DAN TIDAK BOLEH LEBIH DARI 4    "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 11.IDCURANG DI AWALI HURUF 'K' DAN TIDAK BOLEH LEBIH DARI 4   "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 12.URUTAN MASUKAN HARUS SESUAI FORMATNYA                      "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||                                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "------------------------------------------------------------------------------\n"RESET);
}
void bantushow(){
    printf(BRIGHT_YELLOW "------------------------------------------------------------------------------\n"RESET);
    printf(BRIGHT_YELLOW "||                                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "CYAN"                          [KETERANGAN SHOW]                             "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||                                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "BLUE"A.FORMAT MASUKAN FILE MAHASISWA,SKILL,LOMBA,CURANG DAN COMPLATE:        "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"SHOW [NAMAFILE]                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "BLUE"B.CONTOH:                                                               "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| SHOW MAHASISWA#                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "|| "GREEN"CATATAN "WHITE": 1.JANGAN LUPA UNTUK INPUTAN SELALU DIAKHIRI DENGAN PAGAR(#)   "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 2.INPUTAN TIDAK BOLEH LEBIH DAN KURANG                        "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 3.NAMA FILE HARUS SESUAI DENGAN DATA YANG ADA                 "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 4.UNTUK SHOW INPUT NAMA FILENYA SAJA                          "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 5.MASUKAN QUERY DAN NAMA FILE HARUS HURUF BESAR               "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||          "WHITE" 6.URUTAN MASUKAN HARUS SESUAI FORMATNYA                       "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "||                                                                         "BRIGHT_YELLOW" ||\n"RESET);
    printf(BRIGHT_YELLOW "------------------------------------------------------------------------------\n"RESET);
}

//BAGIAN PROSEDUR UNTUK MENAMPILKAN PESAN ERROR
void inputkurang(){
    printf(RED);
    printf("=============================ERROR=============================\n");
    printf("|------------MAAF INPUTAN YANG KAMU MASUKAN KURANG------------|\n");
    printf("=============================ERROR=============================\n");
    printf(RESET);
}
void inputlebih(){
    printf(RED);
    printf("=============================ERROR=============================\n");
    printf("|-------------MAAF INPUTAN YANG KAMU MASUKAN LEBIH------------|\n");
    printf("=============================ERROR=============================\n");
    printf(RESET);
}
void inputankedua(){
    printf(RED);
    printf("=============================ERROR=============================\n");
    printf("|---------------MAAF MASUKAN KEDUA TIDAK SESUAI---------------|\n");
    printf("|------------SILAKAN BACA PANDUAN TERLEBIH DAHULU-------------|\n");
    printf("=============================ERROR=============================\n");
    printf(RESET);
}
void idskill(){
    printf(RED);
    printf("=============================ERROR=============================\n");
    printf("|-------------MAAF KODE IDSKILL YANG KAMU MASUKAN ------------|\n");
    printf("|-----------------TIDAK ADA DALAM TABEL SKILL-----------------|\n");
    printf("=============================ERROR=============================\n");
    printf(RESET);
}
void idlomba(){
    printf(RED);
    printf("=============================ERROR=============================\n");
    printf("|-------------MAAF KODE IDLOMBA YANG KAMU MASUKAN ------------|\n");
    printf("|-----------------TIDAK ADA DALAM TABEL LOMBA-----------------|\n");
    printf("=============================ERROR=============================\n");
    printf(RESET);
}
void idcurang(){
    printf(RED);
    printf("=============================ERROR=============================\n");
    printf("|------------MAAF KODE IDCURANG YANG KAMU MASUKAN ------------|\n");
    printf("|----------------TIDAK ADA DALAM TABEL CURANG-----------------|\n");
    printf("=============================ERROR=============================\n");
    printf(RESET);
}
void pesanexit(){
    printf(RED);
    printf("=============================ERROR=============================\n");
    printf("|--------------MAAF NAMA KODE RAHASIA TIDAK VALID-------------|\n");
    printf("=============================ERROR=============================\n");
    printf(RESET);
}

//BAGIAN PROSEDUR UNTUK MENGECEK INPUTAN
void input(mahasiswa datapribadi[],mahasiswa temp1[],deskripsi temp2[],deskripsi a[],deskripsi b[],deskripsi c[],char pita[],int *m,int *idx1,int *idx2,int *idx3){
    if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
        INC(pita);//maju satu kata     
        if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
            if(strcmp(getcw(),"MAHASISWA")==0){//jika kata sekarang itu MAHASISWA
                INC(pita);//majukan kata
                if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                    int ada=0;
                    for(int i=0;i<*m;i++){//for loop mengecek primari
                        if(strcmp(getcw(),datapribadi[i].id)==0){//jika ada yang sama
                            ada=1;//ubah ada jadi 1
                        }
                    }
                    if(ada==1){//jika ada itu 1
                        printf(RED);//tampilkan pesan error
                        printf("=============================ERROR=============================\n");
                        printf("|-------------MAAF KODE PRIMARI YANG KAMU MASUKAN-------------|\n");
                        printf("|---------------SUDAH ADA DALAM TABEL MAHASISWA---------------|\n");
                        printf("=============================ERROR=============================\n");
                        printf(RESET);
                    }else{//jika tidak
                        int k=0;
                        strcpy(temp1[k].id,getcw());//simpan kata sekarang ke temp1 id
                        if((temp1[k].id[0]!='D') || (getlen()>4) || (getlen()<4)){//jika huruf pertama itu bukan 'D' dan panjangnya lebih atau kurang dari 4
                            printf(RED);//tampilkan pesan error
                            printf("=============================ERROR=============================\n");
                            printf("|------MAAF KODE PRIMARI YANG KAMU MASUKAN TIDAK SESUAI-------|\n");
                            printf("|-----------SILAKAN BACA PANDUAN TERLEBIH DAHULU--------------|\n");
                            printf("=============================ERROR=============================\n");
                            printf(RESET);
                        }else{//jika tidak
                            INC(pita);//majukan kata
                            if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                                int nama=0;
                                strcpy(temp1[k].nama,getcw());//simpan kata sekarang ke temp1 nama
                                for(int i=0;i<*m;i++){//for loop mengecek apa ada nama yang sama di tabel MAHASISWA
                                    if(strcmp(temp1[k].nama,datapribadi[i].nama)==0){//jika ada yang sama
                                        nama=1;//ubah nama menjadi 1
                                    }
                                }
                                if(nama==1){//jika nama itu 1
                                    printf(RED);//tampilkan pesan error
                                    printf("=============================ERROR=============================\n");
                                    printf("|-------------MAAF NAMA YANG KAMU MASUKAN SUDAH ADA-----------|\n");
                                    printf("|--------------------DALAM TABEL MAHASISWA--------------------|\n");
                                    printf("=============================ERROR=============================\n");
                                    printf(RESET);
                                }else{//jika tidak 
                                    INC(pita);//majukan kata
                                    if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                                        strcpy(temp1[k].nim,getcw());//simpan kata sekarang ke temp1 nim
                                        int angka=0;
                                        for(int i=0;i<getlen();i++){//for loop mengecek nim apa angka atau bukan
                                            if((temp1[k].nim[i]>='0') && (temp1[k].nim[i]<='9')){//jika angka
                                                angka++;//angka bertambah
                                            }
                                        }
                                        if((getlen()>7) || (getlen()<7) || (angka<7) || (angka>7)){//jika panjang nim lebih atau kurang atau angkanya kurang atau lebih
                                            printf(RED);//tampilkan pesan error
                                            printf("=============================ERROR=============================\n");
                                            printf("|-----------MAAF NIM YANG KAMU MASUKAN TIDAK SESUAI-----------|\n");
                                            printf("|------------SILAKAN BACA PANDUAN TERLEBIH DAHULU-------------|\n");
                                            printf("=============================ERROR=============================\n");
                                            printf(RESET);
                                        }else{//jika tidak
                                            int nim=0;
                                            for(int i=0;i<*m;i++){//for loop untuk mengecek apa ada nim yang sama di tabel MAHASISWA
                                                if(strcmp(temp1[k].nim,datapribadi[i].nim)==0){//jika ada yang sama
                                                    nim=1;//ubah nim menjadi 1
                                                }
                                            }
                                            if(nim==1){//jika nim itu 1
                                                printf(RED);//tampilkan pesan error
                                                printf("=============================ERROR=============================\n");
                                                printf("|----------MAAF NIM YANG KAMU MASUKAN ADA YANG SAMA-----------|\n");
                                                printf("|-------------------DALAM TABEL MAHASISWA---------------------|\n");
                                                printf("=============================ERROR=============================\n");
                                                printf(RESET);
                                            }else{//jika tidak
                                                INC(pita);//majukan kata
                                                    if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                                                    int ketemu1=0;
                                                    for(int i=0;i<*idx1;i++){//for loop mengecek idskill apa ada yang sama di tabel SKILL
                                                        if(strcmp(getcw(),a[i].id)==0){//jika ada yang sama
                                                            ketemu1=1;//ubah ketemu1 menjadi 1
                                                        }
                                                    }
                                                    if(ketemu1==1){//jika ketemu1 itu 1
                                                        strcpy(temp1[k].idskill,getcw());//simpan kata sekarang ke temp1 idskill
                                                        INC(pita);//majukan kata
                                                        if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                                                            int ketemu2=0;
                                                            for(int i=0;i<*idx2;i++){//for loop mengecek idlomba apa ada yang sama di tabel LOMBA
                                                                if(strcmp(getcw(),b[i].id)==0){//jika ada yang sama
                                                                    ketemu2=1;//ubah ketemu2 menjadi 1
                                                                }
                                                            }
                                                            if(ketemu2==1){//jika ketemu2 itu 1
                                                                strcpy(temp1[k].idlomba,getcw());//simpan kata sekarang ke temp1 idlomba
                                                                INC(pita);//majukan kata
                                                                if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                                                                    inputlebih();//tampilkan pesan error
                                                                }else{//jika tidak
                                                                    int ketemu3=0;
                                                                    for(int i=0;i<*idx3;i++){//for loop mengecek idcurang apa ada yang sama di tabel CURANG
                                                                        if(strcmp(getcw(),c[i].id)==0){//jika ada yang sama
                                                                            ketemu3=1;//ubah ketemu3 menjadi 1
                                                                        }
                                                                    }
                                                                    if(ketemu3==1){//jika ketemu3 itu 1
                                                                        strcpy(temp1[k].idcurang,getcw());//simpan kata sekarang ke temp1 idcurang 
                                                                        int i=0;
                                                                        while((i<*m) && (strcmp(temp1[k].id,datapribadi[i].id)>0)){//selama kurang dari jumlah dan temp2 id lebih besar dari id tabel datapribadi
                                                                            i++;//indeks terus bertambah
                                                                        }
                                                                        for(int j=*m-1;j>=i;j++){
                                                                            datapribadi[j+1]=datapribadi[j];
                                                                        }
                                                                        datapribadi[i]=temp1[k];;//ubah tabel datapribadi ke-i menjadi temp1
                                                                        *m=*m+1;//tambahkan jumlahnya
                                                                        strcpy(datapribadi[*m].id,"####");//tambahkan damy
                                                                        tulisfile1(*m,datapribadi,"dataMahasiswa.txt");//tulis data baru ke file MAHASISWA
                                                                        printf(YELLOW"---> "GREEN"HOREE INPUT BERHASIL(^_^)\n"RESET);//tampilkan input berhasil
                                                                    }else{//jika tidak
                                                                        idcurang();//tampilkan pesan error
                                                                    }
                                                                }
                                                            }else{//jika tidak
                                                                idlomba();//tampilkan pesan error
                                                            }
                                                        }else{//jika tidak
                                                            inputkurang();//tampilkan pesan error
                                                        }
                                                    }else{//jika tidak
                                                        idskill();//tampilkan pesan error
                                                    }
                                                }else{//jika tidak
                                                    inputkurang();//tampilkan pesan error
                                                }
                                            }   
                                        } 
                                    }else{//jika tidak
                                        inputkurang();//tampilkan pesan error
                                    }
                                }
                            }else{//jika tidak
                                inputkurang();//tampilkan pesan error
                            }
                        }
                    }
                }else{//jika tidak
                    inputkurang();//tampilkan pesan error
                } 
            }else if(strcmp(getcw(),"SKILL")==0){//jika kata sekarang itu SKILL
                INC(pita);//majukan kata
                if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                    int ketemu1=0;
                    for(int i=0;i<*idx1;i++){//for loop mengecek apa ada yang sama di tabel SKILL
                        if(strcmp(getcw(),a[i].id)==0){//jika ada sama
                            ketemu1=1;//ubah ketemu1 menjadi 1
                        }
                    }
                    if(ketemu1==1){//jika ketemu1 itu 1
                        printf(RED);//tampilkan pesan error
                        printf("=============================ERROR=============================\n");
                        printf("|-------------MAAF KODE PRIMARI YANG KAMU MASUKAN-------------|\n");
                        printf("|-----------------SUDAH ADA DALAM TABEL SKILL-----------------|\n");
                        printf("=============================ERROR=============================\n");
                        printf(RESET);
                    }else{//jika tidak
                        int k=0;
                        strcpy(temp2[k].id,getcw());//simpan kata sekarang ke temp2 id
                        if((temp2[k].id[0]!='S') || (getlen()>4)){//jika huruf pertama itu bukan 'S' dan panjangnya lebih atau kurang dari 4
                            printf(RED);//tampilkan pesan error
                            printf("=============================ERROR=============================\n");
                            printf("|------MAAF KODE PRIMARI YANG KAMU MASUKAN TIDAK SESUAI-------|\n");
                            printf("|-----------SILAKAN BACA PANDUAN TERLEBIH DAHULU--------------|\n");
                            printf("=============================ERROR=============================\n");
                            printf(RESET);
                        }else{//jika tidak
                            INC(pita);//majukan kata
                            if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                                inputlebih();//tampilkan pesan error
                            }else{//jika tidak
                                strcpy(temp2[k].atribut,getcw());//simpan kata sekarang ke temp2 atribut
                                int nama=0;
                                for(int i=0;i<*idx1;i++){//for loop mengecek apa ada nama yang sama di tabel SKILL
                                    if(strcmp(temp2[k].atribut,a[i].atribut)==0){//jika ada yang sama 
                                        nama=1;//ubah nama menjadi 1
                                    }                                   
                                }
                                if(nama==1){//jika nama itu 1
                                    printf(RED);//tampilkan pesan error
                                    printf("=============================ERROR=============================\n");
                                    printf("|-------------MAAF NAMA YANG KAMU MASUKAN SUDAH ADA-----------|\n");
                                    printf("|----------------------DALAM TABEL SKILL----------------------|\n");
                                    printf("=============================ERROR=============================\n");
                                    printf(RESET);
                                }else{//jika tidak
                                    int i=0;
                                    while((i<*idx1) && (strcmp(temp2[k].id,a[i].id)>0)){//selama kurang dari jumlah dan temp2 id lebih besar dari id tabel a
                                        i++;//indeks terus bertambah
                                    }
                                    for(int j=*idx1-1;j>=i;j++){//for loop untuk memajukan data
                                        a[j+1]=a[j];//data berpindah
                                    }
                                    a[i]=temp2[k];//ubah data a index ke-i menjadi temp2
                                    *idx1=*idx1+1;//tambah jumlahnya
                                    strcpy(a[*idx1].id,"####");//tambahkan damy
                                    tulisfile2(*idx1,a,"skill.txt");//tulis data baru ke file SKILL
                                    printf(YELLOW"---> "GREEN"HOREE INPUT BERHASIL(^_^)\n"RESET);//tampilkan input berhasil
                                }                            
                            }
                        }
                    }
                }else{//jika tidak
                    inputkurang();//tampilkan pesan error
                }            
            }else if(strcmp(getcw(),"LOMBA")==0){//jika kata sekarang itu LOMBA
                INC(pita);//majukan kata
                if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                    int ketemu2=0;
                    for(int i=0;i<*idx2;i++){//for loop mengecek idlomba apa ada yang sama di tabel LOMBA
                        if(strcmp(getcw(),b[i].id)==0){//jika ada yang sama
                            ketemu2=1;//ubah ketemu2 menjadi 1
                        }
                    }
                    if(ketemu2==1){//jika ketemu2 itu 1
                        printf(RED);//tampilkan pesan error
                        printf("=============================ERROR=============================\n");
                        printf("|-------------MAAF KODE PRIMARI YANG KAMU MASUKAN-------------|\n");
                        printf("|-----------------SUDAH ADA DALAM TABEL LOMBA-----------------|\n");
                        printf("=============================ERROR=============================\n");
                        printf(RESET);
                    }else{//jika tidak
                        int k=0;
                        strcpy(temp2[k].id,getcw());//simpan kata sekarang ke temp2 id
                        if((temp2[k].id[0]!='L') || (getlen()>4) || (getlen()<4)){//jika huruf pertama itu bukan 'L' dan panjangnya lebih atau kurang dari 4
                            printf(RED);//tampilkan pesan error
                            printf("=============================ERROR=============================\n");
                            printf("|------MAAF KODE PRIMARI YANG KAMU MASUKAN TIDAK SESUAI-------|\n");
                            printf("|-----------SILAKAN BACA PANDUAN TERLEBIH DAHULU--------------|\n");
                            printf("=============================ERROR=============================\n");
                            printf(RESET);
                        }else{//jika tidak
                            INC(pita);//majukan kata
                            if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                                inputlebih();//tampilkan pesan error
                            }else{//jika tidak
                                strcpy(temp2[k].atribut,getcw());//simpan kata sekarang ke temp2 atribut 
                                int nama=0;
                                for(int i=0;i<*idx2;i++){//for loop mengecek apa ada nama yang sama di tabel LOMBA
                                    if(strcmp(temp2[k].atribut,b[i].atribut)==0){//jika ada nama yang sama
                                        nama=1;//ubah nama menjadi 1
                                    }                                   
                                }
                                if(nama==1){//jika nama itu 1
                                    printf(RED);//tampilkan pesan error
                                    printf("=============================ERROR=============================\n");
                                    printf("|-------------MAAF NAMA YANG KAMU MASUKAN SUDAH ADA-----------|\n");
                                    printf("|----------------------DALAM TABEL LOMBA----------------------|\n");
                                    printf("=============================ERROR=============================\n");
                                    printf(RESET);
                                }else{
                                    int i=0;
                                    while((i<*idx2) && (strcmp(temp2[k].id,b[i].id)>0)){//selama kurang dari jumlah dan temp2 id lebih besar dari id tabel b
                                        i++;//indeks terus bertambah
                                    }
                                    for(int j=*idx2-1;j>=i;j++){//for loop untuk memajukan data
                                        b[j+1]=b[j];//data berpindah
                                    }
                                    b[i]=temp2[k];//ubah tabel b ke-i menjadi temp2
                                    *idx2=*idx2+1;//tambah jumlahnya
                                    strcpy(b[*idx2].id,"####");//tambahkan damy
                                    tulisfile2(*idx2,b,"lomba.txt");//tulis data baru ke file LOMBA
                                    printf(YELLOW"---> "GREEN"HOREE INPUT BERHASIL(^_^)\n"RESET);//tampilkan input berhasil
                                }
                            }
                        }
                    }
                }else{//jika tidak
                    inputkurang();//tampilkan pesan error
                }                
            }else if(strcmp(getcw(),"CURANG")==0){//jika kata sekarang itu CURANG
                INC(pita);//majukan kata
                if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                    int ketemu3=0;
                    for(int i=0;i<*idx3;i++){//for loop mengecek idcurang apa ada yang sama di tabel CURANG
                        if(strcmp(getcw(),c[i].id)==0){//jika ada yang sama
                            ketemu3=1;//ubah ketemu3 menjadi 1
                        }
                    }
                    if(ketemu3==1){//jika ketemu3 itu 1
                        printf(RED);//tampilkan pesan error
                        printf("=============================ERROR=============================\n");
                        printf("|-------------MAAF KODE PRIMARI YANG KAMU MASUKAN-------------|\n");
                        printf("|----------------SUDAH ADA DALAM TABEL CURANG-----------------|\n");
                        printf("=============================ERROR=============================\n");
                        printf(RESET);
                    }else{//jika tidak
                        int k=0;
                        strcpy(temp2[k].id,getcw());//simpan kata sekarang ke temp2 id 
                        if((temp2[k].id[0]!='K') || (getlen()>4) || (getlen()<4)){//jika huruf pertama itu bukan 'K' dan panjangnya lebih atau kurang dari 4
                            printf(RED);//tampilkan pesan error
                            printf("=============================ERROR=============================\n");
                            printf("|------MAAF KODE PRIMARI YANG KAMU MASUKAN TIDAK SESUAI-------|\n");
                            printf("|-----------SILAKAN BACA PANDUAN TERLEBIH DAHULU--------------|\n");
                            printf("=============================ERROR=============================\n");
                            printf(RESET);
                        }else{//jika tidak
                            INC(pita);//majukan kata
                            if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                                inputlebih();//tampilkan pesan error
                            }else{//jika tidak
                                strcpy(temp2[k].atribut,getcw());//simpan kata sekarang ke temp2 atribut 
                                int nama=0;
                                for(int i=0;i<*idx3;i++){//for loop mengecek apa ada nama yang sama di tabel CURANG
                                    if(strcmp(temp2[k].atribut,c[i].atribut)==0){//jika ada yang sama
                                        nama=1;//ubah nama menjadi 1
                                    }                                   
                                }
                                if(nama==1){//jika nama itu 1
                                    printf(RED);//tampilkan pesan error
                                    printf("=============================ERROR=============================\n");
                                    printf("|-------------MAAF NAMA YANG KAMU MASUKAN SUDAH ADA-----------|\n");
                                    printf("|---------------------DALAM TABEL CURANG----------------------|\n");
                                    printf("=============================ERROR=============================\n");
                                    printf(RESET);
                                }else{
                                    int i=0;
                                    while((i<*idx3) && (strcmp(temp2[k].id,c[i].id)>0)){//selama kurang dari jumlah dan temp2 id lebih besar dari id tabel c
                                        i++;//indeks terus bertambah
                                    }
                                    for(int j=*idx3-1;j>=i;j++){//for loop untuk memajukan data
                                        c[j+1]=c[j];//data berpindah
                                    }
                                    c[i]=temp2[k];//ubah tabel c ke-i menjadi temp2
                                    *idx3=*idx3+1;//tambahkan jumlahnya
                                    strcpy(c[*idx3].id,"####");//tambahkan damy
                                    tulisfile2(*idx3,c,"kecurangan.txt");//tulis data baru ke file CURANG
                                    printf(YELLOW"---> "GREEN"HOREE INPUT BERHASIL(^_^)\n"RESET);//tampilkan input berhasil
                                }
                            }
                        }
                    }
                }else{//jika tidak
                    inputkurang();//tampilkan pesan error
                }                    
            }else if(strcmp(getcw(),"COMPLATE")==0){//jika kata sekarang itu CURANG
                printf(RED);//tampilkan pesan error
                printf("=============================ERROR=============================\n");
                printf("|------MAAF TIDAK BISA MELAKUKAN INPUT DI TABEL COMPLATE------|\n");
                printf("=============================ERROR=============================\n");
                printf(RESET);
            }else{//jika tidak
                inputankedua();//tampilkan pesan error
            }
        }else{//jika tidak
            inputkurang();//tampilkan pesan error
        }
    }else{//jika tidak
        inputkurang();//tampilkan pesan error
    }
}
void update(mahasiswa datapribadi[],mahasiswa temp1[],deskripsi temp2[],deskripsi a[],deskripsi b[],deskripsi c[],char pita[],int m,int idx1,int idx2,int idx3){
    if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
        INC(pita);//majukan kata
        if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
            if(strcmp(getcw(),"MAHASISWA")==0){//jika kata sekarang itu MAHASISWA
                INC(pita);//majukan kata
                if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                    int ada=0;
                    int indeks=0;
                    for(int i=0;i<m;i++){//for loop mengecek primari apa ada yang sama di tabel MAHASISWA
                        if(strcmp(getcw(),datapribadi[i].id)==0){//jika ada yang sama
                            ada=1;//ubah ada menjadi 1
                            indeks=i;//simpan index ke-i ke indeks
                        }  
                    }
                    if(ada==1){//jika ada itu 1
                        int k=0;
                        strcpy(temp1[k].id,getcw());//simpan kata sekarang ke temp1 id
                        INC(pita);//majukan kata
                        if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                            int nama=0;
                            strcpy(temp1[k].nama,getcw());//simpan kata sekarang ke temp1 nama
                            for(int i=0;i<m;i++){//for loop mengecek apa ada nama yang sama di tabel MAHASISWA
                                if(strcmp(temp1[k].nama,datapribadi[i].nama)==0){//jika ada yang sama
                                    nama=1;//ubah nama menjadi 1
                                }
                            }
                            if(nama==1){//jika nama itu 1
                                printf(RED);//tampilkan pesan error
                                printf("=============================ERROR=============================\n");
                                printf("|-------------MAAF NAMA YANG KAMU MASUKAN SUDAH ADA-----------|\n");
                                printf("|--------------------DALAM TABEL MAHASISWA--------------------|\n");
                                printf("=============================ERROR=============================\n");
                                printf(RESET);
                            }else{
                                INC(pita);//majukan kata
                                if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                                    strcpy(temp1[k].nim,getcw());//simpan kata sekarang ke temp1 nim
                                    int angka=0;
                                    for(int i=0;i<getlen();i++){//for loop mengecek nim apa ada angka atau tidak
                                        if((temp1[k].nim[i]>='0') && (temp1[k].nim[i]<='9')){//jika ada angka
                                            angka++;//angak bertambah
                                        }
                                    }
                                    if((getlen()>7) || (getlen()<7) || (angka<7) || (angka>7)){//jika panjang nim lebih atau kurang atau angkanya kurang atau lebih
                                        printf(RED);//tampilkan pesan error
                                        printf("=============================ERROR=============================\n");
                                        printf("|-----------MAAF NIM YANG KAMU MASUKAN TIDAK SESUAI------------|\n");
                                        printf("|------------SILAKAN BACA PANDUAN TERLEBIH DAHULU--------------|\n");
                                        printf("=============================ERROR=============================\n");
                                        printf(RESET);
                                    }else{//jika tidak
                                        int nim=0;
                                        for(int i=0;i<m;i++){//for loop untuk mengecek apa ada nim yang sama di tabel MAHASISWA
                                            if(strcmp(temp1[k].nim,datapribadi[i].nim)==0){//jika ada yang sama
                                                nim=1;//ubah nim menjadi 1
                                            }
                                        }
                                        if(nim==1){//jika nim itu 1
                                            printf(RED);//tampilkan pesan error
                                            printf("=============================ERROR=============================\n");
                                            printf("|----------MAAF NIM YANG KAMU MASUKAN ADA YANG SAMA-----------|\n");
                                            printf("|-------------------DALAM TABEL MAHASISWA---------------------|\n");
                                            printf("=============================ERROR=============================\n");
                                            printf(RESET);
                                        }else{//jika tidak
                                            INC(pita);//majukan kata
                                            if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                                                int ketemu1=0;
                                                for(int i=0;i<idx1;i++){//for loop mengecek idskill apa ada yang sama di tabel SKILL
                                                    if(strcmp(getcw(),a[i].id)==0){//jika ada yang sama
                                                        ketemu1=1;//ubah ketemu1 menjadi 1
                                                    }
                                                }
                                                if(ketemu1==1){//jika ketemu1 itu 1
                                                    strcpy(temp1[k].idskill,getcw());//simpan kata sekarang ke temp1 idskill
                                                    INC(pita);//majukan kata
                                                    if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                                                        int ketemu2=0;
                                                        for(int i=0;i<idx2;i++){//for loop mengecek idlomba apa ada yang sama di tabel LOMBA
                                                            if(strcmp(getcw(),b[i].id)==0){//jika ada yang sama
                                                                ketemu2=1;//ubah ketemu2 menjadi 1
                                                            }
                                                        }
                                                        if(ketemu2==1){//jika ketemu2 itu 1
                                                            strcpy(temp1[k].idlomba,getcw());//simpan kata sekarang ke temp1 idlomba
                                                            INC(pita);//majukan kata
                                                            if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                                                                inputlebih();//tampilkan pesan error
                                                            }else{//jika tidak
                                                                int ketemu3=0;
                                                                for(int i=0;i<idx3;i++){//for loop mengecek id apa acurangda yang sama di tabel CURANG
                                                                    if(strcmp(getcw(),c[i].id)==0){//jika ada yang sama
                                                                        ketemu3=1;//ubah ketemu3 menjadi 1
                                                                    }
                                                                }
                                                                if(ketemu3==1){//jika ketemu3 itu 1
                                                                    strcpy(temp1[k].idcurang,getcw());//simpan kata sekarang ke temp1 idcurang 
                                                                    datapribadi[indeks]=temp1[k];//update tabel datapribadi ke-indeks menjadi temp2
                                                                    printf(YELLOW"---> "GREEN"HOREE UPDATE BERHASIL(^_^)\n"RESET);//tampilkan update berhasil
                                                                }else{//jika tidak
                                                                    idcurang();//tampilkan pesan error
                                                                }
                                                            }
                                                        }else{//jika tidak
                                                            idlomba();//tampilkan pesan error
                                                        }
                                                    }else{//jika tidak
                                                        inputkurang();//tampilkan pesan error
                                                    }
                                                }else{//jika tidak
                                                    idskill();//tampilkan pesan error
                                                }
                                            }else{//jika tidak
                                                inputkurang();//tampilkan pesan error
                                            }
                                        }
                                    }
                                }else{//jika tidak
                                    inputkurang();//tampilkan pesan error
                                }
                            }
                        }else{//jika tidak
                            inputkurang();//tampilkan pesan error
                        }
                    }else{//jika tidak
                        printf(RED);//tampilkan pesan error
                        printf("=============================ERROR=============================\n");
                        printf("|-------------MAAF KODE PRIMARI YANG KAMU MASUKAN-------------|\n");
                        printf("|---------------TIDAK ADA DALAM TABEL MAHASISWA---------------|\n");
                        printf("=============================ERROR=============================\n");
                        printf(RESET);
                    }
                }else{//jika tidak
                    inputkurang();//tampilkan pesan error
                }
            }else if(strcmp(getcw(),"SKILL")==0){//jika kata sekarang itu SKILL
                INC(pita);//majukan kata
                if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                    int ketemu1=0;
                    int indeks=0;
                    for(int i=0;i<idx1;i++){//for loop mengecek idskill apa ada yang sama di tabel SKILL
                        if(strcmp(getcw(),a[i].id)==0){//jika ada yang sama
                            ketemu1=1;//ubah ketemu1 menjadi 1
                            indeks=i;//simpan index ke-i ke indeks
                        } 
                    }
                    if(ketemu1==1){//jika ketemu1 itu 1
                            int k=0;
                            strcpy(temp2[k].id,getcw());//simpan kata sekarang ke temp2 id 
                            INC(pita);//majukan kata
                            if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                                inputlebih();//tampilkan pesan error
                            }else{//jika tidak
                                int nama=0;
                                strcpy(temp2[k].atribut,getcw());//simpan kata sekarang ke temp2 atribut
                                for(int i=0;i<idx1;i++){//for loop mengecek apa ada nama yang sama di tabel SKILL
                                    if(strcmp(temp2[k].atribut,a[i].atribut)==0){//jika ada yang sama
                                        nama=1;//ubah nama menjadi 1
                                    }
                                }
                                if(nama==1){//jika nama itu 1
                                    printf(RED);//tampilkan pesan error
                                    printf("=============================ERROR=============================\n");
                                    printf("|-------------MAAF NAMA YANG KAMU MASUKAN SUDAH ADA-----------|\n");
                                    printf("|----------------------DALAM TABEL SKILL----------------------|\n");
                                    printf("=============================ERROR=============================\n");
                                    printf(RESET);
                                }else{
                                    a[indeks]=temp2[k];//update tabel a ke-indeks menjadi temp2
                                    printf(YELLOW"---> "GREEN"HOREE UPDATE BERHASIL(^_^)\n"RESET);//tampilkan update berhasil
                                } 
                            }
                    }else{//jika tidak
                        printf(RED);//tampilkan pesan error
                        printf("=============================ERROR=============================\n");
                        printf("|-------------MAAF KODE PRIMARI YANG KAMU MASUKAN-------------|\n");
                        printf("|-----------------TIDAK ADA DALAM TABEL SKILL-----------------|\n");
                        printf("=============================ERROR=============================\n");
                        printf(RESET);
                    }
                }else{//jika tidak
                    inputkurang();//tampilkan pesan error
                }
            }else if(strcmp(getcw(),"LOMBA")==0){//jika kata sekarang itu LOMBA
                INC(pita);//majukan kata
                if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                    int ketemu2=0;
                    int indeks=0;
                    for(int i=0;i<idx2;i++){//for loop mengecek idlomba apa ada yang sama di tabel LOMBA
                        if(strcmp(getcw(),b[i].id)==0){//jika ada yang sama 
                            ketemu2=1;//ubah ketemu2 menjadi 1
                            indeks=i;//simpan index ke-i ke indeks
                        }
                    }
                    if(ketemu2==1){//jika ketemu2 itu 1
                            int k=0;
                            strcpy(temp2[k].id,getcw());//simpan kata sekarang ke temp2 id 
                            INC(pita);//majukan kata
                            if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                                inputlebih();//tampilkan pesan error
                            }else{//jika tidak
                                int nama=0;
                                strcpy(temp2[k].atribut,getcw());//simpan kata sekarang ke temp2 atribut
                                for(int i=0;i<idx2;i++){//for loop mengecek apa ada nama yang sama di tabel LOMBA
                                    if(strcmp(temp2[k].atribut,b[i].atribut)==0){//jika ada yang sama
                                        nama=1;//ubah nama menjadi 1
                                    }
                                }
                                if(nama==1){//jika nama itu 1
                                    printf(RED);//tampilkan pesan error
                                    printf("=============================ERROR=============================\n");
                                    printf("|-------------MAAF NAMA YANG KAMU MASUKAN SUDAH ADA-----------|\n");
                                    printf("|----------------------DALAM TABEL LOMBA----------------------|\n");
                                    printf("=============================ERROR=============================\n");
                                    printf(RESET);
                                }else{
                                    b[indeks]=temp2[k];//update tabel b ke-indeks menjadi temp2
                                    printf(YELLOW"---> "GREEN"HOREE UPDATE BERHASIL(^_^)\n"RESET);//tampilkan update berhasil
                                }
                            }
                    }else{//jika tidak
                        printf(RED);//tampilkan pesan error
                        printf("=============================ERROR=============================\n");
                        printf("|-------------MAAF KODE PRIMARI YANG KAMU MASUKAN-------------|\n");
                        printf("|-----------------TIDAK ADA DALAM TABEL LOMBA-----------------|\n");
                        printf("=============================ERROR=============================\n");
                        printf(RESET);
                    }
                }else{//jika tidak
                    inputkurang();//tampilkan pesan error
                }
            }else if(strcmp(getcw(),"CURANG")==0){//jika kata sekarang itu CURANG
                INC(pita);//majukan kata
                if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                    int ketemu3=0;
                    int indeks=0;
                    for(int i=0;i<idx3;i++){//for loop mengecek idcurang apa ada yang sama di tabel CURANG
                        if(strcmp(getcw(),c[i].id)==0){//jika ada yang sama
                            ketemu3=1;//ubah ketemu3 menjadi 1
                            indeks=i;//simpan index ke-i ke indeks
                        }    
                    }
                    if(ketemu3==1){//jika ketemu3 itu 1
                            int k=0;
                            strcpy(temp2[k].id,getcw());//simpan kata sekarang ke temp2 id 
                            INC(pita);//majukan kata
                            if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                                inputlebih();//tampilkan pesan error
                            }else{//jika tidak
                                int nama=0;
                                strcpy(temp2[k].atribut,getcw());//simpan kata sekarang ke temp2 atribut
                                for(int i=0;i<idx3;i++){//for loop mengecek apa ada nama yang sama di tabel LOMBA
                                    if(strcmp(temp2[k].atribut,c[i].atribut)==0){//jika ada yang sama
                                        nama=1;//ubah nama menjadi 1
                                    }
                                }
                                if(nama==1){//jika nama itu 1
                                    printf(RED);//tampilkan pesan error
                                    printf("=============================ERROR=============================\n");
                                    printf("|-------------MAAF NAMA YANG KAMU MASUKAN SUDAH ADA-----------|\n");
                                    printf("|---------------------DALAM TABEL CURANG----------------------|\n");
                                    printf("=============================ERROR=============================\n");
                                    printf(RESET);
                                }else{
                                    c[indeks]=temp2[k];//update tabel c ke-indeks menjadi temp2
                                    printf(YELLOW"---> "GREEN"HOREE UPDATE BERHASIL(^_^)\n"RESET);//tampilkan update berhasil
                                }                             
                            }
                    }else{//jika tidak
                        printf(RED);//tampilkan pesan error
                        printf("=============================ERROR=============================\n");
                        printf("|-------------MAAF KODE PRIMARI YANG KAMU MASUKAN-------------|\n");
                        printf("|----------------TIDAK ADA DALAM TABEL CURANG-----------------|\n");
                        printf("=============================ERROR=============================\n");
                        printf(RESET);
                    }
                }else{//jika tidak
                    inputkurang();//tampilkan pesan error
                }
            }else if(strcmp(getcw(),"COMPLATE")==0){//jika kata sekarang itu CURANG
                printf(RED);//tampilkan pesan error
                printf("=============================ERROR=============================\n");
                printf("|------MAAF TIDAK BISA MELAKUKAN UPDATE DI TABEL COMPLATE-----|\n");
                printf("=============================ERROR=============================\n");
                printf(RESET);
            }else{//jika tidak
                inputankedua();//tampilkan pesan error
            }
        }else{//jika tidak
            inputkurang();//tampilkan pesan error
        }
    }else{//jika tidak
        inputkurang();//tampilkan pesan error
    }
}
void del(mahasiswa datapribadi[],mahasiswa temp1[],deskripsi temp2[],deskripsi a[],deskripsi b[],deskripsi c[],char pita[],int *m,int *idx1,int *idx2,int *idx3){
    if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
        INC(pita);//majukan kata
        if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
            if(strcmp(getcw(),"MAHASISWA")==0){//jika kata sekarang itu MAHASISWA
                INC(pita);//majukan kata
                if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                    inputlebih();//tampilkan pesan error
                }else{//jika tidak
                    int ada=0;
                    int indeks=0;
                    for(int i=0;i<*m;i++){//for loop mengecek idmahasiswa apa ada yang sama di tabel MAHASISWA
                        if(strcmp(getcw(),datapribadi[i].id)==0){//jika ada yang sama
                            ada=1;//ubah ada menjadi 1
                            indeks=i;//simpan index ke-i ke indeks
                        }      
                    }
                    if(ada==1){//jika ada itu 1
                            for(int j=indeks;j<*m;j++){//for loop untuk memindahkan data selanjutnya ke data sebelumnya
                                datapribadi[j]=datapribadi[j+1];//ubah data selanjutnya menjadi indeks ke-j
                            }
                            *m=*m-1;//kurangi jumlahnya
                            tulisfile1(*m,datapribadi,"dataMahasiswa.txt");//tulis data baru ke file MAHASISWA
                            printf(YELLOW"---> "GREEN"HOREE DEL BERHASIL(^_^)\n"RESET);//tampilkan del berhasil
                    }else{//jika ada itu 0
                        printf(RED);//tampilkan pesan error
                        printf("=============================ERROR=============================\n");
                        printf("|-------------MAAF KODE PRIMARI YANG KAMU MASUKAN-------------|\n");
                        printf("|---------------TIDAK ADA DALAM TABEL MAHASISWA---------------|\n");
                        printf("=============================ERROR=============================\n");
                        printf(RESET);
                    }
                }
            }else if(strcmp(getcw(),"SKILL")==0){//jika kata sekarang itu SKILL
                INC(pita);//majukan kata
                if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                    inputlebih();
                }else{//jika tidak
                    int ketemu1=0;
                    int indeks=0;
                    for(int p=0;p<*idx1;p++){//for loop mengecek idskill apa ada yang sama di tabel SKILL
                        if(strcmp(getcw(),a[p].id)==0){//jika ada yang sama
                            ketemu1=1;//ubah ketemu1 menjadi 1
                            indeks=p;//simpan index ke-p ke indeks
                        }
                        
                    }
                    if(ketemu1==1){//jika ketemu1 itu 1
                            int dipakai1=0;
                            for(int i=0;i<*m;i++){//for loop mengecek idskill apa ada yang sama di tabel MAHASISWA
                                if(strcmp(getcw(),datapribadi[i].idskill)==0){//jika ada yang sama
                                    dipakai1=1;//ubah dipakai1 menjadi 1
                                }
                            }
                            if(dipakai1==1){//jiika dipakai1 itu 1
                                printf(RED);//tampilkan pesan error
                                printf("=============================ERROR=============================\n");
                                printf("|-------------MAAF KODE PRIMARI YANG KAMU MASUKAN-------------|\n");
                                printf("|------------MASIH DIGUNAKAN DALAM TABEL MAHASISWA------------|\n");
                                printf("=============================ERROR=============================\n");
                                printf(RESET);
                            }else{//jika tidak
                                for(int j=indeks;j<*idx1;j++){//for loop untuk memindahkan data selanjutnya ke data sebelumnya
                                    a[j]=a[j+1];//ubah data selanjutnya menjadi indeks ke-j
                                }
                                *idx1=*idx1-1;//kurangi jumlahnya
                                tulisfile2(*idx1,a,"skill.txt");//tulis data baru ke file SKILL
                                printf(YELLOW"---> "GREEN"HOREE DEL BERHASIL(^_^)\n"RESET);//tampilkan del berhasil
                            }
                    }else{
                        printf(RED);//tampilkan pesan error
                        printf("=============================ERROR=============================\n");
                        printf("|-------------MAAF KODE PRIMARI YANG KAMU MASUKAN-------------|\n");
                        printf("|-----------------TIDAK ADA DALAM TABEL SKILL-----------------|\n");
                        printf("=============================ERROR=============================\n");
                        printf(RESET);
                    }
                }
            }else if(strcmp(getcw(),"LOMBA")==0){//jika kata sekarang itu LOMBA
                INC(pita);//majukan kata
                if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                    inputlebih();//tampilkan pesan error
                }else{//jika tidak
                    int ketemu2=0;
                    int indeks=0;
                    for(int p=0;p<*idx2;p++){//for loop mengecek idlomba apa ada yang sama di tabel LOMBA
                        if(strcmp(getcw(),b[p].id)==0){//jika ada yang sama
                            ketemu2=1;//ubah ketemu2 jadi 1
                            indeks=p;//simpan index ke-p ke indeks
                        }
                    }
                    if(ketemu2==1){//jika ketemu2 1
                            int dipakai2=0;
                            for(int i=0;i<*m;i++){//for loop mengecek idlomba apa ada yang sama di tabel MAHASISWA
                                if(strcmp(getcw(),datapribadi[i].idlomba)==0){//jika ada yang sama
                                    dipakai2=1;//ubah dipakai2 menjadi 1
                                }
                            }
                            if(dipakai2==1){//jika dipakai2 itu 1
                                printf(RED);//tampilkan pesan error
                                printf("=============================ERROR=============================\n");
                                printf("|-------------MAAF KODE PRIMARI YANG KAMU MASUKAN-------------|\n");
                                printf("|------------MASIH DIGUNAKAN DALAM TABEL MAHASISWA------------|\n");
                                printf("=============================ERROR=============================\n");
                                printf(RESET);
                            }else{//jika tidak
                                for(int j=indeks;j<*idx2;j++){//for loop untuk memindahkan data selanjutnya ke data sebelumnya
                                    b[j]=b[j+1];//ubah data selanjutnya menjadi indeks ke-j
                                }
                                *idx2=*idx2-1;//kurangi jumlahnya
                                tulisfile2(*idx2,b,"lomba.txt");//tulis data baru ke file LOMBA
                                printf(YELLOW"---> "GREEN"HOREE DEL BERHASIL(^_^)\n"RESET);//tampilkan del berhasil
                            }
                    }else{
                        printf(RED);//tampilkan pesan error
                        printf("=============================ERROR=============================\n");
                        printf("|-------------MAAF KODE PRIMARI YANG KAMU MASUKAN-------------|\n");
                        printf("|-----------------TIDAK ADA DALAM TABEL LOMBA-----------------|\n");
                        printf("=============================ERROR=============================\n");
                        printf(RESET);
                    }
                }
            }else if(strcmp(getcw(),"CURANG")==0){//jika kata sekarang itu CURANG
                INC(pita);//majukan kata
                if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                    inputlebih();//tampilkan pesan error
                }else{//jika tidak
                    int ketemu3=0;
                    int indeks=0;
                    for(int p=0;p<*idx3;p++){//for loop mengecek idcurang apa ada yang sama di tabel CURANG
                        if(strcmp(getcw(),c[p].id)==0){//jika ada yang sama
                            ketemu3=1;//ubah ketemmu3 jadi 1
                            indeks=p;//simpan index ke-p ke indeks
                        }    
                    }
                    if(ketemu3==1){//jika ketemu3 1
                            int dipakai3=0;
                            for(int i=0;i<*m;i++){//for loop mengecek idcurang apa ada yang sama di tabel MAHASISWA
                                if(strcmp(getcw(),datapribadi[i].idcurang)==0){//jika ada yang sama
                                    dipakai3=1;//ubah dipakai3 menjadi 1
                                }
                            }
                            if(dipakai3==1){//jika dipakai3 itu 1
                                printf(RED);//tampilkan pesan error
                                printf("=============================ERROR=============================\n");
                                printf("|-------------MAAF KODE PRIMARI YANG KAMU MASUKAN-------------|\n");
                                printf("|------------MASIH DIGUNAKAN DALAM TABEL MAHASISWA------------|\n");
                                printf("=============================ERROR=============================\n");
                                printf(RESET);
                            }else{//jika tidak
                                for(int j=indeks;j<*idx3;j++){//for loop untuk memindahkan data selanjutnya ke data sebelumnya
                                    c[j]=c[j+1];//ubah data selanjutnya menjadi indeks ke-j
                                }
                                *idx3=*idx3-1;//kurangi jumlahnya
                                tulisfile2(*idx3,c,"skill.txt");//tulis data baru ke file CURANG
                                printf(YELLOW"---> "GREEN"HOREE DEL BERHASIL(^_^)\n"RESET);//tampilkan del berhasil
                            }
                    }else{//jika tidak
                        printf(RED);//tampilkan pesan error
                        printf("=============================ERROR=============================\n");
                        printf("|-------------MAAF KODE PRIMARI YANG KAMU MASUKAN-------------|\n");
                        printf("|----------------TIDAK ADA DALAM TABEL CURANG-----------------|\n");
                        printf("=============================ERROR=============================\n");
                        printf(RESET);
                    }
                }
            }else if(strcmp(getcw(),"COMPLATE")==0){//jika kata sekarang itu COMPLATE
                printf(RED);//tampilkan pesan error
                printf("=============================ERROR=============================\n");
                printf("|-------MAAF TIDAK BISA MELAKUKAN DEL DI TABEL COMPLATE-------|\n");
                printf("=============================ERROR=============================\n");
                printf(RESET);
            }else{//jika tidak
                inputankedua();//tampilkan pesan error
            }
        }else{//jika tidak
            inputkurang();//tampilkan pesan error
        }
    }else{//jika tidak
        inputkurang();//tampilkan pesan error
    }
} 
void show(mahasiswa datapribadi[],mahasiswa complate[],deskripsi a[],deskripsi b[],deskripsi c[],char pita[],int m,int idx1,int idx2,int idx3){
    if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
        INC(pita);//majukan kata
        if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
            inputlebih();//tampilkan pesan error
        }else{//jika tidak
            if(strcmp(getcw(),"MAHASISWA")==0){//jika kata sekarang itu MAHASISWA
                cetaktabelmahasiswa(datapribadi,m);//tampilkan tabelnya
                printf(YELLOW"---> "GREEN"HOREE SHOW BERHASIL(^_^)\n"RESET);//tampilkan show berhasil
            }else if(strcmp(getcw(),"SKILL")==0){//jika kata sekarang itu SKILL
                cetaktabelskill(a,idx1);//tampilkan tabelnya
                printf(YELLOW"---> "GREEN"HOREE SHOW BERHASIL(^_^)\n"RESET);//tampilkan show berhasil
            }else if(strcmp(getcw(),"LOMBA")==0){//jika kata sekarang itu LOMBA
                cetaktabellomba(b,idx2);//tampilkan tabelnya
                printf(YELLOW"---> "GREEN"HOREE SHOW BERHASIL(^_^)\n"RESET);//tampilkan show berhasil
            }else if(strcmp(getcw(),"CURANG")==0){//jika kata sekarang itu CURANG
                cetaktabelcurang(c,idx3);//tampilkan tabelnya
                printf(YELLOW"---> "GREEN"HOREE SHOW BERHASIL(^_^)\n"RESET);//tampilkan show berhasil
            }else if(strcmp(getcw(),"COMPLATE")==0){//jika kata sekarang itu COMPLATE      
                join1(datapribadi,a,b,c);//join foregin key menjadi namanya
                for(int p=0;p<m;p++){//for loop untuk memindahkan data datapribadi yang telah di join ke dalam data listcompalte
                    complate[p]=datapribadi[p];//simpan tabel MAHASISWA ke data COMPLATE
                }
                join2(datapribadi,a,b,c);//join foregin key menjadi idnya
                tulisfile1(m,complate,"dataComplate.txt");//tulis ke file
                cetaktabelcomplate(complate,m);//tampilkan tebel yang telah di join
                printf(YELLOW"---> "GREEN"HOREE SHOW BERHASIL(^_^)\n"RESET);//tampilkan show berhasil
            }else{//jika tidak
                inputankedua();//tampilkan pesan error
            }
        }
    }else{//jika tidak
        inputkurang();//tampilkan pesan error
    }
} 
void keluar(char pita[],int *lanjut){
    if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
        INC(pita);//majukan kata
        if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
            if(strcmp(getcw(),"JANGAN")==0){//jika kata sekarang itu JANGAN
                INC(pita);//majukan kata
                if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                    if(strcmp(getcw(),"LUPA")==0){//jika kata sekarang itu LUPA
                        INC(pita);//majukan kata
                        if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                            if(strcmp(getcw(),"TERTAWA")==0){//jika kata sekarang itu TERTAWA
                                INC(pita);//majukan kata
                                if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                                    if(strcmp(getcw(),"WALAUPUN")==0){//jika kata sekarang itu WALAUPUN
                                        INC(pita);//majukan kata
                                        if(EOP(pita)==0){//jika masih ada lanjutan kata berikutnya
                                            inputlebih();//tampilkan pesan error
                                        }else{//jika tidak
                                            if(strcmp(getcw(),"TERLUKA")==0){//jika kata sekarang itu TERLUKA
                                                *lanjut=0;//hentiikan loop
                                            }else{//jika tidak
                                                pesanexit();//tampilkan pesan error
                                            }
                                        }
                                    }else{//jika tidak
                                        pesanexit();//tampilkan pesan error
                                    }
                                }else{//jika tidak
                                    inputkurang();//tampilkan pesan error
                                }
                            }else{//jika tidak
                                pesanexit();//tampilkan pesan error
                            }
                        }else{//jika tidak
                            inputkurang();//tampilkan pesan error
                        }
                    }else{//jika tidak
                        pesanexit();//tampilkan pesan error
                    }
                }else{//jika tidak
                    inputkurang();//tampilkan pesan error
                }
            }else{//jika tidak
                pesanexit();//tampilkan pesan error
            }
        }else{//jika tidak
            inputkurang();//tampilkan pesan error
        }
    }else{//jika tidak
        inputkurang();//tampilkan pesan error
    }
} 