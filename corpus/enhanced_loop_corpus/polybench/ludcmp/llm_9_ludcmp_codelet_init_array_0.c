#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double b[2000];
extern double x[2000];
extern double y[2000];
extern int i;
extern double fn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i;
double temp1, temp2;
for (i = 0; i < n; i++) {
    x[i] = 0;
    y[i] = 0;
    temp1 = (i + 1) / fn;
    temp2 = temp1 * 0.5;
    b[i] = temp2 + 4;
}
}
