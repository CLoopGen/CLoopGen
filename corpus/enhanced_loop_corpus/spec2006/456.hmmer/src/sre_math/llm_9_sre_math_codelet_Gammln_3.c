#include <stdio.h>

#include <inttypes.h>

extern int i;
extern double tmp;
extern double value;
extern double cof[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 20; i >= 0; i--) {
        value += (cof[i % 11] * cof[i % 11]) / (tmp + (double)i);
        tmp -= 0.5;
    }
}
