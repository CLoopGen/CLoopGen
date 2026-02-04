#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uint8;

typedef int int32;

extern uint8 *data;
extern int32 len;
extern char *key;
extern int32 i;
extern int32 j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 local_i, local_j;
    local_i = 0;
    local_j = 0;
    for (; local_i < len; local_i++, local_j += 2) {
        uint8 val = data[local_i];
        key[local_j] = 'A' + (val & 15);
        key[local_j + 1] = 'J' + ((val >> 4) & 15);
    }
    i = local_i;
    j = local_j;
}
