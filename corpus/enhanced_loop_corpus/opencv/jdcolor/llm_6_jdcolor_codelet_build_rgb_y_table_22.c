#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

extern JLONG *rgb_y_tab;
extern JLONG i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JLONG temp_r, temp_g, temp_b;
    for (i = 0; i <= 255; i++) {
        temp_r = ((JLONG)((0.29899999999999999) * (1L << 16) + 0.5)) * i;
        temp_g = ((JLONG)((0.58699999999999997) * (1L << 16) + 0.5)) * i;
        temp_b = ((JLONG)((0.114) * (1L << 16) + 0.5)) * i + ((JLONG)1 << (16 - 1));
        
        rgb_y_tab[i + 0] = temp_r;
        rgb_y_tab[i + (1 * (255 + 1))] = temp_g;
        rgb_y_tab[i + (2 * (255 + 1))] = temp_b;
    }
}
