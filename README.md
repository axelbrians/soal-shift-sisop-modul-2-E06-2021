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
Membuat folder dengan nama folder-foldernya adalah Musyik untuk mp3, Fylm untuk mp4, dan Pyoto untuk jpg.
```
void create_folder(pid_t child_id){
	if(child_id == 0){
		char *argv[] = {"mkdir", "Pyoto", "Musyik", "Fylm", NULL};
		execv("/bin/mkdir", argv);
	}
}
```
- `char *argv[]`, variabel ini nantinya berguna sebagai nama folder yang akan dibuat saat fungsi `exec` menjalankan program baru.
- `execv("/bin/mkdir", argv);`, exec ini akan menjalankan program untuk membuat folder baru sesuai dengan isi variabel `char *argv[]`.

### B.
Mendownload dari link yang telah disediakan disoal.
```
void download_file(pid_t child_id){
	char *files[] ={
		"https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", "Foto_for_Stevany.zip",
		"https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "Musik_for_Stevany.zip",
		"https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", "Film_for_Stevany.zip"
		};
	
	int status;

	for(int i = 0; i < 6; i += 2){
		if (child_id == 0){
			char *argv[] = {
				"wget",
				"--no-check-certificate",
				files[i],
				"-O",
				files[i + 1],
				"-q",
				NULL};
			execv("/bin/wget", argv);
		}
		while((wait(&status)) > 0);
		child_id = fork();
	}
}
```
- `char *files[]`, variabel ini menyimpan link drive yang akan didownload dan nama file yang telah didownload.
- `char *argv[]`, variabel ini berguna sebagai perintah saat fungsi `exec` menjalankan program baru.
- `execv("/bin/wget", argv);`, exec ini akan menjalankan program untuk memdownload dan menamai file download-an tersebut sesuai dengan isi variabel `char *argv[]`.
- `while((wait(&status)) > 0);`, berguna untuk memastikan proses download telah selesai agar dapat memulai proses download lainnya.
- `child_id = fork();`, berguna untuk mengatur ulang nilai child_id agar bisa digunakan lagi untuk proses download file selanjutnya.

### C.
Meng-extract file zip yang telah didownload pada soal B.
```
void extract_file(pid_t child_id){
	char *files[] ={
		"Foto_for_Stevany.zip",
		"Musik_for_Stevany.zip",
		"Film_for_Stevany.zip"
	};

	int status;

	for(int i = 0; i < 3; i++){
		if (child_id == 0){
			char *argv[] = {
				"unzip", 
				files[i],
				NULL};
			execv("/bin/unzip", argv);
		}
		while((wait(&status)) > 0);
		child_id = fork();
	}
}
```
- `char *files[]`, variabel ini akan menunjukkan file .zip mana yang semestinya di unzip sesuai dengan char yang tersimpan di variabel ini.
- `char *argv[]`, variabel ini berguna sebagai perintah saat fungsi `exec` menjalankan program baru.
- `execv("/bin/unzip", argv);`, exec ini akan menjalankan program untuk melakukan proses unzip pada .zip sesuai dengan isi  `char *argv[]`.
- `while((wait(&status)) > 0);`, berguna untuk memastikan proses unzip telah selesai agar dapat memulai proses unzip lainnya.
- `child_id = fork();`, berguna untuk mengatur ulang nilai child_id agar bisa digunakan lagi untuk proses selanjutnya.

