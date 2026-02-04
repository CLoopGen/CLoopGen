#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int trafo_size;
extern int x;
extern int y;
extern uint8_t *src;
extern  uint8_t *top;
extern  uint8_t *left;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t s = stride;
    int sz = size;
    int tr_sz = trafo_size + 1;
    uint8_t *s_src = src;
    uint8_t *s_top = top;
    uint8_t *s_left = left;

    for (y = 0; y < sz; y++) {
        int temp_left_y = s_left[y];
        int temp_left_size = s_left[sz];
        int temp_top_size = s_top[sz];
        for (x = 0; x < sz; x++) {
            int term1 = (sz - 1 - x) * temp_left_y;
            int term2 = (x + 1) * temp_top_size;
            int term3 = (sz - 1 - y) * s_top[x];
            int term4 = (y + 1) * temp_left_size;
            s_src[x + s * y] = (uint8_t)((term1 + term2 + term3 + term4 + sz) >> tr_sz);
        }
    }
}
