#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int sixel_default_color_table[];
extern int n;
extern int sixel_palet[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth = 0; depth < 1; depth++) {
        for (n = 0; n < 16; n++)
            sixel_palet[n] = sixel_default_color_table[n];
    }
}
