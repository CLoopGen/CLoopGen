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
    for (i = 0; i < n_el; i += 2) {
        sum = (sum << 10 | sum >> 22) + i16[i];
        if (i + 1 < n_el) {
            sum = (sum << 10 | sum >> 22) + i16[i + 1];
        }
    }
}
