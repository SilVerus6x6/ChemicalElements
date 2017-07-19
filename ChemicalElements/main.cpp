#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <string>
std::vector<std::string> pier;
std::vector<int> ilosc;
int dodaj(int a, std::string b) {
	for (int i = 0; i < pier.size(); i++) {
		if (b == pier[i]) {
			int tmp = a + ilosc[i];
			ilosc[i] = tmp;
			return 1;
		}
	}
	ilosc.push_back(a);
	pier.push_back(b);
	return 1;
}
void rob(std::string t) {
	pier.clear();
	ilosc.clear();
	std::string nazwa = "";
	int pomoc = 1;
	int mnoznik = 1;
	int ile = 0;
	std::cout << t << std::endl;
	do {
		int x = t[0];
		pomoc = 1;
		if (t[0] == '(') {
			int pocz = t.find(')', 0) + 1;
			ile = 0;
			std::string pom = "";
			do {
				int y = t[pocz + ile];
				if (y >= 48 && y <= 57) {
					pom += y;
					ile++;
				}
				else break;
			} while (true);
			if (pom != "")mnoznik = std::stoi(pom, nullptr, 10);
			t.erase(pocz, ile);
			t.erase(0, 1);
			continue;
		}
		if (t[0] == ')') {
			mnoznik = 1;
			t.erase(0, 1);
			continue;
		}
		if (x >= 48 && x <= 57) {
			t.erase(0, 1);
			continue;
		}
		if (x >= 65 && x <= 90) {
			ile = 1;
			nazwa = t[0];
			int y = t[1];
			if (y >= 97 && y <= 122) {
				nazwa += t[1];
				y = t[2];
				ile++;
			}
			std::string pom = "";
			do {
				y = t[ile];
				if (y >= 48 && y <= 57) {
					pom += y;
					ile++;
				}
				else break;
			} while (true);
			if (pom != "")pomoc = std::stoi(pom, nullptr, 10);
			int z = pomoc*mnoznik;
			dodaj(z, nazwa);
			t.erase(0, ile);
		}
		if (t.length() == 0)break;
	} while (true);
	for (int i = 0; i < ilosc.size(); i++)std::cout << pier[i].c_str() << ": " << ilosc[i] << std::endl;
}
void main() {
	std::string t = "C6H12O6";
	pier.reserve(10);
	ilosc.reserve(10);
	rob(t);
	t = "CCl2F2";
	rob(t);
	t = "NaHCO3";
	rob(t);
	t = "C4H8(OH)2";
	rob(t);
	t = "PbCl(NH3)2(COOH)2";
	rob(t);
	_getch();
}