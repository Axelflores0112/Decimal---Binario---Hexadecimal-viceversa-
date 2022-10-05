#pragma once
#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;

class Convertidor{
private:
	int digito[20];
public: 
	Convertidor(int);
	void conversion();
};

Convertidor::Convertidor(int _digito){
	digito[20] = _digito;
}

void Convertidor::conversion(){
	short bin[8];
	int i, eleccion=0, a = 0, resto = 0,opc, hexa = 0, x = 0, hex = 0, multi = 1, y = 1, rem, b = 0;
	do{
	cout << "Cual conversion quiere realizar?" << endl;
	cout << "1.Decimal a Binario" << endl;
	cout << "2.Decimal a Hexadecimal" << endl;
	cout << "3.Binario a Decimal" << endl;
	cout << "4.Binario a Hexadecimal" << endl;
	cout << "5.Hexadecimal a decimal" << endl;
	cout << "6.Hexadecimal a Binario" << endl;
	cin >> eleccion;
	switch (eleccion) {
	case 1:
		cout << "El numnero a convertir de decimal a binario es: " << endl;
		cin >> digito[0];
		for (i = 0; digito[i] != 1; i++) {
			digito[i + 1] = digito[i] / 2;
			bin[i] = digito[i] % 2;
			if (digito[i + 1] == 1) {
				bin[i + 1] = 1;
			}
		}
		for (int j = i; j >= 0; j--) {
			cout << bin[j] << endl;
		}
		break;
	case 2:
		int deci, residuo, resultado;
		int num[20];
		cout << "El numero a convertir en decimal a hexadecimal es: ";
		cin >> deci;
		do {
			residuo = deci % 16;
			resultado = deci / 16;
			num[a] = residuo;
			deci = resultado;
			a++;
		} while (resultado > 15);
		num[a] = resultado;
		for (int i = a; i >= 0; i--) {
			if (num[i] == 10) {
				cout << "A";
			}
			else if (num[i] == 11) {
				cout << "B";
			}
			else if (num[i] == 12) {
				cout << "C";
			}
			else if (num[i] == 13) {
				cout << "D";
			}
			else if (num[i] == 14) {
				cout << "E";
			}
			else if (num[i] == 15) {
				cout << "F";
			}
			else {
				
				cout<<num[i];
				
			}
			cout << endl;
		}
		break;
	case 3:
		int bi, resul;
		int digi[8];

		cout << "El numero a convertir en Binario a Decimal: " << endl;
		cin >> bi;

		for (int i = 0; i < 8; i++)
		{
			digi[i] = bi % 10;
			bi /= 10;
		}

		for (int i = 7; i >= 0; i--)
		{
			resul = (resto * 2) + digi[i];
			resto = resul;
		}

		cout << resul << endl;
		break;
	case 4:
		int numbi ;
		char numhex[20];
		cout << "El numero a convertir de Binario a Hexadecimal es: ";
		cin >> numbi;
		while (numbi != 0)
		{
			rem = numbi % 10;
			hex = hex + (rem * multi);
			if (y % 4 == 0)
			{
				if (hex < 10)
					numhex[b] = hex + 48;
				else
					numhex[b] = hex + 55;
				multi = 1;
				hex = 0;
				y = 1;
				b++;
			}
			else
			{
				multi = multi * 2;
				y++;
			}
			numbi = numbi / 10;
		}
		if (y != 1)
			numhex[b] = hex + 48;
		if (y == 1)
			b--;
		for (b = b; b >= 0; b--)
			cout << numhex[b];
		cout << endl;
		break;
	case 5:
		char nume[10];
		int a, b, len ;
		cout << "El numero a convertit de hexadecimal a decimal es: ";
		cin >> nume;
		len = strlen(nume);
		for (a = 0; nume[a] != '\0'; a++)
		{
			len--;
			if (nume[a] >= '0' && nume[a] <= '9')
				b = nume[a] - 48;
			else if (nume[a] >= 'a' && nume[a] <= 'f')
				b = nume[a] - 87;
			else if (nume[a] >= 'A' && nume[a] <= 'F')
				b = nume[a] - 55;
			hexa += b * pow(16, len);
		}
		cout << hexa << endl;;
		break;
	case 6:
		char numhexa[10];
		cout << "El numero a convertir De Hexadecimal a binario es: ";
		cin >> numhexa;
		
		while (numhexa[x])
		{
			switch (numhexa[x])
			{
			case '0':
				cout << "0000";
				break;
			case '1':
				cout << "0001";
				break;
			case '2':
				cout << "0010";
				break;
			case '3':
				cout << "0011";
				break;
			case '4':
				cout << "0100";
				break;
			case '5':
				cout << "0101";
				break;
			case '6':
				cout << "0110";
				break;
			case '7':
				cout << "0111";
				break;
			case '8':
				cout << "1000";
				break;
			case '9':
				cout << "1001";
				break;
			case 'A':
			case 'a':
				cout << "1010";
				break;
			case 'B':
			case 'b':
				cout << "1011";
				break;
			case 'C':
			case 'c':
				cout << "1100";
				break;
			case 'D':
			case 'd':
				cout << "1101";
				break;
			case 'E':
			case 'e':
				cout << "1110";
				break;
			case 'F':
			case 'f':
				cout << "1111";
				break;
			}
			x++;
		}
		cout << endl;
		
		break;

	}
	cout << "convertir de nuevo?" << endl;
	cout << "1.SI"<< endl;
	cout << "0.NO" << endl;
	cin >> opc;
	} while (opc != 0);
	

	

}
