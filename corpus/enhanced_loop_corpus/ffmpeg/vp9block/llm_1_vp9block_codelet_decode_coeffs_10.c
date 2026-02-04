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
    for (n = 1; n < end_y; n += 2) {
        l[n] = l[n - 1];
        if (n + 2 < end_y) {
            n += 2;
            l[n] = l[n - 1];
            n -= 2;
        }
    }
}
}
