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
    for (j = 1; j < n; j++) {
        if (j % 2 == 0) {
            d = 2 * j / (2. * x - d);
        } else {
            d = (2 * j + 1) / (2. * x - d + 1.0);
        }
    }
}
