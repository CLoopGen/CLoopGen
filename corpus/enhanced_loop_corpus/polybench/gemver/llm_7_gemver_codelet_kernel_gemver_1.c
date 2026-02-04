#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern double u1[2000];
extern double v1[2000];
extern double u2[2000];
extern double v2[2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < n; j++) {
        for (i = 0; i < n; i++) {
            // Reverse loop order: introduces different data access pattern and potential loop-carried dependence in j-dimension
            // Now column-major update: A[i][j] depends on previous iterations of i for same j (but still independent across j)
            A[i][j] += u1[i] * v1[j] + u2[i] * v2[j];
        }
    }
}
