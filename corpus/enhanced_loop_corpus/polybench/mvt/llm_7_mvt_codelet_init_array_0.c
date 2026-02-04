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
double temp_x1, temp_x2, temp_y1, temp_y2;
for (i = 0; i < n; i++) {
    temp_x1 = (double)(i % n) / n;
    temp_x2 = (double)((i + 1) % n) / n;
    temp_y1 = (double)((i + 3) % n) / n;
    temp_y2 = (double)((i + 4) % n) / n;
    
    x1[i] = temp_x1;
    x2[i] = temp_x2;
    y_1[i] = temp_y1;
    y_2[i] = temp_y2;
    
    for (j = 0; j < n; j++) {
        A[i][j] = (double)(i * j % n) / n;
    }
}
}
