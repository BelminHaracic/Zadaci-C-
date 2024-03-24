#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

/*
   Napisati program u kome se èitaju podaci o proizvodima u jednoj prodavnici auto-djelova iz postojeæe
datoteke proizvodi.txt i kreira niz struktura tipa proizvod ( naziv, proizvoðaè, cjena, kolièina),a zatim
štampa:
- ukupan broj proizvoda u datoteci,
- ukupna vrijednost svih proizvoda u prodavnici,
- spisak proizvoda èija je kolièina 0,
- broj proizvoda koje proizvodi FIAT,
- spisak proizvoda sortiranih po cjeni.
*/
struct proizvodi{
    string naziv;
    string proizvodac;
    double cijena;
    int kolicina;
};

int main() {
    int n;
    cout<<"Unesite broj proizvoda koje unosite: ";
    cin>>n;
    proizvodi products [n];
    ofstream proizvodUpis;
    proizvodUpis.open("Proizvod.txt",ios::app);
    if(proizvodUpis.is_open()){
        for(int i=0;i<n;i++){
            cout<<"Unesite ime proizvoda: ";
            cin>>products[i].naziv;
            cout<<endl<<"Unesite ime proizvodaca: ";
            cin>>products[i].proizvodac;
            cout<<endl<<"Unesite cijenu: ";
            cin>>products[i].cijena;
            cout<<endl<<"Unesite kolicinu: ";
            cin>>products[i].kolicina;
            proizvodUpis<<products[i].naziv<<","<<products[i].proizvodac<<","<<products[i].cijena<<","<<products[i].kolicina<<','<<endl;
        }
        proizvodUpis.close();
    } else cout<<"Not open"<<endl;

    ifstream proizvodCitanje;
    proizvodCitanje.open("Proizvod.txt",ios::in);
    int br=0;
    string podaci;
    stringstream ss;
    int sum=0;
    string line;
    vector<string>linije;
    string rijec;
    int fiatBrojac=0;
    vector<string>nulaProizvod;
    vector<int>cijene;
    if(proizvodCitanje.is_open()){
        while(proizvodCitanje.good()) {
            getline(proizvodCitanje,podaci);
            br++;
            for(int i=0;i<podaci.length();i++){
                if(podaci[i]!=','){
                   rijec.push_back(podaci[i]);
                }else {
                    linije.push_back(rijec);
                    rijec.clear();
                }

            }
            sum = sum + (stoi(linije[2]) * stoi(linije[3]));
            if(linije[3]=="0") nulaProizvod.push_back(linije[0]);
            if(linije[1]=="FIAT") fiatBrojac++;
            int cijena = stoi(linije[2]);
            cijene.push_back(cijena);
            linije.clear();
        }
        cout<<endl;
        cout<<"Broj proizvoda: "<<br-1;
        cout<<endl<<"Ukupna vrijednost proizvoda: "<<sum;
        cout<<endl<<"Proizvodi sa 0 kolicinom: "<<endl;
        for(auto i : nulaProizvod){
            cout<<i<<endl;
            }
        cout<<"Broja Fiata: "<<fiatBrojac;
        cout<<endl<<"Proizvodi sortirani po cijeni: "<<endl;
        sort(cijene.begin(),cijene.end());
        for(int i=1;i<br;i++){
            cout<<cijene[i]<<endl;
        }
        proizvodCitanje.close();
    }else cout<<"Not open"<<endl;

    cout<<endl;
    system("pause");
}


