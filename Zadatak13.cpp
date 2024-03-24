#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
   Zadatak zahtijeva pisanje programa koji �e de�ifrovati poruke koje su �ifrirane kako je opisano u
narednom primjeru. Dat je �ifrirani tekst: saoreecessinntfi. Potrebno je primjetiti da se sastoji od �esnaest
slova. Tekst je mogu�e postaviti u matricu veli�ine 4�4 �ime se dobije:

s a o r
e e c e
s s i n
n t f i

Tekst �e se de�ifrovati ukoliko se znakovi poredaju na osnovu kolona odozgo prema dolje, tj. prvo znakovi iz
prve kolone, potom znakovi iz druge kolone itd. Na osnovu navedenog, tra�ena rije� u primjeru je:
sesnaestocifreni. Program otvara fajl pod nazivom �test.txt�. U fajlu se nalaze �ifrirani tekstovi jedan ispod
drugog. Program treba ispisati de�ifrovane tekstove svaki u zasebnoj liniji. Ukoliko broj znakova ulaznog teksta
nije kvadrat nekog broja program ispisuje rije� GRESKA.
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

