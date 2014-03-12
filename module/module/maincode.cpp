#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

void main()
{
	long n;
	char* insides;
	char* output;
	FILE* f;

	f = fopen ("text1.txt","rt");
	fseek (f, 0, SEEK_END);
	n = ftell (f);
	insides = new char[n];
	output = new char[n];
	rewind(f);
	fread (&insides, sizeof(char), 1, f);

	for (int i=0; i<30; i++)
	{
		fread(&(output[i]), sizeof(char), 1, f);
		cout<<output[i];
	}	

	system("pause");
}