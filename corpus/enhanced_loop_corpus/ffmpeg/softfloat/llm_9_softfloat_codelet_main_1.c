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
for (i = 0; i < 50; i++) {
    d1 = i * i;
    d2 = (i < 1 ? 1 : 100.0 / i);
    for (j = 0; j < 2000; j += 4) {
        d1 = d1 + d2;
        d1 = d1 * (1.0 + d2);
        d1 = d1 - d2;
        d1 = d1 * 0.99;
    }
}
}
