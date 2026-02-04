#include <stdio.h>

#include <inttypes.h>

typedef char int8;

typedef int8 s3cipid_t;

typedef int int32;

extern s3cipid_t *lc;
extern int32 n_lc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 temp_n_lc = 0;
    s3cipid_t val;
    for (; temp_n_lc < 1000; temp_n_lc++) { // Remove direct loop-carried dependency on n_lc
        val = lc[temp_n_lc];
        if (val < 0) break;
    }
    n_lc = temp_n_lc; // Write final value only once, eliminating WAW and WAR in loop
}
