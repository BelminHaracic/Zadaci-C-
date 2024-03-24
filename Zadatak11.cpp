#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

/*
   Data je datoteka ispiti.txt èiji redovi imaju sljedeæu strukturu:
brindexa predmet ocjena

Kreirajte ovu datoteku koristeæi Notepad i napunite je nekim testnim podacima. predmeti su zadani
imenom predmeta.
Zatim napravite program koji na ulazu traži broj predmeta, te ispisuje prosjeènu ocjenu i prolaznost
(procenat studenata koji su položili tj. dobili ocjenu 6 ili više). Takoðer treba program ispisat ukupan broj
predmeta koje je student odslušao, broj položenih, te prosjeènu ocjenu.
*/
int back = 0;

struct ispiti{
    int brIndexa;
    string predmet;
    int ocjena;

};

void Meni(){
    system("cls");
    cout<<endl<<"1. Unesite ime predmeta(NTP, RM, OEE) ";
    cout<<endl<<"2. Unesite broj indexa ";
    cout<<endl<<"3. EXIT";
}

void povratak() {
    do {
        cout << endl << "Za povratrak u meni unesite 1: ";
        cin >> back;
        if (back == 1) {
            system("cls");
            Meni();
        }

    }while (back != 1);
    back=0;
}

void indexi(vector<ispiti>ispit){
    system("cls");
    for(auto i : ispit){
        cout<<endl<<i.brIndexa;
    }
}


void studentInfo(vector<ispiti>ispit){
    int broj;
    cout<<endl<<"Unesi broj indexa: ";
    cin>>broj;
    int brPolozenih=0;
    int brOdlusanih=0;
    double sum=0;
    for(auto i : ispit){
        if(i.brIndexa == broj){
            if(i.ocjena>=6) {
                brPolozenih++;
                sum = sum + i.ocjena;
            }
            brOdlusanih++;
        }
    }
    cout<<endl;
    cout<<"Broj polozenih: "<<brPolozenih<<endl;
    cout<<"Broj odslusanih: "<<brOdlusanih<<endl;
    cout<<"Prosjecna ocjena: "<<sum/brPolozenih<<endl;
}

void predmetInfo(vector<ispiti>ispit) {
    string predmet;
    system("cls");
    cout << "Unesite predmet(RM,NTP,OEE): ";
    cin >> predmet;
    double prosjecnaOcjena = 0;
    double prosli=0;
    double padanje=0;
    for (auto i: ispit) {
        if (i.predmet == predmet) {
            if (i.ocjena >= 6) {
                prosjecnaOcjena = prosjecnaOcjena + i.ocjena;
                prosli++;
            }else padanje++;
        }
    }
    cout<<endl;
    cout<<"Prosjecna ocjena iz ovog predmeta: "<<prosjecnaOcjena/prosli;
    cout<<endl<<"Prolzanost: "<<(prosli/(prosli+padanje))*100<<"%"<<endl;
}

int main() {
    fstream ispit;
    vector<ispiti> lista;
    ispit.open("ispiti.txt", ios::in);
    if (ispit.is_open()) {
        ispiti temp;
        while (ispit >> temp.brIndexa >> temp.predmet >> temp.ocjena) {
            lista.push_back(temp);
        }
        ispit.close();
    } else cout << "Not open";
    cout << endl;
    int num;
    Meni();
    do {
        cout << endl << "Izaberi opciju: ";
        cin >> num;
        switch (num) {
            case 1:
                predmetInfo(lista);
                povratak();
                break;
            case 2:
                indexi(lista);
                studentInfo(lista);
                povratak();
                break;
        }
    }while(num!=3);
}
