#include <stdio.h>

#include <inttypes.h>

extern int count;
extern unsigned int parts[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 2; i++)
        for (count = i * 8; count < (i + 1) * 8; count++)
            parts[count] = 0;
}
