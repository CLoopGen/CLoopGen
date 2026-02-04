#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef unsigned int uint32;

typedef unsigned char uint8;

extern int32 n_el;
extern uint32 sum;
extern int32 i;
extern uint8 *i8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int32 outer;
for (outer = 0; outer < 1; outer++) {
    for (i = 0; i < n_el; i++)
        sum = (sum << 5 | sum >> 27) + i8[i];
}
}
