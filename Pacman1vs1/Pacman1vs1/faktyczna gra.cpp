#include "headers.h"
#include <conio.h> //zbieranie inputu bez entera
#include <chrono>
#include <thread>

const chrono::milliseconds przerwa(300); // 0.3 s;

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
    int win_condition = 10;
    bool czy_dalej = true; //kontynuowanie gry

    vector<vector<char>> plansza; // mapa na której trwa rozgrywka
    stack <Krok> sciezka; // sciezka do punktu ktora bedzie podazac bot



    Player player = Player();
    Bot bot = Bot();
    Punkt punkt = Punkt();

    //wylosowanie mapy i rozstawienie punktów
    for(auto x: read_map("test.txt"))
        plansza.push_back(x);

    plansza = player.place(plansza);
    plansza = bot.place(plansza);
    for (int i = 0; i < 5; i++) {
        plansza = punkt.place(plansza);
    }

    char znak = ' '; //zmienna w której przechowywany jest wciśnięty klawisz
    auto ostatni_ruch = chrono::steady_clock::now(); // czas ostatniego ruchu gracza

    while(czy_dalej)
    {
        auto teraz = chrono::steady_clock::now(); //obecny czas;
        auto roznica_czasu = chrono::duration_cast<chrono::milliseconds>(teraz - ostatni_ruch);

        if(punkty_gracza == win_condition || punkty_bota == win_condition) break; //sprawdzenie warunku wygranej/przegranej

        print(plansza, punkty_gracza, punkty_bota);

        //sekcja bota

        if(roznica_czasu.count() >= przerwa.count())
        {
            sciezka = bot.bfs(plansza, bot); //stwozenie sciezki dla bota;
            plansza[bot.y][bot.x] = ' ';
            bot.y = sciezka.top().y;
            bot.x = sciezka.top().x;
            plansza[bot.y][bot.x] = 'B';
            sciezka.pop();
            if(sciezka.empty())
            {
                punkty_bota++;
                punkt.place(plansza);
                 
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
                plansza = punkt.place(plansza);
                 
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
                plansza = punkt.place(plansza);
                 
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
                plansza = punkt.place(plansza);
                 
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
                plansza = punkt.place(plansza);
                 
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
    return 0;
}