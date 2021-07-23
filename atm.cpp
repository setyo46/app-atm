#include <iostream>
#include <windows.h> //sleep dan gotoxy

using namespace std;

int nPin, nTransfer, nPilih;
char chRekening[10];
int nUang = 10000000; //global variabel
int transaksi(int a, int b)
{
	nUang = a - b;
}

void gotoxy(int x, int y)
{
	COORD k = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), k);
}

void garis()
{
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
}

void looding()
{
	system("COLOR 1F");
	int i, j = 100;
	for (i = 0; i < 100, j >= 0; i++, j--)
	{
		gotoxy(i, 2);
		Sleep(20);
		cout << "_";
		Sleep(20);
		gotoxy(j, 21);
		cout << "_";
	}

	gotoxy(47, 10);
	cout << "PLEASE WAIT";
	gotoxy(40, 12);
	cout << "COMPLETE ICC APPLICATION";
	gotoxy(38, 13);
	cout << "SELECTION AND INITIALIZATION";
	Sleep(1000);
}

void menu();
int password()
{
	looding();
	system("cls");		// clear screan
	system("COLOR 1F"); // Warna
	gotoxy(38, 1);
	cout << "SELAMAT DATANG DI ATM BERSAMA";
	gotoxy(36, 2);
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
	gotoxy(38, 5);
	cout << "MASUKAN PIN ATM ANDA : ";
	cin >> nPin;
	if (nPin == 123456)
	{
		menu();
	}
	else
	{
		gotoxy(36, 6);
		cout << " \a\a\aPIN YANG ANDA MASUKAN SALAH ";
		Sleep(1000);
		password();
	}
}

void tunggu()
{
	system("cls");
	system("COLOR 1F");
	gotoxy(47, 10);
	cout << "HARAP TUNGGU";
	gotoxy(40, 11);
	cout << "TRANSAKSI SEDANG DI PROSESES";
	gotoxy(1, 12);
	garis();
	gotoxy(40, 14);
	cout << "NIKMATI KEMUDAHAN BERTRANSAKSI";
	gotoxy(45, 15);
	cout << "MELALUI ATM LINK";
	Sleep(10000); //timer menit
}

selesai() //fungsi untuk menu tarik tunai
{
	tunggu();
	system("cls");		// clear screan
	system("COLOR 1F"); //

	gotoxy(35, 3);
	cout << "TRANSAKSI TELAH SELESAI";
	gotoxy(35, 5);
	cout << "PERLU TRANSAKSI LAGI ? : ";
	gotoxy(75, 10);
	cout << " TEKAN 1 JIKA YA    -->";
	gotoxy(75, 12);
	cout << " TEKAN 2 JIKA TIDAK -->";
	gotoxy(35, 18);
	cout << "SALDO RP." << nUang << endl;
	gotoxy(76, 13);
	cout << "";
	cin >> nPilih;
	if (nPilih == 1)
	{
		menu();
	}
	else
	{
		system("cls");
		exit(0);
	}
}

// MENU PILIHAN

void penarikan();
void saldo();
void transfer();
void setor();

void menu()
{

	system("cls");		// clear screan
	system("COLOR 1F"); // Warna
	Sleep(1000);

	gotoxy(35, 2);
	cout << "PILIH TRANSAKSI YANG ANDA INGINKAN";
	gotoxy(38, 4);
	cout << "PILIH KELUAR UNTUK PEMBATALAN" << endl;
	gotoxy(10, 10);
	cout << "<-- 1. PENARIKAN ";
	gotoxy(10, 15);
	cout << "<-- 2. INFORMASI SALDO ";
	gotoxy(75, 10);
	cout << "3. TRANSFER    --> ";
	gotoxy(75, 15);
	cout << "4. SETOR TUNAI -->";
	gotoxy(1, 20);
	garis();
	gotoxy(38, 23);
	cout << " SILIHKAN PILIH MENU DI ATAS: ";
	cin >> nPilih;

	switch (nPilih) // switch to case menu
	{
	case 1:
	{
		penarikan();
		break;
	}
	case 2:
	{
		saldo();
		break;
	}
	case 3:
	{
		transfer();
		break;
	}

	case 4:
	{
		setor();
		break;
	}
	default:
	{
		gotoxy(68, 23);
		cout << "\a\a\aSALAH"; //terminating to mainmenu
		Sleep(1000);
		menu();
	}
	}
}

