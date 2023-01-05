#include "TUBES.h"

void createlistTim(listTim &T){
    firstTim(T) = NULL;
}
void createlistAnggota(listAnggota &A){
    firstAnggota(A) = NULL;
}

adrTim newElemenTim(){
    infotypeTim x;
    cout << "Masukkan nama tim : ";  cin >> x.nama;
    cout << "Masukkan pelatih : "; cin >> x.pelatih;
    adrTim P = new elemenTim;
    info(P) = x;
    info(P).jumlahAnggota = 0;
    nextTim(P) = NULL;
    return P;
}

adrAnggota newElemenAnggota(){
    infotypeAnggota y;
    cout << "Masukkan nama anggota : ";  cin >> y.nama;
    cout << "Masukkan umur : "; cin >> y.umur;
    adrAnggota P = new elemenAnggota;
    info(P) = y;
    parent(P) = NULL;
    nextAnggota(P) = NULL;
    return P;
}

void addElemenTim(listTim &T){
    adrTim Q;adrTim P;
    int N;

    cout << "Jumlah tim yang ingin dibuat: "; cin >> N;
    while(N != 0){
        P = newElemenTim();
        if(firstTim(T) != NULL){
            Q = firstTim(T);
            while(nextTim(Q) != NULL){
                Q = nextTim(Q);
            }
            nextTim(Q) = P;
        }else{
            firstTim(T) = P;
        }
        nextTim(P) = NULL;
        N--;
        cout<< "Tim berhasil dibuat"<<endl;
        cout << endl;
    }
}

void addElemenAnggota(listAnggota &A){
    adrAnggota Q;adrAnggota P;
    int N;
    cout << "Jumlah anggota yang ingin dibuat: "; cin >> N;
    while(N != 0){
        P = newElemenAnggota();
        if(firstAnggota(A) != NULL){
            Q = firstAnggota(A);
            while(nextAnggota(Q) != NULL){
                Q = nextAnggota(Q);
            }
            nextAnggota(Q) = P;
        }else{
            firstAnggota(A) = P;
        }
        nextAnggota(P) = NULL;
        parent(P) = NULL;
        N--;
        cout<< "Anggota berhasil dibuat"<<endl;
        cout << endl;
    }
}

adrTim findTim(listTim T,string namaTim){
    adrTim P = firstTim(T);

    if(firstTim(T) == NULL){
        return NULL;
    }else{
        while((info(P).nama != namaTim) && nextTim(P) != NULL){
            P = nextTim(P);
        }
        if (info(P).nama == namaTim){
            return P;
        }else{
            return NULL;
        }
    }
}

adrAnggota findAnggota(listAnggota A,string namaAnggota){
    adrAnggota P = firstAnggota(A);
    if(firstAnggota(A) == NULL){
        return NULL;
    }else{
        while((info(P).nama != namaAnggota) && nextAnggota(P) != NULL){
            P = nextAnggota(P);
        }
        if (info(P).nama == namaAnggota){
            return P;
        }else{
            return NULL;
        }
    }
}

void connectedFam(listTim &T, listAnggota &A){
    int N;int i = 0; string namaAnggota; string namaTim;
    string Back = "Tidak";

    while (Back != "Ya"){
        cout << "Nama Tim yang ingin dimasukkan: "; cin >> namaTim;
        adrTim P = findTim(T, namaTim);
        if (P != NULL) {
            cout << "Jumlah anggota yang ingin dimasukkan: "; cin >> N;
            while (N != 0){
                cout << "Nama anggota yang ingin dimasukkan: "; cin >> namaAnggota;
                adrAnggota Q = findAnggota(A, namaAnggota);
                if (Q!= NULL){
                    parent(Q) = P;
                    cout << "Anggota berhasil ditambahkan" << endl;
                    i++;
                } else {
                    cout << "Anggota gagal ditambahkan" << endl;
                }
                N--;
            }
            cout << "Kembali ke menu? (Ya/Tidak): "; cin >> Back;
        } else {
            cout << "Tim tidak ditemukan" << endl;
            cout << "Kembali ke menu? (Ya/Tidak): "; cin >> Back;
        }
        info(P).jumlahAnggota = i;
    }
    cout<<endl;

}

void printAll(listTim T,listAnggota A){
    adrTim P = firstTim(T);
    bool isEmpty = false;

    if (firstTim(T) != NULL){
        while(P != NULL){
            adrAnggota Q = firstAnggota(A);
            cout << "Nama Tim: " << info(P).nama << endl;
            cout << "Banyak Anggota: " << info(P).jumlahAnggota << endl;
            cout << "Anggota Tim: " << endl;
            int i = 1;
            while(Q != NULL){
                if(parent(Q) == P){
                    cout << i << "."<< info(Q).nama << endl;
                    isEmpty = true;
                    i++;
                }
                Q = nextAnggota(Q);
            }
            if (isEmpty == false){
                cout << "Anggota Tim kosong" << endl;
            }
            isEmpty = false;
            P = nextTim(P);
            cout << endl;
        }
    } else {
        cout<<"List Tim Kosong"<<endl;
    }

    cout<<endl;
}

