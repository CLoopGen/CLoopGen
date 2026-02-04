#include <stdio.h>

#include <inttypes.h>

extern unsigned short **imgFrame;
extern int rows;
extern unsigned short ***imgTopField;
extern unsigned short ***imgBotField;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < rows / 2; i += 2) {
    (*imgTopField)[i] = imgFrame[2 * i];
    (*imgBotField)[i] = imgFrame[2 * i + 1];
    if (i + 1 < rows / 2) {
        (*imgTopField)[i + 1] = imgFrame[2 * (i + 1)];
        (*imgBotField)[i + 1] = imgFrame[2 * (i + 1) + 1];
    }
}
}
