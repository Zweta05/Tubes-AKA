#include "TUBES.h"

int main() {
    int jumlahObat;
    cout << "Masukkan jumlah obat: ";
    cin >> jumlahObat;

    Obat *inventaris = new Obat[jumlahObat];

    // Input data obat
    for (int i = 0; i < jumlahObat; ++i) {
        cout << "Masukkan nama obat ke-" << (i + 1) << ": ";
        cin >> inventaris[i].nama;
        cout << "Masukkan stok awal obat ke-" << (i + 1) << ": ";
        cin >> inventaris[i].stok;
    }

    // Pilihan operasi
    string namaObat;
    int perubahan;
    int pilihan;
    cout << "Pilih metode pembaruan stok: 1. Iteratif 2. Rekursif\n";
    cin >> pilihan;

    cout << "Masukkan nama obat yang ingin diperbarui: ";
    cin.ignore();
    getline(cin, namaObat);

    // Validasi nama obat
    bool namaDitemukan = false;
    for (int i = 0; i < jumlahObat; ++i) {
        if (inventaris[i].nama == namaObat) {
            namaDitemukan = true;
            break;
        }
    }

    if (!namaDitemukan) {
        cout << "Nama obat tidak ditemukan dalam inventaris!" << endl;
        delete[] inventaris;
        return 0;
    }

    cout << "Masukkan perubahan stok (Bertambah/Berkurang): ";
    cin >> perubahan;

    // Panggil fungsi sesuai pilihan
    if (pilihan == 1) {
        updateStokIteratif(inventaris, jumlahObat, namaObat, perubahan);
    } else if (pilihan == 2) {
        updateStokRekursif(inventaris, jumlahObat, namaObat, perubahan);
    } else {
        cout << "Pilihan tidak valid!" << endl;
    }


    // Tampilkan hasil
    cout << "\nData inventaris obat setelah pembaruan:\n";
    tampilkanObat(inventaris, jumlahObat);

    delete[] inventaris;
    return 0;
}
