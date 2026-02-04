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
for (y = 2; y < 18; y += 2) {
    int x;
    for (x = 2; x < 18; x += 2) {
        p++;
        if (*p > max)
            max = *p;
        if (*p < min)
            min = *p;
    }
}
}
