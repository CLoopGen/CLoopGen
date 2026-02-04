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
extern uint8_t *dst;
extern ptrdiff_t stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp_val_8;
    uint16_t temp_val_16;
    for (i = 0; i < n_px_need; i++) {
        int read_index = i * stride - 1;
        int write_index = n_px_need - 1 - i;
        if (bytesperpixel == 1) {
            temp_val_8 = dst[read_index];
            l[write_index] = temp_val_8;
        } else {
            temp_val_16 = ((const av_alias16*)&dst[read_index * 2])->u16;
            ((av_alias16*)&l[write_index * 2])->u16 = temp_val_16;
        }
    }
}
