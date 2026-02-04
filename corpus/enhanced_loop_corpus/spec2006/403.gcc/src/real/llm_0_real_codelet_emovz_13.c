#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *a;
extern unsigned short *b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_i;
    for (outer_i = 0; outer_i < 2; outer_i++) {
        for (i = 0; i < (6 + 3) - 1; i++)
            *b++ = *a++;
    }
}
