#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern int16_t *res_pst;
extern int subframe_size;
extern int tmp2;
extern int i;
extern int gt;
extern int ga;
extern int fact;
extern int sh_fact;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reverse traversal using pointer arithmetic
    int16_t *out_ptr = out + subframe_size - 1;
    int16_t *res_ptr = res_pst + subframe_size - 1;
    for (i = subframe_size - 1; i >= 1; i--) {
        tmp2 = (gt * (*(res_ptr - 1))) * 2 + 16384;
        tmp2 = (*res_ptr) + (tmp2 >> 15);
        tmp2 = (tmp2 * ga + fact) >> sh_fact;
        *out_ptr = tmp2;
        out_ptr--;
        res_ptr--;
    }
}
