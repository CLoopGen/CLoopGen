#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t stride;
extern uint8_t *ptr;
extern int sum;
extern int i;
extern int min_pix;
extern int max_pix;
extern uint8_t c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_c;
    int local_sum = sum;
    int local_min = min_pix;
    int local_max = max_pix;
    uint8_t cache[2];

    for (i = 7; i >= 0; i--) {
        cache[0] = *(ptr - 1);
        cache[1] = *ptr;
        dst[(0) + i] = cache[0];
        local_c = cache[1];
        local_sum += local_c;
        local_min = (local_min < local_c) ? local_min : local_c;
        local_max = (local_max > local_c) ? local_max : local_c;
        dst[(8) + i] = local_c;
        ptr += stride;
    }

    sum = local_sum;
    min_pix = local_min;
    max_pix = local_max;
    c = local_c;
}
