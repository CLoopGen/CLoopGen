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
    // Variant 2: Consecutive Block Access with Local Tiling
    // Precompute row base pointers to enable more predictable, block-like memory access
    uint8_t* img_row_base = image_read_position - start_posx;
    uint8_t* msk_row_base = mask_read_position - start_posx;
    int width = (end_posx - start_posx + 1);

    for (j = start_posy; j <= end_posy; j++) {
        uint8_t* img_current = img_row_base + (j * (image_linesize / sizeof(uint8_t)));
        uint8_t* msk_current = msk_row_base + (j * (mask_linesize / sizeof(uint8_t)));

        for (i = 0; i < width; i++) {
            if (!(msk_current[i]) && mask[mask_size][i][j - start_posy]) {
                accumulator += img_current[i];
                divisor++;
            }
        }
    }

    // Final pointer update to maintain external state consistency
    image_read_position = img_row_base + ((end_posy + 1) * (image_linesize / sizeof(uint8_t)));
    mask_read_position = msk_row_base + ((end_posy + 1) * (mask_linesize / sizeof(uint8_t)));
}
