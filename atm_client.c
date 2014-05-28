/* Bai tap giua ky mon Ngon Ngu C
Chuong trinh mo phong hoat dong may ATM
|=========================================|
|-- Chuong trinh Mo Phong Hoat Dong ATM --|
|---------| Copyright (c) 2014  |---------|
|------------| Author: SFT |--------------|
|---------| PIN Default: 123456 |---------|
|---------| Password: 557363 |------------|
|---------| PIN ID 001 (Test): 111111 |---|
|=========================================|*/
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

/* Struct INFO */
typedef struct
{
    char num[20];  /* so tai khoan */
    char pin[10];  /* ma PIN */
    char name[20]; /* ten chu tai khoan */
    long int balance; /* so du tai khoan */
    char  lasttime[30]; /* thoi diem giao dich lan cuoi */
    char notice[100];
    char status;
} INFO;

/* Protype */
void Excute();
void Run();
void Kill();
void Welcome();
void Flash();
void Processing();
void Printing();
void Cancel();
void Stage1();
int Stage2();
void Stage2_check(int h);
void Stage3();
void Stage3_check();
char Stage4();
void Stage4_check(int k);
void Goodbye();
int Withdraw_cash();
char Withdraw_printf();
long Amount_cash();
long Other_cash();
char Balance_printf();
int Balance_check();
char Backup_printf();
char Backup_check();
int Transfer_id(char id[10]);
int Transfer_money();
char Change_PIN();
int Readf(char id[10]);
INFO readFile(char id[10]);
void writeFile(char id[10], INFO temp);
void ReadLog(char id[10]);
void WriteLog(char id[10], INFO temp, long so, char key);
void Get_pass(char pw[10]);
void Get_time(char cur[30]);
void gotoxy(short x, short y);

/* Global variable */
char ID[3];

int main()
{
	Excute();
    Run();
    Kill();
    return (0);
}

void Excute()
{
    system("title ATM v1.0 by SFT");
    system("Color 0A");
    system("mode con: cols=54 lines=18");
	system("cls");
    printf("\nroot@atm:~#_ Excuting."); Sleep(200);
    printf(".");  Sleep(300);
    printf(".");  Sleep(300);
    printf(".");  Sleep(200);
    printf(".\n\n");
}

void Run()
{
    int temp1, temp2;
    do
    {
        Welcome();
        Stage1();
        Processing();
        temp1 = Stage2();
        Stage2_check(temp1);
        Stage3_check();
        temp2 = Stage4();
       	Stage4_check(temp2);
        Goodbye();
    }
    while (getch()!=27);
}

void Kill()
{
    FILE *f;
    char pass[20],pw[20];
    fflush(stdin);
    f = fopen("passwd","r+t");
    fscanf(f,"%[^\t\n]s",pw);
    fclose(f);
    system("cls");
    printf("\nroot@atm:~#_ ");
    Sleep(300);
    printf("\nroot@atm:~#_ Enter password: ");Get_pass(pass);
    if (strcmp(pass,pw)!=0)
       {
            printf("\nroot@atm:~#_ Failure ");
            Sleep(700); Run();  Kill();
       }
    else
    {
        printf("\nroot@atm:~#_ Successful ");
        Sleep(700);
        printf("\nroot@atm:~#_ Killing."); Sleep(200);
        printf(".");  Sleep(300);
        printf(".");  Sleep(300);
        printf(".");  Sleep(200);
        printf(".\n\n");
    }
}

void Welcome()
{
    char flag=0;
    system("cls");
    while (!_kbhit())
    {
		Flash();
	}
	//while (!_kbhit());
	getch();
}

void Flash()
{
    gotoxy(0,0);
    printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
	printf("\nบ                                                   บ");
	printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
	printf("\nบ                                                   บ");
	printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
	printf("\nบ                                                   บ");
	printf("\nบ                                                   บ");
    printf("\nบ               CHAO MUNG QUY KHACH                 บ");
	printf("\nบ                                                   บ");
	printf("\nบ            DEN VOI DICH VU ATM 24/24              บ");
	printf("\nบ                                                   บ");
	printf("\nบ                                                   บ");
	printf("\nบ                                                   บ");
	printf("\nบ        Chia se co hoi - Hop tac thanh cong        บ");
	printf("\nบ                                                   บ");
	printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
    Sleep(1700);
    Sleep(200);
    gotoxy(0,7);
    printf("\nบ                                                   บ");
	printf("\nบ                                                   บ");
	printf("\nบ                                                   บ");
    Sleep(200);
    gotoxy(0,7);
    printf("\nบ               C                                   บ");
	printf("\nบ                                                   บ");
	printf("\nบ                                    4              บ");
    Sleep(200);
    gotoxy(0,7);
    printf("\nบ               CH                                  บ");
	printf("\nบ                                                   บ");
	printf("\nบ                                   24              บ");
    Sleep(200);
    gotoxy(0,7);
    printf("\nบ               CHA                                 บ");
	printf("\nบ                                                   บ");
	printf("\nบ                                  /24              บ");
    Sleep(200);
    gotoxy(0,7);
    printf("\nบ               CHAO                                บ");
	printf("\nบ                                                   บ");
	printf("\nบ                                 4/24              บ");
    Sleep(200);
    gotoxy(0,7);
    printf("\nบ               CHAO M                              บ");
	printf("\nบ                                                   บ");
	printf("\nบ                                24/24              บ");
    Sleep(200);
    gotoxy(0,7);
    printf("\nบ               CHAO MU                             บ");
	printf("\nบ                                                   บ");
	printf("\nบ                                24/24              บ");
    Sleep(200);
    gotoxy(0,7);
    printf("\nบ               CHAO MUN                            บ");
	printf("\nบ                                                   บ");
	printf("\nบ                              M 24/24              บ");
    Sleep(200);
    gotoxy(0,7);
    printf("\nบ               CHAO MUNG                           บ");
	printf("\nบ                                                   บ");
	printf("\nบ                             TM 24/24              บ");
    Sleep(200);
    gotoxy(0,7);
    printf("\nบ               CHAO MUNG Q                         บ");
	printf("\nบ                                                   บ");
	printf("\nบ                            ATM 24/24              บ");
    Sleep(200);
    gotoxy(0,7);
    printf("\nบ               CHAO MUNG QU                        บ");
	printf("\nบ                                                   บ");
	printf("\nบ                          U ATM 24/24              บ");
    Sleep(200);
    gotoxy(0,7);
    printf("\nบ               CHAO MUNG QUY                       บ");
	printf("\nบ                                                   บ");
	printf("\nบ                         VU ATM 24/24              บ");
    Sleep(200);
    gotoxy(0,7);
    printf("\nบ               CHAO MUNG QUY K                     บ");
	printf("\nบ                                                   บ");
	printf("\nบ                       H VU ATM 24/24              บ");
    Sleep(200);
    gotoxy(0,7);
    printf("\nบ               CHAO MUNG QUY KH                    บ");
	printf("\nบ                                                   บ");
	printf("\nบ                      CH VU ATM 24/24              บ");
    Sleep(200);
    gotoxy(0,7);
    printf("\nบ               CHAO MUNG QUY KHA                   บ");
	printf("\nบ                                                   บ");
	printf("\nบ                     ICH VU ATM 24/24              บ");
    Sleep(200);
    gotoxy(0,7);
    printf("\nบ               CHAO MUNG QUY KHAC                  บ");
	printf("\nบ                                                   บ");
	printf("\nบ                    DICH VU ATM 24/24              บ");
    Sleep(200);
    gotoxy(0,7);
    printf("\nบ               CHAO MUNG QUY KHACH                 บ");
	printf("\nบ                                                   บ");
	printf("\nบ                  I DICH VU ATM 24/24              บ");
    Sleep(200);
    gotoxy(0,7);
    printf("\nบ               CHAO MUNG QUY KHACH                 บ");
	printf("\nบ                                                   บ");
	printf("\nบ                 OI DICH VU ATM 24/24              บ");
 	Sleep(200);
    gotoxy(0,7);
    printf("\nบ               CHAO MUNG QUY KHACH                 บ");
	printf("\nบ                                                   บ");
	printf("\nบ                VOI DICH VU ATM 24/24              บ");
 	Sleep(100);
    gotoxy(0,7);
    printf("\nบ               CHAO MUNG QUY KHACH                 บ");
	printf("\nบ                                                   บ");
	printf("\nบ              N VOI DICH VU ATM 24/24              บ");
    Sleep(100);
    gotoxy(0,7);
    printf("\nบ               CHAO MUNG QUY KHACH                 บ");
	printf("\nบ                                                   บ");
	printf("\nบ             EN VOI DICH VU ATM 24/24              บ");
    Sleep(100);
    gotoxy(0,7);
    printf("\nบ               CHAO MUNG QUY KHACH                 บ");
	printf("\nบ                                                   บ");
	printf("\nบ            DEN VOI DICH VU ATM 24/24              บ");
	gotoxy(34,11);
}

