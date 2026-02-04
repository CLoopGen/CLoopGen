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
        for (JLONG j = 0; j <= 2; j++) {
            if (j == 0) {
                rgb_y_tab[i + 0] = ((JLONG)((0.29899999999999999) * (1L << 16) + 0.5)) * i;
            } else if (j == 1) {
                rgb_y_tab[i + (1 * (255 + 1))] = ((JLONG)((0.58699999999999997) * (1L << 16) + 0.5)) * i;
            } else if (j == 2) {
                rgb_y_tab[i + (2 * (255 + 1))] = ((JLONG)((0.114) * (1L << 16) + 0.5)) * i + ((JLONG)1 << (16 - 1));
            }
        }
    }
}
