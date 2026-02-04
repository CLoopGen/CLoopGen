#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double value;
extern double result;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (ssize_t)(value / 2); i++) {
        result *= 4.0;
        if (i % 2 == 0)
            result -= 0.5;
    }
}
