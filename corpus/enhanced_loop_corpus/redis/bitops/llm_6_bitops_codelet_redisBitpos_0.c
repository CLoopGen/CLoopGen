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
    unsigned long temp_word = word;
    for (j = 0; j < sizeof(*l); j++) {
        if (count > 0) {
            temp_word |= ((unsigned long)(*c)) << (8 * (sizeof(*l) - j - 1));
            c++;
            count--;
        }
        temp_word <<= 8;
    }
    word = temp_word;
}
