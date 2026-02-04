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
    int total_iterations = (end_posy - start_posy + 1) * (end_posx - start_posx + 1);
    uint8_t *img_ptr = image_read_position;
    uint8_t *msk_ptr = mask_read_position;
    int row_width = (end_posx - start_posx + 1);

    for (int idx = 0; idx < total_iterations; idx++) {
        int i_local = (idx % row_width) + start_posx;
        int j_local = (idx / row_width) + start_posy;
        int offset = j_local - start_posy;
        int mask_val = mask[mask_size][i_local - start_posx][offset];

        if (!(*msk_ptr) && mask_val) {
            accumulator += *img_ptr;
            divisor++;
        }
        img_ptr++;
        msk_ptr++;

        if ((idx + 1) % row_width == 0) {
            img_ptr += (image_linesize - row_width);
            msk_ptr += (mask_linesize - row_width);
        }
    }
}
