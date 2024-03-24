#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
/*
  Napisati program u kome se èitaju podaci o uèenicima iz postojeæe datoteke uèenici.txt i kreira niz
struktura tipa uèenik (ime, prezime, razred (1-4), uspjeh, prosjeèna ocjena), a zatim štampa:
- ukupan broj uèenika u datoteci,
- broj uèenika 4. razreda,
- imena uèenika koji imaju odlièan uspjeh,
- ime uèenika koji ima najbolju prosjeènu ocjenu,
- imena uèenika sortiranih po razredima.
*/
string crte = "\n------------------------------------------------------------------------------------------------------------------\n";

struct Ucenik{
    char ime[15];
    char prezime[20];
    int razred;
    int uspjeh;
    float prosjecnaOcjena;
}ucenik[50];
void sortiraj(Ucenik *, int);
void sortiraj1(Ucenik *, int);
int main() {
    ifstream ucenici("ucenici.txt");
    int brU = 0;
    if(ucenici.is_open()){
    
        while(ucenici >> ucenik[brU].ime >> ucenik[brU].prezime >> ucenik[brU].razred >>
                ucenik[brU].uspjeh >> ucenik[brU].prosjecnaOcjena){brU++;}
        cout << crte << "Ukupan broj ucenika navedenih u datoteci je: " << brU;

        int brojac4 = 0;
        for(int i = 0; i < brU; i++){
            if(ucenik[i].razred)brojac4++;}
        cout << crte << "Broj ucenika u 4. razredu: " << brojac4;

        cout << crte << "Imena ucenika sa odlicnim uspjehom: ";
        for(int i = 0; i < brU; i++){
            if(ucenik[i].uspjeh == 5) cout << endl << ucenik[i].ime;}

        //ime ucenika koji ima najbolju prosjecnu ocjenu
        float temp = 0; char temp1;
        for(int i = 0; i < brU; i++){
            if(ucenik[i].prosjecnaOcjena > temp){
                temp = ucenik[i].prosjecnaOcjena;
                temp1 = reinterpret_cast<char>(ucenik[i].ime);
            }
        }
        cout << crte << "Ime ucenika sa najboljim uspjehom: " << temp1;

        
        sortiraj(ucenik, brU);
        int brojacIspisa = 0;
        cout << crte << "Ispis ucenika sortiranih prema razredu: \n";
        cout << setw(10) << "Redni broj" << setw(20) << "Ime i prezime" << setw(20) << "Razred" <<
             setw(30) << "Uspjeh" << setw(10) << "Prosjecna ocjena" << crte;
        for(int i = 0; i < brU; i++){
            cout << setw(6) << ++brojacIspisa << "." << setw(20) << ucenik[i].ime << " " << ucenik[i].prezime
                 << setw(20) << ucenik[i].razred << setw(20) << ucenik[i].uspjeh << setw(15)
                 << ucenik[i].prosjecnaOcjena << crte;
        }
    } else {
        cout << crte << "Trazena datoteka ne postoji ili nije otvorena" << crte;
    }
    system("pause");
}

void sortiraj(Ucenik *u, int br){
    for(int i = 0; i < br; i++){
        for(int y = 0; y < br; y++){
            if(u[i].razred < u[y].razred)swap(u[i], u[y]);
        }
    }
}
