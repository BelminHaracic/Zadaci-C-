#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;
/*
  Napisati program u kome se èitaju podaci o apartmana jedne turistièke agencije iz postojeæe datoteke
apartmani.txt i kreira niz struktura tipa apartman ( naziv, mjesto, broj kreveta, cjena), a zatim štampa:
- ukupan broj apartmana u datoteci,
- prosjeèna cjena apartmana u toj agenciji,
- broj apartmana u mjestu Paralia,
- naziv apartmana za 2 osobe sa najmanjom cjenom,
- spisak apartmana sortiranih po cjeni.
*/
struct apartman{
    string naziv;
    string mjesto;
    int brojKreveta;
    double cijena;
};

bool poredi(apartman a, apartman b){
    if(a.cijena<b.cijena) return 1;
    else return 0;
}

int main(){
    fstream apartmaniUpis;
    int n;
    cout<<endl<<"Unesi broj apartmana: ";
    cin>>n;
    apartman apartmans[n];
    apartmaniUpis.open("apartmani.txt",ios::out);
    if(apartmaniUpis.is_open()){
        for(int i=0;i<n;i++) {
            cout << "Unesite ime : ";
            cin >> apartmans[i].naziv;
            cout << endl << "Unesite mjesto: ";
            cin >> apartmans[i].mjesto;
            cout << endl << "Unesite broj kreveta: ";
            cin >> apartmans[i].brojKreveta;
            cout << endl << "Unesite cijenu: ";
            cin >> apartmans[i].cijena;
            apartmaniUpis << apartmans[i].naziv << " " << apartmans[i].mjesto << " " << apartmans[i].brojKreveta << " "<< apartmans[i].cijena << endl;
        }
        apartmaniUpis.close();
    }
    int j=0;
    apartman IpsisApartmani[n];
    ifstream apartmaniIspis;
    apartmaniIspis.open("apartmani.txt",ios::in);
    if(apartmaniIspis.is_open()){

        apartman temp;
        while(apartmaniIspis>>temp.naziv>>temp.mjesto>>temp.brojKreveta>>temp.cijena){
            IpsisApartmani[j]=temp;
            j++;
        }
        apartmaniIspis.close();
    }
    cout<<endl<<"Broj apartmana: "<<j;
    double sum=0;
    int paraliaBr=0;
    string ime2osobe;
    double najmanjaCijena=999999999;
    for(int i=0;i<n;i++){
        sum = sum + IpsisApartmani[i].cijena;
        if(IpsisApartmani[i].mjesto=="Paralia") paraliaBr++;
        if(IpsisApartmani[i].brojKreveta==2){
            if(IpsisApartmani[i].cijena<najmanjaCijena) {
                najmanjaCijena = IpsisApartmani[i].cijena;
                ime2osobe = IpsisApartmani[i].naziv;
            }
        }
    }
    cout<<endl<<"Prosjecna cijena apartmana: "<<sum/j;
    cout<<endl<<"Broj apartmana u Parelijij: "<<paraliaBr;
    cout<<endl<<"Ime najjeftinijeg apartmana za 2 osobe: "<<ime2osobe;
    cout<<endl<<"Apartmani po cijeni: "<<endl;
    cout<<endl;
    sort(IpsisApartmani,IpsisApartmani+n, poredi);
    for(int i=0;i<n;i++){
        cout<<endl<<IpsisApartmani[i].naziv<<", "<<IpsisApartmani[i].cijena;
    }
    cout<<endl;
    system("pause");

}

