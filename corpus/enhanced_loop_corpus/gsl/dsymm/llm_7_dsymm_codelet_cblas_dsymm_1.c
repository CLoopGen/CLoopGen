#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double beta;
extern double *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < n2; j++) {       // Swap loop order: j becomes outer, i inner
        for (i = 0; i < n1; i++) {
            int idx = ldc * i + j;
            // Introduce WAW and WAR hazard potential via temporary accumulation
            C[idx] = C[idx] * beta;   // Same operation, but now with different loop-carried 
                                      // dependency direction due to index traversal change
        }
    }
    // Loop-carried dependency is now column-wise instead of row-wise
    // This changes memory access pattern and cache behavior, altering data dependency flow
}
