#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

/*
   U datotekama grupa1.txt, grupa2.txt i grupa3.txt prati se rad uèenika na vježbama iz programiranja. U
svakom redu datoteka je ime uèenika, prosjeèna ocjena vježbi i broj vježbi koje je uèenik propustio.
Proèitati sve podatke i u datoteku izvjestaj.txt upisati sortirane uèenike, njihove zakljuène ocjene i
komentar da li je uèenik zadovoljio minimum rada na vježbama (manje od 5 propuštenih vježbi).
*/
struct student{
    string ime;
    double prosjek;
    int propustene;
};

void UpisGrupe(fstream &Grupa,student *grupa1,int n1,string ImeDatoteke){
    Grupa.open(ImeDatoteke,ios::out);
    if(Grupa.is_open()){
        for(int i=0;i<n1;i++){
            cout<<endl<<"Unesi ime "<<i+1<<". studenta: ";
            cin>>grupa1[i].ime;
            cout<<endl<<"Unesi prosjek "<<i+1<<". studenta: ";
            cin>>grupa1[i].prosjek;
            cout<<endl<<"Unesi broj propustenih vjezbi "<<i+1<<". studenta: ";
            cin>>grupa1[i].propustene;
            Grupa<<grupa1[i].ime<<" "<<grupa1[i].prosjek<<" "<<grupa1[i].propustene<<endl;
        }
        Grupa.close();
        system("cls");
    }else cout<<"Nije otvoreno";
}

void Ispis(fstream &IspisGrupa,student *Ispisgrupa,string ImeDatoteke){
    int j=0;
    IspisGrupa.open(ImeDatoteke,ios::in);
    if(IspisGrupa.is_open()){
        student temp;
        while(IspisGrupa>>temp.ime>>temp.prosjek>>temp.propustene){
            Ispisgrupa[j]=temp;
            j++;
        }
        IspisGrupa.close();
    }else cout<<"Not open";
}

bool poredi(student a,student b){
    if(a.ime<b.ime) return true;
    else return  false;
}

int main(){
    int n1,n2,n3;
    fstream Grupa1,Grupa2,Grupa3;
    cout<<endl<<"Unesite broj studenata u prvoj grupi: ";
    cin>>n1;
    cout<<endl<<"Unesite broj studenata u drugoj grupi: ";
    cin>>n2;
    cout<<endl<<"Unesite broj studenata u trecoj grupi: ";
    cin>>n3;
    student grupa1[n1],grupa2[n2],grupa3[n3];
    UpisGrupe(Grupa1,grupa1,n1,"grupa1.txt");
    cout<<endl;
    UpisGrupe(Grupa2,grupa2,n2,"grupa2.txt");
    cout<<endl;
    UpisGrupe(Grupa3,grupa3,n3,"grupa3.txt");
    cout<<endl;
    fstream IspisGrupa1,IspisGrupa2,IspisGrupa3;
    student Ispisgrupa1[n1],Ispisgrupa2[n2],Ispisgrupa3[n3];
    Ispis(IspisGrupa1,Ispisgrupa1,"grupa1.txt");
    cout<<endl;
    Ispis(IspisGrupa2,Ispisgrupa2,"grupa2.txt");
    cout<<endl;
    Ispis(IspisGrupa3,Ispisgrupa3,"grupa3.txt");
    cout<<endl;
    int n = n1+n2+n3;
    vector<student> grupa;
    for(int i=0;i<n1;i++){
        grupa.push_back(Ispisgrupa1[i]);
    }
    for(int i=0;i<n2;i++){
        grupa.push_back(Ispisgrupa2[i]);
    }
    for(int i=0;i<n3;i++){
        grupa.push_back(Ispisgrupa3[i]);
    }
    sort(grupa.begin(),grupa.end(),poredi);
    cout<<endl;
    fstream izvjestaj;
    izvjestaj.open("izvjestaj.txt",ios::out);
    if(izvjestaj.is_open()){
        for(auto i : grupa){
            string komentar;
            if(i.propustene>5) komentar = "Nije zadovoljio";
            else komentar = "Zadovoljio";
            izvjestaj<<i.ime<<" "<<i.prosjek<<" "<<komentar<< endl;
        }
        izvjestaj.close();
    }else cout<<"Not Open";
    system("pause");
}

