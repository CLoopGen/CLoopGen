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
    ssize_t local_runlength = runlength;
    unsigned char local_index = index;
    unsigned char *local_p = p;
    unsigned char *local_q = q;
    ssize_t local_count = count;

    for (i = (ssize_t)bytes_per_line - 1; i >= 0; i--) {
        if (local_index == *local_p) {
            local_runlength++;
        } else {
            if (local_runlength < 3) {
                for (; local_runlength > 0; local_runlength--) {
                    *local_q++ = local_index;
                    local_count++;
                    if (local_count == 128) {
                        *local_q++ = 127;
                        local_count -= 128;
                    }
                }
            } else {
                if (local_count > 0) {
                    *local_q++ = (unsigned char)(local_count - 1);
                    local_count = 0;
                }
                ssize_t remaining = local_runlength;
                for (; remaining > 0; ) {
                    ssize_t repeat_count = remaining > 128 ? 128 : remaining;
                    *local_q++ = local_index;
                    *local_q++ = (unsigned char)(257 - repeat_count);
                    remaining -= repeat_count;
                }
            }
            local_runlength = 1;
        }
        local_index = *local_p;
        local_p--;
    }

    // Update shared state only once at the end to eliminate loop-carried WAW and WAR hazards
    runlength = local_runlength;
    index = local_index;
    p = local_p;
    q = local_q;
    count = local_count;
}
