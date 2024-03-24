#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

/*
  Neopravdani izostanci uèenika èuvaju se u datoteci Izostanci.txt. Proèitati ih i napraviti niz. Pomoæu
funkcija izraèunati: ukupan broj izostanaka u odjeljenju, prosjeèan broj izostanaka, koliki je najveæi broj i
koliko ima uèenika bez neopravdanih izostanaka.
*/
struct ucenik{
    string ime;
    int izostanak;
};

void unos(fstream &izostanci,int n){
    string ime;
    int  izostanakovi;
    izostanci.open("izostanci.txt",ios::out);
    for(int i=0;i<n;i++){
        cout<<endl<<"Unesite ime ucenika: ";
        cin>>ime;
        cout<<endl<<"Unesite broj izostanaka: ";
        cin>>izostanakovi;
        izostanci<<ime<<" "<<izostanakovi<<endl;
    }
    izostanci.close();
}

void Ispis(fstream &izostanci,ucenik *ucenici){
    izostanci.open("izostanci.txt",ios::in);
    ucenik temp;
    int j=0;
    while(izostanci>>temp.ime>>temp.izostanak){
        ucenici[j] = temp;
        j++;
    }
}

int UkupnoIzostanci(ucenik *ucenici,int n){
    int broj=0;
    for(int i=0;i<n;i++){
        broj = broj + ucenici[i].izostanak;
    }
    return broj;
}

int prosjekIzostanaka(ucenik *ucenici,int n){
    return UkupnoIzostanci(ucenici,n)/n;
}

int najveci(ucenik *ucenici,int n){
    int broj=-1;
    for(int i=0;i<n;i++){
        if(ucenici[i].izostanak>broj) broj = ucenici[i].izostanak;
    }
    return broj;
}

void nulaIzostanci(ucenik *ucenici,int n){
    vector<ucenik> ucenicovi;
    for(int i=0;i<n;i++){
        if(ucenici[i].izostanak==0) ucenicovi.push_back(ucenici[i]);
    }

    for(auto i : ucenicovi){
        cout<<endl<<i.ime;
    }
}

int main() {
    int n;
    fstream izostanciUnos;
    cout<<endl<<"Unesite broj ucenika: ";
    cin>>n;
    cout<<endl;
    unos(izostanciUnos,n);
    cout<<endl;
    ucenik ucenici[n];
    fstream izostanciIspis;
    Ispis(izostanciIspis,ucenici);
    cout<<endl<<"Ukupan broj izostanaka: "<<UkupnoIzostanci(ucenici,n);
    cout<<endl<<"Prosjek izostanaka: "<<prosjekIzostanaka(ucenici,n);
    cout<<endl<<"Najveci broj izostanaka: "<<najveci(ucenici,n);
    cout<<endl<<"Ucenici bez izostanaka: ";
    nulaIzostanci(ucenici,n);
    cout<<endl;
    system("pause");


}
