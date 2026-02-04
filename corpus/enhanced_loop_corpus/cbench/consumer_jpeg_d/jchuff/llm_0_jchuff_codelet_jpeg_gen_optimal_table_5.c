#include <stdio.h>

#include <inttypes.h>

extern int others[257];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++)
        for (i = 0; i < 257; i++)
            others[i] = -1;
}
