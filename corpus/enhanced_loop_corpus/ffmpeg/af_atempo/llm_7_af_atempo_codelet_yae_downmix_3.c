#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern  uint8_t *src;
extern  uint8_t *src_end;
extern FFTSample *xdat;
extern int tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_buffer[4];
    int count = 0;
    for (; src + sizeof(int) <= src_end && count < 4; src += sizeof(int), count++) {
        temp_buffer[count] = *(const int *)src;
    }
    for (int i = 0; i < count; i++) {
        *xdat++ = (FFTSample)temp_buffer[i];
    }
}
