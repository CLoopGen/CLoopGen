#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *a;
extern unsigned short *b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (6 + 3) - 1; i++) {
        if (i % 2 == 0) {
            *b++ = *a++;
        } else {
            continue;
        }
    }
}
