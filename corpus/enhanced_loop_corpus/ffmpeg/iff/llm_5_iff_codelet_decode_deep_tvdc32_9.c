#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int src_size;
extern int width;
extern int height;
extern int linesize;
extern  int16_t *tvdc;
extern int x;
extern int y;
extern int plane;
extern int8_t pixel;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < src_size * 2;) {
        int index = i >> 1;
        int nibble = (i & 1) ? (src[index] & 15) : (src[index] >> 4);
        int d = tvdc[nibble];
        i++;

        if (d) {
            pixel += d;
            dst[y * linesize + x * 4 + plane] = pixel;
            x++;
        } else {
            i++; // Skip next nibble immediately
            if (i > src_size * 2) break;

            int run_length = ((i & 1) ? (src[i >> 1] & 15) : (src[i >> 1] >> 4)) + 1;
            run_length = (run_length > (width - x)) ? (width - x) : run_length;

            while (run_length-- > 0) { // Replacing for with while-like behavior using expression
                dst[y * linesize + x * 4 + plane] = pixel;
                x++;
            }
        }

        if (x >= width) {
            plane = (plane + 1) % 4;
            if (plane == 0) {
                y++;
                if (y >= height) return;
                x = 0;
                pixel = 0;
                i = (i + 1) & ~1;
            }
        }
    }
}
