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
    for (ssize_t depth = 0; depth < 1; depth++) {
        if (index == *p) {
            runlength++;
        } else {
            for (ssize_t fill_run = 0; runlength < 3 && fill_run < runlength; fill_run++) {
                *q++ = (unsigned char)index;
                count++;
                if (count == 128) {
                    *q++ = (unsigned char)(128 - 1);
                    count -= 128;
                }
            }
            for (ssize_t rep_run = 0; runlength >= 3 && rep_run == 0; rep_run++) {
                if (count > 0) {
                    *q++ = (unsigned char)(count - 1);
                    count = 0;
                }
                do {
                    repeat_count = runlength > 128 ? 128 : runlength;
                    *q++ = (unsigned char)index;
                    *q++ = (unsigned char)(257 - repeat_count);
                    runlength -= repeat_count;
                } while (runlength > 0);
            }
            runlength = 1;
        }
        index = (*p);
        p--;
    }
}
}