void deleteTim(listTim &T,listAnggota &A){
    string namaTim;
    adrTim Q = firstTim(T);
    adrAnggota X = firstAnggota(A);

    cout << "Nama Tim yang ingin dihapus: "; cin >> namaTim;
    adrTim P = findTim(T, namaTim);
    if (P != NULL){
        if(P == firstTim(T)){
            firstTim(T) = nextTim(P);
            nextTim(P) = NULL;
        }else{
            while(nextTim(Q) != P){
                Q = nextTim(Q);
            }
            nextTim(Q) = nextTim(P);
            nextTim(P) = NULL;
        }
        while(nextAnggota(X) != NULL){
            if (parent(X) == P){
                parent(X) = NULL;
            }
            X = nextAnggota(X);
        }
        cout<<"Tim berhasil dihapus"<<endl;
    }else{
        cout<<"Tim tidak ditemukan"<<endl;
    }
    cout<<endl;
}

void deleteAnggota(listTim &T,listAnggota &A){
    string namaAnggota;
    adrAnggota Q = firstAnggota(A);
    cout << "Nama Anggota yang ingin dihapus: "; cin >> namaAnggota;
    adrAnggota P = findAnggota(A, namaAnggota);

    if (P != NULL){
        if(P == firstAnggota(A)){
            firstAnggota(A) = nextAnggota(P);
            nextAnggota(P) = NULL;
        }else{
            while(nextAnggota(Q) != P){
                Q = nextAnggota(Q);
            }
            nextAnggota(Q) = nextAnggota(P);
            nextAnggota(P) = NULL;
        }
        cout<<"Anggota berhasil dihapus"<<endl;
        adrTim X = parent(P);
        if (X != NULL){
            info(X).jumlahAnggota = info(X).jumlahAnggota - 1;
        }
    }else{
        cout<<"Anggota tidak ditemukan"<<endl;
    }
    cout<<endl;
}

void deleteAnggotadaritim(listTim &T,listAnggota &A){
    string namaAnggota;
    cout << "Nama Anggota yang ingin dihapus dari tim: "; cin >> namaAnggota;
    adrAnggota P = findAnggota(A, namaAnggota);

    if (P != NULL){
        adrTim X = parent(P);
        parent(P) = NULL;
        cout << "Anggota berhasil dihapus dari tim" << endl;
        if(X != NULL){
            info(X).jumlahAnggota = info(X).jumlahAnggota - 1 ;
        }
    } else {
        cout << "Anggota gagal dihapus dari tim" << endl;
    }
}

void printTimdanAnggota(listTim T,listAnggota A){
    adrTim P = firstTim(T);
    adrAnggota Q = firstAnggota(A);
    int jumlahTim = 0;
    int jumlahAnggota = 0;

    while(P != NULL){
        jumlahTim++;
        P = nextTim(P);
    }
    while(Q != NULL){
        jumlahAnggota++;
        Q = nextAnggota(Q);
    }
    cout<<"Jumlah Tim : "<<jumlahTim<<endl;
    cout<<"Jumlah Anggota : "<<jumlahAnggota<<endl;
    cout << endl;
}

void maxAnggota(listTim T,listAnggota A){
    int i = 1;
    adrTim P = firstTim(T);
    int Max = info(P).jumlahAnggota;

    while(P != NULL){
        if (info(P).jumlahAnggota > Max){
            Max = info(P).jumlahAnggota;
        }
        P = nextTim(P);
    }

    cout<<"Tim dengan anggota terbanyak: "<<endl;
    P = firstTim(T);
    while(P != NULL){
        if (info(P).jumlahAnggota == Max){
            cout<<i<<"."<<info(P).nama<<endl;
            i++;
        }
        P = nextTim(P);
    }
    cout<<"Banyak Anggota: "<<Max<<endl;
}

void minAnggota(listTim T, listAnggota A){
    int i = 1;
    adrTim P = firstTim(T);
    int Min = info(P).jumlahAnggota;

    while(P != NULL){
        if (info(P).jumlahAnggota < Min){
            Min = info(P).jumlahAnggota;
        }
        P = nextTim(P);
    }
    cout<<"Tim dengan anggota terdikit: "<<endl;

    P = firstTim(T);
    while(P != NULL){
        if (info(P).jumlahAnggota == Min){
            cout<<i<<"."<<info(P).nama<<endl;
            i++;
        }
        P = nextTim(P);
    }
    cout<<"Banyak Anggota: "<<Min<<endl;
}

char printMenu(){
    char input;
    cout << "============MENU============" << endl;
    cout << "1. Tambahkan tim, anggota, dan relasi baru" << endl;
    cout << "2. Cari tim dan anggota" << endl;
    cout << "3. Hapus tim, anggota, dan relasi" << endl;
    cout << "4. Tim dengan anggota terbanyak dan tersedikit" << endl;
    cout << "5. Tampilkan tim beserta pemainnya" << endl;
    cout << "6. Close program" << endl;
    cout << "Masukkan pilihan: "; cin>>input;
    cout<<endl;
    return input;
}
