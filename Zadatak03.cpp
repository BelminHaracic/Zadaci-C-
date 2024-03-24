#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

/*
   Napisati program u kome se èitaju podaci o radnicima iz postojeæe datoteke radnici.txt i kreira niz
struktura tipa radnik (ime, prezime, broj godina radnog staža, stepen struène spreme i plata), a zatim
štampa:
- ukupan broj radnika u datoteci,
- prosjeèna plata radnika,
- broj radnika koji imaju više od 5 godina radnog staža,
- imena radnika sa najvišim stepenom struène spreme,
- spisak radnika sortiranih po imenima.
*/
struct radnik{
    string ime;
    string prezime;
    int staz;
    int stepenSpreme;
    double plata;
};

bool poredi(radnik a, radnik b){
    if(a.ime<b.ime) return true;
    else return false;
}

int main(){
    fstream radniciUpis;
    int n;
    cout<<endl<<"Unesi broj radnika: ";
    cin>>n;
    radnik radnici[n];
    radniciUpis.open("radnici.txt",ios::out);
    if(radniciUpis.is_open()){
        for(int i=0;i<n;i++) {
            cout << "Unesite ime : ";
            cin >> radnici[i].ime;
            cout << endl << "Unesite prezime: ";
            cin >> radnici[i].prezime;
            cout << endl << "Unesite broj godina radnog staza: ";
            cin >> radnici[i].staz;
            do {
                cout << endl << "Unesite stepen strucne spreme(1,2 ili 3): ";
                cin >> radnici[i].stepenSpreme;
            }while(radnici[i].stepenSpreme!=1 && radnici[i].stepenSpreme!=2 && radnici[i].stepenSpreme!=3 );
            cout << endl << "Unesite platu: ";
            cin >> radnici[i].plata;
            radniciUpis << radnici[i].ime << " " << radnici[i].prezime << " " << radnici[i].staz << " "<< radnici[i].stepenSpreme <<  " "<< radnici[i].plata<<endl;
        }
        radniciUpis.close();
    }else cout<<"Not open";
    cout<<endl;
    int j=0;
    radnik IpsisRadnika[n];
    ifstream radniciIspis;
    radniciIspis.open("radnici.txt",ios::in);
    if(radniciIspis.is_open()){

        radnik temp;
        while(radniciIspis>>temp.ime>>temp.prezime>>temp.staz>>temp.stepenSpreme>>temp.plata){
            IpsisRadnika[j]=temp;
            j++;
        }
        radniciIspis.close();
    }else cout<<"Not open";
    cout<<endl<<"Broj radnika: "<<j;
    double sum=0;
    int godineBr=0;
    for(int i=0;i<n;i++){
        sum = sum + IpsisRadnika[i].plata;
        if(IpsisRadnika[i].staz>5) godineBr++;

    }
    cout<<endl<<"Prosjecna plata: "<<sum/j;
    cout<<endl<<"Broj radnika sa vise od 5 godina staza: "<<godineBr;
    cout<<endl<<"Imena radnika sa najvisom strucnom spremom: ";
    for(int i=0;i<n;i++) {
        if (IpsisRadnika[i].stepenSpreme == 3) {
            cout<<endl<<IpsisRadnika[i].ime<<" "<<IpsisRadnika[i].prezime;
        }
    }
    cout<<endl<<"Spisak radnika sortiranih po imenima: ";
    sort(IpsisRadnika,IpsisRadnika+n, poredi);
    for(int i=0;i<n;i++){
        cout<<endl<<IpsisRadnika[i].ime<<" "<<IpsisRadnika[i].prezime;
    }
    cout<<endl;
    system("pause");
}


