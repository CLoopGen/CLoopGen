#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern int *a;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nseq; i++) {
        if (i % 3 == 0) {
            continue;
        }
        a[i] = i;
    }
}
