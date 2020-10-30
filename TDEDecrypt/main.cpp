#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <intrin.h>

#define _BYTE unsigned __int8

const char* const a = "599Cc51887A8cb0C20F9CdE34cf9e0A535E5cAd1C26c7b562596ACC207Ae9A0bfB3E3161f31af5bEf1c2f064b3628174D83BF6E0739D9D6918fD9C2Eba02D5aD\0";
const char* const b = "0C3b676fe8d7188Cde022F71632830F36b98b181aD48Fed160006eA59\0";

//auto input = "D:\\Steam\\steamapps\\common\\Teardown\\data\\music\\menu.ogg.tde";
//auto output = "D:\\Project\\TD\\test\\menu.ogg";
auto input = "D:\\Steam\\steamapps\\common\\Teardown\\data\\gfx\\foam.png.tde";
auto output = "D:\\Project\\TD\\test\\foam.png";

int main()
{
	FILE* infile = fopen(input, "rb");
	FILE* outfile = fopen(output, "wb");
	fseek(infile, 0, SEEK_END);
	size_t len = ftell(infile);
	fseek(infile, 0, SEEK_SET);

	for (size_t i = 0; i < len; i++)
	{
		int dat = fgetc(infile);
		fputc(dat ^ a[i & 0x7F] ^ b[i % 57], outfile);
	}

	fclose(infile);
	fclose(outfile);

	return 0;
}