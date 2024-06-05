#include <iostream>

using namespace std;

// Structur Dasar Node
struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* n = NULL;
Node* head = NULL;
Node* tail = NULL;
Node* x = NULL;

//Membuat Node Baru
void BuatNodeBaru(int i) {
    n = new Node;
    n->data = i;
    n->prev = NULL;
    head = n;
    tail = n;
    tail->next = NULL;
}

//Menambah Node pda bagian belakang
void tambahDiBelakang(int i) {
    n = new Node;
    n->data = i;
    n->prev = tail;
    tail->next = n;
    tail = n;
    tail->next = NULL;
}

//Menambah Node pada bagian depan
void tambahDiDepan(int i) {
    n = new Node;
    n->data = i;
    n->next = head;
    head->prev = n;
    n->prev = NULL;
    head = n;
}

//Menambah Node pada bagian tengah
void tambahDiTengah(int i, int j) {
    x = head;
    while (x->data != j) x = x->next;
    n = new Node;
    n->data = i;
    n->next = x->next;
    if (x->next != NULL) {
        x->next->prev = n;
    }
    x->next = n;
    n->prev = x;
}

//Menghapus Node pada bagian depan
void hapusDiDepan() {
    x = head;
    head = x->next;
    head->prev = NULL;
    delete (x);
    x = NULL;
}

//Menghapus Node Pada bagian belakang
void hapusDiBelakang() {
    x = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete (x);
    x = NULL;
}

//Menghapus Node pada bagian tengah
void hapusDiTengah(int i) {
    x = head;
    while (x->data != i) {
        x = x->next;
    }
    if (x->prev != NULL) {
        x->prev->next = x->next;
    }
    if (x->next != NULL) {
        x->next->prev = x->prev;
    }
    delete (x);
    x = NULL;
}

