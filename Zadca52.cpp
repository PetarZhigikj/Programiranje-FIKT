#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Covek

{

int redbroj;

string Ime;

float  poeni;

Covek(int redbroj, const string& Ime)

: redbroj(redbroj), Ime(Ime), poeni(poeni)
{

}

bool operator<(const Covek& p) const

{

return Ime < p.Ime; 

}

};


struct SortProfilePointers

{
bool operator()(const Covek* lhs, const Covek* rhs) const

{

return *lhs < *rhs;

}

};

int main()

{

vector<Covek*> Profiles;

Profiles.push_back(new Covek(3, "Petar"));

Profiles.push_back(new Covek(2, "Sara"));

Profiles.push_back(new Covek(7, "Andrej"));

Profiles.push_back(new Covek(5, "David"));

Profiles.push_back(new Covek(6, "Darko"));

Profiles.push_back(new Covek(4, "Marija"));

Profiles.push_back(new Covek(1, "Stefan"));


sort(Profiles.begin(), Profiles.end(), SortProfilePointers());

for(const auto* p: Profiles)

cout << p->redbroj << ": " << p->Ime << '\n';

for(auto* p: Profiles)

delete p;

    vector<string> v;
    ofstream outFile("INKI818PetarZhigikj.txt");
    for (const auto &e : v) outFile << e << "\n";
}