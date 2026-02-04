#include <stdio.h>

#include <inttypes.h>

extern char **argv;
extern int bottom;
extern int middle;
extern int top;
extern char *tem;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled loop (tripled arithmetic), reduced trip count
    int n = len / 3;
    for (i = 0; i < n; i++) {
        int idx1 = bottom + 3*i;
        int idx2 = top - (middle - bottom) + 3*i;
        
        // Unroll three iterations into one
        tem = argv[idx1];
        argv[idx1] = argv[idx2];
        argv[idx2] = tem;

        tem = argv[idx1 + 1];
        argv[idx1 + 1] = argv[idx2 + 1];
        argv[idx2 + 1] = tem;

        tem = argv[idx1 + 2];
        argv[idx1 + 2] = argv[idx2 + 2];
        argv[idx2 + 2] = tem;
    }
    
    // Handle remaining elements
    for (; i < len; i++) {
        tem = argv[bottom + i];
        argv[bottom + i] = argv[top - (middle - bottom) + i];
        argv[top - (middle - bottom) + i] = tem;
    }
}
