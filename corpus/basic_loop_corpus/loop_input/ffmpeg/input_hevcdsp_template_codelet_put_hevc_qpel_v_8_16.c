#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dst;
int height;
int width;
int x;
int y;
uint8_t *src;
ptrdiff_t srcstride;
int8_t *filter;

void init_vars() {
    height = 512;
    width = 64;
    srcstride = 64;

    size_t src_size = (height + 7) * srcstride; // allow for filter reaching 4 rows ahead
    size_t dst_size = height * (width);         // 64 int16_t per row, advanced by dst += 64

    src = (uint8_t*)calloc(src_size, sizeof(uint8_t));
    dst = (int16_t*)calloc(dst_size, sizeof(int16_t));
    filter = (int8_t*)calloc(8, sizeof(int8_t));

    // Initialize filter with some values; example: symmetric filter
    filter[0] = -1;
    filter[1] = 3;
    filter[2] = -5;
    filter[3] = 7;
    filter[4] = 7;
    filter[5] = -5;
    filter[6] = 3;
    filter[7] = -1;

    // Ensure that src accesses from x - 3*srcstride to x + 4*srcstride are valid
    // So we need at least 4 rows before and after the current row access range
    // We allocated extra rows above: 7 extra at beginning/end covered by (height + 7)
    // But we start src base such that first valid row is at index 3*srcstride offset
    // However, in loop we only iterate over 'height' rows, so as long as underlying memory allows
    // access to [x ± k*srcstride] safely, we're fine.

    // Since we access up to x - 3*srcstride, we must ensure that the first accessed row is >= 3*srcstride
    // Our src pointer already points to beginning of extended buffer, so during first iteration:
    // row index 0: accessing src[x - 3*srcstride] -> requires data starting at -3*srcstride offset?
    // That would be invalid if src points to start.

    // Therefore, shift src forward by 3*srcstride so that the first actual pixel row starts there.
    // Then when y=0, x-3*srcstride refers to src[-3*srcstride] relative to original base — which is bad.

    // Instead, let's make sure our allocation has enough padding before the first used row.
    // Reallocate with prefix padding.

    free(src);
    size_t pad_before = 4 * srcstride;
    src_size = pad_before + height * srcstride + 4 * srcstride; // 4 before, 4 after
    src = (uint8_t*)calloc(src_size, sizeof(uint8_t));
    // Now point src to the start of usable data (after 4-row padding)
    src += pad_before;

    // Adjust dst similarly: no negative indexing, but we write directly
    free(dst);
    dst = (int16_t*)calloc(height * 64, sizeof(int16_t)); // each row writes 64 elements

    // Initialize src with non-zero test pattern if needed
    for (int i = 0; i < height * srcstride; i++) {
        src[i] = rand() & 0xFF;
    }
}

// Do not include main(), headers, explanations or comments.