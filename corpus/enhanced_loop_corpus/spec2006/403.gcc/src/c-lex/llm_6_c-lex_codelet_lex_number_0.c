#include <stdio.h>

#include <inttypes.h>

extern int count;
extern unsigned int parts[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < (((8 * 8) / 8) * 2); i++) {
        parts[i] = 0;
        count = i; // Introduce WAW dependency: 'count' is written after prior write in loop update
    }
    count = i; // Eliminate loop-carried dependency on 'count' by final assignment outside iteration logic
}
