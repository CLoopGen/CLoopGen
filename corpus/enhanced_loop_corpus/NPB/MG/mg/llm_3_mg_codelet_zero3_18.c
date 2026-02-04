#include <stdio.h>

extern double ***z;
extern int n1;
extern int n2;
extern int n3;
extern int i1;
extern int i2;
extern int i3;



void loop(){
    // Variant 2: Strided memory access with a fixed stride pattern across the first dimension
    int stride = 2;
    // Ensure initialization covers all elements, including those in strided and remaining iterations
    for (i3 = 0; i3 < n3; i3 += stride) {
        for (i2 = 0; i2 < n2; i2++) {
            for (i1 = 0; i1 < n1; i1++) {
                z[i3][i2][i1] = 0.;
                // Handle adjacent index if within bounds (unrolling-like pattern)
                if (i3 + 1 < n3) {
                    z[i3 + 1][i2][i1] = 0.;
                }
            }
        }
    }
}
