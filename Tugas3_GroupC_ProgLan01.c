#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"
#include <omp.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

Akun akun[MAX_ACCOUNTS];
int urutValid;

void displayAwal(){
    int inputAwal;
    printf(ANSI_COLOR_YELLOW "====" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED "====" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_MAGENTA "====" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "====" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW " PROYEK AKHIR KELOMPOK C " ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE "====" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_MAGENTA "====" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED "====" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "====\n" ANSI_COLOR_RESET);
    printf("1. Konversi Suhu\n");
    printf("2. Perkalian 1000\n");
    printf("3. Exit\n");
    printf("Masukkan Pilihan: ");
    scanf("%d", &inputAwal);
    switch (inputAwal){
        case 1:
            sesiGratis();
            break;
        case 2:
            perkalian();
            break;
        case 3:
            return 0;
            break;
        default:
            break;
    }
}

void sesiGratis(){
    // Menampilkan sesi gratis
    for (int i = 0; i < 3; i++) {
        system("cls");
        printf(ANSI_COLOR_BLUE "\n================ Sesi Gratis =================\n" ANSI_COLOR_RESET);
        konversiSuhu();
        system("pause");
        system("cls");
    }
}

void perkalian(){
    int bil1, bil2, t1, t2, i = 0, sum = 0;
    
    do
    {
        if (i > 0)
        {
            printf("Maaf Kedua Angka yang Anda Masukkan kurang dari 1000\n");
            system("pause");
        }
        system("cls");

        printf("\n======================================================\n");
        printf("||                  Perkalian 1000                    ||");
        printf("\n======================================================\n");
        printf("Masukkan bilangan Pertama: ");
        scanf("%d",&bil1);
        printf("Masukkan bilangan Kedua: ");
        scanf("%d",&bil2);
        i++;
    } while (bil1 < 1000 && bil2 < 1000);

    t1 = omp_get_wtime();
    #pragma omp parallel private(i)
    {
        #pragma omp for reduction (+: sum)
        for (i = 0; i < bil2; i++){sum += bil1;}
    }
    t2 = omp_get_wtime();
    printf("jumlah = %d. durasi = %f\n", sum , t2-t1);   
            

}

void displayJudul() {
    printf(ANSI_COLOR_YELLOW "====" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED "====" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_MAGENTA "====" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "====" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW " K" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE "O" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_MAGENTA "N" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED "V" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "E" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "R" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE "S" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_MAGENTA "I" ANSI_COLOR_RESET);
    printf(" ");
    printf(ANSI_COLOR_RED "S" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "U" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "H" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE "U" ANSI_COLOR_RESET);
    printf(" ");
    printf(ANSI_COLOR_BLUE "====" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_MAGENTA "====" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED "====" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "====\n" ANSI_COLOR_RESET);
}

void displayKonversi(){
    printf("||Satuan Awal Suhu                          ||\n");
    printf("||1. Celcius                                ||\n");
    printf("||2. Reamur                                 ||\n");
    printf("||3. Fahrenheit                             ||\n");
    printf("||4. Kelvin                                 ||\n");
    printf("||Masukkan 0 untuk kembali ke menu awal     ||\n");
    printf(ANSI_COLOR_CYAN "Masukkan Pilihan: " ANSI_COLOR_RESET);
}

void konversiSuhu() {
    int pilihan1, pilihan2;
    float suhuAwal, suhuAkhir;
    Suhu suhu[4];
    suhu[0].suhuAwal = 0;
    suhu[0].Ratio = 5;
    suhu[1].suhuAwal = 0;
    suhu[1].Ratio = 4;
    suhu[2].suhuAwal = 32;
    suhu[2].Ratio = 9;
    suhu[3].suhuAwal = 273.15;
    suhu[3].Ratio = 5;

    displayJudul();
    displayKonversi();
    scanf("%d", &pilihan1);

    if (pilihan1 == 0) {
        displayAwal();
    }
    printf("\n==============================================\n");
    displayKonversi();
    scanf("%d", &pilihan2);
    if(pilihan2 == 0) {
        displayAwal();
    }

    printf("\nMasukkan Suhu Awal: ");
    scanf("%f", &suhuAwal);
    
    suhuAkhir = (suhuAwal - suhu[pilihan1-1].suhuAwal) * suhu[pilihan2-1].Ratio / suhu[pilihan1-1].Ratio + suhu[pilihan2-1].suhuAwal;

    printf("\nSuhu Akhir: %0.2f\n", suhuAkhir);
    system("pause");
    system("cls");
}

void registrasiAkun(int *jumlahAkun) {
    char nama[100], password[100];
    FILE *file = fopen("akun.txt", "a");
    if (file == NULL) {
        printf(ANSI_COLOR_RED "Error opening file!\n" ANSI_COLOR_RESET);
        return;
    }

    printf("Masukkan Nama Akun: ");
    scanf("%s", nama);
    printf("Masukkan Password: ");
    scanf("%s", password);

    for (int i = 0; i < *jumlahAkun; i++) {
        if (strcmp(nama, akun[i].nama) == 0) {
            printf(ANSI_COLOR_RED "Akun sudah terdaftar!\n" ANSI_COLOR_RESET);
            system("pause");
            fclose(file);
            return;
        }
    }

    fprintf(file, "%s %s %d\n", nama, password, MAX_CREDITS);
    fclose(file);
    printf(ANSI_COLOR_GREEN "Registrasi berhasil!\n" ANSI_COLOR_RESET);
    system("pause");
    strcpy(akun[*jumlahAkun].nama, nama);
    strcpy(akun[*jumlahAkun].password, password);
    akun[*jumlahAkun].credits = MAX_CREDITS;
    (*jumlahAkun)++;
    system("pause");
    system("cls");
}