void Processing()
{
    system("cls");   fflush(stdin);
    printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
    printf("\nบ                                                   บ");
    printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
    printf("\nบ                                                   บ");
    printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
    printf("\nบ                                                   บ");
    printf("\nบ                                                   บ");
    printf("\nบ             VUI LONG DOI GIAY LAT                 บ");
    printf("\nบ                                                   บ");
    printf("\nบ              DANG XU LY.                          บ");
    printf("\nบ                                                   บ");
    printf("\nบ                                                   บ");
    printf("\nบ                                                   บ");
    printf("\nบ                                                   บ");
    printf("\nบ                                                   บ");
    printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
    Sleep(100);
    gotoxy(0,10);
    printf("บ              DANG XU LY..                         บ");
    Sleep(200);
    gotoxy(0,10);
    printf("บ              DANG XU LY...                        บ");
    Sleep(200);
    gotoxy(0,10);
    printf("บ              DANG XU LY....                       บ");
    Sleep(200);
    gotoxy(0,10);
	printf("บ              DANG XU LY.....                      บ");
    Sleep(200);
}

void Printing()
{
    system("cls");   fflush(stdin);
    printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
    printf("\nบ                                                   บ");
    printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
    printf("\nบ                                                   บ");
    printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
    printf("\nบ                                                   บ");
    printf("\nบ                                                   บ");
    printf("\nบ             VUI LONG DOI GIAY LAT                 บ");
    printf("\nบ                                                   บ");
    printf("\nบ            DANG IN HOA DON.                       บ");
    printf("\nบ                                                   บ");
    printf("\nบ                                                   บ");
    printf("\nบ                                                   บ");
    printf("\nบ                                                   บ");
    printf("\nบ                                                   บ");
    printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
    Sleep(300);
    gotoxy(0,10);
    printf("บ            DANG IN HOA DON..                      บ");
    Sleep(400);
    gotoxy(0,10);
    printf("บ            DANG IN HOA DON...                     บ");
    Sleep(400);
    gotoxy(0,10);
    printf("บ            DANG IN HOA DON....                    บ");
    Sleep(400);
    gotoxy(0,10);
    printf("บ            DANG IN HOA DON.....                   บ");
    Sleep(400);
}

