#include <stdio.h>

extern double ***u;
extern int n1;
extern int n2;
extern int n3;
extern int i1;
extern int i2;
extern int i3;



void loop(){
// Use consecutive memory layout simulation by reordering nested loops
// Prioritize innermost traversal along fastest-changing dimension (i1) first
for (i3 = 1; i3 < n3 - 1; i3++) {
    // First, handle boundary copies with reordered accesses for better spatial locality
    for (i1 = 0; i1 < n1; i1++) {
        for (i2 = 1; i2 < n2 - 1; i2++) {
            // Consecutive access in i1 allows compiler to optimize loads/stores
            if (i1 == n1 - 1) {
                u[i3][i2][i1] = u[i3][i2][1];  // Copy from i1=1 to i1=n1-1
            }
            if (i1 == 0) {
                u[i3][i2][i1] = u[i3][i2][n1 - 2];  // Copy from i1=n1-2 to i1=0
            }
        }
        // Perform cross-plane updates with direct indexing but now grouped consecutively
        u[i3][n2 - 1][i1] = u[i3][1][i1];
        u[i3][0][i1] = u[i3][n2 - 2][i1];
    }
}
}
