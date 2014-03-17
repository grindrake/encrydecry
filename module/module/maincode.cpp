#include <iostream>
#include <fstream>
#include <stdio.h>
#include "CryptoPP\aes.h"
#include "CryptoPP\md5.h"

using namespace std;

void main()
{
	static int inlen;  
	byte *in, *out, *ptr;
	ptr = new byte[15];
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
	ptr = out;

	fread (in, sizeof(char), 0, f);
	
	for (int i=0; i<inlen; i++)   // записываю текст в аут
	{
		fread(&(out[i]), sizeof(char), 1, f);
		cout<<out[i];
	}

	out[inlen]=0;

	cout<<"\n"<<"\n";

	fclose (f);
	}
	else
	{
		cout<<"Empty stream"<<"\n";
	}

	for (int i=-1; i<=outlen; i+=blocksize)
	{
		cout<<ptr;
		cout<<"\n";
	}

	system("pause");
}