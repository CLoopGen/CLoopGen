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
    int local_bit_pos = bit_pos;
    unsigned char *local_bytep = bytep;
    for (i = 0; i < bit_size; i++) {
        if (bit_buffer[i]) {
            if (0)
                *local_bytep |= (1 << (set_word_size - 1 - local_bit_pos));
            else
                *local_bytep |= 1 << local_bit_pos;
        }
        local_bit_pos++;
        if (local_bit_pos >= set_word_size) {
            local_bit_pos = 0;
            local_bytep++;
        }
    }
    bit_pos = local_bit_pos;
    bytep = local_bytep;
}
