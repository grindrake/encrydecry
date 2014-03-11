#include <iostream>
#include <fstream>

void main()
{
	char input[100];
	FILE* f;
	f = fopen ("text1.txt","r");
	input = fread (&n, sizeof(char), 1, f);
}