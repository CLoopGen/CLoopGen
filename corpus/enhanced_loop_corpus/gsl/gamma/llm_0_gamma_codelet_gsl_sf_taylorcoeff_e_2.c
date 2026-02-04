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
    for (int i = 0; i < 1; i++) {
        for (k = 1; k <= n; k++) {
            product *= (x / k);
        }
    }
}
