#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double J[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 100; i++) {
        J[i] = (i >= 10 && i <= 90) ? i / 10. : 0.0;
    }
}
