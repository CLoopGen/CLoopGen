#include <stdio.h>

#include <inttypes.h>

extern int i;
extern double tmp;
extern double value;
extern double cof[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 10; i >= 0; i--) {
        if (tmp == 0.0) {
            continue;
        }
        value += cof[i] / tmp;
        tmp -= 1.;
    }
}
