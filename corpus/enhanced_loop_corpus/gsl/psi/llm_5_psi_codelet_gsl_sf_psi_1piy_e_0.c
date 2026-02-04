#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double y;
extern  int M;
extern double sum;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 1; n <= M; n++) {
        if (n * n + y * y == 0) continue;
        sum += 1. / (n * (n * n + y * y));
    }
}
