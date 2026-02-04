#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int end_y;
extern int n;
extern uint8_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 1; n < end_y - 7; n += 8) {
        l[n] = l[n - 1];
        l[n + 1] = l[n];
        l[n + 2] = l[n + 1];
        l[n + 3] = l[n + 2];
        l[n + 4] = l[n + 3];
        l[n + 5] = l[n + 4];
        l[n + 6] = l[n + 5];
        l[n + 7] = l[n + 6];
    }
}
