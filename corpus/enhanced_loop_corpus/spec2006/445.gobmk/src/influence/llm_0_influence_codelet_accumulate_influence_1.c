#include <stdio.h>

#include <inttypes.h>

extern int ii;
extern int working[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 19 + 1; i++)
        for (int j = 0; j < 19 + 1; j++)
            working[i * (19 + 1) + j] = 0;
}
