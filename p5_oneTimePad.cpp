#include <bits/stdc++.h>
using namespace std;

string Encrypt(string s)
{
    string cipher = "";
    string pad = "";
    int charCount = 0;

    ifstream fin;
    fin.open("p5_pad_encrypt.txt");
    fin >> pad;
    fin.close();

    for (int i = 0, j = 0; i < s.size(); i++, j++)
    {
        if (s[i] == ' ')
        {
            cipher += s[i];
            j--;
            continue;
        }

        cipher += (((s[i] - 'A') + (pad[j] - 'A')) % 26) + 'A';
        charCount++;
    }

    pad = pad.substr(charCount, pad.size() - charCount);
    ofstream fout;
    fout.open("p5_pad_encrypt.txt");
    fout << pad;
    fout.close();

    return cipher;
}

string Decrypt(string cipher)
{
    string s = "";
    string pad = "";
    int charCount = 0;

    ifstream fin;
    fin.open("p5_pad_decrypt.txt");
    fin >> pad;
    fin.close();

    for (int i = 0, j = 0; i < cipher.size(); i++, j++)
    {
        if (cipher[i] == ' ')
        {
            s += cipher[i];
            j--;
            continue;
        }

        s += (((cipher[i] - 'A') + 26 - (pad[j] - 'A')) % 26) + 'A';

        charCount++;
    }

    pad = pad.substr(charCount, pad.size() - charCount);
    ofstream fout;
    fout.open("p5_pad_decrypt.txt");
    fout << pad;
    fout.close();

    return s;
}

int main()
{
    string msg;
    string cipher;

    ifstream fin;
    fin.open("p5_in.txt");
    getline(fin, msg);
    fin.close();

    cipher = Encrypt(msg);
    msg = Decrypt(cipher);

    ofstream fout;
    fout.open("p5_out.txt");
    fout << "Encrypted: " << cipher << endl;
    fout << "Decrypted: " << msg << endl;
    fout.close();

    return 0;
}
