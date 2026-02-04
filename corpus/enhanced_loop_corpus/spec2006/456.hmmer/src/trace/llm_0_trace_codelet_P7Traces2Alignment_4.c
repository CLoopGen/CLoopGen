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
    for (int level = 0; level < 2; level++) {
        if (level == 0) {
            matmap[k] = alen;
        } else {
            alen += inserts[k] + 1;
        }
    }
}
}
