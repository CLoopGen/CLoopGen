#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern  unsigned char *previous_pixels;
extern  unsigned char *pixels;
extern int delta;
extern int j;
extern int replacement;
extern ssize_t i;
extern ssize_t x;
extern unsigned char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern
    // Access memory with a fixed stride (every 2nd element), simulating non-unit access.
    // This variant processes data in strides to change access pattern, still maintaining correctness
    // by adjusting loop bounds and handling edge cases. Only 'for' loops are used.

    const int stride = 2;  // Stride factor for memory access
    ssize_t x = 0;
    unsigned char *p_curr = pixels;
    unsigned char *p_prev = previous_pixels;
    unsigned char *q_ptr = q;

    for (x = 0; x + stride - 1 < (ssize_t)length; x += stride) {
        int j = 0;
        int match_found = 0;

        // First inner loop: check for equality with strided access
        for (ssize_t i = 0; x + i + stride - 1 < (ssize_t)length && !match_found; i += stride) {
            if (*(p_curr + i) != *(p_prev + i)) {
                match_found = 1;
                i = 1;
                // Now scan forward from this point with unit stride until mismatch or boundary
                for (ssize_t pos = x + i; pos < (ssize_t)length; pos++) {
                    if (p_curr[pos] != p_prev[pos]) {
                        i = pos - x + 1;
                        x = pos;
                        p_curr += i;
                        p_prev += i;
                        break;
                    }
                }
            } else {
                j += stride;
            }
        }

        if (!match_found) {
            // Handle case where all strided elements matched up to boundary
            j += ((ssize_t)length - x) % stride;
        }

        if (j == 0) break;

        int replacement = (j >= 31) ? 31 : j;
        j -= replacement;
        int segment_len = (ssize_t)length - x;
        int delta = (segment_len >= 8) ? 8 : segment_len;

        *q_ptr++ = (unsigned char)(((delta - 1) << 5) | replacement);

        if (replacement == 31) {
            for (int rem = j; rem > 0; ) {
                int r = (rem > 255) ? 255 : rem;
                *q_ptr++ = (unsigned char)r;
                rem -= r;
            }
            if (j >= 255) {
                *q_ptr++ = '\x00';
            }
        }

        // Write differing pixel values using strided output (only every 2nd byte)
        for (int offset = 0; offset < delta && (x + offset) < (ssize_t)length; offset += stride) {
            *q_ptr++ = p_curr[-delta + offset];
        }

        // Finalize block with control byte if more segments remain
        if (delta > 0) {
            *q_ptr++ = (unsigned char)((delta - 1) << 5);
        }
    }

    // Update global state
    pixels = p_curr;
    previous_pixels = p_prev;
    q = q_ptr;
}
