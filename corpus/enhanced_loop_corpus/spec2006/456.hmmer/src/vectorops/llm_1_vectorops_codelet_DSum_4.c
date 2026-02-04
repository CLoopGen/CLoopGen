#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern double sum;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (n > 0) {
    x = 0;
    for (int outer = 0; outer < 1; outer++)
        for (x = 0; x < n; x++)
            sum += vec[x];
}
}
