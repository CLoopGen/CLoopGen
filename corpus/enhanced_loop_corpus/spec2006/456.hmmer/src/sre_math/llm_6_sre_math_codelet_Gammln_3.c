#include <stdio.h>

#include <inttypes.h>

extern int i;
extern double tmp;
extern double value;
extern double cof[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_value = value;
    double temp_tmp = tmp;
    for (i = 10; i >= 0; i--) {
        temp_value += cof[i] / temp_tmp;
        temp_tmp -= 1.0;
    }
    value = temp_value;
}
