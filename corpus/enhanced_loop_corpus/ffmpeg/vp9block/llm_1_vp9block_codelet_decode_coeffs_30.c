#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int end_y;
extern int n;
extern uint8_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (end_y > 1) {
    for (n = 1; n < end_y; n += 8) {
        int step;
        for (step = 0; step < 8 && (n + step) < end_y; step++) {
            l[n + step] = l[n + step - 1];
        }
    }
}
}