void Cancel()
{
            system("cls");   fflush(stdin);
            printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
            printf("\nบ                                                   บ");
            printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
            printf("\nบ                                                   บ");
            printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
            printf("\nบ                                                   บ");
            printf("\nบ                GIAO DICH BI HUY BO                บ");
            printf("\nบ                                                   บ");
            printf("\nบ   BAN CO MUON THUC HIEN GIAO DICH KHAC KHONG ?    บ");
            printf("\nบ                               ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
            printf("\nบ                               ณ 1 ณ Co          ณ บ");
            printf("\nบ                               ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
            printf("\nบ                               ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
            printf("\nบ                               ณ 2 ณ Khong       ณ บ");
            printf("\nบ                               ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
            printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
            gotoxy(0,17);
}

void Stage1()
{
    char id[10];
    do
    {
        system("cls");   fflush(stdin);
        printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
        printf("\nบ                                                   บ");
        printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
        printf("\nบ                                                   บ");
        printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
        printf("\nบ                                                   บ");
        printf("\nบ               PLEASE INSERT YOUR CARD             บ");
        printf("\nบ                                                   บ");
        printf("\nบ               VUI LONG DUA THE VAO...             บ");
        printf("\nบ                                                   บ");
        printf("\nบ              ID [001-100] :  ฑฑฑฑฑฑฑฑฑ            บ");
        printf("\nบ                                                   บ");
        printf("\nบ                                                   บ");
        printf("\nบ         Vui long nhap chinh xac 3 chu so ID       บ");
        printf("\nบ                                                   บ");
        printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
        gotoxy(34,11);  gets(id);  fflush(stdin);
        if (Readf(id)==2)
        {
            gotoxy(0,14);
            printf("บ   The nay da bi khoa. Nhan Enter de nhap lai...   บ");
            getch();
            gotoxy(0,14);
            printf("บ         Vui long nhap chinh xac 3 chu so ID       บ");
            gotoxy(0,11);
            printf("บ              ID [001-100] :  ฑฑฑฑฑฑฑฑฑ            บ");
        }
        else if (Readf(id)==1)
            {
                strcpy(ID,id);
                gotoxy(0,14);
                printf("บ         The hop le. Nhan Enter de tiep tuc...     บ");
                gotoxy(0,17);
                getch();
            }
        else
            {
                gotoxy(0,14);
                printf("บ     The khong hop le. Nhan Enter de nhap lai...   บ");
                getch();
                gotoxy(0,14);
                printf("บ         Vui long nhap chinh xac 3 chu so ID       บ");
                gotoxy(0,11);
                printf("บ              ID [001-100] :  ฑฑฑฑฑฑฑฑฑ            บ");
            }
    }
	while (Readf(id)!=1);
}

int Stage2()
{
    INFO temp;
    char chon,flag=0,flag2=0;
    do
    {
        temp = readFile(ID);
        while (strlen(temp.name)<27)
        {
            strcat(temp.name," ");
        }
        system("cls");   fflush(stdin);
        printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
        printf("\nบ                                                   บ");
        printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
        printf("\nบ                                                   บ");
        printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
        printf("\nบ   Welcome - Xin chao, %s บ",temp.name);
        printf("\nบ                                                   บ");
        printf("\nบ             Please select language                บ");
        printf("\nบ            XIN VUI LONG CHON NGON NGU             บ");
        printf("\nบ ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ                               บ");
        printf("\nบ ณ 1 ณ Tieng Viet  ณ                               บ");
        printf("\nบ ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู                               บ");
        printf("\nบ ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ                               บ");
        printf("\nบ ณ 2 ณ English     ณ                               บ");
        printf("\nบ ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู                               บ");
        printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
        gotoxy(0,17);
        switch (getch())
        {
            case 49:
                fflush(stdin);
                flag=1;
                gotoxy(0,10);
                printf("บ ษอออหอออออออออออออป                               บ");
                printf("\nบ บ 1 บ Tieng Viet  บ                               บ");
                printf("\nบ ศอออสอออออออออออออผ                               บ");
                gotoxy(0,17);
                if (getch()==13)
                {
                    flag2 = 1;
                    return(flag);
                }
                break;
            case 50:
                fflush(stdin);
                flag=2;
                gotoxy(0,13);
                printf("บ ษอออหอออออออออออออป                               บ");
                printf("\nบ บ 2 บ English     บ                               บ");
                printf("\nบ ศอออสอออออออออออออผ                               บ");
                gotoxy(0,17);
                if (getch()==13)
                    return(flag);
                break;
        }
    }
	while (flag2!=1);
	return(flag);
}

void Stage2_check(int k)
{
    int h;
    switch (k)
    {
        case 2:
            system("cls");
            printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
            printf("\nบ                                                   บ");
            printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
            printf("\nบ                                                   บ");
            printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
            printf("\nบ                                                   บ");
            printf("\nบ                                                   บ");
            printf("\nบ            THIS FEATER IS BEING BUILT             บ");
            printf("\nบ                                                   บ");
            printf("\nบ             TINH NANG DANG XAY DUNG               บ");
            printf("\nบ                                                   บ");
            printf("\nบ                                                   บ");
            printf("\nบ                                                   บ");
            printf("\nบ             Press Enter to return...              บ");
            printf("\nบ             Nhan Enter de tro ve ...              บ");
            printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
            getch();
            h = Stage2();
            Stage2_check(h);
            break;
        case 1: Stage3(); break;
    }
}

void Stage3()
{
    INFO temp;
    char pass[10],flag=0;
    do
    {
        temp = readFile(ID);
        system("cls");   fflush(stdin);
        printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
        printf("\nบ                                                   บ");
        printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
        printf("\nบ                                                   บ");
        printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
        printf("\nบ                                                   บ");
        printf("\nบ                                                   บ");
        printf("\nบ                                                   บ");
        printf("\nบ                VUI LONG NHAP SO PIN               บ");
        printf("\nบ                                                   บ");
        printf("\nบ                 ฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑ                บ");
        printf("\nบ                                                   บ");
        printf("\nบ                                                   บ");
        printf("\nบ          Vui long nhap chinh xac 6 so PIN         บ");
        printf("\nบ                                                   บ");
        printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
        gotoxy(24,11);  Get_pass(pass);  fflush(stdin);
        if (strcmp(pass,temp.pin)==0)
        {
            flag=5;
            gotoxy(0,14);
            printf("บ         So PIN dung. Nhan Enter de tiep tuc...    บ");
            gotoxy(0,17);
            getch();
            Processing();
        }
        else
        {
            flag+=1;
            gotoxy(0,14);
            printf("บ     So PIN khong dung. Nhan Enter de nhap lai...  บ");
            getch();
            gotoxy(0,14);
            printf("บ          Vui long nhap chinh xac 6 so PIN         บ");
            gotoxy(0,11);
            printf("บ                 ฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑ                บ");
            if (flag==5)
            {
                temp.status=2;
                writeFile(ID,temp);
                gotoxy(0,14);
                printf("บ   Ban da nhap sai 5 lan. Tai khoan da bi khoa...  บ");
                gotoxy(0,17);
                getch();
                Goodbye();
                if (getch()==27)
                {
                    Kill();
                }
                else
                {
					Run();  Kill();
                }
            }
        }
    }
	while (flag!=5);
}

void Stage3_check()
{
    FILE *f;
    INFO temp;
    temp = readFile(ID);
    char kk,tt;
    if (strlen(temp.notice)>14)
    {
        while (strlen(temp.notice)<47)
            strcat(temp.notice," ");
        system("cls");
        printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
        printf("\nบ                                                   บ");
        printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
        printf("\nบ                                                   บ");
        printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
        printf("\nบ                                                   บ");
        printf("\nบ                                                   บ");
        printf("\nบ             BAN CO MOT THONG BAO MOI              บ");
        printf("\nบ                                                   บ");
        printf("\nบ    %sบ",temp.notice);
        printf("\nบ                                                   บ");
        printf("\nบ                                                   บ");
        printf("\nบ                                                   บ");
        printf("\nบ              Nhan Enter de tiep tuc...            บ");
        printf("\nบ                                                   บ");
        printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
        getch();
        strcpy(temp.notice," ");
        writeFile(ID,temp);
    }
    if (strcmp(temp.pin,"123456")==0)
    {

        kk = Change_PIN();
        if (kk==2)
            {
                Goodbye(); Run(); Kill();
            }
            else return;
    }
}

char Stage4()
{
    INFO temp;
    char chon,flag=0;
    do
    {
        temp = readFile(ID);
        while (strlen(temp.name)<37)
        {
            strcat(temp.name," ");
        }
        system("cls");   fflush(stdin);
        printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
        printf("\nบ                                                   บ");
        printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
        printf("\nบ                                                   บ");
        printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
        printf("\nบ          XIN VUI LONG LUA CHON GIAO DICH          บ");
        printf("\nบ ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ          ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
        printf("\nบ ณ 1 ณ Rut tien    ณ          ณ 4 ณ Doi Pin      ณ บ");
        printf("\nบ ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู          ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
        printf("\nบ ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ          ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
        printf("\nบ ณ 2 ณ Xem so du   ณ          ณ 5 ณ Chuyen khoan ณ บ");
        printf("\nบ ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู          ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
        printf("\nบ ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ                               บ");
        printf("\nบ ณ 3 ณ Sao ke TK   ณ          [-Nhan SO. Enter   ] บ");
        printf("\nบ ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู          [-Nhan ESC de thoat] บ");
        printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
        gotoxy(0,17);
        switch (getch())
        {
            case 49:
                fflush(stdin);
                flag=1;
                gotoxy(0,7);
                printf("บ ษอออหอออออออออออออป          ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
                printf("\nบ บ 1 บ Rut tien    บ          ณ 4 ณ Doi Pin      ณ บ");
                printf("\nบ ศอออสอออออออออออออผ          ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
                gotoxy(0,17);
                if (getch()==13)
                    return(flag);
                break;
            case 50:
                fflush(stdin);
                flag=2;
                gotoxy(0,10);
                printf("บ ษอออหอออออออออออออป          ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
                printf("\nบ บ 2 บ Xem so du   บ          ณ 5 ณ Chuyen khoan ณ บ");
                printf("\nบ ศอออสอออออออออออออผ          ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
                gotoxy(0,17);
                if (getch()==13)
                    return(flag);
                break;
            case 51:
                fflush(stdin);
                flag=3;
                gotoxy(0,13);
                printf("บ ษอออหอออออออออออออป                               บ");
                printf("\nบ บ 3 บ Sao ke TK   บ          [-Nhan SO. Enter   ] บ");
                printf("\nบ ศอออสอออออออออออออผ          [-Nhan ESC de thoat] บ");
                gotoxy(0,17);
                if (getch()==13)
                    return(flag);
                break;
            case 52:
                fflush(stdin);
                flag=4;
                gotoxy(0,7);
                printf("บ ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ          ษอออหออออออออออออออป บ");
                printf("\nบ ณ 1 ณ Rut tien    ณ          บ 4 บ Doi Pin      บ บ");
                printf("\nบ ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู          ศอออสออออออออออออออผ บ");
                gotoxy(0,17);
                if (getch()==13)
                    return(flag);
                break;
            case 53:
                fflush(stdin);
                flag=5;
                gotoxy(0,10);
                printf("บ ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ          ษอออหออออออออออออออป บ");
                printf("\nบ ณ 2 ณ Xem so du   ณ          บ 5 บ Chuyen khoan บ บ");
                printf("\nบ ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู          ศอออสออออออออออออออผ บ");
                gotoxy(0,17);
                if (getch()==13)
                    return(flag);
                break;
            case 27:
                /* Nhan ESC de thoat khoi menu */
                flag=6;
                break;
        }
    }
	while (flag!=6);
	return(flag);
}

void Stage4_check(int k)
{
    int kk,t;
    do
    {
        switch (k)
        {
            case 1: ;
                t = Withdraw_cash();
                if (t==1)
                {
                    kk = Stage4();  Stage4_check(kk);
                }
                k = 7;  break;
            case 2:
                t = Balance_check();
                if (t==1)
                {
                    kk = Stage4();  Stage4_check(kk);
                }
                k = 7;  break;
            case 3:
                if (Backup_check()==1)
                {
                    kk = Stage4();  Stage4_check(kk);
                }
                k = 7;  break;
            case 4:
                t = Change_PIN();
                if (t==1)
                {
                    kk = Stage4();  Stage4_check(kk);
                }
                k = 7;  break;
            case 5:
                t = Transfer_money();
                if (t==1)
                {
                    kk = Stage4();  Stage4_check(kk);
                }
                k = 7;  break;
            case 6: Goodbye(); k = 7; break;
        }
    }
    while (k!=7);
}

void Goodbye()
{
    system("cls");
    printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
	printf("\nบ                                                   บ");
	printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
	printf("\nบ                                                   บ");
	printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
	printf("\nบ                                                   บ");
	printf("\nบ                                                   บ");
	printf("\nบ               XIN CHAO VA HEN GAP LAI             บ");
	printf("\nบ                                                   บ");
	printf("\nบ                  CAM ON QUY KHACH                 บ");
	printf("\nบ                                                   บ");
	printf("\nบ                                                   บ");
	printf("\nบ        Chia se co hoi - Hop tac thanh cong        บ");
	printf("\nบ                                                   บ");
	printf("\nบ       Nhan ESC lan nua de tat chuong trinh !      บ");
	printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
}

long Other_cash()
{
    long money, flag=0;
    INFO temp;
    do
    {
        temp = readFile(ID);
        system("cls");   fflush(stdin);
        printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
        printf("\nบ                                                   บ");
        printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
        printf("\nบ                                                   บ");
        printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
        printf("\nบ                                                   บ");
        printf("\nบ               VUI LONG NHAP SO TIEN               บ");
        printf("\nบ                                                   บ");
        printf("\nบ                                                   บ");
        printf("\nบ                 ฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑ                 บ");
        printf("\nบ                                                   บ");
        printf("\nบ                                                   บ");
        printf("\nบ     Luu y: So tien phai la boi so cua 10.000      บ");
        printf("\nบ                                                   บ");
        printf("\nบ                (Nhan ESC de huy bo)               บ");
        printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
        gotoxy(20,10);  scanf("%ld",&money);  fflush(stdin);
        if (temp.balance-money<50000)
        {
            gotoxy(0,10);
            printf("บ                 ฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑ                 บ");
            gotoxy(0,14);
            printf("บ      So du khong du. Nhan Enter de nhap lai...    บ");
            gotoxy(0,17);
            if (getch()==27)
            {
                flag = 1;
                money = 0;
            }
        }
        else if ((money%10000==0)&&(temp.balance-money>=50000)&&(money>=10000))
            {
                gotoxy(0,14);
                printf("บ      So tien hop le. Nhan Enter de tiep tuc...    บ");
                gotoxy(0,17);
                flag = 1;
                if (getch()==27)
                {
                    flag = 1;
                    money = 0;
                }
            }
            else if ((money>=0)&&(money<10000))
                {
                    gotoxy(0,10);
                    printf("บ                 ฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑ                 บ");
                    gotoxy(0,14);
                    printf("บ   So tien khong hop le. Nhan Enter de nhap lai... บ");
                    gotoxy(0,17);
                    if (getch()==27)
                    {
                        flag = 1;
                        money = 0;
                    }
                }
                else
                {
                    gotoxy(0,10);
                    printf("บ                 ฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑ                 บ");
                    gotoxy(0,14);
                    printf("บ   So tien khong hop le. Nhan Enter de nhap lai... บ");
                    gotoxy(0,17);
                    if (getch()==27)
                    {
                        flag = 1;
                        money = 0;
                    }
                }
    }
	while (flag!=1);
	return (money);
}

long Amount_cash()
{
    INFO temp;
    long flag;
    char flag2=0;
    do
    {
        temp = readFile(ID);
        system("cls");   fflush(stdin);
        printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
        printf("\nบ                                                   บ");
        printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
        printf("\nบ                                                   บ");
        printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
        printf("\nบ           XIN VUI LONG LUA CHON SO TIEN           บ");
        printf("\nบ ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ          ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
        printf("\nบ ณ 1 ณ    50.000   ณ          ณ 4 ณ    500.000   ณ บ");
        printf("\nบ ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู          ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
        printf("\nบ ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ          ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
        printf("\nบ ณ 2 ณ   100.000   ณ          ณ 5 ณ  1.000.000   ณ บ");
        printf("\nบ ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู          ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
        printf("\nบ ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ          ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
        printf("\nบ ณ 3 ณ   200.000   ณ          ณ 6 ณ   So Khac    ณ บ");
        printf("\nบ ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู          ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
        printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
        gotoxy(0,17);
        switch (getch())
        {
                case 49:
                    fflush(stdin);
                    flag=50000;
                    gotoxy(0,7);
                    printf("บ ษอออหอออออออออออออป          ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
                    printf("\nบ บ 1 บ    50.000   บ          ณ 4 ณ    500.000   ณ บ");
                    printf("\nบ ศอออสอออออออออออออผ          ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
                    gotoxy(0,17);
                    if (getch()==13)
                    {
                        flag2 = 1;
                        if ((flag%10000==0)&&(temp.balance-flag>=50000)&&(flag>=10000))
                            return(flag);
                        else return(0);
                    }
                    break;
                case 50:
                    fflush(stdin);
                    flag=100000;
                    gotoxy(0,10);
                    printf("บ ษอออหอออออออออออออป          ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
                    printf("\nบ บ 2 บ   100.000   บ          ณ 5 ณ  1.000.000   ณ บ");
                    printf("\nบ ศอออสอออออออออออออผ          ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
                    gotoxy(0,17);
                    if (getch()==13)
                    {
                        flag2 = 1;
                        if ((flag%10000==0)&&(temp.balance-flag>=50000)&&(flag>=10000))
                            return(flag);
                        else return(0);
                    }
                    break;
                case 51:
                    fflush(stdin);
                    flag=200000;
                    gotoxy(0,13);
                    printf("บ ษอออหอออออออออออออป          ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
                    printf("\nบ บ 3 บ   200.000   บ          ณ 6 ณ   So Khac    ณ บ");
                    printf("\nบ ศอออสอออออออออออออผ          ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
                    gotoxy(0,17);
                    if (getch()==13)
                    {
                        flag2 = 1;
                        if ((flag%10000==0)&&(temp.balance-flag>=50000)&&(flag>=10000))
                            return(flag);
                        else return(0);
                    }
                    break;
                case 52:
                    fflush(stdin);
                    flag = 500000;
                    gotoxy(0,7);
                    printf("บ ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ          ษอออหออออออออออออออป บ");
                    printf("\nบ ณ 1 ณ    50.000   ณ          บ 4 บ    500.000   บ บ");
                    printf("\nบ ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู          ศอออสออออออออออออออผ บ");
                    gotoxy(0,17);
                    if (getch()==13)
                    {
                        flag2 = 1;
                        if ((flag%10000==0)&&(temp.balance-flag>=50000)&&(flag>=10000))
                            return(flag);
                        else return(0);
                    }
                    break;
                case 53:
                    fflush(stdin);
                    flag = 1000000;
                    gotoxy(0,10);
                    printf("บ ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ          ษอออหออออออออออออออป บ");
                    printf("\nบ ณ 2 ณ   100.000   ณ          บ 5 บ  1.000.000   บ บ");
                    printf("\nบ ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู          ศอออสออออออออออออออผ บ");
                    gotoxy(0,17);
                    if (getch()==13)
                    {
                        flag2 = 1;
                        if ((flag%10000==0)&&(temp.balance-flag>=50000)&&(flag>=10000))
                            return(flag);
                        else return(0);
                    }
                    break;
                case 54:
                    fflush(stdin);
                    flag=6;
                    gotoxy(0,13);
                    printf("บ ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ          ษอออหออออออออออออออป บ");
                    printf("\nบ ณ 3 ณ   200.000   ณ          บ 6 บ   So Khac    บ บ");
                    printf("\nบ ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู          ศอออสออออออออออออออผ บ");
                    gotoxy(0,17);
                    if (getch()==13)
                    {
                        flag2 = 1;
                        flag = Other_cash();
                        return(flag);
                    }
                    break;
            }
        }
        while (flag2==0);
	return (flag);
}

char Withdraw_printf()
{
    INFO temp;
    char flag=0,flag2=0;
    do
    {
        temp = readFile(ID);
        system("cls");   fflush(stdin);
        printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
        printf("\nบ                                                   บ");
        printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
        printf("\nบ                                                   บ");
        printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
        printf("\nบ                                                   บ");
        printf("\nบ             BAN CO MUON IN HOA DON ?              บ");
        printf("\nบ                                                   บ");
        printf("\nบ                                                   บ");
        printf("\nบ                               ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
        printf("\nบ                               ณ 1 ณ Co          ณ บ");
        printf("\nบ                               ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
        printf("\nบ                               ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
        printf("\nบ                               ณ 2 ณ Khong       ณ บ");
        printf("\nบ                               ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
        printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
        gotoxy(0,17);
        switch (getch())
        {
            case 49:
                fflush(stdin);
                flag = 1;
                gotoxy(0,10);
                printf("บ                               ษอออหอออออออออออออป บ");
                printf("\nบ                               บ 1 บ Co          บ บ");
                printf("\nบ                               ศอออสอออออออออออออผ บ");
                gotoxy(0,17);
                if (getch()==13)
                        flag2 = 1;
                break;
            case 50:
                fflush(stdin);
                flag=2;
                gotoxy(0,13);
                printf("บ                               ษอออหอออออออออออออป บ");
                printf("\nบ                               บ 2 บ Khong       บ บ");
                printf("\nบ                               ศอออสอออออออออออออผ บ");
                gotoxy(0,17);
                if (getch()==13)
                        flag2 = 1;
                break;
        }
    }
	while (flag2==0);
	return (flag);
}

int Withdraw_cash()
{
    INFO temp;
    long cash, balance;
    char flag=0,flag2=0,sodutt[25],soducp[25];
    cash = Amount_cash();
    if (cash==0)
        {
        Processing();
        do
        {
            temp = readFile(ID);
            Cancel();
            switch (getch())
            {
                case 49:
                    fflush(stdin);
                    flag=1;
                    gotoxy(0,10);
                    printf("บ                               ษอออหอออออออออออออป บ");
                    printf("\nบ                               บ 1 บ Co          บ บ");
                    printf("\nบ                               ศอออสอออออออออออออผ บ");
                    gotoxy(0,17);
                    if (getch()==13)
                        flag2 = 1;
                    break;
                case 50:
                    fflush(stdin);
                    flag=2;
                    gotoxy(0,13);
                    printf("บ                               ษอออหอออออออออออออป บ");
                    printf("\nบ                               บ 2 บ Khong       บ บ");
                    printf("\nบ                               ศอออสอออออออออออออผ บ");
                    gotoxy(0,17);
                    if (getch()==13)
                        flag2 = 1;
                    break;
            }
        }
        while (flag2==0);
        }
    else if (Withdraw_printf()==1)
        {
            Printing();
            temp = readFile(ID);
            temp.balance -= cash;
            Get_time(temp.lasttime);
            writeFile(ID,temp);
            WriteLog(ID,temp,cash,'-');
            balance = temp.balance - 50000;
            sprintf(sodutt,"%ld",temp.balance);
            sprintf(soducp,"%ld",balance);
            strcat(sodutt," VND");
            strcat(soducp," VND");
            while (strlen(soducp)<23)
                strcat(soducp," ");
            while (strlen(sodutt)<23)
                strcat(sodutt," ");
            do
            {
                system("cls");   fflush(stdin);
                printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
                printf("\nบ                                                   บ");
                printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
                printf("\nบ                                                   บ");
                printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
                printf("\nบ             SO DU TAI KHOAN CUA BAN               บ");
                printf("\nบ     So du cho phep :      %s บ",soducp);
                printf("\nบ     So du thuc te  :      %s บ",sodutt);
                printf("\nบ   BAN CO MUON THUC HIEN GIAO DICH KHAC KHONG ?    บ");
                printf("\nบ                               ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
                printf("\nบ                               ณ 1 ณ Co          ณ บ");
                printf("\nบ                               ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
                printf("\nบ                               ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
                printf("\nบ                               ณ 2 ณ Khong       ณ บ");
                printf("\nบ                               ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
                printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
                gotoxy(0,17);
                switch (getch())
                {
                    case 49:
                        fflush(stdin);
                        flag=1;
                        gotoxy(0,10);
                        printf("บ                               ษอออหอออออออออออออป บ");
                        printf("\nบ                               บ 1 บ Co          บ บ");
                        printf("\nบ                               ศอออสอออออออออออออผ บ");
                        gotoxy(0,17);
                        if (getch()==13)
                            flag2 = 1;
                        break;
                    case 50:
                        fflush(stdin);
                        flag=2;
                        gotoxy(0,13);
                        printf("บ                               ษอออหอออออออออออออป บ");
                        printf("\nบ                               บ 2 บ Khong       บ บ");
                        printf("\nบ                               ศอออสอออออออออออออผ บ");
                        gotoxy(0,17);
                        if (getch()==13)
                            flag2 = 1;
                        break;
                }
            }
            while (flag2!=1);
        }
        else
        {
            Processing();
            temp = readFile(ID);
            temp.balance -= cash;
            Get_time(temp.lasttime);
            writeFile(ID,temp);
            WriteLog(ID,temp,cash,'-');
            balance = temp.balance - 50000;
            sprintf(sodutt,"%ld",temp.balance);
            sprintf(soducp,"%ld",balance);
            strcat(sodutt," VND");
            strcat(soducp," VND");
            while (strlen(soducp)<23)
                strcat(soducp," ");
            while (strlen(sodutt)<23)
                strcat(sodutt," ");
            do
            {
                system("cls");   fflush(stdin);
                printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
                printf("\nบ                                                   บ");
                printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
                printf("\nบ                                                   บ");
                printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
                printf("\nบ             SO DU TAI KHOAN CUA BAN               บ");
                printf("\nบ     So du cho phep :      %s บ",soducp);
                printf("\nบ     So du thuc te  :      %s บ",sodutt);
                printf("\nบ   BAN CO MUON THUC HIEN GIAO DICH KHAC KHONG ?    บ");
                printf("\nบ                               ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
                printf("\nบ                               ณ 1 ณ Co          ณ บ");
                printf("\nบ                               ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
                printf("\nบ                               ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
                printf("\nบ                               ณ 2 ณ Khong       ณ บ");
                printf("\nบ                               ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
                printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
                gotoxy(0,17);
                switch (getch())
                {
                    case 49:
                        fflush(stdin);
                        flag=1;
                        gotoxy(0,10);
                        printf("บ                               ษอออหอออออออออออออป บ");
                        printf("\nบ                               บ 1 บ Co          บ บ");
                        printf("\nบ                               ศอออสอออออออออออออผ บ");
                        gotoxy(0,17);
                        if (getch()==13)
                            flag2 = 1;
                        break;
                    case 50:
                        fflush(stdin);
                        flag=2;
                        gotoxy(0,13);
                        printf("บ                               ษอออหอออออออออออออป บ");
                        printf("\nบ                               บ 2 บ Khong       บ บ");
                        printf("\nบ                               ศอออสอออออออออออออผ บ");
                        gotoxy(0,17);
                        if (getch()==13)
                            flag2 = 1;
                        break;
                }
            }
            while (flag2!=1);
        }
	return (flag);
}

int Balance_check()
{
    INFO temp;
    long balance;
    char flag=0,flag2=0,sodutt[25],soducp[25];
    if (Balance_printf()==2)
    {
        Processing();
        temp = readFile(ID);
        balance = temp.balance - 50000;
        Get_time(temp.lasttime);
        writeFile(ID,temp);
        sprintf(sodutt,"%ld",temp.balance);
        sprintf(soducp,"%ld",balance);
        strcat(sodutt," VND");
        strcat(soducp," VND");
        while (strlen(soducp)<23)
        {
            strcat(soducp," ");
        }
        while (strlen(sodutt)<23)
        {
            strcat(sodutt," ");
        }
        do
        {
            system("cls");   fflush(stdin);
            printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
            printf("\nบ                                                   บ");
            printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
            printf("\nบ                                                   บ");
            printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
            printf("\nบ             SO DU TAI KHOAN CUA BAN               บ");
            printf("\nบ     So du cho phep :      %s บ",soducp);
            printf("\nบ     So du thuc te  :      %s บ",sodutt);
            printf("\nบ   BAN CO MUON THUC HIEN GIAO DICH KHAC KHONG ?    บ");
            printf("\nบ                               ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
            printf("\nบ                               ณ 1 ณ Co          ณ บ");
            printf("\nบ                               ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
            printf("\nบ                               ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
            printf("\nบ                               ณ 2 ณ Khong       ณ บ");
            printf("\nบ                               ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
            printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
            gotoxy(0,17);
            switch (getch())
            {
                case 49:
                    fflush(stdin);
                    flag=1;
                    gotoxy(0,10);
                    printf("บ                               ษอออหอออออออออออออป บ");
                    printf("\nบ                               บ 1 บ Co          บ บ");
                    printf("\nบ                               ศอออสอออออออออออออผ บ");
                    gotoxy(0,17);
                    if (getch()==13)
                    {
                        flag2 = 1;
                        return(flag);
                    }
                    break;
                case 50:
                    fflush(stdin);
                    flag=2;
                    gotoxy(0,13);
                    printf("บ                               ษอออหอออออออออออออป บ");
                    printf("\nบ                               บ 2 บ Khong       บ บ");
                    printf("\nบ                               ศอออสอออออออออออออผ บ");
                    gotoxy(0,17);
                    if (getch()==13)
                    {
                        flag2 = 1;
                        return(flag);
                    }
                    break;
            }
        }
        while (flag2==0);
    }
    else
    {
        Printing();
        temp = readFile(ID);
        balance = temp.balance - 50000;
        Get_time(temp.lasttime);
        writeFile(ID,temp);
        sprintf(sodutt,"%ld",temp.balance);
        sprintf(soducp,"%ld",balance);
        strcat(sodutt," VND");
        strcat(soducp," VND");
        while (strlen(soducp)<23)
        {
            strcat(soducp," ");
        }
        while (strlen(sodutt)<23)
        {
            strcat(sodutt," ");
        }
        do
        {
            system("cls");   fflush(stdin);
            printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
            printf("\nบ                                                   บ");
            printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
            printf("\nบ                                                   บ");
            printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
            printf("\nบ             SO DU TAI KHOAN CUA BAN               บ");
            printf("\nบ     So du cho phep :      %s บ",soducp);
            printf("\nบ     So du thuc te  :      %s บ",sodutt);
            printf("\nบ   BAN CO MUON THUC HIEN GIAO DICH KHAC KHONG ?    บ");
            printf("\nบ                               ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
            printf("\nบ                               ณ 1 ณ Co          ณ บ");
            printf("\nบ                               ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
            printf("\nบ                               ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
            printf("\nบ                               ณ 2 ณ Khong       ณ บ");
            printf("\nบ                               ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
            printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
            gotoxy(0,17);
            switch (getch())
            {
                case 49:
                    fflush(stdin);
                    flag=1;
                    gotoxy(0,10);
                    printf("บ                               ษอออหอออออออออออออป บ");
                    printf("\nบ                               บ 1 บ Co          บ บ");
                    printf("\nบ                               ศอออสอออออออออออออผ บ");
                    gotoxy(0,17);
                    if (getch()==13)
                    {
                        flag2 = 1;
                        return(flag);
                    }
                    break;
                case 50:
                    fflush(stdin);
                    flag=2;
                    gotoxy(0,13);
                    printf("บ                               ษอออหอออออออออออออป บ");
                    printf("\nบ                               บ 2 บ Khong       บ บ");
                    printf("\nบ                               ศอออสอออออออออออออผ บ");
                    gotoxy(0,17);
                    if (getch()==13)
                    {
                        flag2 = 1;
                        return(flag);
                    }
                    break;
            }
        }
        while (flag2==0);
    }
	return (flag);
}

char Balance_printf()
{
    INFO temp;
    char flag=0,flag2=0;
    do
    {
        temp = readFile(ID);
        system("cls");   fflush(stdin);
        printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
        printf("\nบ                                                   บ");
        printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
        printf("\nบ                                                   บ");
        printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
        printf("\nบ                                                   บ");
        printf("\nบ       BAN MUON XEM SO DU TAI KHOAN CUA BAN        บ");
        printf("\nบ                                                   บ");
        printf("\nบ                                                   บ");
        printf("\nบ                               ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
        printf("\nบ                               ณ 1 ณ In hoa don  ณ บ");
        printf("\nบ                               ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
        printf("\nบ                               ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
        printf("\nบ                               ณ 2 ณ Hien thi    ณ บ");
        printf("\nบ                               ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
        printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
        gotoxy(0,17);
        switch (getch())
        {
            case 49:
                fflush(stdin);
                gotoxy(0,10);
                printf("บ                               ษอออหอออออออออออออป บ");
                printf("\nบ                               บ 1 บ In hoa don  บ บ");
                printf("\nบ                               ศอออสอออออออออออออผ บ");
                gotoxy(0,17);
                if (getch()==13)
                    flag2 = 1;
                break;
            case 50:
                fflush(stdin);
                flag=2;
                gotoxy(0,13);
                printf("บ                               ษอออหอออออออออออออป บ");
                printf("\nบ                               บ 2 บ Hien thi    บ บ");
                printf("\nบ                               ศอออสอออออออออออออผ บ");
                gotoxy(0,17);
                if (getch()==13)
                    flag2 = 1;
                break;
        }
    }
	while (flag2==0);
	return (flag);
}

int Transfer_id(char id[10])
{
    char flag=0, flag2=0,stk[20];
    do
    {
        system("cls");   fflush(stdin);
        printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
        printf("\nบ                                                   บ");
        printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
        printf("\nบ                                                   บ");
        printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
        printf("\nบ                                                   บ");
        printf("\nบ                                                   บ");
        printf("\nบ                                                   บ");
        printf("\nบ      BAN HAY NHAP TAI KHOAN MUON CHUYEN DEN       บ");
        printf("\nบ                                                   บ");
        printf("\nบ                ฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑ                 บ");
        printf("\nบ                                                   บ");
        printf("\nบ                                                   บ");
        printf("\nบ   Vui long nhap chinh xac so tai khoan co 14 so   บ");
        printf("\nบ                                                   บ");
        printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
        gotoxy(19,11);  gets(stk);  fflush(stdin);
        strcpy(id,"");
        strncat(id,stk,3);
        if ((strcmp(id,ID)!=0)&&(Readf(id)==2)&&(strlen(stk)==14))
        {
            gotoxy(0,14);
            printf("บ   So TK da bi khoa. Nhan Enter de nhap lai...     บ");
            getch();
            gotoxy(0,14);
            printf("บ   Vui long nhap chinh xac so tai khoan co 14 so   บ");
            gotoxy(0,11);
            printf("บ                ฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑ                 บ");
        }
        else if ((strcmp(id,ID)!=0)&&(Readf(id)==1)&&(strlen(stk)==14))
            {
                gotoxy(0,14);
                printf("บ       So TK hop le. Nhan Enter de tiep tuc...     บ");
                gotoxy(0,17);
                flag2= 1;
                flag = 1;
                if (getch()==27)
                {
                    flag2= 1;
                    flag = 0;
                }
            }
            else if ((strcmp(id,ID)!=0)&&(Readf(id)==0)&&(strlen(stk)==14))
                {
                    gotoxy(0,14);
                    printf("บ   So TK khong hop le. Nhan Enter de nhap lai...   บ");
                    getch();
                    gotoxy(0,14);
                    printf("บ   Vui long nhap chinh xac so tai khoan co 14 so   บ");
                    gotoxy(0,11);
                    printf("บ                ฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑ                 บ");
                }
                else
                {
                    gotoxy(0,14);
                    printf("บ      So TK khong hop le. Nhan ESC de huy bo...    บ");
                    gotoxy(0,11);
                    printf("บ                ฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑ                 บ");
                    if (getch()==27)
                    {
                        flag2= 1;
                        flag = 0;
                    }
                }
    }
	while (flag2!=1);
	return (flag);
}

int Transfer_money()
{
    INFO temp,temp2;
    long cash, balance;
    char check,flag=0,flag2=0,id2[10],sotien[60],num[60],name2[60],s[60];
    check = Transfer_id(id2);
    cash = Other_cash();
    if ((check=!1)||(cash==0))
    {
    Processing();
    do
        {
            temp = readFile(ID);
            Cancel();
            switch (getch())
            {
                case 49:
                    fflush(stdin);
                    flag=1;
                    gotoxy(0,10);
                    printf("บ                               ษอออหอออออออออออออป บ");
                    printf("\nบ                               บ 1 บ Co          บ บ");
                    printf("\nบ                               ศอออสอออออออออออออผ บ");
                    gotoxy(0,17);
                    if (getch()==13)
                        flag2 = 1;
                    break;
                case 50:
                    fflush(stdin);
                    flag=2;
                    gotoxy(0,13);
                    printf("บ                               ษอออหอออออออออออออป บ");
                    printf("\nบ                               บ 2 บ Khong       บ บ");
                    printf("\nบ                               ศอออสอออออออออออออผ บ");
                    gotoxy(0,17);
                    if (getch()==13)
                        flag2 = 1;
                    break;
            }
        }
        while (flag2==0);
    }
    else if (Balance_printf()==1)
            {
                Printing();
                temp = readFile(ID);
                temp2 = readFile(id2);
                temp.balance -= cash;
                temp2.balance += cash;
                Get_time(temp.lasttime);
                sprintf(sotien,"%ld",cash);
                fflush(stdin);
                strcpy(s,"");
                strcpy(s,"TK ");
                strcat(s,temp.num);
                strcat(s," DA CHUYEN CHO BAN: ");
                strcat(s,sotien);
                strcat(s,".");
                strcpy(temp2.notice,s);
                fflush(stdin);
                writeFile(ID,temp);
                writeFile(id2,temp2);
                WriteLog(ID,temp,cash,'-');
                WriteLog(id2,temp2,cash,'+');
                strcpy(num,temp2.num);
                while (strlen(num)<23)
                    strcat(num," ");
                strcpy(name2,temp2.name);
                while (strlen(name2)<23)
                    strcat(name2," ");
                strcat(sotien," VND");
                while (strlen(sotien)<23)
                    strcat(sotien," ");
                do
                {
                    system("cls");   fflush(stdin);
                    printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
                    printf("\nบ                                                   บ");
                    printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
                    printf("\nบ                                                   บ");
                    printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
                    printf("\nบ              THONG TIN CHUYEN KHOAN               บ");
                    printf("\nบ     Chu tai khoan :       %s บ",name2);
                    printf("\nบ     Tai khoan dich  :     %s บ",num);
                    printf("\nบ     So tien da chuyen :   %s บ",sotien);
                    printf("\nบ                               ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
                    printf("\nบ   BAN CO MUON THUC HIEN       ณ 1 ณ Co          ณ บ");
                    printf("\nบ   GIAO DICH KHAC KHONG ?      ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
                    printf("\nบ                               ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
                    printf("\nบ                               ณ 2 ณ Khong       ณ บ");
                    printf("\nบ                               ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
                    printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
                    gotoxy(0,17);
                    switch (getch())
                    {
                        case 49:
                            fflush(stdin);
                            flag=1;
                            gotoxy(0,10);
                            printf("บ                               ษอออหอออออออออออออป บ");
                            printf("\nบ   BAN CO MUON THUC HIEN       บ 1 บ Co          บ บ");
                            printf("\nบ   GIAO DICH KHAC KHONG ?      ศอออสอออออออออออออผ บ");
                            gotoxy(0,17);
                            if (getch()==13)
                            flag2 = 1;
                            break;
                        case 50:
                            fflush(stdin);
                            flag=2;
                            gotoxy(0,13);
                            printf("บ                               ษอออหอออออออออออออป บ");
                            printf("\nบ                               บ 2 บ Khong       บ บ");
                            printf("\nบ                               ศอออสอออออออออออออผ บ");
                            gotoxy(0,17);
                            if (getch()==13)
                                flag2 = 1;
                            break;
                    }
                }
                while (flag2==0);
            }
            else
            {
                Processing();
                temp = readFile(ID);
                temp2 = readFile(id2);
                temp.balance -= cash;
                temp2.balance += cash;
                Get_time(temp.lasttime);
                sprintf(sotien,"%ld",cash);
                fflush(stdin);
                strcpy(s,"");
                strcpy(s,"TK ");
                strcat(s,temp.num);
                strcat(s," DA CHUYEN CHO BAN: ");
                strcat(s,sotien);
                strcat(s,".");
                strcpy(temp2.notice,s);
                fflush(stdin);
                writeFile(ID,temp);
                writeFile(id2,temp2);
                WriteLog(ID,temp,cash,'-');
                WriteLog(id2,temp2,cash,'+');
                strcpy(num,temp2.num);
                while (strlen(num)<23)
                    strcat(num," ");
                strcpy(name2,temp2.name);
                while (strlen(name2)<23)
                    strcat(name2," ");
                strcat(sotien," VND");
                while (strlen(sotien)<23)
                    strcat(sotien," ");
                do
                {
                    system("cls");   fflush(stdin);
                    printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
                    printf("\nบ                                                   บ");
                    printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
                    printf("\nบ                                                   บ");
                    printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
                    printf("\nบ              THONG TIN CHUYEN KHOAN               บ");
                    printf("\nบ     Chu tai khoan :       %s บ",name2);
                    printf("\nบ     Tai khoan dich  :     %s บ",num);
                    printf("\nบ     So tien da chuyen :   %s บ",sotien);
                    printf("\nบ                               ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
                    printf("\nบ   BAN CO MUON THUC HIEN       ณ 1 ณ Co          ณ บ");
                    printf("\nบ   GIAO DICH KHAC KHONG ?      ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
                    printf("\nบ                               ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
                    printf("\nบ                               ณ 2 ณ Khong       ณ บ");
                    printf("\nบ                               ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
                    printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
                    gotoxy(0,17);
                    switch (getch())
                    {
                        case 49:
                            fflush(stdin);
                            flag=1;
                            gotoxy(0,10);
                            printf("บ                               ษอออหอออออออออออออป บ");
                            printf("\nบ   BAN CO MUON THUC HIEN       บ 1 บ Co          บ บ");
                            printf("\nบ   GIAO DICH KHAC KHONG ?      ศอออสอออออออออออออผ บ");
                            gotoxy(0,17);
                            if (getch()==13)
                                flag2 = 1;
                            break;
                        case 50:
                            fflush(stdin);
                            flag=2;
                            gotoxy(0,13);
                            printf("บ                               ษอออหอออออออออออออป บ");
                            printf("\nบ                               บ 2 บ Khong       บ บ");
                            printf("\nบ                               ศอออสอออออออออออออผ บ");
                            gotoxy(0,17);
                            if (getch()==13)
                                flag2 = 1;
                            break;
                    }
                }
                while (flag2==0);
            }
	return (flag);
}

char Change_PIN()
{
    INFO temp;
    char flag=0,flag2=0,pin1[10],pin2[10];
    temp = readFile(ID);
    system("cls");   fflush(stdin);
    printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
    printf("\nบ                                                   บ");
    printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
    printf("\nบ                                                   บ");
    printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
    printf("\nบ                                                   บ");
    printf("\nบ                                                   บ");
    printf("\nบ              VUI LONG NHAP SO PIN MOI             บ");
    printf("\nบ                                                   บ");
    printf("\nบ                 ฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑ                บ");
    printf("\nบ                                                   บ");
    printf("\nบ                                                   บ");
    printf("\nบ                                                   บ");
    printf("\nบ               Vui long nhap 6 so PIN              บ");
    printf("\nบ                                                   บ");
    printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
    gotoxy(24,10);  Get_pass(pin1);  fflush(stdin);
    gotoxy(0,17);
    getch();
    system("cls");  fflush(stdin);
    printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
    printf("\nบ                                                   บ");
    printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
    printf("\nบ                                                   บ");
    printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
    printf("\nบ                                                   บ");
    printf("\nบ                                                   บ");
    printf("\nบ           VUI LONG NHAP LAI SO PIN MOI            บ");
    printf("\nบ                                                   บ");
    printf("\nบ                 ฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑ                บ");
    printf("\nบ                                                   บ");
    printf("\nบ                                                   บ");
    printf("\nบ                                                   บ");
    printf("\nบ               Vui long nhap 6 so PIN              บ");
    printf("\nบ                                                   บ");
    printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
    gotoxy(24,10);  Get_pass(pin2);  fflush(stdin);
    gotoxy(0,17);
    getch();
    if ((strcmp(pin1,pin2)==0)&&(strcmp(pin1,temp.pin)!=0))
    {
        Processing();
        temp = readFile(ID);
        strcpy(temp.pin,pin1);
        Get_time(temp.lasttime);
        writeFile(ID,temp);
        do
        {
            system("cls");   fflush(stdin);
            printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
            printf("\nบ                                                   บ");
            printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
            printf("\nบ                                                   บ");
            printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
            printf("\nบ                                                   บ");
            printf("\nบ            BAN DA DOI PIN THANH CONG              บ");
            printf("\nบ                                                   บ");
            printf("\nบ   BAN CO MUON THUC HIEN GIAO DICH KHAC KHONG ?    บ");
            printf("\nบ                               ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
            printf("\nบ                               ณ 1 ณ Co          ณ บ");
            printf("\nบ                               ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
            printf("\nบ                               ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
            printf("\nบ                               ณ 2 ณ Khong       ณ บ");
            printf("\nบ                               ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
            printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
            gotoxy(0,17);
            switch (getch())
            {
                case 49:
                    fflush(stdin);
                    flag=1;
                    gotoxy(0,10);
                    printf("บ                               ษอออหอออออออออออออป บ");
                    printf("\nบ                               บ 1 บ Co          บ บ");
                    printf("\nบ                               ศอออสอออออออออออออผ บ");
                    gotoxy(0,17);
                    if (getch()==13)
                        flag2 = 1;
                    break;
                case 50:
                    fflush(stdin);
                    flag=2;
                    gotoxy(0,13);
                    printf("บ                               ษอออหอออออออออออออป บ");
                    printf("\nบ                               บ 2 บ Khong       บ บ");
                    printf("\nบ                               ศอออสอออออออออออออผ บ");
                    gotoxy(0,17);
                    if (getch()==13)
                        flag2 = 1;
                    break;
            }
        }
        while (flag2==0);
    }
    else
    {
        temp = readFile(ID);
        Processing();
        do
        {
            system("cls");   fflush(stdin);
            printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
            printf("\nบ                                                   บ");
            printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
            printf("\nบ                                                   บ");
            printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
            printf("\nบ                                                   บ");
            printf("\nบ             DOI PIN KHONG THANH CONG              บ");
            printf("\nบ                                                   บ");
            printf("\nบ                                                   บ");
            printf("\nบ   BAN CO MUON THUC HIEN GIAO DICH KHAC KHONG ?    บ");
            printf("\nบ                               ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
            printf("\nบ                               ณ 1 ณ Co          ณ บ");
            printf("\nบ                               ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
            printf("\nบ                               ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
            printf("\nบ                               ณ 2 ณ Khong       ณ บ");
            printf("\nบ                               ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
            printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
            gotoxy(0,17);
            switch (getch())
            {
                case 49:
                    fflush(stdin);
                    flag=1;
                    gotoxy(0,10);
                    printf("บ                               ษอออหอออออออออออออป บ");
                    printf("\nบ                               บ 1 บ Co          บ บ");
                    printf("\nบ                               ศอออสอออออออออออออผ บ");
                    gotoxy(0,17);
                    if (getch()==13)
                        flag2 = 1;
                    break;
                case 50:
                    fflush(stdin);
                    flag=2;
                    gotoxy(0,13);
                    printf("บ                               ษอออหอออออออออออออป บ");
                    printf("\nบ                               บ 2 บ Khong       บ บ");
                    printf("\nบ                               ศอออสอออออออออออออผ บ");
                    gotoxy(0,17);
                    if (getch()==13)
                        flag2 = 1;
                    break;
            }
        }
        while (flag2==0);
    }
	return (flag);
}

int Readf(char id[3])
{
    FILE *f;
    INFO temp;
    char fn[10];
    /* Generation Filename */
    strcpy(fn,"acc");
    strcat(fn,id);
    strcat(fn,".dat");
    /* End */

    /* Check file */
    if (fopen(fn,"rb")!=0)
        {
            temp = readFile(id);
            if (temp.status==1)
                return(1);
            else if(temp.status==2)
                return(2);
        }
    else return(0);
}

INFO readFile(char id[10])
{
    FILE *f;
    INFO temp;
    char fn[10];
    /* Generation Filename */
    strcpy(fn,"acc");
    strcat(fn,id);
    strcat(fn,".dat");
    /* End */

    /* Read file */
    f = fopen(fn,"r+b");
    fread(&temp,sizeof(INFO),1,f);
    fclose(f);
    return temp;
}

void writeFile(char id[10], INFO temp)
{
    FILE *f;
    char fn[10];
    /* Generation Filename */
    strcpy(fn,"acc");
    strcat(fn,id);
    strcat(fn,".dat");
    /* End */

    /* Write file */
    f = fopen(fn,"w+b");
    fwrite(&temp,sizeof(INFO),1,f);
    fclose(f);
}

char Backup_printf()
{
    INFO temp;
    char flag=0,flag2=0;
    do
    {
        temp = readFile(ID);
        system("cls");   fflush(stdin);
        printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
        printf("\nบ                                                   บ");
        printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
        printf("\nบ                                                   บ");
        printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
        printf("\nบ                                                   บ");
        printf("\nบ    BAN MUON XEM CAC GIAO DICH MOI NHAT CUA BAN    บ");
        printf("\nบ                                                   บ");
        printf("\nบ                                                   บ");
        printf("\nบ                               ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
        printf("\nบ                               ณ 1 ณ In hoa don  ณ บ");
        printf("\nบ                               ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
        printf("\nบ                               ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
        printf("\nบ                               ณ 2 ณ Hien thi    ณ บ");
        printf("\nบ                               ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
        printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
        gotoxy(0,17);
        switch (getch())
        {
            case 49:
                fflush(stdin);
                gotoxy(0,10);
                printf("บ                               ษอออหอออออออออออออป บ");
                printf("\nบ                               บ 1 บ In hoa don  บ บ");
                printf("\nบ                               ศอออสอออออออออออออผ บ");
                gotoxy(0,17);
                if (getch()==13)
                    flag2 = 1;
                flag=1;
                break;
            case 50:
                fflush(stdin);
                flag=2;
                gotoxy(0,13);
                printf("บ                               ษอออหอออออออออออออป บ");
                printf("\nบ                               บ 2 บ Hien thi    บ บ");
                printf("\nบ                               ศอออสอออออออออออออผ บ");
                gotoxy(0,17);
                if (getch()==13)
                    flag2 = 1;
                break;
        }
    }
	while (flag2==0);
	return (flag);
}

char Backup_check()
{
    INFO temp;
    long balance;
    char flag=0,flag2=0,sodutt[25],soducp[25];
    if (Backup_printf()==2)
    {
        Processing();
        do
        {
            system("cls");   fflush(stdin);
            printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
            printf("\nบ                                                   บ");
            printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
            printf("\nบ                                                   บ");
            printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
            printf("\nบ                 SAO KE TAI KHOAN                  บ");
            ReadLog(ID);
            printf("\nบ    BAN CO MUON THUC HIEN GIAO DICH KHAC KHONG     บ");
            printf("\nบ ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ           ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
            printf("\nบ ณ 1 ณ Co          ณ           ณ 2 ณ Khong       ณ บ");
            printf("\nบ ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู           ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
            printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
            gotoxy(0,17);
            switch (getch())
            {
                case 49:
                    fflush(stdin);
                    flag=1;
                    gotoxy(0,13);
                    printf("บ ษอออหอออออออออออออป           ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
                    printf("\nบ บ 1 บ Co          บ           ณ 2 ณ Khong       ณ บ");
                    printf("\nบ ศอออสอออออออออออออผ           ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
                    gotoxy(0,17);
                    if (getch()==13)
                    {
                        flag2 = 1;
                        return(flag);
                    }
                    break;
                case 50:
                    fflush(stdin);
                    flag=2;
                    gotoxy(0,13);
                    printf("บ ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ           ษอออหอออออออออออออป บ");
                    printf("\nบ ณ 1 ณ Co          ณ           บ 2 บ Khong       บ บ");
                    printf("\nบ ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู           ศอออสอออออออออออออผ บ");
                    gotoxy(0,17);
                    if (getch()==13)
                    {
                        flag2 = 1;
                        return(flag);
                    }
                    break;
            }
        }
        while (flag2==0);
    }
    else
    {
        Printing();
        do
        {
            system("cls");   fflush(stdin);
            printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
            printf("\nบ                                                   บ");
            printf("\nบ   K-Bank  ณ  NGAN HANG HOC VIEN KY THUAT MAT MA   บ");
            printf("\nบ                                                   บ");
            printf("\nบ   ฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿   บ");
            printf("\nบ                 SAO KE TAI KHOAN                  บ");
            ReadLog(ID);
            printf("\nบ    BAN CO MUON THUC HIEN GIAO DICH KHAC KHONG     บ");
            printf("\nบ ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ           ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
            printf("\nบ ณ 1 ณ Co          ณ           ณ 2 ณ Khong       ณ บ");
            printf("\nบ ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู           ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
            printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
            gotoxy(0,17);
            switch (getch())
            {
                case 49:
                    fflush(stdin);
                    flag=1;
                    gotoxy(0,13);
                    printf("บ ษอออหอออออออออออออป           ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ บ");
                    printf("\nบ บ 1 บ Co          บ           ณ 2 ณ Khong       ณ บ");
                    printf("\nบ ศอออสอออออออออออออผ           ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู บ");
                    gotoxy(0,17);
                    if (getch()==13)
                    {
                        flag2 = 1;
                        return(flag);
                    }
                    break;
                case 50:
                    fflush(stdin);
                    flag=2;
                    gotoxy(0,13);
                    printf("บ ฺฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฟ           ษอออหอออออออออออออป บ");
                    printf("\nบ ณ 1 ณ Co          ณ           บ 2 บ Khong       บ บ");
                    printf("\nบ ภฤฤฤมฤฤฤฤฤฤฤฤฤฤฤฤฤู           ศอออสอออออออออออออผ บ");
                    gotoxy(0,17);
                    if (getch()==13)
                    {
                        flag2 = 1;
                        return(flag);
                    }
                    break;
            }
        }
        while (flag2==0);
    }
	return (flag);
}

void WriteLog(char id[10], INFO temp, long so, char key)
{
    FILE *f;
    char fn[10], lasttime[30];
    /* Generation Filename */
    strcpy(fn,"acc");
    strcat(fn,id);
    strcat(fn,"_log.data");
    /* End */

    /* Write file */
    Get_time(lasttime);
    while (strlen(lasttime)<20)
        strcat(lasttime," ");
    f = fopen(fn,"a+t");
    fprintf(f,"%20s  %c  %10ld VND\n",lasttime,key,so);
    fclose(f);
}

void ReadLog(char id[10])
{
    FILE *f;
    char fn[10],stt,line[1024],line1[50],k;
    /* Generation Filename */
    strcpy(fn,"acc");
    strcat(fn,id);
    strcat(fn,"_log.data");
    /* End */

    /* Read file */
    if (fopen(fn,"rt")==0)
    {
        printf("\nบ                                                   บ");
        printf("\nบ                 Khong co du lieu                  บ");
        printf("\nบ                                                   บ");
        printf("\nบ                                                   บ");
        printf("\nบ                                                   บ");
    }
    else
    {
        f = fopen(fn,"r+t");
        fseek(f,-41,SEEK_END);
            stt = 1;
            while ((stt<=5)&&(SEEK_CUR!=SEEK_SET))
            {
                stt++;
                fscanf(f,"%[^\t\n]s",line);
                printf("\nบ      %s      บ",line);
                k = fseek(f,(-40*stt)-(stt),SEEK_END);
                if (k!=0)
                {
                    for (;stt<=5;stt++)
                        printf("\nบ                                                   บ");
                    break;
                }
            }
        fclose(f);
    }
}

void Get_pass(char pw[10])
{
	int x=0,t;
	do
	{
		t = getch();  fflush(stdin);
		if ((t>=32 && t<=57)||(t>=65 && t<=90)||(t>=97 && t<=122))
		{
			putch('*');
			pw[x]=t;
            x++;
        }
    }
    while (t!=13);
	pw[x]='\0';
}

void Get_time(char cur[30])
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char current[]="",temp[10],ss;
    sprintf(temp,"%d",tm.tm_hour);
    strcat(current,temp);
    strcat(current,":");
    sprintf(temp,"%d",tm.tm_min);
    strcat(current,temp);
    strcat(current,":");
    ss = tm.tm_sec;
    sprintf(temp,"%d",ss);
    strcat(current,temp);
    strcat(current," ");
    sprintf(temp,"%d",tm.tm_mday);
    strcat(current,temp);
    strcat(current,"/");
    sprintf(temp,"%d",tm.tm_mon+1);
    strcat(current,temp);
    strcat(current,"/");
    sprintf(temp,"%d",tm.tm_year + 1900);
    strcat(current,temp);
    strcpy(cur,current);
}

void gotoxy( short x, short y )
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD position = { x, y } ;
    SetConsoleCursorPosition( hStdout, position ) ;
}
