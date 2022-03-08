#include <bits/stdc++.h>
using namespace std;

string Encrypt(string s)
{
    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = (((s[i] - 'a') + 3) % 26) + 'a';
        }

        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = (((s[i] - 'A') + 3) % 26) + 'A';
        }
    }
    return s;
}

string Decrypt(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = (((s[i] - 'a') + 26 - 3) % 26) + 'a';
        }

        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = (((s[i] - 'A') + 26 - 3) % 26) + 'A';
        }
    }
    return s;
}

int main()
{
    string msg;
    string cipher;

    ifstream fin;
    fin.open("p_1_in.txt");
    getline(fin, msg);
    fin.close();

    cipher = Encrypt(msg);
    msg = Decrypt(cipher);

    ofstream fout;
    fout.open("p_1_out.txt");
    fout << "Encrypted : " << cipher << endl;
    fout << "Decrypted : " << msg << endl;
    fout.close();

    return 0;
}
