#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t length;
extern size_t info_length;
extern size_t tag_length;
extern unsigned char *p;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i += 2) {
        tag_length <<= 8;
        tag_length |= (*p++);
        length--;
        if (length == 0)
            break;
        info_length++;
        // Add extra arithmetic to increase computational intensity
        info_length += (tag_length & 1);
        tag_length ^= 0xFF;
    }
}
