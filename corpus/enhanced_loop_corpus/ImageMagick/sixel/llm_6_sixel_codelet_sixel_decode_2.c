#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int sixel_default_color_table[];
extern int n;
extern int sixel_palet[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[16];
    for (int i = 0; i < 16; i++) {
        temp[i] = sixel_default_color_table[i];
    }
    for (int i = 0; i < 16; i++) {
        sixel_palet[i] = temp[i];
    }
}
