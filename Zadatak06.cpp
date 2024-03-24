#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

/*
   Kreiranje tekstualne datoteke „Podaci.txt“ u radnom direktorijumu i upis jednog reda koji sadrži: ime,
pol, godište i prosjek. Omoguciti dodavanje novih podataka u datoteku. Odrediti broj ženskih osoba i
osoba sa prosjekom veæim od 4.50 u datoteci Podaci.txt.
*/
int main(){
    fstream podaciUnos;
    podaciUnos.open("podaci.txt",ios::app);
    if(podaciUnos.is_open()){
        string ime,pol;
        int godiste;
        double prosjek;
        cout<<"Unesite ime: ";
        cin>>ime;
        do {
            cout << "Unesite pol(musko/zensko): ";
            cin>>pol;
        }while(pol!="musko" && pol!="zensko");
        cout<<"Unesite godiste: ";
        cin>>godiste;
        cout<<"Unesite prosjek: ";
        cin>>prosjek;
        podaciUnos<<ime<<","<<pol<<","<<godiste<<","<<prosjek<<","<<endl;
        podaciUnos.close();
    }else cout<<"Not open";
    cout<<endl;
    fstream podaciIspis;
    string podaci;
    podaciIspis.open("podaci.txt",ios::in);
    int brZ=0;
    int brO=0;
    vector<string>info;
    string rijec;
    if(podaciIspis.is_open()){
        while(!podaciIspis.eof()){
            getline(podaciIspis,podaci);
            for(int i=0;i<podaci.length();i++){
                if(podaci[i]!=','){
                    rijec.push_back(podaci[i]);
                }else {
                    info.push_back(rijec);
                    rijec.clear();
                }
            }
            if(info[1]=="zensko") brZ++;
            if(stod(info[3])>=4.51) brO++;
            info.clear();

        }
        podaciIspis.close();
    }else cout<<"Not open";
   if(info[1]=="zensko") brZ--;
   if(stod(info[3])>=4.51) brO--;
    cout<<endl<<"Broj zenskih osoba je "<<brZ;
    cout<<endl<<"Broj osoba sa prosjekom preko 4.5 "<<brO;
    cout<<endl;
    system("pause");
}

