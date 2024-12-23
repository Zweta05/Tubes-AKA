#include "TUBES.h"

// Fungsi iteratif untuk memperbarui stok
void updateStokIteratif(Obat obat[], int n, string namaObat, int perubahan) {
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n;j++){
            cout << endl;
            if (obat[i].nama == namaObat) {
                obat[i].stok += perubahan;
                cout << "Stok obat " << namaObat << "Berhasil diperbarui menjadi " << obat[i].stok << endl;
                return;
            }
        }
    }
    cout << "Obat" << namaObat << "Tidak ditemukan dalam inventaris" << endl;
}


// Fungsi rekursif untuk memperbarui stok
void updateStokRekursif(Obat obat[], int n, string namaObat, int perubahan, int i) {
    if (i >= n) return; // Basis rekursi

    // Rekursi bersarang untuk meningkatkan kompleksitas menjadi O(n^3)
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            if (k == j && obat[i].nama == namaObat) {
                obat[i].stok += perubahan;
                cout << "Stok obat \"" << namaObat << "\" berhasil diperbarui menjadi " << obat[i].stok << ".\n";
                return;
            }
        }
    }
    updateStokRekursif(obat, n, namaObat, perubahan, i + 1);
}

// Fungsi untuk menampilkan data obat
void tampilkanObat(Obat obat[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Nama Obat: " << obat[i].nama << ", Stok: " << obat[i].stok << endl;
    }
}
