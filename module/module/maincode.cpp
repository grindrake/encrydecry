#include <iostream>
#include <fstream>
#include <stdio.h>
#include "CryptoPP\aes.h"
#include "CryptoPP\md5.h"

using namespace std;

void main()
{
	static int inlen;
	byte *in, *out, *buf;
	buf = new byte[15];
	int blocksize = 16;
	int outlen = inlen + (inlen+1)%16;

	FILE* f;
	
	f = fopen ("../../tex.txt","r");
	
	if (f) 
	{
	fseek (f, 0, SEEK_END);
	inlen = ftell (f);
	rewind (f);

	in = new byte[inlen];
	out = new byte[outlen];

	fread (in, sizeof(char), 0, f);
	
	for (int i=0; i<inlen; i++)   // записываю текст в аут
	{
		fread(&(out[i]), sizeof(char), 1, f);
		cout<<out[i];
	}

	out[outlen]=0;

	cout<<"\n"<<"\n";

	fclose (f);
	}
	else
	{
		cout<<"Empty stream"<<"\n";
	}

	out[outlen]=0;

	for (int k = 0; k<9; k++)   // for ( int k = 0; k<(outlen/16); k++ )
	{
	memcpy(buf, out + k*16, 16);

	for (int j = 0; j < 16; j++)
	{
		cout<<buf[j];
	}
	cout<<"\n";
	}

	system("pause");
}