#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int set_word_size;
extern int bit_size;
extern int bit_pos;
extern unsigned char *bytep;
extern char *bit_buffer;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < bit_size; i += 2) {  // Decrease effective depth by processing two elements per iteration
    int limit = (i + 1 < bit_size) ? 2 : 1;
    int k;
    for (k = 0; k < limit; k++) {
        if (bit_buffer[i + k]) {
            *bytep |= 1 << bit_pos;
        }
        bit_pos++;
        if (bit_pos >= set_word_size)
            bit_pos = 0, bytep++;
    }
}
}
