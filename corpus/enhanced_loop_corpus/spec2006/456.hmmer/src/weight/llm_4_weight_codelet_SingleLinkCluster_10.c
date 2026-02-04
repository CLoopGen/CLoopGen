#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern int *a;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nseq; i++) {
        if (i % 2 == 0) {
            a[i] = i;
        }
    }
}
