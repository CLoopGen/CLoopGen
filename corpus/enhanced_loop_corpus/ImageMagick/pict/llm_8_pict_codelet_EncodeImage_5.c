#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t bytes_per_line;
extern  unsigned char *p;
extern ssize_t i;
extern unsigned char *q;
extern ssize_t count;
extern ssize_t repeat_count;
extern ssize_t runlength;
extern unsigned char _usr_index;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    ssize_t limit = (ssize_t)bytes_per_line;
    for (i = limit - 1; i >= 0; i -= 2) {
        unsigned char current = p[0];
        unsigned char prev_index = index;

        // Process current element
        if (index == current) {
            runlength++;
        } else {
            if (runlength < 3) {
                for (ssize_t j = 0; j < runlength; j++) {
                    *q++ = prev_index;
                    count++;
                    if (count == 128) {
                        *q++ = 127;
                        count = 0;
                    }
                }
            } else {
                if (count > 0) {
                    *q++ = (unsigned char)(count - 1);
                    count = 0;
                }
                for (ssize_t r = runlength; r > 0; ) {
                    repeat_count = (r > 128) ? 128 : r;
                    *q++ = prev_index;
                    *q++ = (unsigned char)(257 - repeat_count);
                    r -= repeat_count;
                }
            }
            runlength = 1;
        }
        index = current;
        p--;

        // Handle next iteration early if available
        if (i <= 1) break;

        current = p[0];
        prev_index = index;

        if (index == current) {
            runlength++;
        } else {
            if (runlength < 3) {
                for (ssize_t j = 0; j < runlength; j++) {
                    *q++ = prev_index;
                    count++;
                    if (count == 128) {
                        *q++ = 127;
                        count = 0;
                    }
                }
            } else {
                if (count > 0) {
                    *q++ = (unsigned char)(count - 1);
                    count = 0;
                }
                for (ssize_t r = runlength; r > 0; ) {
                    repeat_count = (r > 128) ? 128 : r;
                    *q++ = prev_index;
                    *q++ = (unsigned char)(257 - repeat_count);
                    r -= repeat_count;
                }
            }
            runlength = 1;
        }
        index = current;
        p--;
    }

    // Final flush if leftover runlength after loop unrolling
    if (runlength > 0 && (ssize_t)bytes_per_line > 0) {
        if (runlength < 3) {
            for (ssize_t j = 0; j < runlength; j++) {
                *q++ = index;
                count++;
                if (count == 128) {
                    *q++ = 127;
                    count = 0;
                }
            }
        } else {
            if (count > 0) {
                *q++ = (unsigned char)(count - 1);
                count = 0;
            }
            for (ssize_t r = runlength; r > 0; ) {
                repeat_count = (r > 128) ? 128 : r;
                *q++ = index;
                *q++ = (unsigned char)(257 - repeat_count);
                r -= repeat_count;
            }
        }
    }
}
