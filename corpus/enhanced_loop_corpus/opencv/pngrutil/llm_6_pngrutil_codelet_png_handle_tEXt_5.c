#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef char *png_charp;

extern png_charp key;
extern png_charp text;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_charp temp = key;
    for (text = key; *temp; temp++) {
        text = temp + 1;
    }
    if (*key) text = key + 1;
}
