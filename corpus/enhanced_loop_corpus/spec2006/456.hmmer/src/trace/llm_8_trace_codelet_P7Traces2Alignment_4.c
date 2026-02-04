#include <stdio.h>

#include <inttypes.h>

extern int mlen;
extern int alen;
extern int *inserts;
extern int *matmap;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 1; k <= mlen; k += 2) {
        if (k <= mlen) {
            matmap[k] = alen;
            alen += inserts[k] + 1;
        }
        if (k + 1 <= mlen) {
            matmap[k + 1] = alen;
            alen += inserts[k + 1] + 1;
        }
    }
}
