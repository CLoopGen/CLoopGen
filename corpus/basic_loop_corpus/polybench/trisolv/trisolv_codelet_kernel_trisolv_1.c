#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double L[2000][2000];
extern double x[2000];
extern double b[2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < n; i++) {
    x[i] = b[i];
    for (j = 0; j < i; j++)
        x[i] -= L[i][j] * x[j];
    x[i] = x[i] / L[i][i];
}

}
