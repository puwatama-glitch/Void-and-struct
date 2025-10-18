#include <iostream>
using namespace std;

const int MAKS = 100; // Batas maksimal mahasiswa

struct Tgl {
    int hari, bulan, tahun;
};

struct Nilai {
    float uts, uas, tugas;
};

struct Mahasiswa {
    string nama;
    int umur;
    string jurusan;
    Tgl lahir;
    Nilai nilai;
};

// Fungsi untuk input data mahasiswa
void inputMahasiswa(Mahasiswa mhs[], int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        cout << "\nMasukkan Data Mahasiswa ke-" << i + 1 << endl;

        cout << "Nama    : ";
        cin >> mhs[i].nama;

        cout << "Umur    : ";
        cin >> mhs[i].umur;

        cout << "Jurusan : ";
        cin >> mhs[i].jurusan;

        cout << "Tanggal Lahir : ";
        cin >> mhs[i].lahir.hari >> mhs[i].lahir.bulan >> mhs[i].lahir.tahun;

        cout << "Masukkan Nilai UTS   : ";
        cin >> mhs[i].nilai.uts;

        cout << "Masukkan Nilai UAS   : ";
        cin >> mhs[i].nilai.uas;

        cout << "Masukkan Nilai Tugas : ";
        cin >> mhs[i].nilai.tugas;
    }
}

// Fungsi untuk menampilkan data mahasiswa
void tampilMahasiswa(Mahasiswa mhs[], int jumlah) {
    cout << "\n\nData Mahasiswa\n";
    for (int i = 0; i < jumlah; i++) {
        float nilaiAkhir = (mhs[i].nilai.uts * 0.35) +
                           (mhs[i].nilai.uas * 0.40) +
                           (mhs[i].nilai.tugas * 0.25);

        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama          : " << mhs[i].nama << endl;
        cout << "Umur          : " << mhs[i].umur << endl;
        cout << "Jurusan       : " << mhs[i].jurusan << endl;
        cout << "Tanggal Lahir : " << mhs[i].lahir.hari << "-"
             << mhs[i].lahir.bulan << "-" << mhs[i].lahir.tahun << endl;

        cout << "Nilai UTS     : " << mhs[i].nilai.uts << endl;
        cout << "Nilai UAS     : " << mhs[i].nilai.uas << endl;
        cout << "Nilai Tugas   : " << mhs[i].nilai.tugas << endl;
        cout << "Nilai Akhir   : " << nilaiAkhir << endl;
    }
}

int main() {
    Mahasiswa mhs[MAKS];
    int jumlah;

    cout << "Masukkan jumlah mahasiswa (maks " << MAKS << "): ";
    cin >> jumlah;

    if (jumlah > MAKS) {
        cout << "Jumlah melebihi batas maksimum (" << MAKS << "). Program dihentikan.\n";
        return 1;
    }

    inputMahasiswa(mhs, jumlah);
    tampilMahasiswa(mhs, jumlah);

    return 0;
}
