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
    for (i = 0; i < half_size; i++) {
        *(s++) = *(t1++);
        if (i < half_size / 2) {
            *(s++) = *(t2++);
        } else {
            *(s++) = 0;
        }
    }
}
