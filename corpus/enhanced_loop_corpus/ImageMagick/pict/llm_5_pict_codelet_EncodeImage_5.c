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
    for (i = (ssize_t)bytes_per_line - 1; i >= 0; i--) {
        unsigned char current = *p;
        int is_same = (index == current);

        runlength += is_same;
        if (!is_same || i == 0) {
            int use_literal = (runlength < 3);
            count += use_literal ? runlength : 0;

            if (!use_literal && count > 0) {
                *q++ = (unsigned char)(count - 1);
                count = 0;
            }

            if (!use_literal) {
                repeat_count = runlength > 128 ? 128 : runlength;
                *q++ = (unsigned char)index;
                *q++ = (unsigned char)(257 - repeat_count);
                runlength -= repeat_count;
                if (runlength > 0) {
                    *q++ = (unsigned char)index;
                    *q++ = (unsigned char)(257 - runlength);
                    runlength = 0;
                }
            } else {
                for (ssize_t j = 0; j < runlength; j++) {
                    *q++ = (unsigned char)index;
                    if (++count == 128) {
                        *q++ = (unsigned char)(128 - 1);
                        count = 0;
                    }
                }
            }

            if (is_same) {
                runlength = 1;
            } else {
                runlength = 1;
                index = current;
            }
        }

        if (!is_same && i != 0) {
            index = current;
        }
        p--;
    }
}
