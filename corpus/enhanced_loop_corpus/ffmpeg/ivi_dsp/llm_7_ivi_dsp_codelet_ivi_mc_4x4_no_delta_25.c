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
int16_t *local_buf = buf;
int16_t *local_ref = ref_buf;
ptrdiff_t local_dpitch = dpitch;
ptrdiff_t local_pitch = pitch;
for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
        local_buf[j] = local_ref[j];
    }
    local_buf += local_dpitch;
    local_ref += local_pitch;
}
}
