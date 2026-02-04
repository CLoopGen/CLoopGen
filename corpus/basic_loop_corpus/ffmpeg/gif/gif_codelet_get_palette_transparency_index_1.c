#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint32_t *palette;
extern int transparent_color_index;
extern unsigned int i;
extern unsigned int smallest_alpha;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 256; i++) {
    const uint32_t v = palette[i];
    if (v >> 24 < smallest_alpha) {
        smallest_alpha = v >> 24;
        transparent_color_index = i;
    }
}

}
