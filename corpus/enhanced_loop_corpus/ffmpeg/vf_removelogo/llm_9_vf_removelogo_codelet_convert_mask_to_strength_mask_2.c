#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int linesize;
extern int w;
extern int h;
extern int x;
extern int y;
extern int current_pass;
extern int has_anything_changed;
extern uint8_t *current_pixel0;
extern uint8_t *current_pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the inner loop by a factor of 2 to increase computational intensity per iteration
    for (y = 1; y < h - 1; y++) {
        current_pixel = current_pixel0 + 1;
        int limit_x = w - 1;
        for (x = 1; x < limit_x - 1; x += 2) {
            uint8_t* pix1 = current_pixel;
            uint8_t* pix2 = current_pixel + 1;

            // First pixel check (original logic)
            if (*pix1 >= current_pass && *(pix1 + 1) >= current_pass && 
                *(pix1 - 1) >= current_pass && *(pix1 + linesize) >= current_pass && 
                *(pix1 - linesize) >= current_pass) {
                (*pix1)++;
                has_anything_changed = 1;
            }

            // Second pixel check (if within bounds)
            if (x + 1 < limit_x - 1) {
                if (*pix2 >= current_pass && *(pix2 + 1) >= current_pass && 
                    *(pix2 - 1) >= current_pass && *(pix2 + linesize) >= current_pass && 
                    *(pix2 - linesize) >= current_pass) {
                    (*pix2)++;
                    has_anything_changed = 1;
                }
            }

            current_pixel += 2;
        }
        // Handle odd width case with a final scalar iteration if needed
        if (x == limit_x - 1) {
            uint8_t* last_pix = current_pixel;
            if (*last_pix >= current_pass && *(last_pix + 1) >= current_pass && 
                *(last_pix - 1) >= current_pass && *(last_pix + linesize) >= current_pass && 
                *(last_pix - linesize) >= current_pass) {
                (*last_pix)++;
                has_anything_changed = 1;
            }
        }
        current_pixel0 += linesize;
    }
}
