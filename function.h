#ifndef FUNCTION_H
#define FUNCTION_H

#define MAX_ACCOUNTS 100
#define MAX_VOUCHERS 100
#define MAX_CREDITS 10

typedef struct {
    char nama[100];
    char password[100];
    int credits;
} Akun;

typedef struct {
    float suhuAwal;
    int Ratio;
} Suhu;

void konversiSuhu();
void registrasiAkun(int *jumlahAkun);
int loginAkun(int jumlahAkun);
void logoutAkun(int *valid);
void redeemVoucher(char voucher[], char VoucherDatabase[MAX_VOUCHERS][100]);
void perkalian();

#endif
