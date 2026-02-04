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
    // Variant 1: Consecutive memory access with forward traversal using pointer arithmetic
    // All array accesses are done in a strictly consecutive, forward manner.
    // The inner logic is restructured to eliminate while loops and use only for loops.

    ssize_t x = 0;
    int j, replacement, delta;
    unsigned char *p_curr = pixels;
    unsigned char *p_prev = previous_pixels;
    unsigned char *q_ptr = q;

    for (x = 0; x < (ssize_t)length; ) {
        j = 0;
        for (ssize_t i = 0; x < (ssize_t)length; x++, p_curr++, p_prev++) {
            if (*p_curr != *p_prev) {
                i = 1;
                break;
            }
            j++;
        }

        // Simulate the second part of the original while loop as a for-loop
        for (; x < (ssize_t)length && *p_curr == *p_prev; ) {
            x++;
            p_curr++;
            p_prev++;
            i++;
        }

        if (i == 0) break;

        replacement = (j >= 31) ? 31 : j;
        j -= replacement;
        delta = (i >= 8) ? 8 : (int)i;
        *q_ptr++ = (unsigned char)(((delta - 1) << 5) | replacement);

        if (replacement == 31) {
            for (int rem = j; rem > 0; ) {
                int chunk = (rem > 255) ? 255 : rem;
                *q_ptr++ = (unsigned char)chunk;
                rem -= chunk;
            }
            if (j >= 255) {
                *q_ptr++ = '\x00';
            }
        }

        p_curr -= i;  // Rewind to start of differing segment

        for (int remaining = i; remaining > 0; ) {
            int step = (remaining >= 8) ? 8 : remaining;
            delta = step;
            *q_ptr++ = (unsigned char)((delta - 1) << 5);
            for (int k = 0; k < delta; k++) {
                *q_ptr++ = *p_curr++;
            }
            remaining -= delta;
        }
    }

    // Update global pointers
    pixels = p_curr;
    previous_pixels = p_prev;
    q = q_ptr;
}
