#include <iostream>
#include <string>
#include <vector>

using namespace std;

// struct berisi judul buku, penulis buku dan tahun rilis buku
struct Buku {
  string judul;
  string penulis;
  int tahun;
};

// vector untuk menyimpan data buku
vector<Buku> koleksiBuku;

// fungsi untuk menambah buku
void tambahBuku(const string &judul, const string &penulis, const int &tahun) {
  Buku bukuBaru = {judul, penulis, tahun};
  koleksiBuku.push_back(bukuBaru);
  cout << "Buku Berhasil Disimpan! \n";
};

// fungsi untuk menampilkan semua buku
void tampilkanBuku() {
  // mengecek element di dalam vector koleksiBuku
  if (koleksiBuku.empty()) {
    cout << "Tidak ada buku dalam perpustakaan.\n";
    return;
  } // looping semua element di dalam vector koleksiBuku
  for (int i = 0; i < koleksiBuku.size(); ++i) {
    cout << "\n-----------------------\n";
    cout << "Buku " << i + 1 << ":\n";
    cout << "Judul   : " << koleksiBuku[i].judul << "\n";
    cout << "Penulis : " << koleksiBuku[i].penulis << "\n";
    cout << "Tahun   : " << koleksiBuku[i].tahun << "\n";
    cout << "------------------------\n";
  }
}

int main() {
  // variabel untuk menyimpan opsi pilihan user dan hasil input dari user
  int opsi, tahun;
  string judul, penulis;

  // looping untuk menampilkan semua opsi
  while (true) {
    cout << "\nProgram Pengelola Buku Perpustakaan\n";
    cout << "1. Tambah Buku\n";
    cout << "2. Tampilkan Semua Buku\n";
    cout << "3. Keluar\n";
    cout << "Pilih Opsi (1-5) : ";
    cin >> opsi; // mengambil input opsi user

    switch (opsi) {
    case 1:
      cout << "Masukan Judul Buku :";
      cin.ignore();
      getline(cin, judul);
      cout << "Masukan Penulis Buku :";
      getline(cin, penulis);
      cout << "Masukan Tahun Rilis Buku :";
      cin >> tahun;
      tambahBuku(judul, penulis, tahun);
      break;
    case 2:
      tampilkanBuku();
      break;
    case 3:
      return EXIT_SUCCESS;
    }
  }
};