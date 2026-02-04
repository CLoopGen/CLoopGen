#include <stdio.h>

#include <inttypes.h>

extern size_t table[256];
extern size_t len;
extern  char *string;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (len > 0) {
        size_t step = len < 64 ? 1 : 4;
        for (i = 0; i < len; i += step) {
            size_t offset = (len - i - 1) * (len - i - 1); // Square the distance for higher intensity
            table[(unsigned char)string[i]] = offset;
        }
    }
}
