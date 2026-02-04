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
    // Variant 1: Strided Memory Access Pattern
    // Instead of incrementing pointers per iteration, use strided access with calculated offsets
    ptrdiff_t img_stride = 1;
    ptrdiff_t msk_stride = 1;
    ptrdiff_t img_line_skip = image_linesize - ((end_posx + 1) - start_posx);
    ptrdiff_t msk_line_skip = mask_linesize - ((end_posx + 1) - start_posx);

    for (j = start_posy; j <= end_posy; j++) {
        for (i = start_posx; i <= end_posx; i++) {
            size_t img_offset = (j * (image_linesize / sizeof(uint8_t)) + i) * img_stride;
            size_t msk_offset = (j * (mask_linesize / sizeof(uint8_t)) + i) * msk_stride;

            if (!(mask_read_position[msk_offset]) && mask[mask_size][i - start_posx][j - start_posy]) {
                accumulator += image_read_position[img_offset];
                divisor++;
            }
        }
        image_read_position += (image_linesize - ((end_posx + 1) - start_posx)) + (end_posx - start_posx + 1);
        mask_read_position += (mask_linesize - ((end_posx + 1) - start_posx)) + (end_posx - start_posx + 1);
    }
}
