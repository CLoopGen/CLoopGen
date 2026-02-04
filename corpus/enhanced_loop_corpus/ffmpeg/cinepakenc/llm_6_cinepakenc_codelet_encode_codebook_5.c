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
    int i, j;
    for (i = 0; i < size; i++) {
        int base = i * entry_size;
        for (j = 0; j < entry_size; j++) {
            int temp = codebook[base + j];
            if (j >= 4) {
                temp ^= 128;
            }
            buf[ret++] = temp;
        }
    }
}
