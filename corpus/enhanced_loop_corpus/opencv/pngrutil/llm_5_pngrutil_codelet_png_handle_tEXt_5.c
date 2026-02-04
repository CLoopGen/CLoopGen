#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef char *png_charp;

extern png_charp key;
extern png_charp text;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (text = key; *text && (*text >= 'a' && *text <= 'z'); text++)
        ;
}
