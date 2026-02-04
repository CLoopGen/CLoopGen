#include <stdio.h>

#include <inttypes.h>

extern int i;
extern double tmp;
extern double value;
extern double cof[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 10; i >= 0; i -= 2) {
        value += cof[i] / tmp;
        if (i > 0) {
            value += cof[i-1] / (tmp - 1.0);
        }
        tmp -= 2.0;
    }
}
