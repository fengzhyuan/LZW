
#include "LZString.h"
#include "URLEncode.h"
#include <sstream>
#include <fstream>
#include <streambuf>
#include <iostream>
#include <functional>

using namespace std;

typedef wstring(*fn_encoder)(string  &);
typedef wstring(*fn_decoder)(wstring &);

void TestCase(string case_name, string &str_data, fn_encoder encoder, fn_decoder decoder) {
    time_t t1, t2;

    t1 = clock(); 
    wstring compressed = encoder(str_data);
    wstring decompressed = decoder(compressed);
    string str_recovered = LZString::ToStr(decompressed);
    t2 = clock() - t1;

    cout << case_name << endl;
    cout << "=================\n";
    cout << "string length:" << str_data.length() << " compress ratio:" << 
        (float)(decompressed.length()/compressed.length()) << endl;
    
    cout << "time elapsed (s): " << (float)t2/CLOCKS_PER_SEC << endl;

    cout << "checking correctness: [string compressed == decompressed]:" << (str_data == str_recovered) << endl;
    cout << "=================\n\n";
}
void Test() {
    ifstream t("data.json");
    string str((istreambuf_iterator<char>(t)), istreambuf_iterator<char>());
    str += "€?!##$$%^^&*()+}|{><";

    fn_encoder encoder;
    fn_decoder decoder;

    encoder = &LZString::Compress;
    decoder = &LZString::Decompress;
    TestCase("[Test Default algorithm]", str, encoder, decoder);

    encoder = &LZString::CompressToUTF16;
    decoder = &LZString::DecompressFromUTF16;
    TestCase("[Test UTF16]", str, encoder, decoder);

    encoder = &LZString::CompressToBase64;
    decoder = &LZString::DecompressFromBase64;
    TestCase("[Test Base64]", str, encoder, decoder);
}
int main(int argc, char* argv[])
{
    Test();
    return 0;
}
