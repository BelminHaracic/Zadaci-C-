#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
   Zadatak zahtijeva pisanje programa koji æe dešifrovati poruke koje su šifrirane kako je opisano u
narednom primjeru. Dat je šifrirani tekst: saoreecessinntfi. Potrebno je primjetiti da se sastoji od šesnaest
slova. Tekst je moguæe postaviti u matricu velièine 4×4 èime se dobije:

s a o r
e e c e
s s i n
n t f i

Tekst æe se dešifrovati ukoliko se znakovi poredaju na osnovu kolona odozgo prema dolje, tj. prvo znakovi iz
prve kolone, potom znakovi iz druge kolone itd. Na osnovu navedenog, tražena rijeè u primjeru je:
sesnaestocifreni. Program otvara fajl pod nazivom ”test.txt”. U fajlu se nalaze šifrirani tekstovi jedan ispod
drugog. Program treba ispisati dešifrovane tekstove svaki u zasebnoj liniji. Ukoliko broj znakova ulaznog teksta
nije kvadrat nekog broja program ispisuje rijeè GRESKA.
test.txt
*/
int main(){
    fstream test;
    test.open("test.txt",ios::in);
    vector<string>sifre;
    if(test.is_open()){
        string podaci;
        while(getline(test,podaci)){
            sifre.push_back(podaci);
        }
        test.close();
    }else cout<<"NOT OPEN";
    for(auto i:sifre){
        if(floor(sqrt(i.length()))==ceil(sqrt(i.length()))){
            int a=sqrt(i.length());
           char niz[a][a];
           int br=0;
               for (int j = 0; j < a; j++) {
                   for (int x = 0; x < a; x++) {
                       niz[j][x] = i[br];
                       br++;
                   }
               }
           cout<<endl;
           for(int j=0;j<a;j++){
               for(int x=0;x<a;x++){
                   cout<<niz[x][j];
               }
           }
           cout<<endl;
        }else cout<<endl<<"GRESKA"<<endl;
    }


    cout<<endl;
    system("pause");
}

