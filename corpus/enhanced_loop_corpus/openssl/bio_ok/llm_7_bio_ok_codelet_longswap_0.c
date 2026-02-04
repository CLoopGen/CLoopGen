#include <stdio.h>

#include <inttypes.h>

extern size_t len;
extern size_t i;
extern unsigned char *p;
extern unsigned char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp0, temp1, temp2, temp3;
    for (i = 0; i < len; i += 4) {
        temp0 = p[i + 0];
        temp1 = p[i + 1];
        temp2 = p[i + 2];
        temp3 = p[i + 3];
        p[i + 0] = temp3;
        p[i + 1] = temp2;
        p[i + 2] = temp1;
        p[i + 3] = temp0;
    }
}
