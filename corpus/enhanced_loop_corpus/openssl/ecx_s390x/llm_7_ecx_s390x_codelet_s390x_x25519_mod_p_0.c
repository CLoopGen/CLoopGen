#include <stdio.h>

#include <inttypes.h>

extern unsigned char u_red[32];
extern unsigned int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int local_c = c;
    for (i = 30; i >= 0; i--) {
        unsigned int sum = local_c + (unsigned int)u_red[i];
        u_red[i] = (unsigned char)sum;
        local_c = sum >> 8;
    }
    c = local_c;
}
