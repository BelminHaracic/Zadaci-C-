#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

/*
   U datoteci ulaz.txt nalazi se broj elemenata niza. Proèitati taj broj, alocirati niz te dužine i unjeti
vrijednosti elemenata tog niza. Izraèunati prosjeènu vrijednost, proširiti niz za jedno mjesto i ubaciti
prosjek u niz. U novu datoteku Izlaz.txt upisati sortiran dati niz.
*/
int main() {
    int n=0;
    fstream ulaz;
    ulaz.open("ulaz.txt", ios::in);
    if (ulaz.is_open()) {
        string podaci;
        getline(ulaz,podaci);
        n = stoi(podaci);
        ulaz.close();
    }else cout<<"Not open";
    double *niz = new double[n];
    for(int i=0;i<n;i++){
        cout<<"["<<i<<"]: ";
        cin>>niz[i];
    }
    cout<<endl;
    double sum=0;
    double prosjek;
    for(int i=0;i<n;i++){
        sum = sum + niz[i];
    }
    prosjek = sum/n;
    double *temp = new double[n+1];
    copy(niz,niz+n,temp);
    delete [] niz;
    niz = temp;
    niz[n] = prosjek;
    cout<<endl;
    fstream izlaz;
    izlaz.open("izlaz.txt",ios::out);
    sort(niz,niz+n);
    if(izlaz.is_open()){
        for(int i=0;i<n+1;i++){
            izlaz<<niz[i]<<endl;
        }
        izlaz.close();
    }else cout<<"Not open";
    cout<<endl<<"Posaci su smjesteni u datoteci izlaz.txt"<<endl;
    system("pause");
}
