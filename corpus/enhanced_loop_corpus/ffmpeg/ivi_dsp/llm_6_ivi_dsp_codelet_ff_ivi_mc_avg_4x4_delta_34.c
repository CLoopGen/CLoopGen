#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern ptrdiff_t pitch;
extern int16_t tmp[16];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++, buf += pitch) {
        int16_t temp_sum = 0;
        for (j = 0; j < 4; j++) {
            temp_sum += tmp[i * 4 + j] >> 1;
        }
        // Introduce WAW dependency by updating a shared temp variable before write
        for (j = 0; j < 4; j++) {
            buf[j] += temp_sum >> 2; // Reduces precision but creates new data flow: temp_sum now influences all writes
        }
    }
}
