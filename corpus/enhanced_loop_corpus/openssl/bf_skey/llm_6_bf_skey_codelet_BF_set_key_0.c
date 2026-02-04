#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *data;
extern int i;
extern unsigned int *p;
extern unsigned int ri;
extern  unsigned char *d;
extern  unsigned char *end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp_load;
    for (i = 0; i < (16 + 2); i++) {
        temp_load = 0;
        temp_load |= *(d++) << 24;
        if (d >= end)
            d = data;
        temp_load |= *(d++) << 16;
        if (d >= end)
            d = data;
        temp_load |= *(d++) << 8;
        if (d >= end)
            d = data;
        temp_load |= *(d++);
        if (d >= end)
            d = data;
        ri = temp_load;
        p[i] ^= ri;
    }
}
