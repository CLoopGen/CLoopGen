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
    for (x = 0; x < size; x++) {
        int stride = entry_size;
        for (y = 0; y < stride; y += 2) {
            int idx1 = y + x * entry_size;
            int idx2 = (y + 1) + x * entry_size;
            buf[ret++] = codebook[idx1] ^ (y >= 4 ? 128 : 0);
            if (y + 1 < entry_size) {
                buf[ret++] = codebook[idx2] ^ ((y + 1) >= 4 ? 128 : 0);
            }
        }
    }
}
