#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf;
extern int L;
extern  int HEAD;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev = buf[0];
    for (i = 1; i < HEAD; i++) {
        uint8_t current = buf[i];
        buf[i] = prev;
        prev = current;
    }
    if (HEAD > 0) {
        L += buf[0];
    }
}
