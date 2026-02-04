#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ch;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ch = 0; ch <= 1; ++ch) {
    int8_t buffer[32];
    int8_t *const base = buffer;
    int8_t *const top = base;
    int8_t *const left = base + 16;
    // Strided memory access: accessing elements with a fixed stride (every 8th element)
    top[ch * 8] = 10;
    top[ch * 8 + 2] = 11;
    left[ch * 8] = 20;
    left[ch * 8 + 2] = 21;
}
}
