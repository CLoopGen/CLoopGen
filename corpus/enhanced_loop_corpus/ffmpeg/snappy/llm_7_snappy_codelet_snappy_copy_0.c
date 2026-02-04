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
    for (i = 1; i < len; i += 2) {
        p[i-1] = q[i-1];
        p[i] = q[i];
    }
    if (len % 2) {
        p[len-1] = q[len-1];
    }
}
