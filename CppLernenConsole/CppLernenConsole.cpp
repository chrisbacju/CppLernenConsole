// CppLernenConsole.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <array>
using namespace std;

bool endProg = false;
char startProg = 0;
char board_TicTacToe[3][3] = { {'.', '.', '.'},{'.', '.', '.'},{'.', '.', '.'} };
int spieler = 1;
bool gewonnen = false;

char FunktionsMenu() 
{
    // Funktions Menu aufrufen
    char menu = 0;
    cout << "Verf\x81gbare Funktionen" << endl;
    cout << "1. Bubblesort" << endl;
    cout << "2. Taschenrechner" << endl;
    cout << "3. TicTacToe" << endl;
    cout << "4. Platzhalter" << endl;
    cout << "5. Platzhalter" << endl;
    cout << "W\x84hlen Sie eine Funktion aus oder (q) f\x81r abbruch" << endl << endl;
    cout << "Auswahl: ";
    cin >> menu;
    cout << endl;


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

    cout << endl;


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

}

void Taschenrechner(float z1, float z2, char op)
{
    float ergebnis = 0;
    cout << z1 << " " << op << " " << z2 << endl;

    if (op == '+')
    {
        ergebnis = z1 + z2;
    }
    else if (op == '-')
    {
        ergebnis = z1 - z2;
    }
    else if (op == '*')
    {
        ergebnis = z1 * z2;
    }
    else if (op == '/')
    {
        ergebnis = z1 / z2;
    }
    else
    {
        cout << "Ung\x81ltiger Operator, beende Taschenrechner" << endl;
    }

    cout << "Das Ergebnis ist: " << ergebnis;
}

void anzeige_TicTacToe()
{
    cout << "Spieler 1 - [X]\t Spieler 2 - [O]" << endl;
    cout << "  \t|\t" << "1" << "\t|\t" << "2" << "\t|\t" << "3" << "\t|" << endl;
    cout << "  \t|\t" << " " << "\t|\t" << " " << "\t|\t" << " " << "\t|" << endl;
    cout << "1.\t|\t" << board_TicTacToe[0][0] << "\t|\t" << board_TicTacToe[0][1] << "\t|\t" << board_TicTacToe[0][2] << "\t|" << endl;
    cout << "2.\t|\t" << board_TicTacToe[1][0] << "\t|\t" << board_TicTacToe[1][1] << "\t|\t" << board_TicTacToe[1][2] << "\t|" << endl;
    cout << "3.\t|\t" << board_TicTacToe[2][0] << "\t|\t" << board_TicTacToe[2][1] << "\t|\t" << board_TicTacToe[2][2] << "\t|" << endl;
}

void spielzug_TicTacToe()
{
    int reihe;
    int spalte;
    bool eingabe = false;
    cout << "Spieler " << spieler << " ist am Zug" << endl;
    
    do
    {
        cout << "Gebe Reihe ein: " << endl;
        cin >> reihe;
        cout << endl;
        if (reihe == 1 || reihe == 2 || reihe == 3)
        {
            eingabe = true;
        }
        else
        {
            cout << "Falsche Eingabe!!" << endl;
        }
    } while (!eingabe);

    eingabe = false;

    do
    {
        cout << "Gebe Spalte ein: " << endl;
        cin >> spalte;
        cout << endl;
        if (spalte == 1 || spalte == 2 || spalte == 3)
        {
            eingabe = true;
        }
        else
        {
            cout << "Falsche Eingabe!!" << endl;
        }
    } while (!eingabe);

    reihe = reihe - 1;
    spalte = spalte - 1;

    if (board_TicTacToe[reihe][spalte] != 'X' && board_TicTacToe[reihe][spalte] != 'O')
    {
        if (spieler == 1)
        {
            board_TicTacToe[reihe][spalte] = 'X';
            spieler = 2;
        }
        else if (spieler == 2)
        {
            board_TicTacToe[reihe][spalte] = 'O';
            spieler = 1;
        }
    }
    else
    {
        cout << "Feld schon belegt!" << endl;
    }
}

