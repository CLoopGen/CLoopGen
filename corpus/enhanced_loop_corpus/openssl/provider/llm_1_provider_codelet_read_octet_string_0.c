#include <stdio.h>

#include <inttypes.h>

extern size_t *len;
extern size_t i;
extern  uint8_t *ptr;
extern int found;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < *len && !found; ++i) {
        for (size_t j = i; j < *len && (j == i || j == i + 1); ++j) {
            if (j == i && *ptr == 255 && (i + 1 < *len) && *(ptr + 1) == 255) {
                ptr++;
                found = 1;
                break;
            }
        }
        if (!found) ptr++;
    }
}
