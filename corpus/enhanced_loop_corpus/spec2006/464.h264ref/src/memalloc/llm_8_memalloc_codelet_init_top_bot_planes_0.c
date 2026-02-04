#include <stdio.h>

#include <inttypes.h>

extern unsigned short **imgFrame;
extern int rows;
extern unsigned short ***imgTopField;
extern unsigned short ***imgBotField;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < rows / 4; i++) {
    int idx1 = 2 * i;
    int idx2 = 2 * i + 1;
    (*imgTopField)[idx1] = imgFrame[2 * idx1];
    (*imgBotField)[idx1] = imgFrame[2 * idx1 + 1];
    (*imgTopField)[idx2] = imgFrame[2 * idx2];
    (*imgBotField)[idx2] = imgFrame[2 * idx2 + 1];
}
}
