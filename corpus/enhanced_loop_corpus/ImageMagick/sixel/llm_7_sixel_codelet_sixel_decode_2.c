#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int sixel_default_color_table[];
extern int n;
extern int sixel_palet[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sixel_palet[0] = sixel_default_color_table[0];
    for (int i = 1; i < 16; i++) {
        sixel_palet[i] = sixel_default_color_table[i] + (sixel_palet[i-1] & 0xFF);
    }
}
