#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double dfdt[];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp1, temp2, temp3;
    for (i = 0; i < 15; i++) {
        temp1 = i * 1.5;
        temp2 = temp1 * temp1;
        temp3 = temp2 / (i + 1.0);
        dfdt[i] = temp3 - temp2 + temp1;
    }
}
