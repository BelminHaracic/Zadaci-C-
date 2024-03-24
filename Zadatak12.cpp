#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

/*
  Data je tekstualna datoteka pismo.txt. Napisati funkcije za:
a) ispis datoteke na standardni izlaz zadržavajuci strukturu po redovima;
b) prepis datoteke u novu mijenjajuci mala i velika slova;
c) ispisati datoteku u obrnutom redosljedu na izlaz (prva postaje zadnja, druga postaje pretposljednja rijec...)
d) ispitati da li je neka rijeè palindrom (isto znaèenje kada se èita i u obrnutom smjeru)
*/
int main(){
    fstream pismo1,pismo2;
    vector<string>niz;
    pismo1.open("pismo.txt",ios::in);
    if(pismo1.is_open()){
        string podaci;
        while(getline(pismo1,podaci)){
            cout<<podaci<<endl;
            niz.push_back(podaci);
        }
        pismo1.close();
    }else cout<<"Not open";

    vector<string>niz1;
    for(auto i:niz){
        for(int j=0;j<i.length();j++){
            if(islower(i[j])) i[j]=toupper(i[j]);
            else if(isupper(i[j])) i[j]=tolower(i[j]);
        }
        niz1.push_back(i);
    }
    pismo2.open("pismo2.txt",ios::out);
    if(pismo2.is_open()){
        string podaci;
        for(auto i: niz1){
            pismo2<<i<<endl;
        }
        pismo2.close();
    }else cout<<"Not open";
    string rijec;
    vector<string>rijeci;
    vector<string>palindromi;
    cout<<endl<<endl;
    for(auto i:niz1) {
        for (int j = 0; j < i.length(); j++) {
            if (i[j] != 32) rijec.push_back(i[j]);
            else {
                rijeci.push_back(rijec);
                rijec.clear();
            }
        }
        reverse(rijeci.begin(),rijeci.end());
        for(auto i: rijeci) {
            cout << i << " ";
            string poredi1,poredi2;
            poredi1=i;
            reverse(i.begin(),i.end());
            poredi2=i;
            if(poredi1==poredi2) palindromi.push_back(poredi1);
            //for(int j=0;j<i.length();j++){

            //}
        }
        cout<<endl;
        rijeci.clear();
    }
    cout<<endl;
    cout<<"Palindrtomi: ";
    for(auto i:palindromi){
        cout<<i<<endl;
    }
    cout<<endl;
    system("pause");
}

