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
for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
        double temp = 0.0;
        if (v1[j] != 0.0)
            temp += u1[i] * v1[j];
        if (v2[j] != 0.0)
            temp += u2[i] * v2[j];
        A[i][j] += temp;
    }
}
