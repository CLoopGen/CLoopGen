#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern int *a;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < nseq; j++) {
        for (i = j; i < j + 1 && i < nseq; i++)
            a[i] = i;
    }
}
