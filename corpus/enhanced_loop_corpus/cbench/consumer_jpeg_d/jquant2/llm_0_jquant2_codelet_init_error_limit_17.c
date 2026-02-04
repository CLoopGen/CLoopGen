#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 3; ++outer) {
        for (; in < ((255 + 1) / 16) * 3; in++, out += (in & 1) ? 0 : 1) {
            table[in] = out;
            table[-in] = -out;
        }
    }
}
