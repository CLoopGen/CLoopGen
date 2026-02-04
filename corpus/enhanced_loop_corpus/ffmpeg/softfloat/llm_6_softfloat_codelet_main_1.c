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
for (i = 0; i < 100; i++) {
    d1 = i;
    d2 = i / 100.;
    double temp = d1;
    for (j = 0; j < 1000; j++) {
        temp = (temp + 1) * d2;
    }
    d1 = temp;
}
}
