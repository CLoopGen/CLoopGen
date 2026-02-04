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
    int j_start = start_posy;
    int j_end = end_posy;
    int i_start = start_posx;
    int i_end = end_posx;
    int img_stride = image_linesize - (end_posx - start_posx + 1);
    int msk_stride = mask_linesize - (end_posx - start_posx + 1);

    for (j = j_start; j <= j_end; j++) {
        for (i = i_start; i <= i_end; i += 2) {
            uint8_t *img_ptr1 = image_read_position;
            uint8_t *msk_ptr1 = mask_read_position;
            accumulator += *img_ptr1;
            divisor++;
            if ((i + 1) <= i_end) {
                uint8_t *img_ptr2 = img_ptr1 + 1;
                uint8_t *msk_ptr2 = msk_ptr1 + 1;
                accumulator += *img_ptr2;
                divisor++;
                image_read_position += 2;
                mask_read_position += 2;
            } else {
                image_read_position++;
                mask_read_position++;
            }
        }
        image_read_position += img_stride;
        mask_read_position += msk_stride;
    }
}
