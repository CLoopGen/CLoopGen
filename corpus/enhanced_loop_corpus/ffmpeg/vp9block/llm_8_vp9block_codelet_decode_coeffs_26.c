#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int end_x;
extern int n;
extern uint8_t *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 2; n < end_x; n += 4) {
        a[n] = a[n - 1];
        a[n + 1] = a[n]; // Additional operation to increase computational intensity
    }
}
