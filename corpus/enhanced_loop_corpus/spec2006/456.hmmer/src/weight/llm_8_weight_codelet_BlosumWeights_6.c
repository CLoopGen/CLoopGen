#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern int *c;
extern int *nmem;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nseq; i += 2) {
        if (i < nseq) nmem[c[i]]++;
        if (i + 1 < nseq) nmem[c[i + 1]]++;
    }
}
