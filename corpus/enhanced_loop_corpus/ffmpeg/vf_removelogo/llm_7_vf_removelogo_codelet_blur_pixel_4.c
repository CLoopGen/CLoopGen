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
    unsigned int temp_acc = accumulator;
    unsigned int temp_div = divisor;

    for (j = start_posy; j <= end_posy; j++) {
        unsigned int row_accumulator = 0;
        unsigned int row_divisor = 0;
        uint8_t *img_row_pos = image_read_position + (j - start_posy) * image_linesize;
        uint8_t *msk_row_pos = mask_read_position + (j - start_posy) * mask_linesize;

        for (i = start_posx; i <= end_posx; i++) {
            ptrdiff_t mask_offset = (i - start_posx);
            if (!(msk_row_pos[mask_offset]) && mask[mask_size][mask_offset][j - start_posy]) {
                row_accumulator += img_row_pos[mask_offset];
                row_divisor++;
            }
        }
        temp_acc += row_accumulator;
        temp_div += row_divisor;
    }

    accumulator = temp_acc;
    divisor = temp_div;
}
