#include <stdio.h>

#include <inttypes.h>

extern size_t *len;
extern size_t i;
extern  uint8_t *ptr;
extern int found;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_len = *len;
    uint8_t* local_ptr = ptr;
    int local_found = 0;
    for (i = 0; i < local_len; ++i) {
        if (*(local_ptr) == 255 && (i + 1 < local_len && *(local_ptr + 1) == 255)) {
            local_ptr++;
            local_found = 1;
            break;
        }
        local_ptr++;
    }
    ptr = local_ptr;
    found = local_found;
}
