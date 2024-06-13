// Gerardin Nabil Zulhian 2306250661
// Nelson Laurensius 2306161845
// Neyla Shakira 2306250655
// Nugroho Ulil Abshar 2306229310
// Rafi Naufal Aryaputra 2306250680
// Syahmi Hamdani  2306220532

#include <omp.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "Tugas3_GroupC_ProgLan01.h"

// ANSI color codes
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void MenuLogin(Akun *akun);
void showMenu(Akun *akun);

int main() {
    Akun *akun = (Akun*)malloc(sizeof(Akun));
    guideMenu();
    for (int i = 0; i < 3; i++) {
        konversiSuhu(i);
        system("pause");
        system("cls");
    }

    MenuLogin(akun);
    showMenu(akun);

    return 0;
}

void showMenu(Akun *akun) {
    int input = 0;
    char *menu[] = {
        "Konversi Suhu",
        "Perkalian Ribuan",
        "Buat & Input Voucher",
        "Profil Pengguna",
        "Keluar"
    };
    int menu_size = sizeof(menu) / sizeof(menu[0]);
    int current_selection = 0;

    while (1) {
        system("cls");
        printf("\n" ANSI_COLOR_GREEN "======================================================\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_GREEN "||                  Menu Pilihan                    ||\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_GREEN "======================================================\n" ANSI_COLOR_RESET);

        for (int i = 0; i < menu_size; i++) {
            if (i == current_selection) {
                printf(ANSI_COLOR_YELLOW "=> %s\n" ANSI_COLOR_RESET, menu[i]);
            } else {
                printf("   %s\n", menu[i]);
            }
        }

        int key = _getch();
        if (key == 224) {
            key = _getch();
            if (key == 72 && current_selection > 0) { // Up arrow
                current_selection--;
            } else if (key == 80 && current_selection < menu_size - 1) { // Down arrow
                current_selection++;
            }
        } else if (key == 13) { // Enter key
            input = current_selection;
            break;
        }
    }

    switch (input) {
    case 0:
        if (akun->point == 0) {
            printf(ANSI_COLOR_RED"Silahkan Kembali Ke Menu Utama Karena Point Anda Tidak Mencukupi\n"ANSI_COLOR_RESET);
            system("pause");
        } else {
            int i = 10;
            konversiSuhu(i);
            akun->point--;
            system("pause");
            system("cls");
        }
        break;

    case 1:
        if (akun->point == 0) {
            printf(ANSI_COLOR_RED"Silahkan Kembali Ke Menu Utama Karena Point Anda Tidak Mencukupi\n"ANSI_COLOR_RESET);
            system("pause");
        } else {
            Perkalian();
            akun->point--;
            system("pause");
            system("cls");
        }
        break;

    case 2:
        topUpVoucher("voucher.txt");
        system("pause");
        system("cls");

        char voucher[100];
        printf(ANSI_COLOR_BLUE"Masukkan Kode Voucher: "ANSI_COLOR_RESET);
        scanf("%s", voucher);
        int data = redeemVoucher("voucher.txt", voucher);
        if (data == 0) {
            printf(ANSI_COLOR_RED"Kode voucher yang Anda Masukkan Salah\n"ANSI_COLOR_RESET);
            getchar();
        } else {
            printf(ANSI_COLOR_GREEN"Kode yang anda masukkan berhasil\n"ANSI_COLOR_RESET);
            akun->point += data;
            getchar();
        }
        break;

    case 3:
        profil(*akun);
        system("cls");
        break;

    case 4:
        system("cls");
        printf(ANSI_COLOR_GREEN"Terima Kasih Sudah Menggunakan Aplikasi Kami.\n"ANSI_COLOR_RESET);
        updatePoint("akun.txt", akun);
        system("pause");
        exit(0);

    default:
        printf(ANSI_COLOR_RED"Harap input dengan benar\n"ANSI_COLOR_RESET);
        break;
    }

    showMenu(akun);
}
