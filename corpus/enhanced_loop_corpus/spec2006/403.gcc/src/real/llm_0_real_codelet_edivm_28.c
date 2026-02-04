#include <stdio.h>

#include <inttypes.h>

extern unsigned short equot[9];
extern unsigned short num[];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++)
        for (i = 0; i < (6 + 3); i++)
            num[i] = equot[i];
}
