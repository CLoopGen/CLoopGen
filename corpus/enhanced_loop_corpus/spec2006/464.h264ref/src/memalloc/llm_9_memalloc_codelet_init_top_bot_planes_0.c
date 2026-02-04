#include <stdio.h>

#include <inttypes.h>

extern unsigned short **imgFrame;
extern int rows;
extern unsigned short ***imgTopField;
extern unsigned short ***imgBotField;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int limit = rows / 2;
for (i = 0; i < limit; i += 2) {
    if (i + 1 < limit) {
        (*imgTopField)[i] = imgFrame[2 * i];
        (*imgBotField)[i] = imgFrame[2 * i + 1];
        (*imgTopField)[i + 1] = imgFrame[2 * (i + 1)];
        (*imgBotField)[i + 1] = imgFrame[2 * (i + 1) + 1];
    } else {
        (*imgTopField)[i] = imgFrame[2 * i];
        (*imgBotField)[i] = imgFrame[2 * i + 1];
    }
}
}
