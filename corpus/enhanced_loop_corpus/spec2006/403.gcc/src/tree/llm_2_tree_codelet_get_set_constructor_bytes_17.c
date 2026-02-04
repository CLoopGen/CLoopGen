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
    // Variant 1: Strided Access Pattern
    // Instead of accessing bit_buffer sequentially, access it with a stride of 2 (alternating elements)
    // This changes memory access pattern to non-consecutive, potentially affecting cache behavior
    int stride = 2;
    int effective_size = (bit_size + stride - 1) / stride; // Adjust loop bound for strided access

    for (i = 0; i < effective_size; i++) {
        int index = i * stride; // Compute actual array index with stride
        if (index < bit_size && bit_buffer[index]) {
            if (0)
                *bytep |= (1 << (set_word_size - 1 - bit_pos));
            else
                *bytep |= 1 << bit_pos;
        }
        bit_pos++;
        if (bit_pos >= set_word_size)
            bit_pos = 0, bytep++;
    }
}
