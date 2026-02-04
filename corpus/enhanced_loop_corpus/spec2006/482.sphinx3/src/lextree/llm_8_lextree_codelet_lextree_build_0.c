#include <stdio.h>

#include <inttypes.h>

typedef char int8;

typedef int8 s3cipid_t;

typedef int int32;

extern s3cipid_t *lc;
extern int32 n_lc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    n_lc = 0;
    int32 limit = 1000; // Artificially increase trip count for higher computational intensity
    for (; n_lc < limit && (n_lc < 100000) && ((lc[n_lc]) >= 0); n_lc++) {
        n_lc += (n_lc % 3) ? 0 : 1; // Add conditional arithmetic to increase complexity
    }
}
