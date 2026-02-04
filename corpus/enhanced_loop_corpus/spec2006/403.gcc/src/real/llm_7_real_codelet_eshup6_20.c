#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;
extern unsigned short *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned short *local_p = p;
    unsigned short *local_x = x;
    for (i = 2; i < (6 + 3) - 1; i += 2) {
        *local_p++ = *local_x++;
        *local_p++ = *local_x++;
    }
    p = local_p;
    x = local_x;
}
