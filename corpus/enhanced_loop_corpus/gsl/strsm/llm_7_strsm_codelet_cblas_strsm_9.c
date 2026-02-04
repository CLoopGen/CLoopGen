#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float alpha;
extern float *B;
extern  int ldb;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_alpha = alpha;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2 - 1; j += 2) {
            // Unroll by 2 and remove potential WAR/WAW conflicts via independent accesses
            B[ldb * i + j] *= local_alpha;
            if (j + 1 < n2) {
                B[ldb * i + j + 1] *= local_alpha;
            }
        }
        // Handle odd-sized n2 with cleanup
        if (n2 % 2 == 1) {
            B[ldb * i + n2 - 1] *= local_alpha;
        }
    }
}
