#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double bee[68];
extern int n;
extern int d;
extern  int bidx[4];
extern double b_new[34];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double sum = 0.0;
    int limit = n + 2;
    for (i = 0; i < limit; i++) {
        sum += bee[bidx[d] + i];
        b_new[i] = sum / (i + 1);
    }
}
