#include <stdio.h>

#include <inttypes.h>

extern size_t *len;
extern size_t i;
extern  uint8_t *ptr;
extern int found;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t limit = *len - (*len > 0 ? 1 : 0);
    for (i = 0; i < limit; ++i) {
        uint8_t current = *ptr;
        uint8_t next = *(ptr + 1);
        if (current == 255 && next == 255) {
            ptr++;
            found = 1;
            break;
        }
        ptr++;
    }
}
