# Soal Shift Sisop Modul 2 2021


Kelompok E-06
- Fajar Satria (05111940000083)
- Axel Briano Suherik (05111940000137)
- Ikhlasul Amal Rivel (05111940000145)
# Soal Shift Modul 2 (Kelompok E6)

**Soal Shift Modul 2 Sistem Operasi 2021:**
* [Soal 1](https://github.com/axelbrians/soal-shift-sisop-modul-2-E06-2021#Soal-1)
* [Soal 2](https://github.com/axelbrians/soal-shift-sisop-modul-2-E06-2021#Soal-2)
* [Soal 3](https://github.com/axelbrians/soal-shift-sisop-modul-2-E06-2021#Soal-3)

## Soal 1
Pada suatu masa, hiduplah seorang Steven yang hidupnya pas-pasan. Steven punya pacar, namun sudah putus sebelum pacaran. Ketika dia galau memikirkan mantan, ia selalu menonton [https://www.youtube.com/watch?v=568DH_9CMKI](https://www.youtube.com/watch?v=568DH_9CMKI) untuk menghilangkan kesedihannya.

Di lain hal Steven anak yang tidak amat sangat super membenci matkul sisop, beberapa jam setelah diputus oleh pacarnya dia menemukan wanita lain bernama Stevany, namun Stevany berkebalikan dengan Steven karena menyukai sisop. Steven ingin terlihat jago matkul sisop demi menarik perhatian Stevany.

Pada hari ulang tahun Stevany, Steven ingin memberikan Stevany zip berisikan hal-hal yang disukai Stevany. Steven ingin isi zipnya menjadi rapi dengan membuat folder masing-masing sesuai extensi. 

(a) Dikarenakan Stevany sangat menyukai huruf Y, Steven ingin nama folder-foldernya adalah Musyik untuk mp3, Fylm untuk mp4, dan Pyoto untuk jpg 

(b) untuk musik Steven mendownloadnya dari link di bawah, film dari link di bawah lagi, dan foto dari link dibawah juga :). 

(c) Steven tidak ingin isi folder yang dibuatnya berisikan zip, sehingga perlu meng-extract-nya setelah didownload serta 

(d) memindahkannya ke dalam folder yang telah dibuat (hanya file yang dimasukkan.

(e) Untuk memudahkan Steven, ia ingin semua hal di atas berjalan otomatis 6 jam sebelum waktu ulang tahun Stevany). 

(f) Setelah itu pada waktu ulang tahunnya Stevany, semua folder akan di zip dengan nama Lopyu_Stevany.zip dan semua folder akan di delete(sehingga hanya menyisakan .zip).

Kemudian Steven meminta bantuanmu yang memang sudah jago sisop untuk membantunya mendapatkan hati Stevany. Bantu Woy!!

**Note:**
- Ulang Tahun Stevany : 09 April Pukul 22.22 WIB
- Semua poin dijalankan oleh 1 script di latar belakang, termasuk mendownload file zip-nya. Jadi cukup jalankan script 1x serta ubah time dan date untuk check hasilnya.

Preview :
[https://drive.google.com/drive/folders/1NzRiPPoVlR_H8P51cxN4jaceeFQGk4un](https://drive.google.com/drive/folders/1NzRiPPoVlR_H8P51cxN4jaceeFQGk4un)
*tontonnya 720p biar jelas.. ಠ‿ಠ

- Tidak boleh menggunakan fungsi system(), mkdir(), dan rename() (Yang di bahasa C) .... FORBIDDENNN!!
- Tidak boleh pake cron !!!
- Menggunakan fork dan exec.
- Link

|  File |                                                                        Link                                                                            |
|:-----:|    :----------------------------------------------------------------------------------------------------------------------------------------------:    |
|  Foto |    [https://drive.google.com/file/d/1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD/view](https://drive.google.com/file/d/1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD/view)    |
| Musik |    [https://drive.google.com/file/d/1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J/view](https://drive.google.com/file/d/1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J/view)    |
|  Film |    [https://drive.google.com/file/d/1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp/view](https://drive.google.com/file/d/1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp/view)    |

**Tips :**
- Gunakan fungsi wait() dan sleep() untuk memperlancarrr..
- untuk mendownload zip yang dibutuhkan bisa menggunakan command :
```
wget --no-check-certificate "https://drive.google.com/uc?id=ID-FILE&export=download" -O Nama_untuk_filenya.ext
```
- contoh
```
Wget --no-check-certificate "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download" -O Musik_for_Stevany.zip
```

#### Jawaban:

### A.

### B.

### C.

### D.

### E.

### F.

### Kesulitan


# Soal 2
## Info
* Dikerjakan oleh 05111940000137 - Axel Briano Suherik.
* Tidak boleh menggunakan: `system()`, *shell script*, `mkdir()`, dan `rename`.
* Menggunakan `fork` dan `exec`.

## Subsoal a
### Penjelasan soal
1. Diminta untuk meng-unzip suatu file zip ke ./petshop
2. Hanya file dengan extensi .jpg, file/folder lainnya dihapus saja.

### Penyelesaian
1. Karena zip dikasih dari soal, maka langsung menjalankan perintah unzip.
2. Dengan command ini `unzip pets.zip *.jpg -d ./petshop` maka perintah no 1 dan 2 selesai.

## Subsoal b
### Penjelasan soal
1. Dapatkan jenis hewan pada file yang telah di unzip
2. Dari tiap jenis hewan, buatkan folder dengan nama sesuai jenisnya.

### Penyelesaian
1. Untuk subsoal ini saya menggunakan stack untuk menyimpan informasi jenis hewan yang ada.
2. Agar nama yang disimpan unique saya membuat fungsi insert untuk melakukan cek kalau data yang baru dimasukkan itu belum ada pada stack.
3. Jenis hewan didapat menggunakan method `strtok(<nama file>, ";");` 
4. Jika sudah di list semua ke dalam stack, maka hanya perlu traversal seluruh elemen stack dan untuk tiap node saya memanggil fungsi buatan sendiri yang isinya membuat folder sesuai parameter yang di passing. Fungsi ini juga otomatis memblock jalannya program artinya tidak dilanjutkan ke tahap berikutnya sebelum selesai membuat folder.

## Subsoal c
### Penjelasan soal
1. Memindahkan tiap file foto ke folder sesuai dengan jenisnya masing - masing.
2. Rename nama file foto sesuai dengan perintah.

### Penyelesaian
1. Digunakan stack untuk menyimpan berbagai data yang diperlukan tiap fotonya.
2. Diantaranya adalah nama foto utuh, nama hasil rename, jenis hewan foto tersebut, serta umur yang nanti dibutuhkan pada subsoal e.
3. Melakukan scan ulang terhadap semua foto pada dir `./petshop`
4. Manfaatkan `strtok()` untuk mendapatkan data yang diekstrak dari nama asli fotonya.
5. Traversal stack dan untuk tiap node memanggil command saya membuat fungsi sendiri yaitu `move_file()`, fungsi ini menkonstruksi path yang sesuai sekaligus melakukan write pada file `keterangan.txt` untuk **subsoal e**.
6. Pada akhir `move_file()` ada `execv(mv)` untuk memindahkan foto ke folder yang sesuai.

## Subsoal d
### Penjelasan soal
1. Dapatkan nama dan jenis hewan jika pada suatu foto terdapat dua hewan sekaligus.
2. Pindahkan hewan kedua pada folder yang sesuai
3. Rename nama foto sesuai nama hewan.

### Penyelesaian
1. Sama seperti **subsoal c**, di sini digunakan stack untuk menyimpan macam - macam informasi.
2. Hanya saja digunakan `execv(cp)` karena tidak ingin hewan pertamanya hilang.

## Subsoal e
### Penjelasan
1. Membuat file `keterangan.txt` pada setiap folder jenis hewan.
2. Isi file `keterangan.txt` dengan nama dan umur hewan pada folder tersebut.
   Format:
   > nama : joni  
   > umur : 3 tahun
   >
   > nama : miko  
   > umur: 2 tahun
   >

### Penyelesaian
1. Sudah dilakukan saat melakukan `mv` atau `cp` pada subsoal sebelumnya.

### Kesulitan
Yang paling merepotkan bagi saya di nomer 2 ini adalah saat memproses suatu file ganda, ex `dog;baro;1_cat;joni;2.jpg` lumayan memakan waktu saat berusaha memproses string namanya ke masing-masing stack. Kemudian memikirkan metode agar dapat memindahkan file ke folder jenis hewan masing - masing juga lumayan, pada akhirnya saya memilih pendekatan dengan stack. Menyimpan semua informasi yang diperlukan, setelah itu menjalankan command yang sesuai untuk tiap node pada stack.

## Soal 3
