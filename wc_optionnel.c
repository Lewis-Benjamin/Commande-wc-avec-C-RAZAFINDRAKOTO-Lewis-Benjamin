#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libwc.h"

int main(int argc, char* argv[])
{
	int c, l, w, L;
	int *tab = NULL;
	char* option = argv[1];
	char* filename = argv[2];
	char* txt = NULL;
	txt = allocation();
	c = charCount(filename, txt);
	w = wordCount(filename, txt);
	l = lineCount(filename, txt);
	tab = allocation2(l);
	L = LeagthCount(filename, txt, tab);
	readFile(filename, txt);
	afficheWc(filename, c, l, w, L, option);
	free(txt);
	return 0;
}
