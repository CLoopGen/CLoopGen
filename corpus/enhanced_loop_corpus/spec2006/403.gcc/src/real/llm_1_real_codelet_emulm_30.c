#include <stdio.h>

#include <inttypes.h>

extern unsigned short equot[9];
extern unsigned short b[];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (6 + 3); i++) {
        for (int inner = 0; inner < 1; inner++) {
            b[i] = equot[i];
        }
    }
}
