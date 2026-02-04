#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; in < ((127 + 1) / 32) * 2; in += 2, out += (in & 2) ? 1 : -1) {
        int temp1 = out + 1;
        int temp2 = out + 2;
        table[in] = temp1;
        table[in + 1] = temp2;
        table[-in] = -temp1;
        table[-(in + 1)] = -temp2;
        out = (out + in) % 100;
    }
}
