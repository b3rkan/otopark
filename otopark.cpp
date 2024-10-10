#include <iostream>
using namespace std;
#define MAX 100 // -> otopark ara� kapasitesini 100 olarak tan�mlad�k.
class Arac {
public:
	string plaka, kisi_ad, kisi_soyad, kisi_tel;
	time_t giris = 0; // -> zaman de�i�keni
}arac[100]; // -> ara� kapasitesi

class Otopark {
public:
	string id, sifre;
	int i, gelir;
	double sure;
	Otopark(string id, string sifre) {
		this->id = id;
		this->sifre = sifre;
		i = 0; // -> ki�i say�s� -1 den ba�l�yor
		gelir = 0;
	}

	void menu() {
		cout << "OTOPARK PROGRAMI\n";
		cout << " ---------------\n";
		cout << "1. Se�enek: Yeni Ara�\n";
		cout << "2. Se�enek: Ara� ��k�� \n";
		cout << "3. Se�enek: Ara� Listesi\n";
		cout << "4. Se�enek: Raporla\n";
		cout << "5. Se�enek: ��k��\n";

		int secim;
	    bas:
		cout << "Yapmak istedi�iniz i�lemi se�iniz:\n";
		cin >> secim;
		switch (secim)
		{
		case 1:yeni(); break;
		case 2:cikis(); break;
		case 3:listele(); break;
		case 4:rapor(); break;
		case 5:exit(0); break;
		default:cout << "Hatal� se�im !\n";
			goto bas;
			break;
		}	
	}

	void yeni() {
		i++;
		cout << "Ad�n�z:";
		cin >> arac[i].kisi_ad;
		cout << "Soyad�n�z:";
		cin >> arac[i].kisi_soyad;
		cout << "Telefon numaran�z:";
		cin >> arac[i].kisi_tel;
		cout << "Ara� plakas�:";
		cin >> arac[i].plaka;
		cout << "��LEM BA�ARILI\n";
		time(&arac[i].giris); // -> arac�n otoparka giri� zaman�n� kaydeder.
		system("pause");
		system("cls");
		menu();
	}

	void cikis() {
		int j = 0;
		string plka;
		time_t cikis;
		bool buldu = false;
		double sure;
		time(&cikis);
		
		cout << "Plaka Giriniz: ";
		cin >> plka;
		while (j <= i)// -> Otoparkta ara� varsa �al���r.
		{
			if (arac[i].plaka == plka) {
				sure = difftime(cikis, arac[i].giris);
				for (int k = j; k <= i; k++) {
					arac[k] = arac[k + 1];
				}
				i--;
				buldu = true;
			}
			if (buldu == false) {
				cout << "Plaka bulunamad�\n";
				system("pause");
				system("cls");
				menu();
			}
			sure = sure / 3600;
			int saat = ceil(sure);
			cout << "�demeniz gereken �cret=" << saat * 5 << "TL\n"; // -> saati 5 tl, otoparkta kal�nan s�reyi 5 ile �arp�yor
			gelir += saat * 5;// -> otopark geliri
			system("pause");
			system("cls");
			menu();
		}
	}
	void listele() {
		for (int j = 0; j <= i; j++) {
			cout << arac[i].plaka << endl;
		}
		system("pause");
		system("cls");
		menu();
	}
	
	void rapor() {
		cout << "�uanki otopark geliri =" << gelir << "TL" << endl;
		cout << "Otoparktaki ara� say�s� =" << i << endl;
		system("pause");
		system("cls");
		menu();
	}
};

int main() {
	setlocale(LC_ALL, "Turkish");
	Otopark calisan("Berkan", "666");
	string ad, sifre;
giris:
	cout << "Kullan�c� ad�n� giriniz: " << endl;
	cin >> ad;
	cout << "�ifrenizi giriniz: " << endl;
	cin >> sifre;
	if (calisan.id == ad && calisan.sifre == sifre) {
		calisan.menu();
	}
	else
		cout << "Tekrar deneyiniz." << endl;
	goto giris;
}