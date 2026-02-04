#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern float *l;
extern float *u;
extern float *m;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Use strided memory access by transposing the iteration order (k outermost)
    // This variant reorganizes loops to make k the outer loop, promoting reuse of l[i][k] and u[j][k] across multiple i,j
    for (k = 0; k < size; k++) {
        for (i = k; i < size; i++) {  // i starts from k since k <= min(i,j) implies i >= k
            int idx_l = i * size + k;  // Fixed column k in row i of l
            for (j = k; j < size; j++) {  // j starts from k
                int idx_u = j * size + k;  // Fixed column k in row j of u
                int idx_m = i * size + j;
                // Accumulate product: now accessing m with non-unit stride
                if (k == 0)
                    m[idx_m] = l[idx_l] * u[idx_u];
                else if (k <= ((i < j) ? i : j))
                    m[idx_m] += l[idx_l] * u[idx_u];
            }
        }
    }
}
