#include <stdio.h>

#include <inttypes.h>

extern int mlen;
extern int alen;
extern int *inserts;
extern int *matmap;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_alen = alen;
    for (k = 1; k <= mlen; k++) {
        matmap[k] = temp_alen;
        temp_alen += inserts[k] + 1;
    }
    alen = temp_alen;
}
