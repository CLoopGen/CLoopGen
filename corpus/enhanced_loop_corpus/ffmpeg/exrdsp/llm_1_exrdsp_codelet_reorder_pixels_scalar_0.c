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
    if (half_size > 0) {
        i = 0;
        for (; i < half_size; ) {
            *(s++) = *(t1++);
            *(s++) = *(t2++);
            i++;
        }
    }
}
