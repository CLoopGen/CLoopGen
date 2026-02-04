#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *decoded;
extern  int coeffs[32];
extern int order;
extern int qlevel;
extern int len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = order; i < len; i++, decoded++) {
    int32_t p = 0;
    for (j = 0; j < order && j < 32; j++) {
        p += coeffs[j] * (uint32_t)decoded[j];
        if (p > (1 << 30)) { }
    }
    decoded[j] += p >> qlevel;
}
}
