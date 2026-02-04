#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern int *a;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nseq; i += 2) {
        if (i + 1 < nseq) {
            a[i]     = i;
            a[i + 1] = i + 1;
        } else {
            a[i] = i;
        }
    }
}
