#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

extern INT32 *rgb_ycc_tab;
extern INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int k = 0; k < 8; k++) { // Loop nesting altered: outer loop now iterates over coefficient groups
        for (i = 0; i <= 255; i++) {
            switch(k) {
                case 0:
                    rgb_ycc_tab[i + 0] = ((INT32)((0.29899999999999999) * (1L << 16) + 0.5)) * i;
                    break;
                case 1:
                    rgb_ycc_tab[i + (1 * (255 + 1))] = ((INT32)((0.58699999999999997) * (1L << 16) + 0.5)) * i;
                    break;
                case 2:
                    rgb_ycc_tab[i + (2 * (255 + 1))] = ((INT32)((0.114) * (1L << 16) + 0.5)) * i + ((INT32)1 << (16 - 1));
                    break;
                case 3:
                    rgb_ycc_tab[i + (3 * (255 + 1))] = (-((INT32)((0.16874) * (1L << 16) + 0.5))) * i;
                    break;
                case 4:
                    rgb_ycc_tab[i + (4 * (255 + 1))] = (-((INT32)((0.33126) * (1L << 16) + 0.5))) * i;
                    break;
                case 5:
                    rgb_ycc_tab[i + (5 * (255 + 1))] = ((INT32)((0.5) * (1L << 16) + 0.5)) * i + ((INT32)128 << 16) + ((INT32)1 << (16 - 1)) - 1;
                    break;
                case 6:
                    rgb_ycc_tab[i + (6 * (255 + 1))] = (-((INT32)((0.41869000000000001) * (1L << 16) + 0.5))) * i;
                    break;
                case 7:
                    rgb_ycc_tab[i + (7 * (255 + 1))] = (-((INT32)((0.081309999999999993) * (1L << 16) + 0.5))) * i;
                    break;
            }
        }
    }
}
