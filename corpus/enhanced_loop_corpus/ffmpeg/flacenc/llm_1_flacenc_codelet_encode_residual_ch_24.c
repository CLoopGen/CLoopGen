#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int opt_order;
extern int allsteps;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (opt_order > 0) {
        i = 0;
        for (; i < opt_order; i++) {
            int temp = 0;
            for (; temp < 1; temp++)
                allsteps *= 3;
        }
    }
}
