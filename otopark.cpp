#include <iostream>
using namespace std;
#define MAX 100 // -> otopark araç kapasitesini 100 olarak tanýmladýk.
class Arac {
public:
	string plaka, kisi_ad, kisi_soyad, kisi_tel;
	time_t giris = 0; // -> zaman deðiþkeni
}arac[100]; // -> araç kapasitesi

class Otopark {
public:
	string id, sifre;
	int i, gelir;
	double sure;
	Otopark(string id, string sifre) {
		this->id = id;
		this->sifre = sifre;
		i = 0; // -> kiþi sayýsý -1 den baþlýyor
		gelir = 0;
	}

	void menu() {
		cout << "OTOPARK PROGRAMI\n";
		cout << " ---------------\n";
		cout << "1. Seçenek: Yeni Araç\n";
		cout << "2. Seçenek: Araç Çýkýþ \n";
		cout << "3. Seçenek: Araç Listesi\n";
		cout << "4. Seçenek: Raporla\n";
		cout << "5. Seçenek: Çýkýþ\n";

		int secim;
	    bas:
		cout << "Yapmak istediðiniz iþlemi seçiniz:\n";
		cin >> secim;
		switch (secim)
		{
		case 1:yeni(); break;
		case 2:cikis(); break;
		case 3:listele(); break;
		case 4:rapor(); break;
		case 5:exit(0); break;
		default:cout << "Hatalý seçim !\n";
			goto bas;
			break;
		}	
	}

	void yeni() {
		i++;
		cout << "Adýnýz:";
		cin >> arac[i].kisi_ad;
		cout << "Soyadýnýz:";
		cin >> arac[i].kisi_soyad;
		cout << "Telefon numaranýz:";
		cin >> arac[i].kisi_tel;
		cout << "Araç plakasý:";
		cin >> arac[i].plaka;
		cout << "ÝÞLEM BAÞARILI\n";
		time(&arac[i].giris); // -> aracýn otoparka giriþ zamanýný kaydeder.
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
		while (j <= i)// -> Otoparkta araç varsa çalýþýr.
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
				cout << "Plaka bulunamadý\n";
				system("pause");
				system("cls");
				menu();
			}
			sure = sure / 3600;
			int saat = ceil(sure);
			cout << "Ödemeniz gereken ücret=" << saat * 5 << "TL\n"; // -> saati 5 tl, otoparkta kalýnan süreyi 5 ile çarpýyor
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
		cout << "Þuanki otopark geliri =" << gelir << "TL" << endl;
		cout << "Otoparktaki araç sayýsý =" << i << endl;
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
	cout << "Kullanýcý adýný giriniz: " << endl;
	cin >> ad;
	cout << "Þifrenizi giriniz: " << endl;
	cin >> sifre;
	if (calisan.id == ad && calisan.sifre == sifre) {
		calisan.menu();
	}
	else
		cout << "Tekrar deneyiniz." << endl;
	goto giris;
}