#include <iostream>
#include <fstream>
#include <stdio.h>
#include "CryptoPP\aes.h"
#include "CryptoPP\md5.h"

using namespace std;

void main()
{
	long n=0;
	long length; 
	char* insides;
	byte* output;
	FILE* f;

	f = fopen ("../../tex.txt","r");

	if (f) 
	{
	fseek (f, 0, SEEK_END);
	n = ftell (f);
	rewind (f);
	insides = new char[n];
	output = new byte[n];
	rewind(f);
	fread (insides, sizeof(char), 0, f);
	
	for (int i=0; i<(sizeof(char)*n); i++)
	{
		fread(&(output[i]), sizeof(char), 1, f);
		cout<<output[i];
	}
	
	fclose (f);
	}
	else
	{
		cout<<"Empty stream"<<"\n";
	}

	system("pause");
}