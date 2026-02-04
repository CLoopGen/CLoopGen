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
        if (index == *p) {
            runlength++;
        } else {
            if (runlength >= 3) {
                if (count > 0) {
                    *q++ = (unsigned char)(count - 1);
                    count = 0;
                }
                repeat_count = runlength;
                *q++ = (unsigned char)index;
                *q++ = (unsigned char)(257 - (repeat_count > 128 ? 128 : repeat_count));
                runlength -= (repeat_count > 128 ? 128 : repeat_count);
                if (runlength > 0) {
                    *q++ = (unsigned char)index;
                    *q++ = (unsigned char)(257 - runlength);
                    runlength = 0;
                }
            } else {
                for (ssize_t j = 0; j < runlength; j++) {
                    *q++ = (unsigned char)index;
                    count++;
                    if (count == 128) {
                        *q++ = (unsigned char)(128 - 1);
                        count -= 128;
                    }
                }
            }
            runlength = 1;
        }
        index = *p;
        p--;
    }
}
