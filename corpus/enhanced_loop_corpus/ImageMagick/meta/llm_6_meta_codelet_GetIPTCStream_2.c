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
    ssize_t temp_info = info_length;
    size_t temp_tag = tag_length;
    for (i = 0; i < 4; i++) {
        temp_tag <<= 8;
        temp_tag |= (*p++);
        length--;
        temp_info++;
        if (length == 0)
            break;
    }
    tag_length = temp_tag;
    info_length = temp_info;
}
