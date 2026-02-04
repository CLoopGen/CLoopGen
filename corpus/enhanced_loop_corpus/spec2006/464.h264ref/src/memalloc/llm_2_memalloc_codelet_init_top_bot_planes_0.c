#include <stdio.h>

#include <inttypes.h>

extern unsigned short **imgFrame;
extern int rows;
extern unsigned short ***imgTopField;
extern unsigned short ***imgBotField;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    unsigned short **top = *imgTopField;
    unsigned short **bot = *imgBotField;
    unsigned short **frame = imgFrame;
    int limit = rows / 2;
    for (i = 0; i < limit; i++) {
        top[i] = frame[2 * i];
        bot[i] = frame[2 * i + 1];
    }
}
