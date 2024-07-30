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

// fungsi untuk mencari buku
void cariBuku(const string &judul) {
  // variabel untuk menunujukan buku ditemukan atau tidak
  bool ditemukan = false;
  // looping semua element di dalam vektor koleksi buku dan mencari berdasarkan
  // judul buku
  for (const auto &Buku : koleksiBuku) {
    // kondisi jika buku ditemukan akan ditampilkan di terminal
    if (Buku.judul == judul) {
      cout << "\n-----------------------\n";
      cout << "Buku ditemukan:\n";
      cout << "Judul  : " << Buku.judul << "\n";
      cout << "Penulis: " << Buku.penulis << "\n";
      cout << "Tahun  : " << Buku.tahun << "\n";
      cout << "-----------------------\n";

      ditemukan = true;
      break;
    }
  }
  // kondisi jika buku tidak ditemukan
  if (!ditemukan) {
    cout << "Buku dengan judul \"" << judul << "\" tidak ditemukan.\n";
  }
}

//fungsi untuk menghapus buku
void hapusBuku(const string& judul) {
  //looping melalui setiap buku dalam "koleksiBuku" menggunakan iterator
    for (auto it = koleksiBuku.begin(); it != koleksiBuku.end(); ++it) {
      //mengecek apakah judul buku cocok dengan judul yang akan dihapus
        if (it->judul == judul) {
          //menghapus buku dari "koleksiBuku"
            koleksiBuku.erase(it);
            cout << "Buku berhasil dihapus.\n";
            return;
        }
    }
    //jika tidak ditemukan, menampilkan pesan bahwa buku tidak ditemukan
    cout << "Buku dengan judul \"" << judul << "\" tidak ditemukan.\n";
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
    cout << "3. Cari Buku Sesuai Judul\n";
    cout << "4. Hapus Buku\n"
    cout << "5. Keluar\n";
    cout << "Pilih Opsi (1-5) : ";
    cin >> opsi; // mengambil input opsi user

    //menggunakan "switch" untuk memproses pilihan user
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
      cout << "Masukkan judul buku yang dicari: ";
      cin.ignore();
      getline(cin, judul);
      cariBuku(judul);
      break;
    case 4:
    cout << "Masukan judul buku yang ingin dihapus: ";
    cin.ignore();
    getline(cin, judul);
    hapusBuku(judul)
    break;
    case 5:
      return EXIT_SUCCESS;
    }
  }
};