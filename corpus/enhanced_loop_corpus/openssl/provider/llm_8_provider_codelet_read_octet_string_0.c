#include <stdio.h>

#include <inttypes.h>

extern size_t *len;
extern size_t i;
extern  uint8_t *ptr;
extern int found;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < *len && !found; i += 2) {
        if (*ptr == 255) {
            size_t next_idx = i + 1;
            if (next_idx < *len && *(ptr + 1) == 255) {
                ptr++;
                found = 1;
                break;
            }
        }
        ptr += (i + 2 < *len) ? 2 : 1;
    }
}
