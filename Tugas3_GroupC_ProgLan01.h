#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct {
    char nama[100];
    char password[100];
    int point;
} Akun;

typedef struct {
    char Nama[100];
    float suhuAwal;
    int Ratio;
} Suhu;

// ANSI color codes
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void guideMenu(){
    system("cls");
    printf(ANSI_COLOR_BLUE "=============================================================\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE "||             " ANSI_COLOR_MAGENTA "PROYEK AKHIR PROGLAN KELOMPOK C" ANSI_COLOR_BLUE "             ||\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE "||               " ANSI_COLOR_MAGENTA "Panduan Penggunaan Program" ANSI_COLOR_BLUE "                ||\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE "=============================================================\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "1. Program memiliki fitur utama untuk mengkonversi suhu\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "2. Program memiliki fitur tambahan lainnya yaitu perkalian\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "   angka 1000 ke atas\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "3. User akan diberikan trial konversi suhu sebanyak 3 kali,\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "   dan setelahnya user harus mendaftarkan atau login akun\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "   untuk melakukan konversi suhu\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "4. Setiap kali user membuat akun, user akan mendapatkan 10\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "   point atau 10 kesempatan untuk menggunakan konversi suhu\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "5. User dapat membuat dan menukarkan voucher, satu kode\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "   voucher dapat ditukarkan dengan 10 point\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "6. Selamat menggunakan aplikasi kami !!!\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE "=============================================================\n" ANSI_COLOR_RESET);
    printf("\nTekan tombol apa saja untuk kembali ke menu utama...");
    _getch();
}

void konversiSuhu(int i) {
    int pilihan1 = 0, pilihan2 = 0;
    float suhuAwal, suhuAkhir;
    Suhu suhu[4];
    // Celcius
    suhu[0].suhuAwal = 0;
    suhu[0].Ratio = 5;
    strcpy(suhu[0].Nama, "Celcius");
    // Reamur
    suhu[1].suhuAwal = 0;
    suhu[1].Ratio = 4;
    strcpy(suhu[1].Nama, "Reamur");
    // Fahrenheit
    suhu[2].suhuAwal = 32;
    suhu[2].Ratio = 9;
    strcpy(suhu[2].Nama, "Fahrenheit");
    // Kelvin
    suhu[3].suhuAwal = 273.15;
    suhu[3].Ratio = 5;
    strcpy(suhu[3].Nama, "Kelvin");

    int current_selection = 0;

    while (1) {
        system("cls");
        if (i<3)
        {
            printf(ANSI_COLOR_GREEN "\n==================== Sesi Gratis %d ====================\n"ANSI_COLOR_RESET, i + 1);
        }

        printf(ANSI_COLOR_BLUE "=======================================================\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_BLUE "||                Satuan Awal Suhu                   ||\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_BLUE "=======================================================\n" ANSI_COLOR_RESET);
        for (int i = 0; i < 4; i++) {
            if (i == current_selection) {
                printf(ANSI_COLOR_YELLOW "=> %s\n" ANSI_COLOR_RESET, suhu[i].Nama);
            } else {
                printf("   %s\n", suhu[i].Nama);
            }
        }
        int key = _getch();
        if (key == 224) {
            key = _getch();
            if (key == 72 && current_selection > 0) { // Up arrow
                current_selection--;
            } else if (key == 80 && current_selection < 3) { // Down arrow
                current_selection++;
            }
        } else if (key == 13) { // Enter key
            pilihan1 = current_selection + 1;
            break;
        }
    }

    current_selection = 0;
    while (1) {
        system("cls");
        if (i<3)
        {
            printf(ANSI_COLOR_GREEN "\n==================== Sesi Gratis %d ====================\n"ANSI_COLOR_RESET, i + 1);
        }
        
        printf(ANSI_COLOR_MAGENTA "=======================================================\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_MAGENTA "||                Satuan AKhir Suhu                  ||\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_MAGENTA "=======================================================\n" ANSI_COLOR_RESET);
        for (int i = 0; i < 4; i++) {
            if (i == current_selection) {
                printf(ANSI_COLOR_YELLOW "=> %s\n" ANSI_COLOR_RESET, suhu[i].Nama);
            } else {
                printf("   %s\n", suhu[i].Nama);
            }
        }
        int key = _getch();
        if (key == 224) {
            key = _getch();
            if (key == 72 && current_selection > 0) { // Up arrow
                current_selection--;
            } else if (key == 80 && current_selection < 3) { // Down arrow
                current_selection++;
            }
        } else if (key == 13) { // Enter key
            pilihan2 = current_selection + 1;
            break;
        }
    }

    printf("\nMasukkan Suhu Awal: ");
    scanf("%f", &suhuAwal);

    suhuAkhir = (suhuAwal - suhu[pilihan1 - 1].suhuAwal) * suhu[pilihan2 - 1].Ratio / suhu[pilihan1 - 1].Ratio + suhu[pilihan2 - 1].suhuAwal;

    printf(ANSI_COLOR_YELLOW"Suhu Akhir dari %0.2f %s menjadi %s ="ANSI_COLOR_RESET ANSI_COLOR_GREEN" %0.2f\n" ANSI_COLOR_RESET, suhuAwal, suhu[pilihan1 - 1].Nama, suhu[pilihan2 - 1].Nama, suhuAkhir);
}

void Regis(const char *filename, Akun *akun) {
    FILE *fptr;
    fptr = fopen(filename, "r");
    int valid = 0, pointDatabase;
    char namaInput[100], passwordInput[100], namaDatabase[100], passwordDatabase[100];

    do {
        printf(ANSI_COLOR_YELLOW"\n=======================================================\n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW"||"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_RED"   Registration Mode (Hanya satu kata perisian)    "ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW"||\n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW"=======================================================\n"ANSI_COLOR_RESET);
        printf("Username: ");
        scanf("%s", namaInput);
        printf("Password: ");
        scanf("%s", passwordInput);

        while (fscanf(fptr, "%s %s %d", namaDatabase, passwordDatabase, &pointDatabase) != EOF) {
            if ((strcmp(namaDatabase, namaInput) == 0) && (strcmp(passwordDatabase, passwordInput) == 0)) {
                printf(ANSI_COLOR_RED"Username dan Password yang anda masukkan sudah digunakan. Mohon masukkan yang lain."ANSI_COLOR_RESET);
                valid = 1;
                system("pause");
            }
        }
    } while (valid == 1);

    fprintf(fptr, "%s %s %d\n", namaInput, passwordInput, 10);
    fclose(fptr);
    strcpy(akun->nama, namaInput);
    strcpy(akun->password, passwordInput);
    akun->point = 10;
}
void MenuLogin(Akun *akun);

void Login(Akun *akun, const char *filename) {
    int valid = 0, pointDatabase;
    char namaInput[100], passwordInput[100], namaDatabase[100], passwordDatabase[100];
    FILE *fptr;
    fptr = fopen(filename, "r");

    printf(ANSI_COLOR_YELLOW"\n=======================================================\n");
    printf(ANSI_COLOR_YELLOW"||       Login Mode (Hanya satu kata perisian)       ||\n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW"=======================================================\n"ANSI_COLOR_RESET);
    printf("Username: ");
    scanf("%s", namaInput);
    printf("Password: ");
    scanf("%s", passwordInput);

    while (fscanf(fptr, "%s %s %d", namaDatabase ,passwordDatabase, &pointDatabase)!=EOF)
    {
        if((strcmp(namaDatabase, namaInput) == 0)&&(strcmp(passwordDatabase, passwordInput)== 0)){
            strcpy(akun->nama,namaInput);
            strcpy(akun->password,passwordInput);
            akun->point = pointDatabase;
            valid = 1;
            printf(ANSI_COLOR_GREEN"Login Berhasil\n"ANSI_COLOR_RESET);
            system("pause");
            break;
        }
    }
    fclose(fptr);
    if (valid == 0)
    {
        printf("Nama yang Anda Masukkan Salah, Harap daftarkan akun anda\n");
        system("pause");
        system("cls");
        MenuLogin(akun);
    }
    
}

void MenuLogin(Akun *akun) {
    int MenuLogin = 0;
    int current_selection = 0;
    const char *menu[] = {"Registrasi", "Login"};
    int menu_size = sizeof(menu) / sizeof(menu[0]);

    while (1) {
        system("cls");
        printf(ANSI_COLOR_RED"\n=============== Sesi Gratis Sudah Habis ===============\n"ANSI_COLOR_RESET);
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
            MenuLogin = current_selection + 1;
            break;
        }
    }

    system("cls");
    if (MenuLogin == 1) {
        Regis("akun.txt", akun);
        system("cls");
    } else if (MenuLogin == 2) {
        Login(akun, "akun.txt");
        system("cls");
    } else {
        printf(ANSI_COLOR_RED"Masukkan Pilihan yang benar\n"ANSI_COLOR_RESET);
        system("pause");
    }
}

void generateVoucher(char *code, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    for (int i = 0; i < length; i++) {
        int index = rand() % (int)(sizeof(charset) - 1);
        code[i] = charset[index];
    }

    code[length] = '\0';
}

void topUpVoucher(const char *filename) {
    char code[21];
    generateVoucher(code, 20);
    printf("Code Voucher:"ANSI_COLOR_YELLOW" %s\n"ANSI_COLOR_RESET, code);

    FILE *fptr;

    fptr = fopen(filename, "a");
    fprintf(fptr, "%s\n", code);
    fclose(fptr);
    printf(ANSI_COLOR_GREEN"Voucher berhasil di buat. Silahkan Cek voucher.txt untuk kode voucher anda\n"ANSI_COLOR_RESET);
}

int redeemVoucher(const char *filename, const char *code) {
    int data, valid = 0;
    char dataCode[21];
    FILE *fptr;

    fptr = fopen(filename, "r");

    while (fscanf(fptr, "%s", dataCode) != EOF) {
        if (strcmp(dataCode, code) == 0) {
            printf(ANSI_COLOR_GREEN"Voucher berhasil di reedem\n"ANSI_COLOR_RESET);
            valid = 1;
            system("pause");
        }
        else {
            printf(ANSI_COLOR_RED"Kode voucher yang Anda masukkan salah\n"ANSI_COLOR_RESET);
            system("pause");
        }
    }

    fptr = fopen(filename, "w+");
    fclose(fptr);

    if (valid == 1) {
        return 10;
    } else {
        return 0;
    }
}

void profil(Akun akun) {
    system("cls");
    printf(ANSI_COLOR_GREEN"=======================================================\n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN"||                    Profil Anda                    ||\n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN"=======================================================\n"ANSI_COLOR_RESET);
    printf("Nama\t: "ANSI_COLOR_YELLOW"%s\n"ANSI_COLOR_RESET, akun.nama);
    printf("Password: "ANSI_COLOR_YELLOW"%s\n"ANSI_COLOR_RESET, akun.password);
    printf("Point\t: "ANSI_COLOR_YELLOW"%d\n"ANSI_COLOR_RESET, akun.point);
    system("pause");
}

void Perkalian() {
    int bil1, bil2, t1, t2, i = 0, sum = 0;

    do {
        if (i > 0) {
            printf(ANSI_COLOR_RED "Maaf Kedua Angka yang Anda Masukkan kurang dari 1000\n" ANSI_COLOR_RESET);
            system("pause");
        }
        system("cls");

        printf("\n" ANSI_COLOR_BLUE "======================================================\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_BLUE "||                 Perkalian 1000                   ||" ANSI_COLOR_RESET);
        printf("\n" ANSI_COLOR_BLUE "======================================================\n" ANSI_COLOR_RESET);
        printf("Masukkan bilangan Pertama: ");
        scanf("%d", &bil1);
        printf("Masukkan bilangan Kedua: ");
        scanf("%d", &bil2);
        i++;
    } while (bil1 < 1000 && bil2 < 1000);

    t1 = omp_get_wtime();
    #pragma omp parallel private(i)
    {
        #pragma omp for reduction(+:sum)
        for (i = 0; i < bil2; i++) { sum += bil1; }
    }
    t2 = omp_get_wtime();
    printf("jumlah = %d \ndurasi = %f\n", sum, t2 - t1);
}

//buat agar update poin menimpa data akun yang lama di akun.txt sehingga tidak terjadi duplikat
// void updatePoint(const char *filename, Akun *akun) {
//     FILE *file = fopen(filename, "w");

//     fprintf(file, "%s %s %d\n", akun->nama, akun->password, akun->point);

//     fclose(file);
// }
void updatePoint(const char *filename, Akun *akun) {
    FILE *inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error: Unable to create temporary file\n");
        fclose(inputFile);
        return;
    }

    char nama[100], password[100];
    int point;
    int found = 0;

    while (fscanf(inputFile, "%s %s %d", nama, password, &point) != EOF) {
        if (strcmp(nama, akun->nama) == 0) {
            fprintf(tempFile, "%s %s %d\n", akun->nama, akun->password, akun->point);
            found = 1;
        } else {
            fprintf(tempFile, "%s %s %d\n", nama, password, point);
        }
    }

    fclose(inputFile);

    if (!found) {
        fprintf(tempFile, "%s %s %d\n", akun->nama, akun->password, akun->point);
    }

    fclose(tempFile);

    remove(filename);

    rename("temp.txt", filename);
}

