#include <stdio.h>

#include <inttypes.h>

extern unsigned short equot[9];
extern unsigned short num[];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (6 + 3); i += 2) {
        num[i] = equot[i];
        if (i + 1 < (6 + 3)) {
            num[i + 1] = equot[i + 1];
        }
    }
}
