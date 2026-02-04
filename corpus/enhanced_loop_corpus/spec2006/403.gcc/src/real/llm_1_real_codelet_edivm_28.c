#include <stdio.h>

#include <inttypes.h>

extern unsigned short equot[9];
extern unsigned short num[];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (6 + 3); i++) {
        for (int k = 0; k < 1; k++)
            num[i] = equot[i];
    }
}
