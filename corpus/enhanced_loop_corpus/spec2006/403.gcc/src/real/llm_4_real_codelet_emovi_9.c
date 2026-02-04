#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *p;
extern unsigned short *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 3; i < (6 + 3); i++) {
        if (i % 2 == 0) {
            *q++ = *p--;
        } else {
            continue;
        }
    }
}
