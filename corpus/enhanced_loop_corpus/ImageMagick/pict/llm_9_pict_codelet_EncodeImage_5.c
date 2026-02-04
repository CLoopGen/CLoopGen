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
    // Reduce effective trip count by skipping small segments and increase per-iteration work
    const ssize_t step = 4;
    ssize_t total = (ssize_t)bytes_per_line;
    ssize_t remaining = total % step;
    
    // Process main loop in chunks of 4 to reduce control overhead
    for (i = total - 1; i >= remaining; i -= step) {
        // Accumulate changes over multiple elements without branching frequently
        unsigned char batch[4];
        ssize_t valid = 0;

        for (ssize_t offset = 0; offset < step && (i - offset) >= 0; offset++) {
            batch[offset] = p[-offset];
            valid++;
        }

        // Process each element in the batch inline
        for (ssize_t b = 0; b < valid; b++) {
            unsigned char curr = batch[b];

            if (index == curr) {
                runlength++;
            } else {
                // Emit literal run if short
                if (runlength < 3) {
                    for (ssize_t rep = 0; rep < runlength; rep++) {
                        *q++ = index;
                        count++;
                        if (count == 128) {
                            *q++ = 127;
                            count = 0;
                        }
                    }
                } else {
                    // Emit compressed run
                    if (count > 0) {
                        *q++ = (unsigned char)(count - 1);
                        count = 0;
                    }
                    ssize_t temp_run = runlength;
                    while (temp_run > 0) {
                        repeat_count = (temp_run > 128) ? 128 : temp_run;
                        *q++ = index;
                        *q++ = (unsigned char)(257 - repeat_count);
                        temp_run -= repeat_count;
                    }
                }
                runlength = 1;
            }
            index = curr;
        }
        p -= valid;
    }

    // Handle remaining elements with direct unrolled logic
    for (; i >= 0; i--) {
        if (index == *p) {
            runlength++;
        } else {
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
                ssize_t temp = runlength;
                for (ssize_t seg = 0; seg < ((temp + 127) / 128); seg++) {
                    repeat_count = (temp > 128) ? 128 : temp;
                    *q++ = index;
                    *q++ = (unsigned char)(257 - repeat_count);
                    temp -= repeat_count;
                }
            }
            runlength = 1;
        }
        index = *p;
        p--;
    }

    // Finalize any pending output
    if (runlength > 0) {
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
            ssize_t rem = runlength;
            for (ssize_t seg = 0; seg < ((rem + 127) / 128); seg++) {
                repeat_count = (rem > 128) ? 128 : rem;
                *q++ = index;
                *q++ = (unsigned char)(257 - repeat_count);
                rem -= repeat_count;
            }
        }
    }
}
