#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double d1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    double temp = d1;
    for (i = 0; i < 10; i++) {
        temp = 1 / (temp + 1);
    }
    d1 = temp;
}
