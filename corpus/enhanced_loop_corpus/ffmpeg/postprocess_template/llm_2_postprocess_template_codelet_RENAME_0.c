#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;
extern int min;
extern int max;
extern uint8_t *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 1; y < 9; y++) {
    int x;
    for (x = 1; x < 9; x++) {
        p += 2; // Strided access: increment pointer by 2 each time
        if (*p > max)
            max = *p;
        if (*p < min)
            min = *p;
    }
}
}
