#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint64_t z_word_t;

extern  uint32_t crc_table[];
extern z_word_t data;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    z_word_t local_data[8];
    local_data[0] = data;
    for (k = 0; k < 8; k++) {
        if (k > 0) {
            local_data[k] = (local_data[k-1] >> 8) ^ crc_table[local_data[k-1] & 255];
        }
    }
    data = local_data[7];
}
