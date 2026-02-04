#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *t1;
extern int half_size;
extern  uint8_t *t2;
extern uint8_t *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < half_size * 2; i += 2) {
        s[0] = t1[0];
        s[1] = t2[0];
        s += 2;
        t1 += 1;
        t2 += 1;
    }
}
