#include <stdio.h>

#include <inttypes.h>

extern char **ali1;
extern int nseq;
extern int alen;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = nseq - 1; i >= 0; i--)
        ali1[i][alen] = '\x00';
}