### D.
Memindahkan isi file yang telah di unzip pada proses C ke dalam folder yang telah dibuat pada proses A.
```
void move_file(pid_t child_id){
	char cwd[PATH_MAX];
	getcwd(cwd, PATH_MAX);
	
	char *files[] ={
		"/Pyoto", "/FOTO",
		"/Musyik", "/MUSIK",
		"/Fylm", "/FILM"
	};

	int status;

	DIR *d;
	struct dirent *dir;
	char current[PATH_MAX];
	char dest[PATH_MAX];
	for(int i = 0; i < 6; i += 2){
		strcpy(current, cwd);
		strcat(current, files[i + 1]);
		strcpy(dest, cwd);
		strcat(dest, files[i]);
		d = opendir(current);
		while ((dir = readdir (d))) {
			if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0){
				if (child_id == 0){
					char file[PATH_MAX];
					strcpy(file, current);
					strcat(file,"/");
					strcat(file,dir->d_name);
					char *argv[] = {"mv", file, dest, NULL};
					execv("/bin/mv", argv);
				}
				while((wait(&status)) > 0);
				child_id = fork();
			}
		}
		closedir(d);
	}
}
```
- `char cwd[PATH_MAX];	getcwd(cwd, PATH_MAX);`, variabel cwd akan menyimpan *path* dari direktori (folder) yang digunakan saat ini.
- `char *files[]`, variabel ini berguna untuk mengarahkan *path* dari direktori (folder) ke direktori yang diinginkan.
- `char current[PATH_MAX];`, variabel ini berguna untuk menunjuk folder mana yang filenya akan dipindahkan. `strcpy(current, cwd);`, variabel ini akan mengcopy isi dari variabel cwd, `strcat(current, files[i + 1]);`, lalu variabel ini mengambungkan isinya dengan isi dari files yang ditentukan.
- `char file[PATH_MAX];`, variabel ini berguna untuk menunjuk file mana yang akan dipindahkan. `strcpy(file, current);`, variabel ini akan mengcopy isi dari variabel cwd, `strcat(file,"/");`, menambahkan /, `strcat(file,dir->d_name);`, dan terakhir mengabungkannya dengan filenya akan dipindahkan.
- `char dest[PATH_MAX];`, variabel ini berguna untuk menunjukan kemana file tersebut akan dipindahkan. `strcpy(dest, cwd);`, variabel ini akan mengcopy isi dari variabel cwd, `strcat(dest, files[i]);`, lalu variabel ini mengambungkan isinya dengan isi dari files yang ditentukan.
- `if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0)`, berguna apabila ditemukan file `.` dan `..`, maka file tersebut tidak akan dipindahkan.
- `char *argv[]`, variabel ini berguna sebagai perintah saat fungsi `exec` menjalankan program baru.
- `execv("/bin/mv", argv);`, exec ini akan menjalankan program untuk memindahkan file sesuai dengan isi  `char *argv[]`.
- `while((wait(&status)) > 0);`, berguna untuk memastikan proses unzip telah selesai agar dapat memulai proses unzip lainnya.
- `child_id = fork();`, berguna untuk mengatur ulang nilai child_id agar bisa digunakan lagi untuk proses selanjutnya.

### E.
Semua proses A, B, C, dan D otomatis berjalan pada bulan April tanggal 9 jam 16:22:00. 
```
if(tm.tm_mon == 3 && tm.tm_mday == 9 && tm.tm_hour == 16 && tm.tm_min == 22 && tm.tm_sec == 0){
	//A
	create_folder(fork());
	//B
	download_file(fork());
	//C
	extract_file(fork());
	//D
	move_file(fork());
}
```
- `if(tm.tm_mon == 3 && tm.tm_mday == 9 && tm.tm_hour == 16 && tm.tm_min == 22 && tm.tm_sec == 0)`, menggunakan fungsi waktu yang tersedia pada library time.h, dimana apabila waktu yang telah ditentukan semuanya sama, maka fungsi void pada masing proses akan berjalan.

