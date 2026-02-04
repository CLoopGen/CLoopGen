#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *ydst;
extern uint8_t *udst;
extern uint8_t *vdst;
extern int height;
extern int lumStride;
extern int chromStride;
extern int srcStride;
extern int y;
extern  int chromWidth;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y += 2) {
    int i;
    const int cwidth = chromWidth;
    uint8_t *src_ptr = src;
    uint8_t *ydst_ptr = ydst;
    uint8_t *udst_ptr = udst;
    uint8_t *vdst_ptr = vdst;

    for (i = 0; i < cwidth; i++) {
        // Interleaved write pattern using consecutive memory writes via pointer arithmetic
        *udst_ptr++ = *src_ptr++;
        *ydst_ptr++ = *src_ptr++;
        *vdst_ptr++ = *src_ptr++;
        *ydst_ptr++ = *src_ptr++; // skips over u/v in src, consumes 4 bytes
        src_ptr++; // skip next U (already consumed in previous row logic)
        src_ptr++; // skip next V
        ydst_ptr += lumStride - 2; // move ydst pointer to next line after completing current
        src_ptr += srcStride - 6;  // adjust src to point to next row start (after skipping UV)
    }

    // Now process second row of luma from the updated src position
    src_ptr = src + srcStride;
    ydst_ptr = ydst + lumStride;

    for (i = 0; i < cwidth; i++) {
        src_ptr++; // skip U
        *ydst_ptr++ = *src_ptr++;
        src_ptr++; // skip V
        *ydst_ptr++ = *src_ptr++;
        ydst_ptr += lumStride - 2;
        src_ptr += srcStride - 4;
    }

    udst += chromStride;
    vdst += chromStride;
    ydst += 2 * lumStride;
    src += 2 * srcStride;
}
}
