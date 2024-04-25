#include <iostream>
using namespace std;

// Mendefinisikan struktur Node untuk representasi data mahasiswa
struct Node {
    int noMhs; //Nomor Mahasiswa
    string name; // Nama Mahasiswa
    Node* next; // pointer ke node berikutnya
};

//  Inisialisasi pointer START ke NULL
Node* START = NULL; 

// Fungsi untuk menambahkan node baru ke linked list
void addNode() {
    int nim; // Variabel untuk menyimpan NIM
    string nama;  // Variabel untuk menyimpan nama
    Node* nodeBaru = new Node(); // Membuat node baru
    cout << "Masukkan NIM: ";
    cin >> nim;
    cout << "Masukkan Nama: ";
    cin >> nama;
    nodeBaru->noMhs = nim; // Mengisi data NIM pada node baru
    nodeBaru->name = nama; // Mengisi data nama pada node baru
}

int main()
{
}