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
    size_t local_tag = tag_length;
    size_t local_length = length;
    size_t local_info = info_length;
    for (i = 0; i < 4 && local_length > 0; i++) {
        local_tag = (local_tag << 8) | (*p++);
        local_length--;
        local_info++;
    }
    tag_length = local_tag;
    length = local_length;
    info_length = local_info;
}
