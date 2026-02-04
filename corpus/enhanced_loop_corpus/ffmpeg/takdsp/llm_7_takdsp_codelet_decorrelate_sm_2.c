#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *p1;
extern int32_t *p2;
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < length; i++) {
    uint32_t a_prev = p1[i];
    int32_t b_prev = p2[i];
    uint32_t a_next = a_prev - (b_prev >> 1);
    int32_t b_next = a_next + b_prev;
    p1[i] = a_next;
    p2[i] = b_next;
}
}
