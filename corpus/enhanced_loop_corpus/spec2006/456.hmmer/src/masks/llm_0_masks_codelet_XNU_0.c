#include <stdio.h>

#include <inttypes.h>

extern int len;
extern int i;
extern int *hit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++)
        for (i = 1; i <= len; i++)
            hit[i] = 0;
}
