#include <stdio.h>

#include <inttypes.h>

extern unsigned short **imgFrame;
extern int rows;
extern unsigned short ***imgTopField;
extern unsigned short ***imgBotField;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access by processing two output elements at a time (unrolled-like pattern)
    int double_rows = rows / 2;
    for (i = 0; i < double_rows; i += 2) {
        (*imgTopField)[i] = imgFrame[2 * i];
        (*imgBotField)[i] = imgFrame[2 * i + 1];
        if (i + 1 < double_rows) {
            (*imgTopField)[i + 1] = imgFrame[2 * (i + 1)];
            (*imgBotField)[i + 1] = imgFrame[2 * (i + 1) + 1];
        }
    }
}
