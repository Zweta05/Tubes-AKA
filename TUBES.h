#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

// Struktur untuk menyimpan data obat
typedef int infotype;
typedef struct Obat *adrObat;

struct Obat {
    string nama;
    int stok;
};

void updateStokIteratif(Obat obat[], int n, string namaObat, int perubahan);
void updateStokRekursif(Obat obat[], int n, string namaObat, int perubahan, int i = 0);
void tampilkanObat(Obat obat[], int n);

#endif // TUBES_H_INCLUDED
