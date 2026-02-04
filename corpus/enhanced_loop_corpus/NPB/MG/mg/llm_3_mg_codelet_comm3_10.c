#include <stdio.h>

extern double ***u;
extern int n1;
extern int n2;
extern int n3;
extern int i1;
extern int i2;



void loop(){
    // Variant 2: Strided memory access with indirect indexing using pointer arithmetic
    // Introduce stride by accessing every second element in inner loop (simulated striding)
    // This creates non-unit stride access pattern across the i1 dimension
    
    for (i2 = 0; i2 < n2; i2++) {
        for (i1 = 0; i1 < n1; i1 += 2) {  // Stride of 2 in i1
            // Ensure bounds for strided access
            if (i1 + 1 <= n1) {
                // Process two elements per iteration to maintain correctness
                u[n3 - 1][i2][i1]     = u[1][i2][i1];
                u[0][i2][i1]          = u[n3 - 2][i2][i1];
                
                if (i1 + 1 < n1) {
                    u[n3 - 1][i2][i1+1] = u[1][i2][i1+1];
                    u[0][i2][i1+1]      = u[n3 - 2][i2][i1+1];
                }
            }
        }
    }
}
