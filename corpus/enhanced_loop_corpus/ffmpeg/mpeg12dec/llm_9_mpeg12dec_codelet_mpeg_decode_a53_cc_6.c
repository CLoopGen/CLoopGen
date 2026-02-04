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
    int step;
    for (i = 5; i + 12 <= buf_size; i += 12) {
        step = (p[i] & 254) == 254 ? 6 : 3;
        if ((p[i] & 254) == 254) cc_count++;
        if (i + step < buf_size && (p[i + step] & 254) == 254) cc_count++;
    }
}