void penarikan()
{

	system("cls");		// clear screan
	system("COLOR 1F"); // Warna
	gotoxy(43, 2);
	cout << "MENU PENARIKAN ";
	gotoxy(35, 3);
	cout << "SILAHKAN PILIH JUMLAH PENARIKAN ";
	gotoxy(10, 8);
	cout << "<-- 1. Rp. 100.000 ";
	gotoxy(10, 11);
	cout << "<-- 2. Rp. 200.000 ";
	gotoxy(10, 14);
	cout << "<-- 3. Rp. 500.000 ";
	gotoxy(10, 17);
	cout << "<-- 4. Rp. 1.000.000 ";
	gotoxy(75, 8);
	cout << "5. Rp. 2.000.000 -->";
	gotoxy(75, 11);
	cout << "6. Rp. 3.000.000 --> ";
	gotoxy(75, 14);
	cout << "7. Rp. 5.000.000 -->";
	gotoxy(75, 17);
	cout << "8. MENU LAINNYA  -->";
	gotoxy(1, 20);
	garis();
	gotoxy(38, 23);
	cout << "SILIHKAN PILIH MENU DI ATAS : ";
	cin >> nPilih;
	switch (nPilih) //sub case menu 2
	{
	case 1:
	{
		transaksi(nUang, 100000);
		break;
	}
	case 2:
	{
		transaksi(nUang, 200000);
		break;
	}
	case 3:
	{
		transaksi(nUang, 500000);
		break;
	}
	case 4:
	{
		transaksi(nUang, 1000000);
		break;
	}
	case 5:
	{
		transaksi(nUang, 2000000);
		break;
	}
	case 6:
	{
		transaksi(nUang, 3000000);
		break;
	}
	case 7:
	{
		transaksi(nUang, 5000000);
		break;
	}
	case 8:
	{
		menu();
	}
	default:
	{
		gotoxy(68, 23);
		cout << "\a\a\aSALAH"; //terminating to mainmenu
		Sleep(1000);
		penarikan();
	}
	}
	selesai();
}

void saldo()
{
	tunggu();
	system("cls"); // clear screan
	system("COLOR 1F");
	gotoxy(43, 5);
	cout << "INFORMASI SALDO ANDA";
	gotoxy(43, 10);
	cout << "SALDO: RP. " << nUang << endl;
	gotoxy(70, 12);
	cout << " TEKAN 1 MENU LAINNYA     -->";
	gotoxy(75, 13);
	cin >> nPilih;
	if (nPilih == 1)
	{
		menu();
	}
	else
	{
		gotoxy(74, 19);
		cout << "\a\a\aSALAH"; //terminating to mainmenu
		Sleep(1000);
		saldo();
	}
}

void transfer()
{

	system("cls"); // clear screan
	system("COLOR 1F");
	gotoxy(40, 4);
	cout << "MASUKKAN NOMER REKENING ";
	gotoxy(41, 5);
	cout << "TUJUAN TRANSFER ANDA ";
	gotoxy(43, 6);
	cout << "";
	cin >> chRekening;
	gotoxy(75, 10);
	cout << "1.BENAR -->";
	gotoxy(75, 12);
	cout << "2.SALAH -->";
	gotoxy(75, 14);
	cout << "PILIH :";
	cin >> nPilih;
	if (nPilih == 1)
	{
		system("cls");
		gotoxy(40, 4);
		cout << "MASUKKAN JUMLAH TRANSFER: ";
		cin >> nTransfer;
		gotoxy(75, 10);
		cout << "1.BENAR -->";
		gotoxy(75, 12);
		cout << "2.SALAH -->";
		gotoxy(75, 14);
		cout << "PILIH :";
		cin >> nPilih;
		if (nPilih == 1)
		{
			tunggu();
			system("cls");
			gotoxy(45, 5);
			cout << "INFORMASI TRANSFER";
			gotoxy(5, 10);
			cout << "KE REKENING   : " << chRekening;
			gotoxy(5, 11);
			cout << "JUMLAH TRANSFER : " << nTransfer;
			gotoxy(75, 15);
			cout << "1. TRANSFER -->";
			gotoxy(75, 17);
			cout << "2. ULANGI --> ";
			gotoxy(75, 19);
			cout << "PILIH :";
			cin >> nPilih;
			if (nPilih == 1)
			{
				nUang = nUang - nTransfer;
				selesai();
			}
			else
			{
				transfer();
			}
		}
	}
	else
	{
		transfer();
	}
}

void setor()
{

	system("cls");
	gotoxy(40, 2);
	cout << "TRANSAKSI SETOR TUNAI";
	gotoxy(40, 4);
	cout << "HANYA MENERIMA UANG TUNAI";
	gotoxy(40, 5);
	cout << "DENGAN DENOMINASI : ";
	gotoxy(45, 6);
	cout << "-RP.  50.000 ";
	gotoxy(45, 7);
	cout << "-RP.  100.000 ";
	gotoxy(10, 10);
	cout << "MOHON PERHATIAN UNTUK : ";
	gotoxy(10, 11);
	cout << "- MAMASTIKAN DENOMINASI UANG  ";
	gotoxy(10, 12);
	cout << "- MERAPIKAN UANG ANDA ";
	gotoxy(10, 14);
	cout << "SILAHKAN TEKAN 1  ";
	gotoxy(10, 15);
	cout << "UNTUK PROSES DEPOSIT  ";
	gotoxy(75, 20);
	cout << "PILIH : ";
	cin >> nPilih;
	if (nPilih == 1)
	{
		system("cls");
		int jumlah, setor[5];
		gotoxy(35, 5);
		cout << "BERAPA JUMLAH UANG YANG ANDA MASUKKAN :";
		cin >> jumlah;
		for (int i = 1; i <= jumlah; i++)
		{
			cout << "MASUKAN YANG " << i << ": RP. ";
			cin >> setor[i];

			nUang = nUang + setor[i];
		}
		selesai();
	}
	else
	{
		gotoxy(78, 20);
		cout << "\a\a\aSALAH"; //terminating to mainmenu
		Sleep(1000);
		setor();
	}
}

int main()
{
	password();
	menu();
	return 0;
}
