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

    // Jika linked list masih kosong atau NIM baru kurang dari atau sama dengan NIM pada node pertama
    if (START == NULL || nim <= START->noMhs) {
        // Jika linked list tidak kosong dan NIM baru sama dengan NIM pada node pertama
        if (START != NULL && nim == START->noMhs)
        {
            cout << "NIM sudah ada" << endl;
            return;
        }
        // Menambahkan node baru di awal linked list
        nodeBaru->next = START;
        START = nodeBaru;
        return;
    }
    // Jika NIM baru lebih besar dari NIM pada node pertama
    Node* previous = START;
    Node* current = START;

    // Mencari posisi yang tepat untuk menyisipkan node baru
    while ((current != NULL) && (nim >= current->noMhs))
    {
        // Jika NIM baru sudah ada dalam linked list
        if (nim == current->noMhs)
        {
            cout << "NIM sudah ada" << endl;
            return;
        }
        previous = current;
        current = current->next;
    }
    // Menyisipkan node baru di posisi yang tepat
    nodeBaru->next = current;
    previous->next = nodeBaru;
}

int main()
{
}