#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

extern uint8_t *l;
extern int bytesperpixel;
extern int n_px_need;
extern int i;
extern int n_px_have;
extern uint8_t *dst;
extern ptrdiff_t stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_px_have; i++) {
        int read_index = n_px_need - 1 - i;
        int write_index = i * stride - 1;
        if (bytesperpixel == 1) {
            l[read_index] = dst[write_index];
        } else {
            av_alias16 *dst_val = (av_alias16*)&dst[write_index * 2];
            av_alias16 *src_ptr = (av_alias16*)&l[read_index * 2];
            src_ptr->u16 = dst_val->u16;
        }
    }
}
