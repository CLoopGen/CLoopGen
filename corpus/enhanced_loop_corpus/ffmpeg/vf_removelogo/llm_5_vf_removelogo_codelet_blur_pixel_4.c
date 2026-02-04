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
for (j = start_posy; j <= end_posy; j++) {
    for (i = start_posx; i <= end_posx; i++) {
        if (mask[mask_size][i - start_posx][j - start_posy]) {
            if (!(*mask_read_position)) {
                accumulator += *image_read_position;
                divisor++;
            }
        }
        image_read_position++;
        mask_read_position++;
    }
    image_read_position += (image_linesize - ((end_posx + 1) - start_posx));
    mask_read_position += (mask_linesize - ((end_posx + 1) - start_posx));
}
}
