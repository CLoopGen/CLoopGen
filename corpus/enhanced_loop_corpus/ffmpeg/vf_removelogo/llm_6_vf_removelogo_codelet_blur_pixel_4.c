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
    unsigned int local_accumulator = 0;
    unsigned int local_divisor = 0;
    uint8_t *img_pos = image_read_position;
    uint8_t *msk_pos = mask_read_position;

    for (j = start_posy; j <= end_posy; j++) {
        for (i = start_posx; i <= end_posx; i++) {
            int mask_val = mask[mask_size][i - start_posx][j - start_posy];
            if (!(*msk_pos) && mask_val) {
                local_accumulator += *img_pos;
                local_divisor++;
            }
            img_pos++;
            msk_pos++;
        }
        img_pos += (image_linesize - ((end_posx + 1) - start_posx));
        msk_pos += (mask_linesize - ((end_posx + 1) - start_posx));
    }
    accumulator += local_accumulator;
    divisor += local_divisor;
}
