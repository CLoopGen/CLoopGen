#include <stdio.h>

#include <inttypes.h>

extern char **ali1;
extern int nseq;
extern int alen;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = 2;
if (nseq > 0) {
    for (i = 0; i < nseq; i += stride) {
        ali1[i][alen] = '\x00';
        if (i + 1 < nseq) {
            ali1[i + 1][alen] = '\x00';
        }
    }
}
}
