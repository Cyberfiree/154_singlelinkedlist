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

// Fungsi untuk mencari apakah node dengan NIM tertentu ada dalam linked list
bool searchNode(int nim, Node* current, Node* previous) {
    previous = START;
    current = START;
    while (current != NULL && nim > current->noMhs)
    {
        previous = current;
        current = current->next;
    }
    if (current == NULL)
    {
        return false;
    }
    else if (current->noMhs == nim)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Fungsi untuk menghapus node dengan NIM tertentu dari linked list
bool deleteNode(int nim) {
    Node* current = START;
    Node* previous = START;
    if (searchNode(nim, previous, current) ==
        false)
        return false;
    previous->next = current->next;
    if (current == START)
        START = current->next;
    return true;
}

// Fungsi untuk memeriksa apakah linked list kosong
bool listEmpty() {
    if (START == NULL)
        return true;
    else
        return false;
}

// Fungsi untuk menelusuri dan mencetak seluruh data dalam linked list
void traverse() {
    if (listEmpty()) {
        cout << "List Kosong" << endl;
        system("pause");
        system("cls");
        return;
    }
    else {
        Node* currentNode = START;
        while (currentNode != NULL) {
            cout << "NIM: " << currentNode->noMhs << ", Nama: " << currentNode->name << endl;
            currentNode = currentNode->next;
        }
    }
}

// Fungsi untuk mencari dan menampilkan data mahasiswa berdasarkan NIM
void searchData() {
    if (listEmpty()) {
        cout << "List Kosong" << endl;
        system("pause");
        system("cls");
        return;
    }
    else {
        int nim;
        cout << "Masukkan NIM: ";
        cin >> nim;
        Node* currentNode = START;
        while (currentNode != NULL) {
            if (currentNode->noMhs == nim) {
                cout << "NIM: " << currentNode->noMhs << ", Nama: " << currentNode->name << endl;
                return;
            }
            currentNode = currentNode->next;
        }
        cout << "Data tidak ditemukan" << endl;
    }
}

// Fungsi utama program
int main()
{
    int pilihan;
    do
    {
        try
        {

            cout << "1. Tambah Data" << endl;
            cout << "2. Hapus Data" << endl;
            cout << "3. Tampilkan data" << endl;
            cout << "4. Cari Data" << endl;
            cout << "5. Keluar" << endl;
            cout << "Pilihan: ";
            cin >> pilihan;
            switch (pilihan)
            {
            case 1:
                addNode();
                cout << "Data Berhasil Ditambahkan" << endl;
                system("pause");
                system("cls");
                break;
            case 2:
                if (listEmpty())
                {
                    cout << "List kosong" << endl;
                    system("pause");
                    system("cls");
                    break;
                }

                int nim;
                cout << "Masukan NIM: ";
                cin >> nim;
                if (deleteNode(nim)) {
                    cout << "nim: " << nim << " berhasil dihapus" << endl;
                    system("pause");
                    system("cls");
                }
                else
                    cout << "Data tidak ditemukan" << endl;
                break;
            case 3:
                traverse();
                break;
            case 4:
                searchData();
                break;
            case 5:
                break;
            default:
                cout << "Pilihan tidak ada" << endl;
                break;
            }
        }
        catch (exception e)
        {
            cout << "Terjadi kesalahan" << endl;
        }

    } while (pilihan != 5);
}