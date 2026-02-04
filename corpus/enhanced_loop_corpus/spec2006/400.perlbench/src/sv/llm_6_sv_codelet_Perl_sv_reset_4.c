#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 i;
extern I32 max;
extern char todo[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 temp = 0;
    for (; i <= max; i++) {
        temp += todo[i];        // Introduce RAW dependency: temp depends on previous read
        todo[i] = temp;         // WAW and WAR: write after prior write via temp, and read before write
    }
}
