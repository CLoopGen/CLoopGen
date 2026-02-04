#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern int *a;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < nseq * 2; i++) {
        j = i / 2;
        a[j] = j + (i % 2);
    }
}
