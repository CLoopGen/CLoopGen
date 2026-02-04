#include <stdio.h>

#include <inttypes.h>

extern int mlen;
extern int alen;
extern int *inserts;
extern int *matmap;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 1; k <= mlen; k++) {
    if (inserts[k] < 0) {
        continue;
    }
    matmap[k] = alen;
    alen += inserts[k] + 1;
}
}
