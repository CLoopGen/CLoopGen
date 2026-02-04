#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ***mask;
extern int mask_linesize;
extern int image_linesize;
extern int mask_size;
extern int start_posx;
extern int start_posy;
extern int end_posx;
extern int end_posy;
extern int i;
extern int j;
extern unsigned int accumulator;
extern unsigned int divisor;
extern  uint8_t *image_read_position;
extern  uint8_t *mask_read_position;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int total_elements = (end_posy - start_posy + 1) * (end_posx - start_posx + 1);
    uint8_t *img_ptr = image_read_position;
    uint8_t *msk_ptr = mask_read_position;
    int img_stride = image_linesize - (end_posx - start_posx + 1);
    int msk_stride = mask_linesize - (end_posx - start_posx + 1);
    int count = 0;
    int i_flat;

    for (i_flat = 0; i_flat < total_elements; i_flat++) {
        int i_local = (i_flat % (end_posx - start_posx + 1)) + start_posx;
        int j_local = (i_flat / (end_posx - start_posx + 1)) + start_posy;

        if (!(*msk_ptr) && mask[mask_size][i_local - start_posx][j_local - start_posy]) {
            accumulator += *img_ptr;
            divisor++;
        }
        img_ptr++;
        msk_ptr++;
        count++;

        if (count % (end_posx - start_posx + 1) == 0) {
            img_ptr += img_stride;
            msk_ptr += msk_stride;
        }
    }
}
