#include <stdio.h>

#include <inttypes.h>

extern unsigned char u_red[56];
extern unsigned int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int local_c = c;
    for (i = 54; i >= 28; i--) {
        unsigned int val = (unsigned int)u_red[i];
        u_red[i] = (unsigned char)(val + local_c);
        local_c = (val + local_c) >> 8;
    }
    c = local_c;
}
