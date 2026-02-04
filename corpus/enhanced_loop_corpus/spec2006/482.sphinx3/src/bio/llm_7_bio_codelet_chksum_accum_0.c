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
    uint32 local_sum = 0;
    for (i = 0; i < n_el; i += 4) {
        local_sum += i8[i];
        if (i + 1 < n_el) local_sum += i8[i + 1];
        if (i + 2 < n_el) local_sum += i8[i + 2];
        if (i + 3 < n_el) local_sum += i8[i + 3];
    }
    sum = (sum << 5 | sum >> 27) + local_sum;
}
