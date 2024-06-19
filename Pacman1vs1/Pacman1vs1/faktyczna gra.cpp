#include "headers.h"
#include <conio.h> //zbieranie inputu bez entera
#include <chrono>
#include <thread>

const chrono::milliseconds przerwa(300); // 0.3 s;

void dodanie_punktu(vector<vector<char>> mapa, int punkty) //dodawanie zebranego punktu na mape
{
    for(int i = punkty; i < 5; i++)
    {
        Punkt P = Punkt();
        P.place(mapa);
    }
}

void print(vector<vector<char>> mapa, int punkty_gracza, int punkty_bota) //wypisywanie aktualnego stanu planszy
{
    cout << "Gracz  Bot\n";
    cout << punkty_gracza << "      " << punkty_bota << "\n\n";

    for(auto x: mapa)
    {
        for(auto y: x)
            cout << y;

        cout << '\n';
    }
}

int gra()
{


    b:
    int punkty_gracza = 0;
    int punkty_bota = 0;
    int curr_liczba_punktow = 0;
    bool czy_dalej = true; //kontynuowanie gry
    vector<vector<char>> plansza; // mapa na której trwa rozgrywka
    stack<punkt> sciezka; // sciezka do punktu ktora bedzie podazac bot


    pair <int, int> punkt; //wspolrzedne wylosowanego kolejnego punktu na mapie 
    Player player = Player();
    Bot bot = Bot();

    //wylosowanie mapy i rozstawienie punktów
    for(auto x: read_map("test.txt"))
        plansza.push_back(x);

    plansza = player.place(plansza);
    plansza = bot.place(plansza);

    char znak = ' '; //zmienna w której przechowywany jest wciśnięty klawisz
    auto ostatni_ruch = chrono::steady_clock::now(); // czas ostatniego ruchu gracza

    while(czy_dalej)
    {
        auto teraz = chrono::steady_clock::now(); //obecny czas;
        auto roznica_czasu = chrono::duration_cast<chrono::milliseconds>(teraz - ostatni_ruch);

        if(punkty_gracza == 30 || punkty_bota == 30) break; //sprawdzenie warunku wygranej/przegranej

        print(plansza, punkty_gracza, punkty_bota);

        //sekcja bota

        if(roznica_czasu.count() >= przerwa.count())
        {
            sciezka = bfs(plansza, pozycja_bota); //stwozenie sciezki dla bota;
            plansza[pozycja_bota.first][pozycja_bota.second] = ' ';
            pozycja_bota.first = sciezka.top().y;
            pozycja_bota.second = sciezka.top().x;
            plansza[pozycja_bota.first][pozycja_bota.second] = 'B';
            sciezka.pop();
            if(sciezka.empty())
            {
                punkty_bota++;
                dodanie_punktu(plansza, curr_liczba_punktow);
                 
            }
            ostatni_ruch = chrono::steady_clock::now();
        }

        this_thread::sleep_for(chrono::milliseconds(100));


        //sekcja gracza

    if(_kbhit()) //sprawdzenie czy został wciśnięty klawisz
    {
        znak = char(_getch()); //przechwytywanie klwisza
        ostatni_ruch = chrono::steady_clock::now();

        if(znak == 'w')
        {
            if(plansza[player.x-1][ player.y] == '*')
            {
                punkty_gracza++;
                dodanie_punktu(plansza, curr_liczba_punktow);
                 
                plansza[ player.x][ player.y] = ' ';
                 player.x--;
                plansza[ player.x][ player.y] = 'P';
            }

            if(plansza[player.x-1][ player.y] != '#' && plansza[player.x-1][ player.y] != 'B') //zabezpiecznie przed wyjsciem poza mape
            {
                plansza[ player.x][ player.y] = ' ';
                 player.x--;
                plansza[ player.x][ player.y] = 'P';
            }
        }
        else if(znak == 's')
        {
            if(plansza[player.x+1][ player.y] == '*')
            {
                punkty_gracza++;
                dodanie_punktu(plansza, curr_liczba_punktow);
                 
                plansza[ player.x][ player.y] = ' ';
                 player.x++;
                plansza[ player.x][ player.y] = 'P';
            }
            else if(plansza[player.x+1][ player.y] != '#' && plansza[player.x+1][ player.y] != 'B') //zabezpiecznie przed wyjsciem poza mape
            {
                plansza[ player.x][ player.y] = ' ';
                 player.x++;
                plansza[ player.x][ player.y] = 'P';
            }
        }
        else if(znak == 'a')
        {
            if(plansza[ player.x][player.y-1] == '*')
            {
                punkty_gracza++;
                dodanie_punktu(plansza, curr_liczba_punktow);
                 
                plansza[ player.x][ player.y] = ' ';
                 player.y--;
                plansza[ player.x][ player.y] = 'P';
            }
            else if(plansza[ player.x][player.y-1] != '#' && plansza[ player.x][player.y-1] != 'B') //zabezpiecznie przed wyjsciem poza mape
            {
                plansza[ player.x][ player.y] = ' ';
                 player.y--;
                plansza[ player.x][ player.y] = 'P';
            }
        }
        else if(znak == 'd')
        {
            if(plansza[ player.x][player.y+1] == '*')
            {
                punkty_gracza++;
                dodanie_punktu(plansza, curr_liczba_punktow);
                 
                plansza[ player.x][ player.y] = ' ';
                 player.y++;
                plansza[ player.x][ player.y] = 'P';
            }
            else if(plansza[ player.x][player.y+1] != '#' && plansza[ player.x][player.y+1] != 'B') //zabezpiecznie przed wyjsciem poza mape
            {
                plansza[ player.x][ player.y] = ' ';
                 player.y++;
                plansza[ player.x][ player.y] = 'P';
            }
        }
    }

        system("cls");
    }

    if(punkty_bota == 30)
    cout << "\n\nPRZEGRANA\n\n";
    else
    cout << "\n\nWYGRANA\n\n";

    cout << "Gracz  Bot\n";
    cout << punkty_gracza << "      " << punkty_bota;

    cout << '\n';

    system("pause");

    system("cls");
    cout << "Czy chcesz grac jeszcze?\n1. Tak\n2. Nie\n";


    a:
    znak = char(_getch()); //przechwytywanie klwisza
    if(znak == '1') goto b;
    if(znak == '2') return 0;
    else goto a;
}