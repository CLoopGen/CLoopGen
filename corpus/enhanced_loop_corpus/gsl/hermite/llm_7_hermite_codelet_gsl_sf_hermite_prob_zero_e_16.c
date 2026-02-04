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
    double local_d = d;
    for (j = 1; j < n; j++) {
        if (j % 2 == 0) {
            local_d = j / (x - local_d);
        } else {
            local_d = (j + 1) / (x - local_d * 0.5);
        }
    }
    d = local_d;
}
