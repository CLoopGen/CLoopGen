#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *m1;
extern  unsigned char *m2;
extern char *p;
extern size_t i;
extern unsigned int diff;
extern  size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < (j + 7) / 8; outer++) {
        size_t block_start = outer * 8;
        size_t block_end = (block_start + 8 < j) ? block_start + 8 : j;
        for (size_t inner = block_start; inner < block_end; inner++) {
            if (m1[inner] == m2[inner]) {
                *p++ = ' ';
                *p++ = ' ';
            } else {
                *p++ = '^';
                *p++ = '^';
                diff = 1;
            }
        }
        if (block_end < j)
            *p++ = ' ';
    }
}
