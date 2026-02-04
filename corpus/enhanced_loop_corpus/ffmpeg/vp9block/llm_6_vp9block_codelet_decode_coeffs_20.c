#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int end_y;
extern int n;
extern uint8_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 1; i < end_y; i += 4) {
        l[i] = l[i - 1];
        l[i + 1] = l[i];  // Introduces WAW and RAW dependencies with next iteration
    }
}
