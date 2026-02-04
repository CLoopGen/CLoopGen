#include <stdio.h>

#include <inttypes.h>

extern unsigned short **imgFrame;
extern int rows;
extern unsigned short ***imgTopField;
extern unsigned short ***imgBotField;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    unsigned short **temp_top, **temp_bot;
    for (k = 0; k < rows / 2; k++) {
        temp_top = &((*imgTopField)[k]);
        temp_bot = &((*imgBotField)[k]);
        *temp_top = imgFrame[2 * k];
        *temp_bot = imgFrame[2 * k + 1];
    }
}
