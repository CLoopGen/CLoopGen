#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int end_y;
extern int n;
extern uint8_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 2; n < end_y; n += 4)
        l[n] = l[n - 2];
}