### F.
Pada bulan April tanggal 9 jam 22:22:00 akan menjalankan proses lainnya.
```
if(tm.tm_mon == 3 && tm.tm_mday == 9 && tm.tm_hour == 22 && tm.tm_min == 22 && tm.tm_sec == 0){
	zip_folder(fork());
	remove_file(fork());
}
```
menggunakan fungsi waktu yang tersedia pada library time.h, dimana apabila waktu yang telah ditentukan semuanya sama, maka fungsi void pada masing proses akan berjalan.
Proses yang akan berjalan ada 2 buah, pertama ialah proses pen-zip-an semua folder yang dibuat pada proses A.
```
void zip_folder(pid_t child_id){
	int status;
	if(child_id == 0){
		char *argv[] = {"zip", "-r", "Lopyu_Stevany.zip","Pyoto", "Musyik", "Fylm", NULL};
		execv("/bin/zip", argv);
	}
	while((wait(&status)) > 0);
}
```
- `char *argv[]`, variabel ini berguna sebagai perintah saat fungsi `exec` menjalankan program baru.
- `execv("/bin/zip", argv);`, exec ini akan menjalankan program untuk penge-zip-an file sesuai dengan isi variabel `char *argv[]`.
- `while((wait(&status)) > 0);`, berguna untuk memastikan proses zip telah selesai agar dapat memulai proses selanjutnya.
Proses kedua ialah mengahapus semua folder yang ada dan menyisakan file dengan extensions .zip
```
void remove_file(pid_t child_id){
	char *files[] ={
		"FOTO", "Pyoto",
		"MUSIK", "Musyik",
		"FILM", "Fylm"
	};

	int status;

	for(int i = 0; i < 6; i++){
		if(child_id == 0){
			char *argv[] = {"rm", "-r", files[i], NULL};
			execv("/bin/rm", argv);
		}
		child_id = fork();
		while((wait(&status)) > 0);
	}
}
```
- `char *files[]`, variabel ini menyimpan nama folder yang akan dihapus.
- `char *argv[]`, variabel ini berguna sebagai perintah saat fungsi `exec` menjalankan program baru.
- `execv("/bin/rm", argv);`, exec ini akan menjalankan program untuk menghapus isi variabel `char *argv[]`.
- `while((wait(&status)) > 0);`, berguna untuk memastikan proses telah selesai agar dapat segera memulai proses selanjutnya.
- `child_id = fork();`, berguna untuk mengatur ulang nilai child_id agar bisa digunakan untuk proses selanjutnya.

### Kesulitan
- Pada soal 1.D, kesuliatan dalam memindahkan file sebelum menyetahui fungsi dari library dirent.h.
- Pada soal 1.D, tidak menyetahui sepenuhnya file apa saja yang dicari pada fungsi dari library dirent.h, sehingga mengakibatkan 2 file yang dipindahkan jadi invalid encoding file.
- Pada soal 1.D, kesalahan penulisan pada *argv yang mengakibatkan tercipta file dan folder invalid encoding.

### Output
https://user-images.githubusercontent.com/79897417/115990016-4779e300-a5eb-11eb-8549-37b339340416.mp4

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
Ranora adalah mahasiswa Teknik Informatika yang saat ini sedang menjalani magang di perusahan ternama yang bernama “FakeKos Corp.”, perusahaan yang bergerak dibidang keamanan data. Karena Ranora masih magang, maka beban tugasnya tidak sebesar beban tugas pekerja tetap perusahaan. Di hari pertama Ranora bekerja, pembimbing magang Ranora memberi tugas pertamanya untuk membuat sebuah program.

(a) Ranora harus membuat sebuah program C yang dimana setiap 40 detik membuat sebuah direktori dengan nama sesuai timestamp [YYYY-mm-dd_HH:ii:ss].

(b) Setiap direktori yang sudah dibuat diisi dengan 10 gambar yang didownload dari https://picsum.photos/, dimana setiap gambar akan didownload setiap 5 detik. Setiap gambar yang didownload akan diberi nama dengan format timestamp [YYYY-mm-dd_HH:ii:ss] dan gambar tersebut berbentuk persegi dengan ukuran (n%1000) + 50 pixel dimana n adalah detik Epoch Unix.

