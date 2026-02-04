#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern int *c;
extern int *nmem;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < nseq; j++) {
        int index = c[j];
        nmem[index] += 1;
    }
}
