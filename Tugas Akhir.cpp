//Tugas Akhir
using namespace std;
#include <iostream>
#include <map>
#include <vector>

struct ProdukModel
{
    string namaBarang;
    int hargaBarang;
};

struct PurchasedItem
{
    int id;
    string namaBarang;
    int hargaBarang;
    int jumlah;
    int totalHarga;
};

map<int, ProdukModel> daftarProduk = {
    {1, {"Aqua 600ml", 5000}}, 
    {2, {"Teh Botol Sosro 500ml", 6500}}, 
    {3, {"indomie goreng", 3500}}, 
    {4, {"Sarimi Ayam Bawang", 2500}}, 
    {5, {"Pop Mie Ayam", 5500}}, 
    {6, {"Susu UHT Ultra Milk 250ml", 6000}}, 
    {7, {"Kopi Kapal Api Special 65gr", 10000}}, 
    {8, {"Good Day Cappucino 3in1", 2000}},
    {9, {"Silverqueen Almond 58gr", 15000}},
    {10, {"Roma Malkist", 7000}},
    {11, {"Oreo 137gr", 13000}},
    {12, {"Lays Rumput Laut", 12000}},
    {13, {"Chitato Sapi Panggang", 15500}},
    {14, {"Sari Roti Coklat", 8000}},
    {15, {"FreshCare Minyak Angin", 17000}},
    {16, {"Tolak Angin Cair", 8500}},
    {17, {"Paracetamol 10 tablet", 4000}},
    {18, {"Biore Body Wash 450ml", 45000}},
    {19, {"Lifebuoy Hand Wash", 17000}},
    {20, {"Pepsodent 75gr", 12000}},
    {21, {"Sunsilk Shampoo 170ml", 23000}},
    {22, {"Downy Pewangi Pakaian 900ml", 35000}},
    {23, {"Rinso Detergen Bubuk 1kg", 20000}},
    {24, {"Baygon Aerosol 600ml", 40000}},
    {25, {"Sunlight Jeruk Nipis 750ml", 22500}},
    {26, {"Indomilk Susu Bubuk 400gr", 42000}},
    {27, {"Frisian Flag Gold 1L", 30000}},
    {28, {"Tropicana Slim Gula Diet", 50000}},
    {29, {"Blue Band Serbaguna 200gr", 17000}},
    {30, {"ABC Kecap Manis 600ml", 21000}},
    {31, {"Masako Ayam 100gr", 6500}},
    {32, {"Royco Sapi 100gr", 7000}},
    {33, {"Bumbu Racik Sayur Asem", 3500}},
    {34, {"Tepung Terigu Segitiga Biru 1kg", 14000}},
    {35, {"Tepung Beras Rose Brand 500gr", 8500}},
    {36, {"Gula Pasir Gulaku 1kg", 18000}},
    {37, {"Garam Refina 500gr", 5000}},
    {38, {"Minyak Goreng Bimoli 2L", 40000}},
    {39, {"Beras Setra Ramos 5kg", 70000}},
    {40, {"Beras Premium 5kg", 80000}},
    {41, {"Telur Ayam Ras 1kg", 32000}},
    {42, {"Ayam Potong 1kg", 38000}},
    {43, {"Sosis So Nice 10pcs", 25000}},
    {44, {"Nugget Fiesta 500gr", 45000}},
    {45, {"Es Krim Cornetto", 12000}},
    {46, {"Yakult 5 botol", 14000}},
    {47, {"Nutrijell Coklat 10gr", 5500}},
    {48, {"Roma Kelapa 300gr", 12000}},
    {49, {"Miwon MSG 500gr", 18000}},
    {50, {"Chiki Balls Keju", 10000}},
};

ProdukModel x = daftarProduk[1];

bool login()
{
    cout << "-------------------Menu Login-------------------" << endl;
    string username;
    string password;

    cout << "Masukan username anda : ";
    cin >> username;

    cout << "Masukan password anda : ";
    cin >> password;

    if (username == "admin" && password == "123456")
    {
        cout << "kamu berhasil login" << endl;
        return true;
    }
    else
    {
        cout << "Username atau password anda salah" << endl;
        return false;
    }
    return false;
}

void menuBelanja()
{
    vector<PurchasedItem> keranjang;
    int inputId;
    int jumlah;
    char lanjut;

    cout << "------------------------Menu Belanja------------------------" << endl;

    for (const auto &dataProduk : daftarProduk)
    {
        int id = dataProduk.first;
        ProdukModel barang = dataProduk.second;
        cout << "ID: " << id << " | Nama: " << barang.namaBarang << " | Harga: " << barang.hargaBarang << endl;
    }

    do
    {
        cout << endl;
        cout << "Masukkan ID Produk yang ingin dibeli: ";
        cin >> inputId;

        if (daftarProduk.find(inputId) != daftarProduk.end())
        {
            cout << "Masukkan jumlah: ";
            cin >> jumlah;

            ProdukModel barang = daftarProduk[inputId]; 
            cout << "barang : " << barang.namaBarang << endl;
            int totalHarga = barang.hargaBarang * jumlah;
            cout << "total harga : " << totalHarga << endl;

            keranjang.push_back({inputId, barang.namaBarang, barang.hargaBarang, jumlah, totalHarga});
            cout << "Produk ditambahkan ke keranjang.\n";
        }
        else
        {
            cout << "ID Produk tidak ditemukan.\n";
        }

        cout << "Ingin menambahkan produk lain? (y/n): ";
        cin >> lanjut;

    } while (lanjut == 'y' || lanjut == 'Y');
    
    system("cls");
    // Print receipt
    cout << "\n=================== Struk Belanja ===================\n";
    int grandTotal = 0;
    for (const auto &item : keranjang)
    {
        cout << "ID: " << item.id
             << " | Nama: " << item.namaBarang
             << " | Harga: " << item.hargaBarang
             << " | Jumlah: " << item.jumlah
             << " | Total: " << item.totalHarga << endl;
        grandTotal += item.totalHarga;
    }
    cout << "-----------------------------------------------------" << endl;
    cout << "Total Bayar: " << grandTotal << endl;
    cout << "=====================================================\n";
}

int uangDibayar 
cout << "Uang Bayar: " << endl;
cin >> uangDibayar

if (uangDibayar <= grandTotal){
    int kembalian = uangDibayar - grandTotal;
    cout << "kembalian" << endl;
}else {
    cout << "Uang Yang Dibayar Tidak cukup! Silahkan Transaksi Ulang";
}


int main()
{
    string x; 

    cout << x << "==========SELAMAT DATANG DI ULYA MART==========" << endl;

    bool isSuccessLogin = login();

    if (isSuccessLogin)
    {
        system("cls");
        menuBelanja();
    }
    else
    {
        cout << "Anda harus login terlebih dahulu" << endl;
    };

    return 0;
}
