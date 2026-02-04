#include <stdio.h>

#include <inttypes.h>

extern int mlen;
extern int alen;
extern int *inserts;
extern int *matmap;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = mlen; k >= 1; k--) {
        matmap[k] = alen;
        alen += inserts[k] + 1;
    }
}
