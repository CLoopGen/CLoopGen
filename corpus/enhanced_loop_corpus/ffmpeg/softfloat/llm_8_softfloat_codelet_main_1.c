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
for (i = 0; i < 200; i += 2) {
    d1 = i * 2.0;
    d2 = (i + 1) / 200.0;
    for (j = 0; j < 500; j++) {
        d1 = (d1 + 2) * d2 - 1;
        d1 = (d1 + d2) * (d2 + 0.01);
    }
}
}
