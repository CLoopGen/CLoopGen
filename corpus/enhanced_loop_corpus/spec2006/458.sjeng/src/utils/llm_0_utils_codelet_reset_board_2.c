#include <stdio.h>

#include <inttypes.h>

extern int moved[144];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++)
        for (i = 0; i <= 143; i++)
            moved[i] = 0;
}
