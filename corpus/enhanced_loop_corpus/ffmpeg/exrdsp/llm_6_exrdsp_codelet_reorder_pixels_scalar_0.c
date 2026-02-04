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
    uint8_t temp1, temp2;
    for (i = 0; i < half_size; i++) {
        temp1 = t1[i];
        temp2 = t2[i];
        s[2*i] = temp1;
        s[2*i + 1] = temp2;
    }
}
