#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int stride = 0; stride < ((255 + 1) / 16) * 3; stride += 4) {
        for (int j = 0; j < 4 && (in + j) < ((255 + 1) / 16) * 3; j++) {
            int temp_in = in + j;
            int temp_out = out + ((temp_in & 1) ? 0 : 1);
            table[temp_in] = temp_out;
            table[-temp_in] = -temp_out;
        }
        in += 4;
        out += ((in & 1) ? 0 : 1);
    }
}
