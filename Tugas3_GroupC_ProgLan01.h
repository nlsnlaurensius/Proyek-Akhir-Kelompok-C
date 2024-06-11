#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct 
{
    char nama[100];
    char password[100];
    int point;
}Akun;

typedef struct 
{
    char Nama[100];
    float suhuAwal;
    int Ratio;
}Suhu;


void konversiSuhu(){
    int pilihan1, pilihan2;
    float suhuAwal, suhuAkhir;
    Suhu suhu[4];
    //celcius
    suhu[0].suhuAwal = 0;
    suhu[0].Ratio = 5;
    strcpy(suhu[0].Nama,"Celcius");
    //reamur
    suhu[1].suhuAwal = 0;
    suhu[1].Ratio = 4;
    strcpy(suhu[1].Nama,"Reamur");
    //farenheit
    suhu[2].suhuAwal = 32;
    suhu[2].Ratio = 9;
    strcpy(suhu[2].Nama,"Farenheit");
    //kelvin
    suhu[3].suhuAwal = 273.15;
    suhu[3].Ratio = 5;
    strcpy(suhu[3].Nama,"Kelvin");
    do
    {
        printf("=======================================================\n");
        printf("||Satuan Awal Suhu                                   ||\n");
        printf("=======================================================\n");
        printf("||1. Celicus                                         ||\n");
        printf("||2. Reamur                                          ||\n");
        printf("||3. Farenheit                                       ||\n");
        printf("||4. Kelvin                                          ||\n");
        printf("=======================================================\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan1);
        system("cls");
    } while (pilihan1 > 4 || pilihan1 < 1);
    
    do
    {
        printf("=======================================================\n");
        printf("||Satuan Akhir Suhu                                  ||\n");
        printf("=======================================================\n");
        printf("||1. Celicus                                         ||\n");
        printf("||2. Reamur                                          ||\n");
        printf("||3. Farenheit                                       ||\n");
        printf("||4. Kelvin                                          ||\n");
        printf("=======================================================\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan2);
        system("cls");
    } while (pilihan2 > 4 || pilihan2 < 1);
    

    printf("Masukkan Suhu Awal: ");
    scanf("%f", &suhuAwal);
    
    suhuAkhir = suhuAkhir = (suhuAwal - suhu[pilihan1-1].suhuAwal) * suhu[pilihan2-1].Ratio / suhu[pilihan1-1].Ratio + suhu[pilihan2-1].suhuAwal;

    printf("Suhu Akhir dari %0.2f %s menjadi %s = %0.2f\n",suhuAwal, suhu[pilihan1].Nama, suhu[pilihan2].Nama, suhuAkhir);
}




//function untuk login
void Regis(const char *filename, Akun *akun){
    FILE *fptr;
    fptr = fopen(filename,"a");
    int valid = 0, pointDatabase;
    char namaInput[100], passwordInput[100], namaDatabase[100], passwordDatabase[100];

    do
    {
        printf("\n=======================================================\n");
        printf("||Registration Mode (Hanya satu kata perisian)       ||\n");
        printf("=======================================================\n");
        printf("Username: ");
        scanf("%s", namaInput );
        printf("Password: ");
        scanf("%s", passwordInput);

        while (fscanf(fptr, "%s %s %d", namaDatabase ,passwordDatabase, &pointDatabase)!=EOF)
        {
            if((strcmp(namaDatabase, namaInput) == 0)&&(strcmp(passwordDatabase, passwordInput)==0)){
                printf("Username dan Password yang anda masukkan sudah digunakan. Mohon masukkan yang lain.");
                valid = 1;
            }
        }
    } while (valid == 1);
    

    fprintf(fptr, "%s %s %d\n", namaInput,passwordInput, 10);
    fclose(fptr);
    strcpy(akun->nama, namaInput);
    strcpy(akun->password,passwordInput);
    akun->point = 10;
}
void MenuLogin(Akun *akun);

//function untuk Regis
void Login(Akun *akun, const char *filename){
    int valid = 0, pointDatabase;
    char namaInput[100], passwordInput[100], namaDatabase[100], passwordDatabase[100];
    FILE *fptr;
    fptr = fopen(filename, "r");

    
    printf("\n=======================================================\n");
    printf("||Login Mode (Hanya satu kata perisian)              ||\n");
    printf("=======================================================\n");
    printf("Username: ");
    scanf("%s", namaInput );
    printf("Password: ");
    scanf("%s", passwordInput);

    while (fscanf(fptr, "%s %s %d", namaDatabase ,passwordDatabase, &pointDatabase)!=EOF)
    {
        if((strcmp(namaDatabase, namaInput) == 0)&&(strcmp(passwordDatabase, passwordInput)== 0)){
            strcpy(akun->nama,namaInput);
            strcpy(akun->password,passwordInput);
            akun->point = pointDatabase;
            valid = 1;
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

void MenuLogin(Akun *akun){
    int MenuLogin;
    do
    {
        printf("\n===============Sesi Gratis Sudah Habis===============\n");
        printf("||1. Registrasi                                     ||\n");
        printf("||2. Login                                          ||\n");
        printf("=====================================================\n");
        printf("Masukkan Pilihan: ");
        scanf("%d", &MenuLogin);
        system("cls");
        if(MenuLogin == 1){
            Regis("akun.txt",akun);
            system("cls");
        }else if(MenuLogin == 2){
            Login(akun,"akun.txt");
            system("cls");
        }else{
            printf("Masukkan Pilihan yang benar\n");
        }
    } while ((MenuLogin != 1) && (MenuLogin != 2));
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
    printf("Code Voucher: %s\n", code);

    FILE *fptr;

    fptr = fopen(filename,"a");
    fprintf(fptr,"%s\n",code);
    fclose(fptr);
    printf("Voucher berhasil di buat. Silahkan Cek voucher.txt untuk kode voucher anda\n");
}

int redeemVoucher(const char *filename, const char *code) {
    int data,valid=0;
    char dataCode[21];
    FILE *fptr;
  
    fptr = fopen(filename, "r");

    while (fscanf(fptr, "%s", dataCode)!=EOF)
    {
        if(strcmp(dataCode, code) == 0){
            printf("Voucher berhasil di reedem");
            valid = 1;
        }
    }
    
    fptr = fopen(filename, "w+");
    fclose(fptr);

    if(valid == 1){
        return 10;
    }else{
        return 0;
    }
        
}

void profil(Akun akun){
    printf("Nama\t: %s\n",akun.nama);
    printf("Password: %s\n",akun.password);
    printf("Point\t: %d\n",akun.point);
    system("pause");
}

void Perkalian(){
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

void updatePoint(const char *filename, Akun *akun) {
    FILE *file = fopen(filename, "w");

    fprintf(file, "%s %s %d\n", akun->nama,akun->password, akun->point);

    fclose(file);
}