#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *p;
extern int buf_size;
extern int cc_count;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_i = 5;
    int count_inc = 0;
    for (; local_i + 6 <= buf_size && ((p[local_i] & 254) == 254); local_i += 6)
        count_inc += 1;
    i = local_i;
    cc_count += count_inc;
}
