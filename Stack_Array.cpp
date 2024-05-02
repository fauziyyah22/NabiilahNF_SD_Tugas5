#include<iostream>
#include<cstdlib> // Library untuk fungsi system("cls")
using namespace std;

void line() {
    for (int i = 0; i <= 70; i++) {
        cout << "=";
    }
    cout << "\n";
}

void identitas() {
    cout << "\nProgram Stack Array - Pemindahan Data dari Satu Menara ke Menara Lain";
    cout << "\nNama     : Nabiilah Nur Fauziyyah";
    cout << "\nNPM      : 2310631170105";
    cout << "\nKelas    : 2C - Informatika" << "\n";
}

const int maxSize = 3;
int towerA[maxSize] = {0};  // Inisialisasi Tower A dengan nilai awal 0
int towerB[maxSize] = {0};  // Inisialisasi Tower B dengan nilai awal 0
int towerC[maxSize] = {0};  // Inisialisasi Tower C dengan nilai awal 0

// Fungsi countSize() digunakan untuk menghitung jumlah elemen yang ada pada stack.
// Input dari fungsi ini adalah sebuah array stack yang mewakili salah satu menara (tower).
// Fungsi ini akan mengembalikan jumlah elemen yang ada pada stack tersebut.
int countSize(int stack[]) {
    int size = 0;  // Inisialisasi variabel size untuk menghitung jumlah elemen
    // Perulangan while akan terus berjalan selama elemen pada stack[size] bukan 0 (nilai akhir)
    // dan ukuran size masih kurang dari maxSize (ukuran maksimum stack).
    while (stack[size] != 0 && size < maxSize) {
        size++;  // Tambahkan size untuk menghitung jumlah elemen
    }
    return size;  // Mengembalikan jumlah elemen yang terhitung
}

// Fungsi pushTo() digunakan untuk menambahkan elemen ke dalam stack (menara).
// Input dari fungsi ini adalah array stack yang akan dimodifikasi dan nilai (number) yang akan ditambahkan.
// Fungsi ini mengecek apakah stack sudah penuh sebelum menambahkan nilai ke dalamnya.
void pushTo(int stack[], int number) {
    int amount = countSize(stack); // Mendapatkan jumlah elemen saat ini pada stack
    // Memeriksa apakah jumlah elemen pada stack sudah mencapai batas maksimum (maxSize)
    if (amount >= maxSize) {
        cout << "Stack sudah penuh\n";  // Menampilkan pesan jika stack sudah penuh
    } else {
        stack[amount] = number;  // Menambahkan nilai ke dalam stack pada posisi yang sesuai (amount)
    }
}

// Fungsi popElement() digunakan untuk menghapus elemen teratas dari stack (menara).
// Input dari fungsi ini adalah array stack yang akan dimodifikasi.
void popElement(int stack[]) {
    int amount = countSize(stack);  // Mendapatkan jumlah elemen saat ini pada stack
    // Memeriksa apakah stack kosong (tidak memiliki elemen)
    if (amount == 0) {
        cout << "Kosong\n";  // Menampilkan pesan jika stack kosong
    } else {
        stack[amount - 1] = 0;  // Menghapus elemen teratas (top) dengan mengubah nilainya menjadi 0
    }
}

// Fungsi displayStack() digunakan untuk menampilkan isi dari suatu stack (menara).
// Input dari fungsi ini adalah array stack yang berisi elemen-elemen stack.
void displayStack(int stack[]) {
    for (int i = 0; i < maxSize; i++) {
        if (stack[i] != 0) {
            cout << stack[i] << " -> ";  // Menampilkan elemen stack kecuali nilai 0
        }
    }
    cout << "\n";  // Output newline setelah menampilkan seluruh elemen stack
}

// Fungsi displayAll() digunakan untuk menampilkan seluruh menara (stack) beserta isinya.
// Fungsi ini memanggil fungsi displayStack() untuk menampilkan isi dari setiap menara.
void displayAll() {
    cout << "Tower A : ";  // Menampilkan label Tower A
    displayStack(towerA);  // Menampilkan isi dari Tower A menggunakan fungsi displayStack()
    cout << "Tower B : ";  // Menampilkan label Tower B
    displayStack(towerB);  // Menampilkan isi dari Tower B menggunakan fungsi displayStack()
    cout << "Tower C : ";  // Menampilkan label Tower C
    displayStack(towerC);  // Menampilkan isi dari Tower C menggunakan fungsi displayStack()
    cout << "\n";  // Output newline untuk memisahkan tampilan antar menara
}

