#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern float sum;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int outer;
for (outer = 0; outer < n; outer += 2) {
    x = outer;
    sum += vec[x];
    if (outer + 1 < n) {
        x = outer + 1;
        sum += vec[x];
    }
}
}
