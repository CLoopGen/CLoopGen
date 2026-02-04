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
for (i = 0; i < bit_size; i++) {
    if (bit_buffer[i]) {
        if (0)
            *bytep |= (1 << (set_word_size - 1 - bit_pos));
        else
            *bytep |= 1 << bit_pos;
    }
    bit_pos++;
    if (bit_pos >= set_word_size)
        bit_pos = 0 , bytep++;
}

}
