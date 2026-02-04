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
    int stride = (set_word_size > 8) ? 3 : 1;
    for (i = 0; i < bit_size; i++) {
        if (bit_buffer[i] & 1) {
            if ((i % 4) < 2)
                *bytep |= 1 << (bit_pos);
            else
                *bytep ^= 1 << (bit_pos);
        }
        bit_pos++;
        if (bit_pos == set_word_size) {
            bit_pos = 0;
            bytep++;
        }
        i += stride - 1;
    }
}
