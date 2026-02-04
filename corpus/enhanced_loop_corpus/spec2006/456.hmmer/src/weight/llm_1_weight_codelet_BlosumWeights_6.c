#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern int *c;
extern int *nmem;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (nseq > 0) {
        i = 0;
        for (; i < nseq; ) {
            nmem[c[i]]++;
            i++;
        }
    }
}
