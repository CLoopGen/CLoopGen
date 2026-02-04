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
int n1;
for (n1 = 1; n1 <= M; n1++) {
    for (n = n1; n <= n1; n++) {
        sum += 1. / (n * (n * n + y * y));
    }
}
}
