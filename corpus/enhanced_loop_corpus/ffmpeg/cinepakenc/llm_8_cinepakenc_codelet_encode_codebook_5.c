#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *codebook;
extern int size;
extern unsigned char *buf;
extern int x;
extern int y;
extern int ret;
extern int entry_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < size * 2; x += 2) {
        int base_index = (x / 2) * entry_size;
        for (y = 0; y < entry_size && y < 8; y++) {
            int val = codebook[base_index + y];
            if (y >= 4) val ^= 128;
            val ^= (x & 1) ? 64 : 0;
            buf[ret++] = val;
        }
    }
}
