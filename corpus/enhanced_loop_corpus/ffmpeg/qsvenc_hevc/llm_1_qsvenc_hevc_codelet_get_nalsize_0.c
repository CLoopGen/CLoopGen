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
    int nested_i, j;
    for (nested_i = 0; nested_i < nal_length_size; nested_i++) {
        for (j = 0; j < 1; j++) { // Artificially increased depth with single iteration inner loop
            nalsize = ((unsigned int)nalsize << 8) | buf[(*buf_index)++];
        }
    }
}
