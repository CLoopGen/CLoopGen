#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

extern INT32 *rgb_ycc_tab;
extern INT32 i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i <= 255; i++) {
    rgb_ycc_tab[i + 0] = ((INT32)((0.29899999999999999) * (1L << 16) + 0.5)) * i;
    rgb_ycc_tab[i + (1 * (255 + 1))] = ((INT32)((0.58699999999999997) * (1L << 16) + 0.5)) * i;
    rgb_ycc_tab[i + (2 * (255 + 1))] = ((INT32)((0.114) * (1L << 16) + 0.5)) * i + ((INT32)1 << (16 - 1));
    rgb_ycc_tab[i + (3 * (255 + 1))] = (-((INT32)((0.168735892) * (1L << 16) + 0.5))) * i;
    rgb_ycc_tab[i + (4 * (255 + 1))] = (-((INT32)((0.331264108) * (1L << 16) + 0.5))) * i;
    rgb_ycc_tab[i + (5 * (255 + 1))] = (i << (16 - 1)) + ((INT32)128 << 16) + ((INT32)1 << (16 - 1)) - 1;
    rgb_ycc_tab[i + (6 * (255 + 1))] = (-((INT32)((0.41868758900000003) * (1L << 16) + 0.5))) * i;
    rgb_ycc_tab[i + (7 * (255 + 1))] = (-((INT32)((0.081312411000000001) * (1L << 16) + 0.5))) * i;
}

}
