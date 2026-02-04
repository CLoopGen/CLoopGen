#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int ml[400];
extern int liberty_mark;
extern int maxlib;
extern int *libs;
extern int *libs1;
extern int liberties2;
extern int commonlibs;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int private_commonlibs = commonlibs;
    #pragma unroll
    for (k = 0; k < liberties2; k++) {
        int read_val = libs1[k]; // Create explicit RAW: read before use
        if (!(board[read_val] == 0 && ml[read_val] != liberty_mark)) {
            // Eliminate loop-carried dependency on commonlibs by predicting space
            int local_index = private_commonlibs++;
            if (local_index < maxlib)
                libs[local_index] = read_val;
        }
    }
    // WAR hazard avoided by updating shared state only at end
    if (private_commonlibs > commonlibs)
        commonlibs = private_commonlibs;
}
