#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double x1[2000];
extern double x2[2000];
extern double y_1[2000];
extern double y_2[2000];
extern double A[2000][2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < n; i++) {
    x1[i] = (double)(i % n) / n;
    x2[i] = (double)((i + 1) % n) / n;
    y_1[i] = (double)((i + 3) % n) / n;
    y_2[i] = (double)((i + 4) % n) / n;
    for (j = 0; j < n; j++)
        A[i][j] = (double)(i * j % n) / n;
}

}
