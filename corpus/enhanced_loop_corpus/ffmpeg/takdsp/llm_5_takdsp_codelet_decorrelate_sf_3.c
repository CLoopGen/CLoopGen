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
    int index = (i * 3) % length; // Strided access with wrap-around using stride of 3
    uint32_t a = p1[index];
    int32_t b = p2[index];
    b = (unsigned int)((int)(dfactor * (unsigned int)(b >> dshift) + 128) >> 8) << dshift;
    p1[index] = b - a;
}
}
