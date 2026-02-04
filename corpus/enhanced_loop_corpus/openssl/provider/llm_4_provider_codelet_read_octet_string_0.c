#include <stdio.h>

#include <inttypes.h>

extern size_t *len;
extern size_t i;
extern  uint8_t *ptr;
extern int found;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < *len && !found; ++i) {
        if (*ptr == 255) {
            ptr++;
            found = 1;
            break;
        }
        ptr++;
    }
}
