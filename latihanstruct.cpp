#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Mendefinisikan struct untuk data mahasiswa
struct Mahasiswa {
    string nama;
    int usia;
    string jurusan;
};

int main() {
    vector<Mahasiswa> data_mahasiswa; // Mendeklarasikan vektor bertipe struct Mahasiswa

    char lanjut;
    do {
        Mahasiswa mhs;

        // Meminta pengguna untuk memasukkan data mahasiswa
        cout << "Masukkan Nama Mahasiswa: ";
        getline(cin, mhs.nama);

        cout << "Masukkan Usia Mahasiswa: ";
        cin >> mhs.usia;

        cin.ignore(); // Membersihkan newline dari buffer sebelumnya

        cout << "Masukkan Jurusan Mahasiswa: ";
        getline(cin, mhs.jurusan);

        data_mahasiswa.push_back(mhs); // Menambahkan data mahasiswa ke dalam vektor

        cout << "Ingin memasukkan data mahasiswa lagi? (y/n): ";
        cin >> lanjut;
        cin.ignore(); // Membersihkan newline dari buffer sebelumnya
    } while (lanjut == 'y' || lanjut == 'Y');

    // Menampilkan data yang telah dimasukkan
    cout << "\nData Mahasiswa:" << endl;
    for (const Mahasiswa& mhs : data_mahasiswa) {
        cout << "Nama: " << mhs.nama << endl;
        cout << "Usia: " << mhs.usia << endl;
        cout << "Jurusan: " << mhs.jurusan << endl << endl;
    }

    return 0;
}
