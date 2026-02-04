#include <stdio.h>

#include <inttypes.h>

extern char **ali1;
extern int nseq;
extern int alen;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < nseq; i++) {
        for (j = alen; j <= alen; j++) {
            ali1[i][j] = '\x00';
        }
    }
}
