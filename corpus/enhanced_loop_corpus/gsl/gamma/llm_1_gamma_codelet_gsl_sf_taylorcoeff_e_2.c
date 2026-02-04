#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern  double x;
extern double product;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 1; k <= n; k++) {
        for (int j = 0; j < 1; j++) {
            product *= (x / k);
        }
    }
}
