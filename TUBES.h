#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

using namespace std;
#include <iostream>

#define info(P) (P)->info
#define nextTim(P) (P)->nextTim
#define nextAnggota(P) (P)->nextAnggota
#define parent(P) (P)->parent
#define firstTim(T) ((T).firstTim)
#define firstAnggota(A) ((A).firstAnggota)

struct infotypeTim{
    string nama;
    string pelatih;
    int jumlahAnggota;
};

struct infotypeAnggota{
    string nama;
    string umur;
};

typedef struct elemenTim* adrTim;
typedef struct elemenAnggota* adrAnggota;

struct elemenTim{
    infotypeTim info;
    adrTim nextTim;
};

struct elemenAnggota{
    infotypeAnggota info;
    adrTim parent;
    adrAnggota nextAnggota;
};

struct listTim{
    adrTim firstTim;
};

struct listAnggota{
    adrAnggota firstAnggota;
};

void createlistTim(listTim &T);
void createlistAnggota(listAnggota &A);
adrTim newElemenTim();
adrAnggota newElemenAnggota();
void addElemenTim(listTim &T);
void addElemenAnggota(listAnggota &A);
adrTim findTim(listTim T,string namaTim);
adrAnggota findAnggota(listAnggota A,string namaAnggota);
void connectedFam(listTim &T, listAnggota &A);
void printAll(listTim T,listAnggota A);
void deleteTim(listTim &T,listAnggota &A);
void deleteAnggota(listTim &T,listAnggota &A);
void deleteAnggotadaritim(listTim &T,listAnggota &A);
void printTimdanAnggota(listTim T,listAnggota A);
void maxAnggota(listTim T, listAnggota A);
void minAnggota(listTim T, listAnggota A);
char printMenu();

#endif // TUBES_H_INCLUDED
