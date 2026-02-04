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
int outer_n;
for (outer_n = 1; outer_n <= M; outer_n++) {
    n = outer_n;
    if (n % 2 == 1) {
        sum += 1. / (n * (n * n + y * y));
    } else {
        sum += 1. / (n * (n * n + y * y));
    }
}
}
