#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

extern JLONG *rgb_y_tab;
extern JLONG i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 255; i++) {
        if (i < 128) {
            rgb_y_tab[i + 0] = ((JLONG)((0.29899999999999999) * (1L << 16) + 0.5)) * i;
        } else {
            rgb_y_tab[i + 0] = ((JLONG)((0.29899999999999999) * (1L << 16) + 0.5)) * (i - 1);
        }
        rgb_y_tab[i + (1 * (255 + 1))] = ((JLONG)((0.58699999999999997) * (1L << 16) + 0.5)) * i;
        rgb_y_tab[i + (2 * (255 + 1))] = ((JLONG)((0.114) * (1L << 16) + 0.5)) * i + ((JLONG)1 << (16 - 1));
    }
}
