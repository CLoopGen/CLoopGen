#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern int *a;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (nseq > 0) {
        i = 0;
        for (int outer = 0; outer < nseq; outer++) {
            a[i] = i;
            i++;
        }
    }
}