bool gewinn_TicTacToe()
{

    for (int x = 0; x < 3; x++)
    {
        // Prüfe gewinn HORIZONTAL
        if (board_TicTacToe[x][0] == board_TicTacToe[x][1] && board_TicTacToe[x][1] == board_TicTacToe[x][2])
        {
            if (board_TicTacToe[x][0] != '.' && board_TicTacToe[x][1] != '.' && board_TicTacToe[x][2] != '.')
            {
                gewonnen = true;
            }
            
        }
        // Prüfe gewinn SENKRECHT
        if (board_TicTacToe[0][x] == board_TicTacToe[1][x] && board_TicTacToe[1][x] == board_TicTacToe[2][x])
        {
            if (board_TicTacToe[0][x] != '.' && board_TicTacToe[1][x] != '.' && board_TicTacToe[2][x] != '.')
            {
                gewonnen = true;
            }
        }
    }

    // Prüfe gewinn DIAGONAL
    if (board_TicTacToe[0][0] == board_TicTacToe[1][1] && board_TicTacToe[1][1] == board_TicTacToe[2][2])
    {
        if (board_TicTacToe[0][0] != '.' && board_TicTacToe[1][1] != '.' && board_TicTacToe[2][2] != '.')
        {
            gewonnen = true;
        }
    }
    else if (board_TicTacToe[0][2] == board_TicTacToe[1][1] && board_TicTacToe[1][1] == board_TicTacToe[2][0])
    {
        if (board_TicTacToe[0][2] != '.' && board_TicTacToe[1][1] != '.' && board_TicTacToe[2][0] != '.')
        {
            gewonnen = true;
        }
    }

    // Prüfe ob Board voll


    return gewonnen;
}

void TicTacToe()
{
    while (!gewinn_TicTacToe()) 
    {
        anzeige_TicTacToe();
        spielzug_TicTacToe();
    }
    anzeige_TicTacToe();

    if (spieler == 1)
    {
        cout << "Spieler 2 hat gewonnen!" << endl;
    }
    else if (spieler == 2)
    {
        cout << "Spieler 1 hat gewonnen!" << endl;
    }
}

int main()
{


    while(!endProg)
    {
        startProg = FunktionsMenu();

        if (startProg == 'q')
        {
            endProg = true;
        }
        else 
        {
            switch (startProg)
            {
                case '1': // Bubblesort
                {
                    cout << "Bubblesort wird gestartet..." << endl;
                    int zahlen[] = { 1,17,5,23,4,119,26,76,33,2 };
                    int zahlenLength = sizeof(zahlen) / sizeof(zahlen[0]);
                    BubbleSort(zahlen, zahlenLength);
                    break;
                }
                case '2': // Taschenrechner
                {
                    // Taschenrechner eingabe
                    float zahl1 = 0;
                    float zahl2 = 0;
                    char op;
                    cout << "Taschenrechner wird gestartet..." << endl;
                    cout << "Erste Zahl eingeben: ";
                    cin >> zahl1;
                    cout << "Operator eingeben (+, -, *, /): ";
                    cin >> op;
                    cout << "Zweite Zahl eingeben: ";
                    cin >> zahl2;

                    // Taschenrechner funktion starten
                    Taschenrechner(zahl1, zahl2, op);
                    break;
                }
                case '3':
                {
                    cout << "TicTacToe wird gestartet..." << endl;
                    TicTacToe();
                    // Variablen auf Standard setzen falls neues Spiel
                    for (int x = 0; x < 3; x++)
                    {
                        for (int y = 0; y < 3; y++)
                        {
                            board_TicTacToe[x][y] = '.';
                        }
                    }
                    spieler = 1;
                    gewonnen = false;
                    break;
                }
                case '4':
                {
                    cout << "CASE 4";
                    break;
                }
                default:
                {
                    cout << "Ung\x81ltige Eingabe";
                    break;
                }
            }
        }

        cout << endl << endl << endl << endl << endl;


    }
    
    
    


}
