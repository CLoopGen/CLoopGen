#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nal_length_size;
extern  uint8_t *buf;
extern int *buf_index;
extern int i;
extern int nalsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with fixed stride of 2 (simulating non-consecutive pattern)
    // Assumes buffer has sufficient data and stride pattern is valid for the context
    int double_len = nal_length_size * 2;
    int temp_index = *buf_index;
    nalsize = 0; // Reset nalsize as access pattern differs

    for (i = 0; i < double_len; i += 2) {
        unsigned char byte = buf[temp_index + (i / 2)]; // Simulate strided logical access
        nalsize = ((unsigned int)nalsize << 8) | byte;
    }
    *buf_index += nal_length_size; // Update index by actual bytes consumed
}
