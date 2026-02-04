#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double x2[2000];
extern double y_2[2000];
extern double A[2000][2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i += 2) {
    for (j = 0; j < n; j++) {
        if (i < n) {
            x2[i] += A[j][i] * y_2[j];
        }
        if (i + 1 < n) {
            x2[i+1] += A[j][i+1] * y_2[j];
        }
    }
}
}
