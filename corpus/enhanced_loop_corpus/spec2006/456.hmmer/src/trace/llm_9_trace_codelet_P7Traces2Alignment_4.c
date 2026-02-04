#include <stdio.h>

#include <inttypes.h>

extern int mlen;
extern int alen;
extern int *inserts;
extern int *matmap;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_sum = 0;
    for (k = 1; k <= mlen; k++) {
        temp_sum += inserts[k] + 1;
        matmap[k] = alen + temp_sum - (inserts[k] + 1);
    }
    alen += temp_sum;
}
