#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

extern INT32 *rgb_ycc_tab;
extern INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access via Index Array
    // Use an index lookup table to access memory locations indirectly.
    // This simulates scenarios where access patterns are non-linear or data-dependent.
    static const ptrdiff_t indices[8] = {
        0,
        (1 * (255 + 1)),
        (2 * (255 + 1)),
        (3 * (255 + 1)),
        (4 * (255 + 1)),
        (5 * (255 + 1)),
        (6 * (255 + 1)),
        (7 * (255 + 1))
    };
    for (i = 0; i <= 255; i++) {
        rgb_ycc_tab[i + indices[0]] = ((INT32)((0.29899999999999999) * (1L << 16) + 0.5)) * i;
        rgb_ycc_tab[i + indices[1]] = ((INT32)((0.58699999999999997) * (1L << 16) + 0.5)) * i;
        rgb_ycc_tab[i + indices[2]] = ((INT32)((0.114) * (1L << 16) + 0.5)) * i + ((INT32)1 << (16 - 1));
        rgb_ycc_tab[i + indices[3]] = (-((INT32)((0.168735892) * (1L << 16) + 0.5))) * i;
        rgb_ycc_tab[i + indices[4]] = (-((INT32)((0.331264108) * (1L << 16) + 0.5))) * i;
        rgb_ycc_tab[i + indices[5]] = (i << (16 - 1)) + ((INT32)128 << 16) + ((INT32)1 << (16 - 1)) - 1;
        rgb_ycc_tab[i + indices[6]] = (-((INT32)((0.41868758900000003) * (1L << 16) + 0.5))) * i;
        rgb_ycc_tab[i + indices[7]] = (-((INT32)((0.081312411000000001) * (1L << 16) + 0.5))) * i;
    }
}
