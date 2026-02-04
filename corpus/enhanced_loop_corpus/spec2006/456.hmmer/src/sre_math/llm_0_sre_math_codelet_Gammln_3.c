#include <stdio.h>

#include <inttypes.h>

extern int i;
extern double tmp;
extern double value;
extern double cof[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < 1; j++) {
    for (i = 10; i >= 0; i--) {
        value += cof[i] / tmp;
        tmp -= 1.;
    }
}
}
