#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(1252);
    const char* currency[10] = { "EUR", "USD", "JPY", "GBP", "AUD", "CAD", "CHF", "HKD", "KRW", "XAU" };     // Array einführen
    const double currencytoEUR[10] = { 1.00, 1.18, 126.32, 0.9, 1.65, 1.56, 1.08, 9.16, 1400.27, 0.000607};     // Array für Umrechnungsfaktoren einführen
    const char* currency_symbol[10] = { "\u20AC", "$", "\u00a5", "\u20A4", "A$", "C$", "Fr.", "HK$", "KRW", "XAU"};       //Array für Symbole von Währungen

    int fromCurrency = -1;      //Standardwerte festlegen
    int toCurrency = -1;        //Standardwerte festlegen

    for (int i = 0; i < 10; i++) {
        cout << "[" << i + 1 << "] " << currency[i] << endl;        // Liste anzeigen
    }

    while (fromCurrency < 0 || fromCurrency > 10)
    {
        cout << "Konvertiere von Waehrung: "; cin >> fromCurrency; cout << endl;       //Eingabe der Ausgangswährung wird nur akzeptiert wenn sie zwischen 0 und 11 liegt, es wird ansonsten solange weiter nachgefragt wie sie ausserhalb dieses Bereichs liegt
    }


    while (toCurrency < 0 || toCurrency > 10 || toCurrency == fromCurrency)
    {
        cout << "Konvertiere zu Waehrung: "; cin >> toCurrency; cout << endl;       //Eingabe der Zielwährung wird nur akzeptiert wenn sie zwischen 0 und 11 liegt und sie nicht gleich Ausgangswährung ist
    }

    fromCurrency--;     //Array startet mit 0, wird gemacht um richtigen Faktor zu bekommen
    toCurrency--;       //Array startet mit 0, wird gemacht um richtigen Faktor zu bekommen

    cout << "Konvertiere " << currency[fromCurrency] << " zu " << currency[toCurrency] << endl;      //Stellt für den User dar was gemacht wird bzw eingegeben wurde

    double valueToConvert = 0;      //Setzt eine neue Variable fest die zu Anfang 0 ist


    while (valueToConvert <= 0)
    {
        cout << "Bitte geben sie den zu konvertierenden Betrag ein: "; cin >> valueToConvert; cout << endl;      //In dieser Schleife wird so lange nach dem Betrag gefragt wie er kleiner oder gleich null ist
    }

    double outputValue = (valueToConvert / currencytoEUR[fromCurrency]) * currencytoEUR[toCurrency];        //Hier wird der Betrag der Zielwährung berechnet
    system("CLS");

    cout << currency[fromCurrency] << " -> " << currency[toCurrency] << endl << endl;
    cout << "Ihr eingegebener Betrag lautet: " << valueToConvert << currency_symbol[fromCurrency] << endl << endl;
    cout << "Der Wechselkurs betraegt 1 " << currency[fromCurrency] << " = " << currencytoEUR[toCurrency] << " " << currency[toCurrency] << endl << endl;
    cout << valueToConvert << " " << currency_symbol[fromCurrency] << " => " << outputValue << " " << currency_symbol[toCurrency] << endl;        //Letztendliche Ausgabe der berechneten Daten



    system("pause");
}