(c) Setelah direktori telah terisi dengan 10 gambar, program tersebut akan membuat sebuah file “status.txt”, dimana didalamnya berisi pesan “Download Success” yang terenkripsi dengan teknik Caesar Cipher dan dengan shift 5. Caesar Cipher adalah Teknik enkripsi sederhana yang dimana dapat melakukan enkripsi string sesuai dengan shift/key yang kita tentukan. Misal huruf “A” akan dienkripsi dengan shift 4 maka akan menjadi “E”. Karena Ranora orangnya perfeksionis dan rapi, dia ingin setelah file tersebut dibuat, direktori akan di zip dan direktori akan didelete, sehingga menyisakan hanya file zip saja.

(d) Untuk mempermudah pengendalian program, pembimbing magang Ranora ingin program tersebut akan men-generate sebuah program “Killer” yang executable, dimana program tersebut akan menterminasi semua proses program yang sedang berjalan dan akan menghapus dirinya sendiri setelah program dijalankan. Karena Ranora menyukai sesuatu hal yang baru, maka Ranora memiliki ide untuk program “Killer” yang dibuat nantinya harus merupakan program bash.

(e) Pembimbing magang Ranora juga ingin nantinya program utama yang dibuat Ranora dapat dijalankan di dalam dua mode. Untuk mengaktifkan mode pertama, program harus dijalankan dsdengan argumen -z, dan Ketika dijalankan dalam mode pertama, program utama akan langsung menghentikan semua operasinya Ketika program Killer dijalankan. Sedangkan untuk mengaktifkan mode kedua, program harus dijalankan dengan argumen -x, dan Ketika dijalankan dalam mode kedua, program utama akan berhenti namun membiarkan proses di setiap direktori yang masih berjalan hingga selesai (Direktori yang sudah dibuat akan mendownload gambar sampai selesai dan membuat file txt, lalu zip dan delete direktori).

Ranora meminta bantuanmu untuk membantunya dalam membuat program tersebut. Karena kamu anak baik dan rajin menabung, bantulah Ranora dalam membuat program tersebut!

**Note:**
- Tidak boleh menggunakan system() dan mkdir()
- Program utama merupakan SEBUAH PROGRAM C
- Wajib memuat algoritma Caesar Cipher pada program utama yang dibuat

#### Jawaban:

### A.
- Timestamp bisa didapatkan dengan memanfaatkan fungsi `strftime` dan juga `localtime`.
```
void getTime(char *string) {
	time_t t;
	char timestamp[50];
	t=time(NULL);
	strftime(timestamp, sizeof(timestamp), "%Y-%m-%d_%H:%M:%S", localtime(&t));
	strcpy(string, timestamp);
	return;
}
```
- Dikarenakan tidak boleh memanggil fungsi `mkdir` secara langsung, maka solusinya adalah dengan menggunakan fungsi `execv` untuk memanggil fungsi `mkdir` tersebut.
- Dengan memanfaatkan fungsi `while(1)` dan `sleep(40)` maka directory dibuat setiap 40 detik sekali secara terus menerus.
```
while(1){
	char pdir[200];
	getTime(pdir);
	char *argv[] = {"mkdir", "-p", pdir, NULL};
	execv("/bin/mkdir", argv);
	sleep(40);
}
```

### B.
```
char nama[300],img[300],url[300];
pid_t cid3;
int status3;
for(int i=1;i<=10;i++){
	getTime(img);
	sprintf(nama, "%s/%s.jpg", pdir, img);

	long long sizeimg = time(NULL) % 1000 + 50;
	snprintf(url, sizeof(url),"https://picsum.photos/%lld",sizeimg);

	cid3 = fork();
	if(cid3 == 0){
		char *argv[] = {"wget", "-q", "-O", nama, url, NULL};
		execv("/usr/bin/wget", argv);
	}
	sleep(5);
}
```
- Fungsi `sprintf(nama, "%s/%s.jpg", pdir, img)` digunakan untuk penamaan file gambar yang akan di unduh sesuai dengan timestamp.
- `snprintf(url, sizeof(url),"https://picsum.photos/%lld",time(NULL) % 1000 + 50)` digunakan untuk membentuk gambar menjadi sebuah persegi dari epoch time unix sesuai ketentuan.
- Dengan membuat child process `cid3`, dapat dilanjutkan dengan fungsi `execv` untuk memanggil `wget` syscall

