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
    int i, j;
    for (i = 0; i < 8; i++) {
        int16_t *temp_buf = buf + i * dpitch;
        int16_t *temp_ref = ref_buf + i * pitch;
        for (j = 0; j < 8; j++) {
            temp_buf[j] = (temp_ref[j] + temp_ref[j + 1]) >> 1;
        }
    }
}
