#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern int *c;
extern int *nmem;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < nseq; i++) {
        int val = c[i];
        for (j = 0; j < 3; j++) {
            nmem[val + j]++;
        }
    }
}
