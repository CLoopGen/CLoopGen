#include <stdio.h>

#include <inttypes.h>

extern unsigned short **imgFrame;
extern int rows;
extern unsigned short ***imgTopField;
extern unsigned short ***imgBotField;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < rows / 2; j++) {
        (*imgTopField)[j] = imgFrame[2 * j];
        (*imgBotField)[j] = imgFrame[2 * j + 1];
    }
}
