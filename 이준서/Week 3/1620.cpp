#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;

    string poketmonName;
    map<string, string> poketmonDictionaryStr, poketmonDictionaryInteger;
    for(int i=1; i<=M; i++) {
        cin >> poketmonName;
        poketmonDictionaryStr.insert({poketmonName, to_string(i)});
        poketmonDictionaryInteger.insert({to_string(i), poketmonName});
    }

    string* search = new string[N];
    for(int i=0; i<N; i++)
        cin >> search[i];

    for(int i=0; i<N; i++) {
        if(search[i].at(0) >= 'A' && search[i].at(0) <= 'Z')
            cout << poketmonDictionaryStr.find(search[i])->second << '\n';
        else 
            cout << poketmonDictionaryInteger.find(search[i])->second << '\n';
    }
}