// penggabungan penghapusan pada node
void hapusNode(int pos, int i = 0) {
    Node* x;
    if (pos == 1) { // Menghapus di bagian depan
        x = head;
        head = x->next;
        if (head != NULL)
            head->prev = NULL;
    } else if (pos == 2) { // Menghapus di bagian belakang
        x = tail;
        tail = tail->prev;
        if (tail != NULL)
            tail->next = NULL;
    } else if (pos == 3) { // Menghapus di bagian tengah
        x = head;
        while (x != NULL && x->data != i) {
            x = x->next;
        }
        if (x != NULL) {
            if (x->prev != NULL)
                x->prev->next = x->next;
            if (x->next != NULL)
                x->next->prev = x->prev;
        }
    } else {
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    if (x != NULL) {
        delete (x);
        x = NULL;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//Menampilkan Node pada bagia depan
void tampilDariDepan() {
    x = head;
    while (x != NULL) {
        cout << x->data << " ";
        x = x->next;
    }
    cout << endl;
}

//Menampilkan Node pada bagian belakang
void tampilDariBelakang() {
    x = tail;
    while (x != NULL) {
        cout << x->data << " ";
        x = x->prev;
    }
    cout << endl;
}

int main() {
    int i, j;
    int pilihan;

    do {
        cout << "Menu : " << endl;
        cout << "1. Buat Node Awal" << endl;
        cout << "2. Tambah Node" << endl;
        cout << "3. Tampilkan Node" << endl;
        cout << "4. Hapus Node" << endl;
        cout << "5. Keluar" << endl;
        cout << "=================" << endl;
        cout << "Masukkan Pilihan : ";
        cin >> pilihan;
        system("cls");

        if (pilihan == 1) {

            cout << "Buat Node Baru" << endl;
            cout << "==============" << endl;
            cout << "Masukkan Nilai : ";
            cin >> i;
            BuatNodeBaru(i);
            system("cls");
            cout << "Nilai " << i << " Berhasil Ditambahkan Di Node Awal" << endl << endl;
        }

        else if (pilihan == 2) {
            int pilihanTambah;
            cout << "1. Tambah Pada Posisi Depan" << endl;
            cout << "2. Tambah Pada Posisi Tengah" << endl;
            cout << "3. Tambah Pada Posisi Belakang" << endl;
            cout << "==============================" << endl;
            cout << "Masukkan Pilihan : ";
            cin >> pilihanTambah;
            system("cls");

            if (pilihanTambah == 1) {
                cout << "Penambahan Node Pada Posisi Depan" << endl;
                cout << "=================================" << endl;
                cout << "Masukkan Angka Yang Ingin Ditambahkan : ";
                cin >> i;
                tambahDiDepan(i);
                system("cls");
                cout << "Data " << i << " Berhasil Ditambahkan" << endl << endl;
            }

            else if (pilihanTambah == 2) {
                cout << "Penambahan Node Pada Posisi Tengah" << endl;
                cout << "=================================" << endl;
                cout << "Masukkan Angka Head Yang Akan Ditambahkan : ";
                cin >> i;
                cout << "Masukkan Nilai Yang Ada Ditengah  :  ";
                cin >> j;
                tambahDiTengah(i, j);
                system("cls");
                cout << "Data " << i << " Berhasil Ditambahkan Setelah " << j << endl << endl;
            }

            else if (pilihanTambah == 3) {;
                cout << "Penambahan Node Pada Posisi Belakang" << endl;
                cout << "=================================" << endl;
                cout << "Masukkan Angka Yang Ingin Ditambahkan : ";
                cin >> i;
                tambahDiBelakang(i);
                system("cls");
                cout << "Data " << i << " Berhasil Ditambahkan" << endl << endl;
            }
        }

        else if (pilihan == 3) {
            system("cls");

            int pilihanTampil;
            cout << "Menampilkan Node" << endl;
            cout << "================" << endl;
            cout << "1. Tampilkan Node Dari Depan" << endl;
            cout << "2. Tampilkan Node Dari Belakang" << endl;
            cout << "Masukkan Pilihan : ";
            cin >> pilihanTampil;
            system("cls");

            if (pilihanTampil == 1) {
                cout << "Menampilkan Node Dari Depan" << endl;
                cout << "==========================" << endl;
                tampilDariDepan();
                cout << endl;
            }

            else if (pilihanTampil == 2) {
                cout << "Menampilkan Node Dari Belakang" << endl;
                cout << "=============================" << endl;
                tampilDariBelakang();
                cout << endl;
            }
        }

        else if (pilihan == 4) {

            int pilihanHapus;
            cout << "Hapus Node" << endl;
            cout << "1. Penghapusan Node Pada Posisi Depan" << endl;
            cout << "2. Penghapusan Node Pada Posisi Tengah" << endl;
            cout << "3. Penghapusan Node Pada Posisi Belakang" << endl;
            cout << "4. Penghapusan Gabungan " << endl;
            cout << "====================================" << endl;
            cout << "Masukkan Pilihan : ";
            cin >> pilihanHapus;
            system("cls");

            if (pilihanHapus == 1) {
                hapusDiDepan();
                system("cls");
                cout << "Data Di Depan Berhasil Dihapus" << endl << endl;
            }

            else if (pilihanHapus == 2) {
                int dataHapus;
                cout << "Masukkan Data Yang Ingin Dihapus: ";
                cin >> dataHapus;
                hapusDiTengah(dataHapus);
                system("cls");
                cout << "Data " << dataHapus << " Berhasil Dihapus" << endl << endl;
            }

            else if (pilihanHapus == 3) {
                hapusDiBelakang();
                system("cls");
                cout << "Data Di Belakang Berhasil Dihapus" << endl << endl;
            }

            else if (pilihanHapus == 4) {
                cout << "masukkan data yang ingi dihapus" << endl;
                cin >> i;
                hapusNode(i);
                system("cls");
                cout << "Data " << i << " Berhasil Dihapus" << endl << endl;
            }
        }

    } while (pilihan != 5);
    
    cout << endl;
    cout << "Program Keluar";
    return 0;
}