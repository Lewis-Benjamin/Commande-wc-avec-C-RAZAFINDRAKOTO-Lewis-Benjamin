#include <stdio.h>
#include <stdlib.h>
#include "libwc.h"

int main(int argc, char* argv[])
{
	int c, l, w;
	char* filename = argv[1];
	char* txt = NULL;
	txt = allocation();
	c = charCount(filename, txt);
	w = wordCount(filename, txt);
	l = lineCount(filename, txt);
	readFile(filename, txt);
	afficheWcDefaut(filename, c, l, w);
	free(txt);
	return 0;
}
