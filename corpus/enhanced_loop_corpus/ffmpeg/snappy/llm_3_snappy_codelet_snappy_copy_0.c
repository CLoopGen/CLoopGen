#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *p;
extern int len;
extern uint8_t *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse-order traversal from end to start
    for (i = len - 1; i >= 0; i--) {
        p[i] = q[i];
    }
}
