#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *p1;
extern int32_t *p2;
extern int length;
extern int dshift;
extern int dfactor;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < length; i++) {
    uint32_t a = p1[i];
    int32_t b = p2[i];
    int32_t temp = (int)(dfactor * (unsigned int)(b >> dshift) + 128) >> 8;
    b = (unsigned int)temp << dshift;
    p1[i] = b - a;
}
}
