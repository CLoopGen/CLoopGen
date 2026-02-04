#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern  uint8_t *cm;
extern uint8_t *top;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 16; y++) {
    const uint8_t *cm_in = cm + src[-1];
    const uint8_t *t = top;
    uint8_t *s = src;
    s[0]  = cm_in[t[0]];   s[4]  = cm_in[t[4]];
    s[8]  = cm_in[t[8]];   s[12] = cm_in[t[12]];
    s[1]  = cm_in[t[1]];   s[5]  = cm_in[t[5]];
    s[9]  = cm_in[t[9]];   s[13] = cm_in[t[13]];
    s[2]  = cm_in[t[2]];   s[6]  = cm_in[t[6]];
    s[10] = cm_in[t[10]];  s[14] = cm_in[t[14]];
    s[3]  = cm_in[t[3]];   s[7]  = cm_in[t[7]];
    s[11] = cm_in[t[11]];  s[15] = cm_in[t[15]];
    src += stride;
}
}
