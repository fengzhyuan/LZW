
#include "LZString.h"
#include "URLEncode.h"
#include <sstream>
#include <fstream>
#include <streambuf>
#include <iostream>

using namespace std;

void Test() {
    ifstream t("C:\\Users\\zfeng\\data.json");
    string str((istreambuf_iterator<char>(t)), istreambuf_iterator<char>());
    
    wstring compress, decompress;
    string dst;
    time_t t1, t2;

    str += "€???????????!##$$%^^&*()+}|{?><??";
    t1 = clock(); 
    compress = LZString::CompressToUTF16(str);
    decompress = LZString::DecompressFromUTF16(compress);
    dst = LZString::ToStr(decompress);
    t2 = clock() - t1;
    cout << "[Test UTF16]\n";
    cout << "string length:" << str.length()*sizeof(char) << " compress ratio:" << 
        (float)(decompress.length()/compress.length()) << endl;
    cout << (float)t2/CLOCKS_PER_SEC << endl;
    cout << "checking result [compressed == decompressed]:" << (bool)(str == dst) << endl;

    t1 = clock(); 
    compress = LZString::CompressToBase64(str);
    decompress = LZString::DecompressFromBase64(compress);
    dst = LZString::ToStr(decompress);
    t2 = clock() - t1;
    cout << "[Test UTF16]\n";
    cout << "string length:" << str.length()*sizeof(char) << " compress ratio:" << 
        (float)(decompress.length()/compress.length()) << endl;
    cout << (float)t2/CLOCKS_PER_SEC << endl;
    cout << "checking result [compressed == decompressed]:" << (bool)(str == dst) << endl;

    //t1 = clock();
    //wstr = s2ws(str);
    //wstrto = LZString::CompressToBase64(wstr);
    //wstrfrom = LZString::DecompressFromBase64(wstrto);
    //to = ws2s(wstrfrom);
    //t2 = clock() - t1;
    //cout << "[Test Base64]\n";
    //cout << "string length:" << str.length()*sizeof(char) << " compress ratio:" << 
    //(float)(wstr.length()*sizeof(char)/(wstrto.length()*sizeof(wchar_t))) << endl;
    //cout << (float)t2/CLOCKS_PER_SEC << endl;
    //cout << "checking result is equal:" << (bool)(str == to) << endl;

    getchar();
}
int main(int argc, char* argv[])
{
    Test();
    return 0;
}
