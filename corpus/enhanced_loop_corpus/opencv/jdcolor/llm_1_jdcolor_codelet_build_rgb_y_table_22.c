#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

extern JLONG *rgb_y_tab;
extern JLONG i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 255; i += 8) {
        for (JLONG k = 0; k < 8; k++) {
            JLONG idx = i + k;
            if (idx > 255) break;
            rgb_y_tab[idx + 0] = ((JLONG)((0.29899999999999999) * (1L << 16) + 0.5)) * idx;
            rgb_y_tab[idx + (1 * (255 + 1))] = ((JLONG)((0.58699999999999997) * (1L << 16) + 0.5)) * idx;
            rgb_y_tab[idx + (2 * (255 + 1))] = ((JLONG)((0.114) * (1L << 16) + 0.5)) * idx + ((JLONG)1 << (16 - 1));
        }
    }
}
