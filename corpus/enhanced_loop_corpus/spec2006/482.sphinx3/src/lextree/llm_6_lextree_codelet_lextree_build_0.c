#include <stdio.h>

#include <inttypes.h>

typedef char int8;

typedef int8 s3cipid_t;

typedef int int32;

extern s3cipid_t *lc;
extern int32 n_lc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 i;
    s3cipid_t prev_val = 0;
    for (i = 0; i < n_lc + 1; i++) {
        if (i >= 0 && lc[i] >= 0) {
            n_lc = i;
            prev_val = lc[i]; // Introduce RAW dependency: read after write of lc[i]
        }
    }
}
