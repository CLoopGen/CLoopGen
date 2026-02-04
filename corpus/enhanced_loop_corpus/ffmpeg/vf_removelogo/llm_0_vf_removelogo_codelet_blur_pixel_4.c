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
    uint8_t *img_ptr = image_read_position;
    uint8_t *msk_ptr = mask_read_position;
    int img_line_skip = image_linesize - (i_end + 1 - i_start);
    int msk_line_skip = mask_linesize - (i_end + 1 - i_start);

    for (j = j_start; j <= j_end; j++) {
        for (i = i_start; i <= i_end; i++) {
            if (!(*msk_ptr) && mask[mask_size][i - i_start][j - j_start]) {
                accumulator += *img_ptr;
                divisor++;
            }
            img_ptr++;
            msk_ptr++;
        }
        img_ptr += img_line_skip;
        msk_ptr += msk_line_skip;
    }
}
