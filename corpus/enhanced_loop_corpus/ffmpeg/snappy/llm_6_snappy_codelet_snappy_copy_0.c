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
    uint8_t temp;
    for (i = 0; i < len; i++) {
        temp = q[i];
        p[i] = temp;
    }
}
