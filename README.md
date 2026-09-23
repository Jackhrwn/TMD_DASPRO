# 🎓 TMD_DASPRO — *Tugas Masa Depan* (Dasar-dasar Pemrograman)

> **Real Competition 2025** — Program DBMS Mini berbasis **mesin kata (word machine)** yang diimplementasikan dalam **Bahasa C**.
> Data mahasiswa, skill, lomba, dan kecurangan dikelola lewat query ala SQL: `INPUT`, `UPDATE`, `DEL`, `SHOW`.

**👤 Penulis:** Jaka Permana Herawan — **NIM:** 2509371
**📚 Mata Kuliah:** Dasar-dasar Pemrograman (DASPRO)
**🎬 Video dokumentasi:** [https://youtu.be/B42Eainwo2k](https://youtu.be/B42Eainwo2k)

---

## 📜 Janji 

Setiap berkas sumber program (`main.c`, `header.h`, `mesin.c`) dibuka dengan janji berikut:

> *Saya **Jaka Permana Herawan** dengan NIM **2509371** sebagai manusia yang berTuhan, saya mengerjakan evaluasi **Tugas Masa Depan** dalam mata kuliah **Dasar-dasar Pemrograman** untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*

Janji ini juga ditegaskan kembali lewat mekanisme program: perintah `EXIT` hanya bisa menutup aplikasi bila diikuti **kode rahasia** yang benar:

```
EXIT JANGAN LUPA TERTAWA WALAUPUN TERLUKA#
```

---

## 🧠 Penjelasan Program

**TMD_DASPRO** adalah program CLI (Command Line Interface) yang meniru cara kerja sistem manajemen basis data (DBMS) sederhana. Pengguna mengetik query di prompt `dbms Jack >>`, lalu program mem-parse query tersebut dengan **mesin kata** dan mengeksekusinya terhadap data yang tersimpan di file `.txt`.

### Konsep inti yang dipakai

| Konsep | Penerapan dalam program |
|---|---|
| **Mesin Kata** | `START`, `INC`, `EOP`, `getcw`, `getlen` memecah pita karakter menjadi kata per kata, diakhiri penanda `#` |
| **Array of Struct** | Data disimpan dalam array berukuran maksimal **51 record** (`mahasiswa[51]`, `deskripsi[51]`) |
| **Primary Key** | `id` mahasiswa (`D…`), skill (`S…`), lomba (`L…`), kecurangan (`K…`) — wajib unik |
| **Foreign Key** | `idskill`, `idlomba`, `idcurang` pada tabel MAHASISWA wajib ada di file masing-masing |
| **JOIN** | Prosedur `join1()` mengubah ID menjadi nama, `join2()` mengembalikan ID — untuk membuat file **COMPLATE** |
| **File I/O** | `bacafile1/2` untuk membaca, `tulisfile1/2` untuk menyimpan perubahan balik ke file |
| **Antarmuka berwarna** | Makro ANSI (`RED`, `GREEN`, `YELLOW`, `CYAN`, `BLUE`, `RESET`) untuk pesan sukses/error |

### Struktur data

```c
typedef struct {
    char id[5];        // primary key  -> D001, D002, ...
    char nama[51];
    char nim[51];      // wajib 7 digit
    char idskill[51];  // foreign key -> S001, ...
    char idlomba[51];  // foreign key -> L001, ...
    char idcurang[51]; // foreign key -> K001, ...
} mahasiswa;

typedef struct {
    char id[5];        // S001 / L001 / K001
    char atribut[51];  // isi / deskripsi
} deskripsi;
```

### Tabel yang tersedia

| Nama File | Sumber | Isi |
|---|---|---|
| `MAHASISWA` | `dataMahasiswa.txt` | Data pokok mahasiswa (id, nama, nim, 3 foreign key) |
| `SKILL` | `skill.txt` | Daftar kemampuan |
| `LOMBA` | `lomba.txt` | Daftar kompetisi |
| `CURANG` | `kecurangan.txt` | Daftar pelanggaran / kecurangan |
| `COMPLATE` | `dataComplate.txt` | Hasil **JOIN** mahasiswa + skill + lomba + curang (read-only) |

---

## 📁 Struktur Folder

```
TMD_DASPRO/
│
├── main.c              # Titik masuk program: loop prompt, dispatch query
├── header.h            # Definisi struct, makro warna, deklarasi semua fungsi
├── mesin.c             # Implementasi: mesin kata, file I/O, join, tabel, query
│
├── dataMahasiswa.txt   # [TABEL] Data mahasiswa (primary key: ID Dxxx)
├── skill.txt           # [TABEL] Data skill (primary key: ID Sxxx)
├── lomba.txt           # [TABEL] Data lomba (primary key: ID Lxxx)
├── kecurangan.txt      # [TABEL] Data kecurangan (primary key: ID Kxxx)
├── dataComplate.txt    # [VIEW]  Hasil JOIN (dibuat ulang oleh SHOW COMPLATE)
│
├── testcase.txt        # Dokumentasi test case benar & salah
├── README.md           # Dokumentasi ini
│
└── Tampilan/                # 📸 Folder screenshot tampilan program
    ├── Tampilan Menu1.png   # Menu awal (intro + panduan bagian 1)
    ├── Tampilan Menu2.png   # Panduan bagian 2 (lanjutan catatan INPUT & UPDATE)
    └── Tampilan Menu3.png   # Panduan bagian 3 (DEL, SHOW, BANTU, EXIT) & prompt
```

**Keterangan berkas kode:**

| Berkas | Peran |
|---|---|
| `header.h` | Deklarasi makro warna, `typedef struct`, prototipe seluruh prosedur/fungsi, serta `extern` variabel global mesin kata |
| `main.c` | Membaca semua file → menampilkan intro & panduan → **looping** menerima input → memanggil prosedur sesuai kata pertama query |
| `mesin.c` | Jantung program: mesin kata, pembacaan/penulisan file, pencetakan tabel, prosedur `input`, `update`, `del`, `show`, `keluar`, dan semua pesan bantuan/error |

---

## 🔄 Alur Program

```
                         ┌──────────────────────────┐
                         │        START main()      │
                         └────────────┬─────────────┘
                                      ▼
                 bacafile1(dataMahasiswa.txt, &m)
                 bacafile2(skill.txt,   &idx1)
                 bacafile2(lomba.txt,   &idx2)
                 bacafile2(kecurangan.txt, &idx3)
                                      ▼
                       judul()  +  panduan()
                                      ▼
                    ┌──►  dbms()  →  prompt "Jack >>"
                    │            │
                    │            ▼
                    │   scanf pita (maks 500 karakter)
                    │            │
                    │            ▼
                    │   getadapagar(pita) ── belum diakhiri '#' ──► ERROR
                    │            │ (ada '#')
                    │            ▼
                    │   START(pita)  →  ambil kata pertama (cw)
                    │            │
                    │   ┌────────┴──────────────────────────────┐
                    │   │  if  cw == "INPUT"  → input(...)      │
                    │   │  elif cw == "UPDATE" → update(...)    │
                    │   │  elif cw == "DEL"    → del(...)       │
                    │   │  elif cw == "SHOW"   → show(...)      │
                    │   │  elif cw == "BANTU"  → bantu*()       │
                    │   │  elif cw == "EXIT"   → keluar(...)    │
                    │   │  else                → ERROR pertama  │
                    │   └────────┬──────────────────────────────┘
                    │            ▼
                    │   tampilkan hasil / pesan error
                    └──── lanjut == 1 ?  (EXIT yang benar → lanjut = 0)
                                      ▼
                               return 0 (selesai)
```

**Detail langkah:**

1. **Inisialisasi** — Empat array struct disiapkan (`datapribadi`, `skill`, `lomba`, `curang`) beserta counter-nya (`m`, `idx1`, `idx2`, `idx3`), lalu seluruh file `.txt` dibaca ke memori.
2. **Intro & Panduan** — `judul()` menampilkan banner ASCII art, `panduan()` menampilkan daftar query, file, format input, dan seluruh aturan main.
3. **Loop query** — Program menampilkan prompt berwarna `dbms Jack >>` dan membaca masukan ke variabel `pita[501]`.
4. **Validasi EOP** — `getadapagar()` memastikan masukan diakhiri `#`. Jika tidak → pesan error merah.
5. **Parsing mesin kata** — `START(pita)` mengambil kata pertama; `INC(pita)` maju ke kata berikutnya; `EOP(pita)` mengecek penanda `#`.
6. **Dispatch** — Kata pertama menjadi penentu prosedur yang dipanggil (`INPUT`/`UPDATE`/`DEL`/`SHOW`/`BANTU`/`EXIT`).
7. **Validasi menyeluruh** — Setiap prosedur memeriksa: jumlah kata (kurang/lebih), keberadaan primary key, keberadaan foreign key, format ID, panjang NIM, duplikasi nama/NIM, serta nama file yang boleh dipakai.
8. **Eksekusi & penyimpanan** — Data di array diperbarui, lalu ditulis ulang ke file dengan `tulisfile1`/`tulisfile2`.
9. **Keluar** — `EXIT` dengan kode rahasia yang benar mengubah `lanjut = 0` dan mengakhiri loop.

---

## 📖 Dokumentasi

### 1. Cara Menjalankan

Pastikan terpasang compiler C (MinGW / TDM-GCC / clang), lalu dari terminal di root folder:

```bash
gcc main.c mesin.c -o tmd.exe
./tmd.exe
```

> ⚠️ File `.txt` harus berada di **folder yang sama** dengan executable, karena program membacanya secara relatif.

### 2. Ringkasan Query

| Query | Fungsi | Format |
|---|---|---|
| `INPUT` | Menambah data baru | `INPUT [NAMAFILE] [PRIMARY] ...` |
| `UPDATE` | Mengubah data | `UPDATE [NAMAFILE] [PRIMARY] ...` |
| `DEL` | Menghapus data | `DEL [NAMAFILE] [PRIMARY]` |
| `SHOW` | Menampilkan tabel | `SHOW [NAMAFILE]` |
| `BANTU` | Panduan per query | `BANTU [NAMAQUERY]` |
| `EXIT` | Keluar program | `EXIT JANGAN LUPA TERTAWA WALAUPUN TERLUKA#` |

### 3. Format & Contoh Perintah

#### ✅ INPUT
```
INPUT MAHASISWA [ID] [NAMA] [NIM] [IDSKILL] [IDLOMBA] [IDCURANG]#
INPUT SKILL     [ID] [ATRIBUT]#
INPUT LOMBA     [ID] [ATRIBUT]#
INPUT CURANG    [ID] [ATRIBUT]#

# contoh
INPUT MAHASISWA D010 kiboy_ml 2502381 S004 L003 K003#
INPUT SKILL S014 Cepat_Beradaptasi#
INPUT LOMBA L012 C-COMPETITION#
INPUT CURANG K011 Ngehack_Web_Kampus#
```

#### ✅ UPDATE
```
UPDATE MAHASISWA [ID] [NAMA] [NIM] [IDSKILL] [IDLOMBA] [IDCURANG]#
UPDATE SKILL     [ID] [ATRIBUT]#

# contoh
UPDATE MAHASISWA D001 kevin 2537825 S004 L003 K002#
UPDATE LOMBA L002 TopSCIENCE#
```

#### ✅ DEL
```
DEL [NAMAFILE] [PRIMARY]#

# contoh
DEL MAHASISWA D007#
DEL SKILL S007#
DEL LOMBA L008#
```

#### ✅ SHOW
```
SHOW MAHASISWA#     -- tampilkan tabel mahasiswa
SHOW SKILL#         -- tampilkan tabel skill
SHOW LOMBA#         -- tampilkan tabel lomba
SHOW CURANG#        -- tampilkan tabel kecurangan
SHOW COMPLATE#      -- JOIN semua tabel lalu tampilkan & tulis dataComplate.txt
```

#### ✅ BANTU & EXIT
```
BANTU INPUT#
BANTU UPDATE#
BANTU DEL#
BANTU SHOW#

EXIT JANGAN LUPA TERTAWA WALAUPUN TERLUKA#
```

### 4. Aturan Wajib

1. Setiap masukan **harus diakhiri `#`**.
2. Jumlah kata **tidak boleh kurang dan tidak boleh lebih**.
3. Primary key **belum boleh ada** saat `INPUT`, dan **harus ada** saat `UPDATE`/`DEL`.
4. `IDSKILL`, `IDLOMBA`, `IDCURANG` wajib sudah ada di file masing-masing.
5. Nama file harus sesuai: `MAHASISWA`, `SKILL`, `LOMBA`, `CURANG`, `COMPLATE`.
6. **`COMPLATE` hanya bisa di-`SHOW`** — tidak bisa di-`INPUT`, `UPDATE`, maupun `DEL`.
7. Query dan nama file **huruf besar semua** (case-sensitive).
8. Kata yang terdiri dari lebih dari satu kata harus dipisahkan **underscore `_`** (contoh: `Cepat_Berpikir_kritis`).
9. NIM **tepat 7 digit**.
10. ID mahasiswa diawali `D`, skill `S`, lomba `L`, kecurangan `K`, dan panjangnya **maksimal 4 karakter**.
11. Tidak boleh ada nama maupun NIM yang sama.
12. Urutan masukan harus persis sesuai format.

### 5. 📸 Dokumentasi Tampilan Menu Awal

Berikut tampilan program saat pertama kali dijalankan — banner sambutan **DBMS "JACK"** dan **panduan query** yang ditampilkan otomatis oleh `judul()` dan `panduan()`, sebelum masuk ke prompt `dbms Jack >>`:

![Tampilan Menu Awal — Banner & Panduan](Tampilan/Tampilan%20Menu1.png)

<details>
<summary><b>Lanjutan tampilan panduan (klik untuk membuka)</b></summary>

**Panduan bagian 2** — sisa aturan `INPUT`, format dan catatan `UPDATE`:

![Tampilan Menu Awal — Panduan bagian 2](Tampilan/Tampilan%20Menu2.png)

**Panduan bagian 3** — keterangan `DEL`, `SHOW`, `BANTU`, `EXIT`, sampai ke prompt perintah:

![Tampilan Menu Awal — Panduan bagian 3](Tampilan/Tampilan%20Menu3.png)

</details>

### 6. Test Case

Lihat [`testcase.txt`](testcase.txt) untuk daftar lengkap test case **benar** dan **salah** untuk keempat query, contohnya:

| Kondisi | Masukan | Keterangan |
|---|---|---|
| ❌ | `INPUT` | Tidak ada `#` di akhir |
| ❌ | `INPUT MAHASISWA#` | Input kurang |
| ❌ | `INPUT MAHASISWA D010 kiboy_ml 2502381 S004 L003 K003 F001#` | Input lebih |
| ❌ | `INPUT MAHASISWA D010 kiboy_ml 250 S004 L003 K003#` | NIM kurang dari 7 digit |
| ❌ | `INPUT COMPLATE C001 DATA#` | COMPLATE bersifat read-only |
| ❌ | `DEL SKILL S001#` | ID masih dipakai di tabel MAHASISWA |
| ❌ | `SHOW MAHASISWA SKILL#` | SHOW hanya menerima satu nama file |

### 7. Pesan Error yang Tersedia

| Prosedur | Pesan |
|---|---|
| `inputkurang()` | Masukan terlalu sedikit / kurang kata |
| `inputlebih()` | Masukan terlalu banyak / lebih kata |
| `inputankedua()` | Kata kedua (nama file / query) tidak sesuai |
| `idskill()` | ID skill tidak ditemukan |
| `idlomba()` | ID lomba tidak ditemukan |
| `idcurang()` | ID kecurangan tidak ditemukan |
| `pesanexit()` | Kode rahasia `EXIT` tidak valid |
| *inline* | Masukan tidak diakhiri `#` |
| *inline* | Kata pertama bukan query yang dikenal |

---

## 🎥 Dokumentasi Video

Video penjelasan dan demo program dapat ditonton di YouTube:

### 👉 [https://youtu.be/B42Eainwo2k](https://youtu.be/B42Eainwo2k)

---

## 📌 Catatan

- Kapasitas maksimal: **50 record per tabel** (array berukuran 51, indeks 0 dipakai sebagai buffer sementara).
- Variabel global mesin kata: `idx` (posisi pada pita), `cw[51]` (kata saat ini), `wlen` (panjang kata).
- Seluruh perubahan data langsung ditulis kembali ke file `.txt`, sehingga data bertahan antar sesi program.

> *Program ini dibuat untuk keperluan Tugas Masa Depan(TMD) mata kuliah Dasar-dasar Pemrograman.*
