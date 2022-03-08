#include <bits/stdc++.h>
using namespace std;

string Encrypt(string s, int width)
{
    string cipher = "";
    int rows = ceil(cipher.size() / (double)width);
    int rem = s.size() % width;
    int trailingSpacesCount = width - rem;

    for(int i=0; i<trailingSpacesCount; i++)
    {
        s += ' ';
    }

    for(int i=0; i<width; i++)
    {
        for(int j=i; j<s.size(); j+=width)
        {
            cipher += s[j];
        }
    }

    return cipher;
}

string Decrypt(string cipher, int width)
{
    string s = "";
    int rows = ceil(cipher.size() / (double)width);
    int rem = cipher.size() % width;


    for(int i=0; i<rows; i++)
    {
        for(int j=i; j<cipher.size(); j+=rows)
        {
            s += cipher[j];
        }
    }

    //Removing Trailing Spaces
    int spaceCount = 0;
    for(int i=s.size()-1; i>=0 ;i--)
    {
        if(s[i] == ' ') spaceCount++;
        else break;
    }
    s = s.substr(0, s.size()-spaceCount);

    return s;
}

int main()
{
    string msg;
    string cipher;
    int width;

    cout<<"Enter Table Width: ";
    cin>>width;

    ifstream fin;
    fin.open("p3_in.txt");
    getline(fin, msg);
    fin.close();

    cipher = Encrypt(Encrypt(msg, width), width);
    msg = Decrypt(Decrypt(cipher, width), width);

    ofstream fout;
    fout.open("p3_out.txt");
    fout<<"Encrypted: "<<cipher<<endl;
    fout<<"Decrypted: "<<msg<<endl;
    fout.close();

    return 0;
}
