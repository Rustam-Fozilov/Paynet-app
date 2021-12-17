#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define T_SONI 2
float balance = 50000;


struct Payments{
    int code;
    char paymenttype[50];
    char phonenumber[13];
    float amount;
    char date[11];

}payments;

float getBalance(){
    return balance;
}

void addBalance(float extra){
    balance += extra;
    printf("Balance uchun %.2f summa qo'shildi.", extra);
}

void initPayments(struct Payments *pay[]){
                        SYSTEMTIME sana;
                        GetSystemTime(&sana);
                        char buffer[5];
                        char cDate[11] = "";
                        sprintf(buffer, "%d", sana.wDay);
                        strcat(cDate, buffer);
                        strcat(cDate, ".");
                        sprintf(buffer, "%d", sana.wMonth);
                        strcat(cDate, buffer);
                        strcat(cDate, ".");
                        sprintf(buffer, "%d", sana.wYear);
                        strcat(cDate, buffer);

    int i;
    for(i=0;i<T_SONI;i++){
    printf("kodni kiritng: \n");
    scanf("%d",pay[i]->code);
    printf("To'lov turi: \n");
    scanf("%s",pay[i]->paymenttype);
    printf("Telefon raqamni  kiritng: \n");
    scanf("%s",pay[i]->phonenumber);
    printf("to'lov miqdorini  kiritng: \n");
    scanf("%0.f",pay[i]->amount);
    strcpy(pay[i]->date, cDate);
    }
}

void printPayments(struct Payments payments[]){
    int j;
    for(j=0;j<T_SONI;j++){
        printf("%d \t %s---%s---%0.f---%s \n", payments[j].code, payments[j].paymenttype, payments[j].phonenumber, payments[j].amount, payments[j].date);
    }
}

void printMenu(){

    printf("*** PAYNET DASTURIGA HUSH KELIBSIZ *** \n");
    printf("\nDASTUR MENYUSI \n\n");
    printf("1. Dastur haqida \n");
    printf("2. Balansni ko'rish \n");
    printf("3. To'lovlar \n");
    printf("4. To'lovlar ro'yhati \n");
    printf("5. Balansni to'ldirish \n");
    printf("0. Dasturdan chiqish \n\n");
}

void programinfo(){

    printf("Dastur Mualifi: Rustam Fozilov \n");
    printf("Guruh: ISE-31U \n");
    printf("Id raqami: ISE20006 \n\n");
    printf("Bu dastur Mobil operatorlar uchun to'lovlarni amalga oshirish uchun ishlatiladi \n");
}

void balanceinfo(){
    printf("Abonent to'lovi: 35000 so'm\n");
    printf("Tarif turi: Zo'r\n");
    printf("Abonent to'lovi 1.05.2021 yechib olinadi\n");
    printf("tarif bo'yicha internet paket: 6000 mb\n");
    printf("tarif bo'yicha sms lar: 600 \n");
    printf("tarif bo'yicha daqiqalar: O'zbekiston bo'ylab cheksiz \n");
}

int main()
{
    char kod[6];
    int urunishlar_soni = 0;
    const int urunishlar = 3;
    int menunumber;
    int backmenu;
    struct Payments pay[T_SONI];

    while(1){
                        SYSTEMTIME sana;
                        GetSystemTime(&sana);
                        printf("Soat: %d:%d:%d\n", sana.wHour+5, sana.wMinute, sana.wSecond);
                        char buffer[5];
                        char cDate[11] = "";
                        sprintf(buffer, "%d", sana.wDay);
                        strcat(cDate, buffer);
                        strcat(cDate, ".");
                        sprintf(buffer, "%d", sana.wMonth);
                        strcat(cDate, buffer);
                        strcat(cDate, ".");
                        sprintf(buffer, "%d", sana.wYear);
                        strcat(cDate, buffer);
                        printf("Sana: %s\n\n",cDate);
    printf("Dasturga kirish uchun [12345] kodni kiriting: ");
    gets(kod);
    if(strcmp(kod, "12345") == 0){

        while(1){
                system("cls");

                printMenu();
                printf("MENYU RAQAMINI TANLANG: ");
                scanf("%d",&menunumber);
                switch(menunumber){
                case 1:
                    system("cls");
                    printf("DASTUR HAQIDA MENYUSI: \n\n");
                    programinfo();
                    printf("\nAsosiy menyuga qaytish uchun ixtiyoriy tugmani bosing: ");
                    getch();
                    break;
                case 2:
                    system("cls");
                    printf("BALANSNI KO'RISH MENYUSI: \n\n");
                    printf("Balance: %.2f\n", getBalance());
                    printf("\nAsosiy menyuga qaytish uchun ixtiyoriy tugmani bosing: ");
                    getch();
                    break;
                case 3:
                    printf("TO'LOVLAR MENYUSI \n");
                    int i;
                    for(i=0;i<T_SONI;i++){
                        printf("\n%d - Mijoz uchun malumotlarni kiriting!\n",i+1);
                        printf("kodni kiritng: ");
                        scanf("%d",&pay[i].code);
                        getchar();
                        printf("To'lov turi: ");
                        scanf("%s",pay[i].paymenttype);
                        printf("Telefon raqamni  kiritng: ");
                        scanf("%s",pay[i].phonenumber);
                        payment_point:
                        printf("to'lov miqdorini  kiritng: ");
                        scanf("%f",&pay[i].amount);
                        if(pay[i].amount <= balance)
                            balance = balance - pay[i].amount;
                        else{
                            printf("Mablag' yetarli emas\n");
                            goto payment_point;
                        }

                        strcpy(pay[i].date, cDate);
                    }

                    printf("\nAsosiy menyuga qaytish uchun ixtiyoriy tugmani bosing: ");
                    getch();
                    break;
                case 4:
                    printf("TO'LOVLARNI KO'RISH MENYUSI \n\n");
                    printPayments(pay);
                    printf("\nAsosiy menyuga qaytish uchun ixtiyoriy tugmani bosing: ");
                    getch();
                    break;
                case 5:
                    printf("BALANSNI TO'LDIRISH MENYUSI \n\n");
                    printf("Summa kiriting: ");
                    float extra;
                    scanf("%f",&extra);
                    addBalance(extra);
                    printf("\nAsosiy menyuga qaytish uchun ixtiyoriy tugmani bosing: ");
                    getch();
                    break;
                case 0:
                    printf("DASTUR TUGADI !!!");
                    exit(0);
                default:
                    printf("iltimos [0-4] oraliqda son kiriting !!!");
                    getch();
            }

        }


    }else{
        printf("parol xato kiritildi !!! \n");
        urunishlar_soni++;
        printf("Sizdagi qolgan urunishlar soni: %d\n", urunishlar-urunishlar_soni);
        if(urunishlar_soni == 3){
            printf("Siz tizimga kira olmadingiz :(");
            exit(0);
        }
    }

    }
    return 0;
}
