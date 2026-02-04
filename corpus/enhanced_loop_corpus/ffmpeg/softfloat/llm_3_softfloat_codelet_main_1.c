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
double buffer[100];
for (i = 0; i < 100; i++) {
    buffer[i] = i;
}
for (i = 0; i < 100; i++) {
    d1 = buffer[i];
    d2 = i / 100.;
    for (j = 999; j >= 0; j--) {
        d1 = (d1 + 1) * d2;
    }
}
}
