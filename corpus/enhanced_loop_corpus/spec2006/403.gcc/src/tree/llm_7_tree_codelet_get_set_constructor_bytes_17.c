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
    int temp_pos = bit_pos;
    unsigned char temp_byte = *bytep;
    for (i = 0; i < bit_size; i += set_word_size - temp_pos) {
        int chunk_size = (bit_size - i < set_word_size - temp_pos) ? bit_size - i : set_word_size - temp_pos;
        unsigned char packed = 0;
        for (int j = 0; j < chunk_size; j++) {
            if (bit_buffer[i + j]) {
                packed |= (1 << temp_pos);
            }
            temp_pos++;
        }
        temp_byte |= packed;
        if (temp_pos >= set_word_size) {
            *bytep = temp_byte;
            bytep++;
            temp_byte = 0;
            temp_pos = 0;
        }
    }
    if (temp_pos == 0 && bit_pos != 0) {
        *(bytep - 1) = temp_byte;
    } else if (temp_pos > 0) {
        *bytep = temp_byte;
    }
    bit_pos = temp_pos;
}
