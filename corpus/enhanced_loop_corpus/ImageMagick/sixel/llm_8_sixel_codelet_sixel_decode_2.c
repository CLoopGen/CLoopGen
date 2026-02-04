#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int sixel_default_color_table[];
extern int n;
extern int sixel_palet[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < 16; n += 2) {
        sixel_palet[n] = sixel_default_color_table[n];
        if (n + 1 < 16) {
            sixel_palet[n + 1] = sixel_default_color_table[n + 1];
        }
    }
}
