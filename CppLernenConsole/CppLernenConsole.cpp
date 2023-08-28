// CppLernenConsole.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <array>
using namespace std;



int FunktionsMenu() 
{
    // Funktions Menu aufrufen
    int menu = 0;
    cout << "Verf\x81gbare Funktionen" << endl;
    cout << "1. Bubblesort" << endl;
    cout << "2. Taschenrechner" << endl;
    cout << "3. TicTacToe" << endl;
    cout << "4. Platzhalter" << endl;
    cout << "5. Platzhalter" << endl;
    cout << "W\x84hlen Sie eine Funktion aus oder (0) f\x81r abbruch" << endl << endl;
    cout << "Auswahl: ";
    cin >> menu;
    cout << endl << endl << endl;


    return menu;
}

void BubbleSort(int zahlenParam[10], int lengthParam)
{
    int sort = 0;

    // Zahlenliste VOR sortierung ausgeben
    cout << "Zahlenliste VOR sortierung:  ";

    for (int i = 0; i < lengthParam; i++)
    {
        cout << zahlenParam[i] << ", ";
    }

    cout << endl << endl;


    // Bubblesort sortierung
    for (int x = 0; x < lengthParam; x++)
    {
        for (int y = 0; y < lengthParam - 1; y++)
        {
            if (zahlenParam[y] > zahlenParam[y + 1])
            {
                sort = zahlenParam[y + 1];
                zahlenParam[y + 1] = zahlenParam[y];
                zahlenParam[y] = sort;
            }
        }
    }


    // Zahlenliste NACH sortierung ausgeben
    cout << "Zahlenliste NACH sortierung: ";

    for (int i = 0; i < lengthParam; i++)
    {
        cout << zahlenParam[i] << ", ";
    }

    cout << endl << endl;
}



int main()
{
    bool stop = false;
    
    while(!stop)
    {
        switch (FunktionsMenu())
        {
            case 1: // Bubblesort
            {
                int zahlen[] = { 1,17,5,23,4,119,26,76,33,2 };
                int zahlenLength = sizeof(zahlen) / sizeof(zahlen[0]);
                BubbleSort(zahlen, zahlenLength);
                break;
            }
            case 2:
            {
                cout << "Taschenrechner" << endl << endl;
                break;
            }
            case 3:
            {
                cout << "TicTacToe" << endl << endl;
                break;
            }
            case 4:
            {
                cout << "CASE 4" << endl << endl;
                break;
            }
            case 0:
            {
                bool stop = true;
                break;
            }
            default:
            {
                cout << "Ung\x81ltige Eingabe" << endl << endl;
                break;
            }

        }

    }
    
    
    


}
