#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *a;
extern unsigned short *b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int trip_count = (6 + 3) - 1;
    for (i = 0; i < trip_count * 2; i += 2) {
        *b++ = *a++;
        *b++ = *a++;
    }
}
