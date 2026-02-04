#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[1300][1300];
extern double B[1300][1300];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_A, temp_B;
    for (i = 0; i < n; i++) {
        temp_A = ((double)i * (i + 2) + 2) / n;
        temp_B = ((double)i * (i + 3) + 3) / n;
        for (j = 0; j < n; j++) {
            A[j][i] = temp_A;
            B[j][i] = temp_B;
        }
    }
}