int loginAkun(int jumlahAkun) {
    char nama[100], password[100];
    printf(ANSI_COLOR_YELLOW "Username: " ANSI_COLOR_RESET);
    scanf("%s", nama);
    printf(ANSI_COLOR_YELLOW "Password: " ANSI_COLOR_RESET);
    scanf("%s", password);

    for (int i = 0; i < jumlahAkun; i++) {
        if (strcmp(nama, akun[i].nama) == 0 && strcmp(password, akun[i].password) == 0) {
            system("cls");
            printf(ANSI_COLOR_GREEN "Berhasil Masuk\n" ANSI_COLOR_RESET);
            urutValid = i;
            return 1;
        }
    }
    printf(ANSI_COLOR_RED "Akun belum terdaftar atau password salah\n" ANSI_COLOR_RESET);
    system("pause");
    return 0;
}

void logoutAkun(int *valid) {
    urutValid = 0;
    printf(ANSI_COLOR_GREEN "Berhasil Logout\n" ANSI_COLOR_RESET);
}

void redeemVoucher(char voucher[], char VoucherDatabase[MAX_VOUCHERS][100]) {
    for (int i = 0; i < MAX_VOUCHERS; i++) {
        if (strcmp(voucher, VoucherDatabase[i]) == 0) {
            akun[urutValid].credits++;
            printf(ANSI_COLOR_GREEN "Voucher Valid. Kredit Anda sekarang: %d\n" ANSI_COLOR_RESET, akun[urutValid].credits);
            return;
        }
    }
    printf(ANSI_COLOR_RED "Voucher Tidak Valid\n" ANSI_COLOR_RESET);
}

int main() {
    // Inisialisasi variabel
    int input, valid = 0, jumlahAkun = 0;
    char voucher[100];

    // Membuka file akun dan membaca data akun
    FILE *akunFile = fopen("akun.txt", "r");
    if (akunFile != NULL) {
        while (fscanf(akunFile, "%s %s %d", akun[jumlahAkun].nama, akun[jumlahAkun].password, &akun[jumlahAkun].credits) != EOF) {
            jumlahAkun++;
        }
        fclose(akunFile);
    }

    // Database voucher
    char VoucherDatabase[MAX_VOUCHERS][100] = { "SUHUGRATIS", "TEMPERATURGRATIS", "KONVERSIGRATIS"};

    displayAwal();

    // Loop sampai user berhasil login
    do {
        system("cls");
        printf(ANSI_COLOR_BLUE "\n========== Sesi Gratis Sudah Habis ===========\n" ANSI_COLOR_RESET);
        displayJudul();
        printf(ANSI_COLOR_YELLOW "Pilihan:\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "1. Registrasi\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "2. Login\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "Masukkan 0 untuk kmebali ke menu awal\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "Masukkan Pilihan: " ANSI_COLOR_RESET);
        scanf("%d", &input);
        
        // Proses input user
        switch (input) {
            case 1:
                registrasiAkun(&jumlahAkun);
                break;
            case 2:
                valid = loginAkun(jumlahAkun);
                break;
            default:
                printf(ANSI_COLOR_RED "Harap input dengan benar\n" ANSI_COLOR_RESET);
                break;
        }
    } while (valid == 0);

    // Jika login gagal, keluar dari program
    if (!valid) {
        return 0; 
    }

    // Menu utama
    do {
        displayJudul();
        printf(ANSI_COLOR_GREEN "Jumlah Kredit Anda : %d\n" ANSI_COLOR_RESET, akun[urutValid].credits);
        printf(ANSI_COLOR_CYAN "||Menu Pilihan                              ||\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_CYAN "----------------------------------------------\n" ANSI_COLOR_RESET);
        displayKonversi();
        scanf("%d", &input);
        system("cls");
                
        // Proses input user
        switch (input) {
            case 0:
                break;
            case 1:
                if (akun[urutValid].credits == 0) {
                    printf(ANSI_COLOR_RED "Kredit Anda telah habis. Silakan masukkan kode voucher untuk menambah kredit.\n" ANSI_COLOR_RESET);
                }
                else {
                    konversiSuhu();
                    akun[urutValid].credits--;
                }
                break;
            case 2:
                perkalian();
                break;
            case 3:
                printf(ANSI_COLOR_YELLOW "Masukkan Kode Voucher: " ANSI_COLOR_RESET);
                scanf("%s", voucher);
                redeemVoucher(voucher, VoucherDatabase);
                break;
            case 4:
                logoutAkun(&valid);
                break;
            default:
                printf(ANSI_COLOR_RED "Harap input dengan benar\n" ANSI_COLOR_RESET);
                break;
        }
    } while (input != 0);

    // Update file akun
    FILE *akunUpdate = fopen("akun.txt", "w");
    if (akunUpdate != NULL) {
        for (int i = 0; i < jumlahAkun; i++) {
            fprintf(akunUpdate, "%s %s %d\n", akun[i].nama, akun[i].password, akun[i].credits);
        }
        fclose(akunUpdate);
    } else {
        printf(ANSI_COLOR_RED "Error updating account file!\n" ANSI_COLOR_RESET);
    }

    return 0;
}
