#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern double d;
extern double x;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    for (j = 0; j < n * 2; j++) {
        k = j % n;
        if (k == 0) k = 1;
        d = (k + 0.5) / (x - d * d);
    }
}
