#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

void main()
{
	int n;
	char* insides;
	char* output;
	FILE* f;

	f = fopen ("../../text1.txt","r");
	if (!f) {}
	else
	{
	fseek (f, 0, SEEK_END);
	}
	if (!f) {}
	else
	{
	n = ftell (f);
	}
	if (!f) {}
	else
	{
	rewind (f);
	}

	insides = new char[n];
	output = new char[n];

	fread (&insides, sizeof(char), 1, f);
	
	for (int i=0; i<(sizeof(char)*n); i++)
	{
		fread(&(output[i]), sizeof(char), 1, f);
		cout<<output[i];
	}
	
	if (!f) {}
	else
	{
	fclose (f);
	}

	system("pause");
}