#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

extern INT32 *rgb_ycc_tab;
extern INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= 255; i += 2) {
    INT32 val = i;
    INT32 val_plus1 = i + 1;
    rgb_ycc_tab[val + 0] = ((INT32)((0.29899999999999999) * (1L << 16) + 0.5)) * val;
    rgb_ycc_tab[val_plus1 + 0] = ((INT32)((0.29899999999999999) * (1L << 16) + 0.5)) * val_plus1;
    
    rgb_ycc_tab[val + (1 * (255 + 1))] = ((INT32)((0.58699999999999997) * (1L << 16) + 0.5)) * val;
    rgb_ycc_tab[val_plus1 + (1 * (255 + 1))] = ((INT32)((0.58699999999999997) * (1L << 16) + 0.5)) * val_plus1;
    
    rgb_ycc_tab[val + (2 * (255 + 1))] = ((INT32)((0.114) * (1L << 16) + 0.5)) * val + ((INT32)1 << (16 - 1));
    rgb_ycc_tab[val_plus1 + (2 * (255 + 1))] = ((INT32)((0.114) * (1L << 16) + 0.5)) * val_plus1 + ((INT32)1 << (16 - 1));
    
    rgb_ycc_tab[val + (3 * (255 + 1))] = (-((INT32)((0.16874) * (1L << 16) + 0.5))) * val;
    rgb_ycc_tab[val_plus1 + (3 * (255 + 1))] = (-((INT32)((0.16874) * (1L << 16) + 0.5))) * val_plus1;
    
    rgb_ycc_tab[val + (4 * (255 + 1))] = (-((INT32)((0.33126) * (1L << 16) + 0.5))) * val;
    rgb_ycc_tab[val_plus1 + (4 * (255 + 1))] = (-((INT32)((0.33126) * (1L << 16) + 0.5))) * val_plus1;
    
    rgb_ycc_tab[val + (5 * (255 + 1))] = ((INT32)((0.5) * (1L << 16) + 0.5)) * val + ((INT32)128 << 16) + ((INT32)1 << (16 - 1)) - 1;
    rgb_ycc_tab[val_plus1 + (5 * (255 + 1))] = ((INT32)((0.5) * (1L << 16) + 0.5)) * val_plus1 + ((INT32)128 << 16) + ((INT32)1 << (16 - 1)) - 1;
    
    rgb_ycc_tab[val + (6 * (255 + 1))] = (-((INT32)((0.41869000000000001) * (1L << 16) + 0.5))) * val;
    rgb_ycc_tab[val_plus1 + (6 * (255 + 1))] = (-((INT32)((0.41869000000000001) * (1L << 16) + 0.5))) * val_plus1;
    
    rgb_ycc_tab[val + (7 * (255 + 1))] = (-((INT32)((0.081309999999999993) * (1L << 16) + 0.5))) * val;
    rgb_ycc_tab[val_plus1 + (7 * (255 + 1))] = (-((INT32)((0.081309999999999993) * (1L << 16) + 0.5))) * val_plus1;
}
}
