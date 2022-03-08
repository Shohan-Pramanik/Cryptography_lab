#include <bits/stdc++.h>
using namespace std;

map<string, string> hashmap;
map<string, string> revHashmap;

void GetHash()
{
    ifstream fin;
    fin.open("hashfile.txt");
    string key, value;

    //Loop until End of FIle
    while(!fin.eof())
    {
        fin>>key>>value;
        hashmap[key] = value;
        revHashmap[value] = key;
    }
    fin.close();
}

string Encrypt(string s)
{
    string cipher = "";
    for(int i=0; i<s.size(); i+=3)
    {
        string tmp = "";
        tmp += s[i];
        tmp += s[i+1];
        tmp += s[i+2];

        cipher += hashmap[tmp];
    }
    return cipher;
}

string Decrypt(string cipher)
{
    string s = "";
    for(int i=0; i<cipher.size(); i+=3)
    {
        string tmp = "";
        tmp += cipher[i];
        tmp += cipher[i+1];
        tmp += cipher[i+2];

        s += revHashmap[tmp];
    }
    return s;
}

int main()
{
    string msg;
    string cipher;

    ifstream fin;
    fin.open("p2_in.txt");
    fin>>msg;
    fin.close();

    GetHash();
    cipher = Encrypt(msg);
    msg = Decrypt(cipher);

    ofstream fout;
    fout.open("p2_out.txt");
    fout<<"Encrypted: "<<cipher<<endl;
    fout<<"Decrypted: "<<msg<<endl;
    fout.close();

    return 0;
}
