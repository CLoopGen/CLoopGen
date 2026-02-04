#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double J[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 100; i++) {
        double temp1 = i * i;
        double temp2 = i + 5.5;
        J[i] = (temp1 - temp2) / 100.0;
    }
}
