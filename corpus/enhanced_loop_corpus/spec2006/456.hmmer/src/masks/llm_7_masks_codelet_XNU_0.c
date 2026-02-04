#include <stdio.h>

#include <inttypes.h>

extern int len;
extern int i;
extern int *hit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= len; i += 2) {
        hit[i] = 0;
        if (i + 1 <= len) {
            hit[i + 1] = 0;  // Eliminate loop-carried dependency by unrolling and writing independent elements
        }
    }
}
