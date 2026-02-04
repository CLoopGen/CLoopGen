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
    int outer = len / 2;
    int remainder = len % 2;
    for (i = 0; i < outer; i++) {
        p[2*i] = q[2*i];
        p[2*i + 1] = q[2*i + 1];
    }
    for (i = 0; i < remainder; i++) {
        p[len - 1] = q[len - 1];
    }
}
