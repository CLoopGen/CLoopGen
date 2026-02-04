#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long count;
extern unsigned long *l;
extern unsigned char *c;
extern unsigned long word;
extern unsigned long j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long local_count = count;
    unsigned char *local_c = c;
    unsigned long local_word = word;

    for (j = 0; j < sizeof(*l); j++) {
        local_word <<= 8;
        if (local_count > 0) {
            local_word |= *local_c;
            local_c++;
            local_count--;
        }
    }

    word = local_word;
    c = local_c;
    count = local_count;
}
