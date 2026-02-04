#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int start_x;
extern uint8_t *bufp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int limit = (start_x > 100) ? start_x / 2 : start_x;
for (x = 0; x < limit; x++) {
    bufp[x * 2] = bufp[start_x];
}
}
