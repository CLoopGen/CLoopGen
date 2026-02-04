#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern uchar *in;
extern uchar *mid;
extern int x_size;
extern int y_size;
extern int i;
extern uchar *midp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process every 4th element first, then stride-1 within each phase
    const int stride = 4;
    uchar *in_local = in;
    uchar *midp_base = midp;
    int total_size = x_size * y_size;
    int phase, i;

    for (phase = 0; phase < stride; phase++) {
        for (i = phase; i < total_size; i += stride) {
            uchar *current_midp = midp_base + i;
            if (*current_midp < 8) {
                *(in_local + (current_midp - mid)) = 0;
            }
        }
    }

    // Advance the global midp pointer by total_size
    midp += total_size;
}
