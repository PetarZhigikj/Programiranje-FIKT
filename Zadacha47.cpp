// Petar Zhigikj INKI818
// Kodiranje i dekodiranje na tekst spored daden kluc - zadaca 47
// Programa vo koja so pomosh na dve funkcii se vrshi kodiranje i dekodiranje na string do 600 karakteri, mozi da ima bukvi, brojki i prazni mesta.
// Da se vnesi 4 cifren broj i ASCII kodot na sekoj karakter da se promeni za razlikata na brojot na cirfi i najmalata cifra od brojot.


#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

string kodiranje(string nizaZnaci, int dolzina, int razlika)                  
{
    int i;
    for(i=0;i<dolzina;i++)
    {
        nizaZnaci[i]=(char)(nizaZnaci[i]+razlika);
    }
    return nizaZnaci;
}
string dekodiranje(string nizaZnaci, int dolzina, int razlika)
{
    int i;
    for(i=0;i<dolzina;i++)
    {
        nizaZnaci[i]=(char)(nizaZnaci[i]-razlika);
    }
    return nizaZnaci;
}
bool uslov (string niza, int dolzina)
{
    int i;
    bool p;
    for(i=0;i<dolzina;i++)
    {
        if((isalpha(niza[i]) || isdigit(niza[i]) || isblank(niza[i])) && dolzina<601)    //Uslovot za stringot (brojki, bukvi, prazni mesta i dolzina 600)
        {
            p=true;
        }
        else
        {
            p=false;
        }
        if (p==false)
        {
            break;
        }
    }
    return p;
}
int presmetajRazlika()                          
{
    int broj, najmala=9, cifra;
    cout<<"Vnesi 4 cifren broj osven 0000"<<endl;
    cin>>broj;
    while((broj<1000 || broj>9999) || broj==0000)
    {
        cout<<"Nevaliden broj, vnesi povtorno"<<endl;
        cin>>broj;
    }
    while(broj>0)
    {
        cifra=broj%10;
        if(cifra<najmala)
        {
            najmala=cifra;
        }
        broj/=10;
    }
    return 4-najmala;
}
int main()
{
    int razlika,opcija,dolzina;
    string niza, kodiranString, dekodiranString;
    bool proveri;
    do
    {
        cout<<"Izberi opcija za kodot: \n1. Kodiranje \n2. Dekodiranje \nVnesi 0 za izlez."<<endl;
        cin>>opcija;
        while(opcija!=1 && opcija!=2 && opcija!=0)
        {
            cout<<"Nevalidno. Obidi se povtorno."<<endl;
            cin>>opcija;
        }
        if(opcija==1)
        {
            cout<<"Vnesi string so maksimalna dolzina od 600 karakteri. Mozi da sodrzi bukvi, brojki i prazni mesta."<<endl;
            cin.clear();
            cin.sync();
            getline(cin,niza);
            dolzina=niza.length();
            proveri=uslov(niza,dolzina);
            while(proveri==false)
            {
                cout<<"Nevaliden string. Obidi se povtorno."<<endl;
                cin.clear();
                cin.sync();
                getline(cin,niza);
                dolzina=niza.length();
                proveri=uslov(niza,dolzina);
            }
            char nizaZnaci[dolzina];
            strcpy(nizaZnaci,niza.c_str());
            razlika=presmetajRazlika();
            kodiranString=kodiranje(nizaZnaci, dolzina, razlika);
            cout<<kodiranString<<endl;
        }
        if(opcija==2)
        {
            cout<<"Vnesi string so maksimalna dolzina od 600 karakteri."<<endl;
            cin.clear();
            cin.sync();
            getline(cin,niza);
            dolzina=niza.size();
            char nizaZnaci[dolzina];
            strcpy(nizaZnaci,niza.c_str());
            razlika=presmetajRazlika();
            dekodiranString=dekodiranje(nizaZnaci, dolzina, razlika);
            cout<<dekodiranString<<endl;
        }
    } while (opcija!=0);
    return 0;
}
