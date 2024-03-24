#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

/*
   Napisati funkciju koja raèuna prosjeènu vrednost niza cjelih brojeva i broj elemenata jednakih 5. Glavna
funkcija koristi datoteku Ocjene.txt u kojoj se èuva broj uèenika u odeljenju (u prvom redu) i u svakom
sljedeæem: ime uèenika, prezime, strani jezik koji uèi (engleski/njemaèki) i ocjena. Štampati prosjecne
ocjene iz engleskog i njemaèkog i broj petica iz oba jezika.
*/
struct ucenik{
    string ime;
    string prezime;
    string jezik;
    int ocjena;
};

double prosjek(vector<ucenik>ucenici,int n){
    double sum=0;
    for(auto i : ucenici){
        sum = sum + i.ocjena;
    }
    return sum/n;
}

int BrojPetica(vector<ucenik>ucenici){
    int br=0;
    for(auto i : ucenici){
        if(i.ocjena==5) br++;
    }
    return br;
}

int main(){
    int n;
    fstream ocjeneUnos;
    ocjeneUnos.open("ocjene.txt",ios::out);
    if(ocjeneUnos.is_open()){
        cout<<endl<<"Unesite broj ucenika: ";
        cin>>n;
        ocjeneUnos<<n<<endl;
        for(int i=0;i<n;i++){
            string ime;
            cout<<"Unesite ime "<<i+1<<". ucenika: ";
            cin>>ime;
            string prezime;
            cout<<"Unesite prezime "<<i+1<<". ucenika: ";
            cin>>prezime;
            string jezik;
            do{
                cout<<"Unesite strani jezik "<<i+1<<". ucenika(engleski ili njemacki): ";
                cin>>jezik;
            }while(jezik!="engleski" && jezik!="njemacki");
            int ocjena;
            do{
                cout<<"Unesite ocjenu iz stranog jezika za "<<i+1<<". ucenika: ";
                cin>>ocjena;
            }while(ocjena>5 || ocjena<1);
            ocjeneUnos<<ime<<" "<<prezime<<" "<<jezik<<" "<<ocjena<<endl;
        }
        ocjeneUnos.close();
    }else cout<<"NIje otvoreno";
    cout<<endl;
    fstream ocjenaIspis;
    string podaci;

    vector<ucenik>ucenici;
    ocjenaIspis.open("ocjene.txt",ios::in);
    if(ocjenaIspis.is_open()){
        ucenik temp;
        string linija;
        getline(ocjenaIspis,linija);
        int j=0;
        while(ocjenaIspis>>temp.ime>>temp.prezime>>temp.jezik>>temp.ocjena){
            ucenici.push_back(temp);
            j++;
        }
        ocjenaIspis.close();
    }else cout<<"NIje otvoreno";
    cout<<endl;

    vector<ucenik>engleski;
    for(auto i : ucenici){
        if(i.jezik=="engleski"){
            engleski.push_back(i);
        }
    }
    vector<ucenik>njemacki;
    for(auto i : ucenici){
        if(i.jezik=="njemacki"){
            engleski.push_back(i);
        }
    }


    cout<<"Prosjecna ocjena iz engleskog "<<prosjek(engleski,engleski.size());
    cout<<endl<<"Prosjecna ocjena iz njemackog "<<prosjek(njemacki,njemacki.size());
    cout<<endl<<"Broj petica iz engleskog: "<<BrojPetica(engleski);
    cout<<endl<<"Broj petica iz njemackog: "<<BrojPetica(njemacki);
    cout<<endl;
    system("pause");

}

