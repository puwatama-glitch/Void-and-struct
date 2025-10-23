#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Nilai {
    float Matematika, BIndo, BInggris, IPA;
};

struct Siswa {
    string nama;
    string NISN;
    string jurusan;
    Nilai nilai;
    float total;
};

// Fungsi untuk menghitung nilai akhir
float hitungNilaiAkhir(Nilai n) {
    return (0.35 * n.Matematika) + (0.25 * n.IPA) + (0.20 * n.BIndo) + (0.20 * n.BInggris);
}

// Fungsi untuk menulis semua data siswa ke file
void simpanData(Siswa siswa[], int jumlah) {
    ofstream file("DataRaport.txt");
    if (!file) {
        cout << "Gagal membuka file untuk menyimpan data.\n";
        return;
    }

    for (int i = 0; i < jumlah; i++) {
        file << siswa[i].nama << '\n';
        file << siswa[i].NISN << '\n';
        file << siswa[i].jurusan << '\n';
        file << siswa[i].nilai.Matematika << '\n';
        file << siswa[i].nilai.BIndo << '\n';
        file << siswa[i].nilai.BInggris << '\n';
        file << siswa[i].nilai.IPA << '\n';
        file << siswa[i].total << '\n';
        file << "-----" << '\n';
    }

    file.close();
}

// Fungsi untuk membaca data dari file ke array
void bacaData(Siswa siswa[], int &jumlah) {
    ifstream file("DataRaport.txt");
    if (!file) {
        jumlah = 0;
        return;
    }

    jumlah = 0;
    while (!file.eof()) {
        Siswa s;
        string garis;
        getline(file, s.nama);
        if (s.nama == "") break; // jika baris kosong, keluar
        getline(file, s.NISN);
        getline(file, s.jurusan);
        file >> s.nilai.Matematika;
        file >> s.nilai.BIndo;
        file >> s.nilai.BInggris;
        file >> s.nilai.IPA;
        file >> s.total;
        getline(file, garis); // buang sisa baris angka terakhir
        getline(file, garis); // buang garis pemisah "-----"

        siswa[jumlah] = s;
        jumlah++;
    }

    file.close();
}

// Fungsi tambah data baru
void tambahData(Siswa siswa[], int &jumlah) {
    if (jumlah >= 100) {
        cout << "Data sudah penuh!\n";
        return;
    }

    Siswa s;
    cout << "\nMasukkan Nama Siswa    : ";
    getline(cin >> ws, s.nama);
    cout << "Masukkan NISN          : ";
    cin >> s.NISN;
    cout << "Masukkan Jurusan       : ";
    getline(cin >> ws, s.jurusan);
    cout << "Nilai Matematika       : ";
    cin >> s.nilai.Matematika;
    cout << "Nilai Bahasa Indonesia : ";
    cin >> s.nilai.BIndo;
    cout << "Nilai Bahasa Inggris   : ";
    cin >> s.nilai.BInggris;
    cout << "Nilai IPA              : ";
    cin >> s.nilai.IPA;

    s.total = hitungNilaiAkhir(s.nilai);
    siswa[jumlah] = s;
    jumlah++;

    simpanData(siswa, jumlah);
    cout << "\nData berhasil disimpan ke file DataRaport.txt\n";
}

// Fungsi tampilkan semua data siswa
void tampilData(Siswa siswa[], int jumlah) {
    if (jumlah == 0) {
        cout << "\nBelum ada data siswa.\n";
        return;
    }

    cout << "\n===== DATA SISWA =====\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "Nama       : " << siswa[i].nama << endl;
        cout << "NISN       : " << siswa[i].NISN << endl;
        cout << "Jurusan    : " << siswa[i].jurusan << endl;
        cout << "Matematika : " << siswa[i].nilai.Matematika << endl;
        cout << "B. Indo    : " << siswa[i].nilai.BIndo << endl;
        cout << "B. Inggris : " << siswa[i].nilai.BInggris << endl;
        cout << "IPA        : " << siswa[i].nilai.IPA << endl;
        cout << "Nilai Akhir: " << siswa[i].total << endl;
        cout << "----------------------\n";
    }
}

// Fungsi cari siswa berdasarkan NISN
void cariSiswa(Siswa siswa[], int jumlah) {
    if (jumlah == 0) {
        cout << "\nBelum ada data siswa.\n";
        return;
    }

    string cari;
    cout << "\nMasukkan NISN yang dicari: ";
    cin >> cari;

    bool ketemu = false;
    for (int i = 0; i < jumlah; i++) {
        if (siswa[i].NISN == cari) {
            cout << "\nData siswa ditemukan:\n";
            cout << "Nama       : " << siswa[i].nama << endl;
            cout << "NISN       : " << siswa[i].NISN << endl;
            cout << "Jurusan    : " << siswa[i].jurusan << endl;
            cout << "Nilai Matematika  : " << siswa[i].nilai.Matematika << endl;
            cout << "Nilai B.In : " << siswa[i].nilai.BIndo << endl;
            cout << "Nilai B.Ig : " << siswa[i].nilai.BInggris << endl;
            cout << "Nilai IPA  : " << siswa[i].nilai.IPA << endl;
            cout << "Nilai Akhir: " << siswa[i].total << endl;
            ketemu = true;
            break;
        }
    }

    if (!ketemu)
        cout << "\nSiswa dengan NISN " << cari << " tidak ditemukan.\n";
}

// Fungsi menampilkan ranking berdasarkan nilai akhir
void tampilRanking(Siswa siswa[], int jumlah) {
    if (jumlah == 0) {
        cout << "\nBelum ada data siswa.\n";
        return;
    }

    // Bubble sort sederhana (tanpa #include <algorithm>)
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (siswa[j].total < siswa[j + 1].total) {
                Siswa temp = siswa[j];
                siswa[j] = siswa[j + 1];
                siswa[j + 1] = temp;
            }
        }
    }

    cout << "\n===== RANKING SISWA =====\n";
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". " << siswa[i].nama << " (" << siswa[i].total << ")\n";
    }
}

// Program utama
int main() {
    Siswa data[100];
    int jumlah = 0;
    int menu;

    bacaData(data, jumlah);

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Tambah Data Siswa\n";
        cout << "2. Tampilkan Semua Data\n";
        cout << "3. Cari Berdasarkan NISN\n";
        cout << "4. Tampilkan Ranking\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> menu;
        cin.ignore();

        switch (menu) {
            case 1: tambahData(data, jumlah); break;
            case 2: tampilData(data, jumlah); break;
            case 3: cariSiswa(data, jumlah); break;
            case 4: tampilRanking(data, jumlah); break;
            case 0: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }
    } while (menu != 0);

    return 0;
}
