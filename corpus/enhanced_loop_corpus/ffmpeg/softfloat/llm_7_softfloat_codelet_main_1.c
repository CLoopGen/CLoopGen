#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double d1;
extern double d2;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
d1 = 0;
d2 = 0.01;
for (i = 0; i < 100; i++) {
    double local_d2 = (i + 1) / 100.;
    for (j = 0; j < 1000; j++) {
        d1 = d1 + local_d2;
    }
    d2 = local_d2;
}
}
