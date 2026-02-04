#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and doubled effective trip count
    for (; in < ((255 + 1) / 8) * 3; in++, out += (in % 3 == 0) ? 2 : ((in & 1) ? 0 : 1)) {
        int temp1 = out * out + 2 * out + 1;
        int temp2 = out - (in & 1 ? 1 : -1);
        table[in] = temp1;
        table[-in] = -temp1;
        if (in > 0) {
            table[in + 256] = temp2;
            table[-(in + 256)] = -temp2;
        }
    }
}
