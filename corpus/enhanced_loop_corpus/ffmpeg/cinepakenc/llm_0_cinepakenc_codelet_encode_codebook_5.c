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
    for (y = 0; y < entry_size; y++) {
        buf[ret++] = codebook[y + x * entry_size] ^ (y >= 4 ? 128 : 0);
    }
}
}
