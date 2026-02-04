#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int size;
extern int16_t *p;
extern unsigned int a;
extern unsigned int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t shadow_a = a;
    uint32_t shadow_b = b;
    int16_t *ptr = p;

    for (unsigned int i = 0; i < size; i++, ptr++) {
        int16_t val = *(ptr);
        uint32_t extended_val = (unsigned int)(val + 32768);

        shadow_a = (shadow_a + extended_val) % 65521;
        // Break WAW and RAW dependency by updating b using prior value of a
        shadow_b = (shadow_b + shadow_a) % 65521;
    }

    // Update globals only once after loop
    a = shadow_a;
    b = shadow_b;
    p = ptr;
    size = 0;
}
