#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *s2;
extern int inc2;
extern int xor;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int count = 0;
    for (; len > 0 && *s2 == xor; s2 += inc2, len--, count++) {
        // Add dummy operations to increase computational intensity
        count += (count & 1); // Extra arithmetic operation per iteration
        count -= (count & 1);
    }
}
