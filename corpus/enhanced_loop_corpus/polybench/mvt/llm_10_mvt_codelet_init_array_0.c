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
for (i = 0; i < n; i += 2) {
    x1[i] = (double)(i % n) / n;
    x2[i] = (double)((i + 1) % n) / n;
    y_1[i] = (double)((i + 3) % n) / n;
    y_2[i] = (double)((i + 4) % n) / n;
    if (i + 1 < n) {
        x1[i + 1] = (double)((i + 1) % n) / n;
        x2[i + 1] = (double)((i + 2) % n) / n;
        y_1[i + 1] = (double)((i + 4) % n) / n;
        y_2[i + 1] = (double)((i + 5) % n) / n;
    }
    for (j = 0; j < n; j++) {
        double temp = (double)(i * j % n) / n;
        A[i][j] = temp * temp + temp;
        if (i + 1 < n && j < n)
            A[i + 1][j] = (double)((i + 1) * j % n) / n;
    }
}
}
