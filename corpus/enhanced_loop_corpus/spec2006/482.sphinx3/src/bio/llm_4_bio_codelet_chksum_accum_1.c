#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef unsigned int uint32;

typedef unsigned short uint16;

extern int32 n_el;
extern uint32 sum;
extern int32 i;
extern uint16 *i16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n_el; i++) {
    if (i % 2 == 0)
        continue;
    sum = (sum << 10 | sum >> 22) + i16[i];
}
}
