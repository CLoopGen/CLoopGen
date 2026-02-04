#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int end_x;
extern int n;
extern uint8_t *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 1; n < end_x; n += 16) {
        a[n] = a[n - 1];
        a[n + 4] = a[n - 1];
        a[n + 8] = a[n - 1];
        a[n + 12] = a[n - 1]; // Reduced trip count with increased operations per iteration
    }
}
