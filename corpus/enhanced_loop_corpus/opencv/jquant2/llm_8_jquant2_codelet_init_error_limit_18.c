#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; in < ((512 + 1) / 8) * 5; in++, out += (in % 3 == 0) ? 2 : 0) {
        table[in] = out + in * 2;
        table[-in] = -out - in * 2;
        table[in + 1] = out + in * 2 + 1;
        table[-(in + 1)] = -out - in * 2 - 1;
    }
}
