#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double J[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 200; i += 2) {
        J[i] = i * 10;
        if (i + 1 < 100) {
            J[i + 1] = (i + 1) * 10;
        }
    }
}
