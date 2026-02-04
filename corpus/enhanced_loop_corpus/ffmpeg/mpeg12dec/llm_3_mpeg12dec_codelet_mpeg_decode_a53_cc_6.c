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
    // Variant 2: Strided access with increased stride (stride of 12 instead of 6)
    for (i = 5; i + 12 <= buf_size && ((p[i] & 254) == 254); i += 12)
        cc_count++;
}
