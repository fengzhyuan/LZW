# Introduction 
A C++ STL based implementation of LZW (Lempel–Ziv–Welch) compression algorithm;
inspired by the following repos:

- https://github.com/pieroxy/lz-string (author website: http://pieroxy.net/blog/pages/lz-string/index.html)
- https://github.com/jawa-the-hutt/lz-string-csharp

# APIs

Implemented the following encoder/decoders:
 - basic implementation `Compress` and `Decompress`
 - UTF16 `CompressToUTF16` and `DecompressFromUTF16`
 - Base64 `CompressToBase64` and `DecompressFromBase64`

 Not yet implemented:
 - encode to/decode from EncodeURIComponent (mainly for JavaScript)

 Util functions:
 - `ToWStr`: convert `std::string` to `std::wstring`
 - `ToStr`: truncted version of string convertion; convert `std::wstring` to `std::string`
   based on `MSDN`: If wcstombs_s encounters a wide character it cannot convert to a multibyte character, it puts 0 in *pReturnValue, sets the destination buffer to an empty string, sets errno to EILSEQ, and returns EILSEQ.
   (`wcstombs` and `wsctombs_s` always return error code `42`, any one knows how
   to do it correctly?)
    
 ~~Each method provides 2 APIs for different parameters `std::string` and `std::wstring`, respectively.~~

 Test case (non-standard / messy version):

 The file `data.json` is used for test purpose; below is the output of local machine:
 `[Test UTF16]`

`string length:1161529 compress ratio:21`

`0.438`

`checking result [compressed == decompressed]:1`

`[Test UTF16]`

`string length:1161529 compress ratio:8`

`0.431`

`checking result [compressed == decompressed]:1`
 