### C.
- Fungsi `Cipher` dapat digunakan untuk shift tiap karakter suatu pesan sebanyak `key`.
```
void Cipher(char *msg, int key) {
	char ch;
	for(int i=0;msg[i]!='\0';++i){
		ch = msg[i];

		if(ch >= 'a' && ch <= 'z'){
			ch += key;
			if(ch > 'z') ch = ch - 'z' + 'a' - 1;
			msg[i] = ch;
		}else if(ch >= 'A' && ch <= 'Z'){
			ch += key;
			if(ch > 'Z') ch = ch - 'Z' + 'A' - 1;
			msg[i] = ch;
		}
	}
}
```
- Setelah proses unduh selesai pada subsoal b, dapat dilanjutkan dengan mengenkripsi pesan "Download Success" lalu menyimpannya pada file `status.txt`
```
char statustxt[100];
char statusmsg[] = "Download Success";
Cipher(statusmsg, 5);

strcpy(statustxt, pdir);
strcat(statustxt, "/status.txt");

FILE *statusFile = fopen(statustxt, "w");
fputs(statusmsg, statusFile);
fclose(statusFile);
```
- Tahap selanjutnya adalah memanggil fungsi `zip` untuk mengompress folder yang sudah dibuat dan dilanjutkan dengan `rm` untuk menghapus folder yang sudah dikompress.
```
pid_t cid4;
int status4;
cid4 = fork();

if(cid4 == 0){
	char outputZip[300];
	sprintf(outputZip, "%s.zip", pdir);

	char *argv[] = {"zip", "-r", outputZip, pdir, NULL};
	execv("/usr/bin/zip", argv);
}else{
	while ((wait(&status4)) > 0);
	char *argv[] = {"rm", "-r", pdir, NULL};
	execv("/usr/bin/rm", argv);
}
```

### D. E.
- Sebuah file bernama `Killer` dibuat dengan isian shell command.
- Untuk argumen `-z`, maka command yang digunakan adalah `killList=$(echo $(pidof ./soal3))` yang berfungsi untuk melakukan cek semua file yang memiliki pid `soal3`, lalu dilanjutkan dengan command "kill -9 $killList\n untuk melakukan kill pada proses child yang terdapat pada variabel killlist.
- Untuk argumen `-x`, maka command yang digunakan adalah `kill %d\n` yang berfungsi untuk melakukan kill pada pid parent saja.
```
void Killer(char mode){
	FILE *killer;
	killer = fopen("Killer", "w");
	if(mode == 'z') fprintf(killer,"#!/bin/bash\nkillList=$(echo $(pidof ./soal3))\nkill -9 $killList\nrm Killer");
	else if(mode == 'x') fprintf(killer,"#!/bin/bash\nkill %d\nrm Killer",getpid());
	fclose(killer);

	pid_t child_chmod;
	child_chmod = fork();

	if(child_chmod == 0){
		char *argv[] = {"chmod", "+x", "Killer", NULL};
		execv("/usr/bin/chmod", argv);
	}
	return;
}

```
- Setelah proses unduh selesai pada subsoal b, dapat dilanjutkan dengan mengenkripsi pesan "Download Success" lalu menyimpannya pada file `status.txt`
```
char statustxt[100];
char statusmsg[] = "Download Success";
Cipher(statusmsg, 5);

strcpy(statustxt, pdir);
strcat(statustxt, "/status.txt");

FILE *statusFile = fopen(statustxt, "w");
fputs(statusmsg, statusFile);
fclose(statusFile);
```

### Kesulitan
- Pada soal 2.B, saat mengunduh sebuah gambar dari suatu url, lalu menyimpan dengan ukuran sesuai dengan epoch time dan berbentuk persegi, lalu disimpan lagi dengan nama timestamp ketika mendownload.

### Output
![ss](https://user-images.githubusercontent.com/72863287/116086198-c04f6c80-a6c9-11eb-909b-c043967469f4.jpg)
