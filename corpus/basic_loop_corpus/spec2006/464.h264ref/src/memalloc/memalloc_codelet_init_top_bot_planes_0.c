#include <stdio.h>

#include <inttypes.h>

extern unsigned short **imgFrame;
extern int rows;
extern unsigned short ***imgTopField;
extern unsigned short ***imgBotField;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < rows / 2; i++) {
    (*imgTopField)[i] = imgFrame[2 * i];
    (*imgBotField)[i] = imgFrame[2 * i + 1];
}

}
