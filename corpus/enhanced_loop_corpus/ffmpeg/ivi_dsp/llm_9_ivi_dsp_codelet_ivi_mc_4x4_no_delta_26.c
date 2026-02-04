#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern ptrdiff_t dpitch;
extern  int16_t *ref_buf;
extern ptrdiff_t pitch;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++, buf += 2 * dpitch, ref_buf += 2 * pitch)
    for (j = 0; j < 8; j++)
        buf[j] = ((3 * ref_buf[j] + ref_buf[j + 1]) >> 2);
}
