#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[1300][1300];
extern double B[1300][1300];
extern double x[1300];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    x[i] = (double)(i % n) / n;
    for (j = 0; j < n; j++) {
        A[i][j] = (double)((i * j + 1) % n) / n;
        B[i][j] = (double)((i * j + 2) % n) / n;
    }
}
// Introduce a WAW dependency on x[i] to create loop-carried dependence
// This creates a write-after-write hazard on x[i] across iterations
for (i = 1; i < n; i++) {
    x[i] = x[i-1] + x[i]; // Loop-carried dependence: x[i] depends on previous x[i-1]
}
}
