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
#include "Tugas3_GroupC_ProgLan01.h"



int main(){
    int input, pilihan, valid = 0, urutValid;
    char nama[100], password[100],voucher[100];

    Akun *akun = (Akun*)malloc(sizeof(Akun));
    
    for (int i = 0; i < 3; i++)
    {
        printf("\n====================Sesi Gratis %d====================\n", i+1);
        konversiSuhu();
        system("pause");
        system("cls");
    }

    MenuLogin(akun);
    
    do
    {
        printf("\n======================================================\n");
        printf("||                  Menu Pilihan                     ||\n");
        printf("======================================================\n");
        printf("||1. Konversi Suhu                                   ||\n");
        printf("||2. Perkalian Ribuan                                ||\n");
        printf("||3. Buat & Input Voucher                            ||\n");
        printf("||4. Profil Pengguna                                 ||\n");
        printf("||0. Keluar                                          ||\n");
        printf("======================================================\n");
        printf("Masukkan Pilihan: ");
        scanf("%d", &input);
            
        switch (input)
        {
        case 0:
            printf("Terima Kasih Sudah Menggunakan Aplikasi Kami.\n");
            updatePoint("akun.txt", akun);
            system("pause");
            break;
        case 1:
            if(akun->point == 0){
                printf("Silahkan Kembali Ke Menu Utama Karena Point Anda Tidak Mencukupi\n");
                system("pause");
            }else{
                konversiSuhu();
                akun->point--;
                system("pause");
                system("cls");
            };
            break;
        
        case 2:
             if(akun->point == 0){
                printf("Silahkan Kembali Ke Menu Utama Karena Point Anda Tidak Mencukupi\n");
                system("pause");
            }else{
                Perkalian();
                akun->point--;
                system("pause");
                system("cls");
            };
            break;

        case 3:
            topUpVoucher("voucher.txt");
            system("pause");
            system("cls");

            printf("Masukkan Kode Voucher: ");
            scanf("%s", voucher);
            int data = redeemVoucher("voucher.txt",voucher);
            if (data == 0)
            {
                printf("Kode voucher yang Anda Masukkan Salah\n");
            } else{
                printf("Kode yang anda masukkan berhasil\n");
                akun->point += data;
            }
            break;

        case 4: 
            profil(*akun);
            system("cls");
            break;

        default:
            printf("Harap input dengan benar\n");
            break;
        }
    } while (input != 0);
}