// Fungsi main() adalah fungsi utama yang akan dieksekusi saat program dijalankan.
// Pada bagian ini, layar akan dibersihkan menggunakan fungsi system("cls") untuk membersihkan tampilan.
// Kemudian, pengguna diminta memasukkan 3 nilai untuk Menara C menggunakan perulangan for.
// Setiap nilai yang dimasukkan akan disimpan ke dalam Menara C menggunakan fungsi pushTo().
// Setelah pengguna selesai memasukkan nilai, layar akan dibersihkan kembali menggunakan system("cls").
int main() {
    system("cls"); // Membersihkan layar

    cout << "Masukkan 3 Nilai pada Menara C:\n";
    for (int i = 0; i < 3; i++) {
        int value;
        cout << "Nilai ke-" << (i + 1) << ": ";
        cin >> value;
        pushTo(towerC, value); // Memasukkan nilai ke Menara C menggunakan fungsi pushTo()
    }

    system("cls"); // Membersihkan layar

    while (true) {
        line(); // Menampilkan garis pembatas
        cout << " \t\t\t Tower Hanoi\n";
        line(); // Menampilkan garis pembatas

        cout << " Keadaan Menara saat ini\n";
        line(); // Menampilkan garis pembatas
        displayAll(); // Menampilkan keadaan seluruh menara menggunakan fungsi displayAll()

        cout << " Pilihan Menu :\n";
        cout << " 1. Pindahkan dari C ke B\n";
        cout << " 2. Pindahkan dari B ke C\n";
        cout << " 3. Pindahkan dari B ke A\n";
        cout << " 4. Keluar\n";
        line(); // Menampilkan garis pembatas

        int choice;
        cout << "Masukkan pilihan Anda: ";
        cin >> choice; // Meminta pengguna memasukkan pilihan menu

        switch (choice) {
            case 1:
                system("cls"); // Membersihkan layar
                line(); // Menampilkan garis pembatas
                cout << " Pindahkan Nilai dari C ke B\n";
                line(); // Menampilkan garis pembatas
                pushTo(towerB, towerC[countSize(towerC) - 1]); // Memindahkan nilai dari Menara C ke Menara B
                popElement(towerC); // Menghapus nilai teratas dari Menara C
                displayAll(); // Menampilkan keadaan seluruh menara
                break;
            case 2:
                system("cls"); // Membersihkan layar
                line(); // Menampilkan garis pembatas
                cout << " Pindahkan Nilai dari B ke C\n";
                line(); // Menampilkan garis pembatas
                pushTo(towerC, towerB[countSize(towerB) - 1]); // Memindahkan nilai dari Menara B ke Menara C
                popElement(towerB); // Menghapus nilai teratas dari Menara B
                displayAll(); // Menampilkan keadaan seluruh menara
                break;
            case 3:
                system("cls"); // Membersihkan layar
                line(); // Menampilkan garis pembatas
                cout << " Pindahkan Nilai dari B ke A\n";
                line(); // Menampilkan garis pembatas
                pushTo(towerA, towerB[countSize(towerB) - 1]); // Memindahkan nilai dari Menara B ke Menara A
                popElement(towerB); // Menghapus nilai teratas dari Menara B
                displayAll(); // Menampilkan keadaan seluruh menara
                break;
            case 4:
                system("cls"); // Membersihkan layar
                line(); // Menampilkan garis pembatas
                cout << " Terima kasih sudah menggunakan program ini!\n";
                line(); // Menampilkan garis pembatas
                identitas(); // Menampilkan identitas pembuat program
                line(); // Menampilkan garis pembatas
                return 0; // Keluar dari program
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }

        cout << "\nTekan tombol Enter untuk melanjutkan...";
        cin.ignore(); // Mengabaikan karakter newline ('\n')
        cin.get(); // Menunggu input tombol Enter
        system("cls"); // Membersihkan layar
    }

    return 0;
}
