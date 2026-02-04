#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char *temp = content;
    size_t local_length = 0;
    for (; temp < content + 1024 && *temp != '\x00'; temp++) {
        int is_high_bit_set = (*temp & 128) != 0;
        local_length += is_high_bit_set ? 2 : 1;
        length = local_length; // Introduce WAW dependency on 'length', now updated each iteration
    }
}
