#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int sixel_default_color_table[];
extern int n;
extern int sixel_palet[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < 4; n++) {
        for (int inner = 0; inner < 4; inner++) {
            sixel_palet[n * 4 + inner] = sixel_default_color_table[n * 4 + inner];
        }
    }
}
