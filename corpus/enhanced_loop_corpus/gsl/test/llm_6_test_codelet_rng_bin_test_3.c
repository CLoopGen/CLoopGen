#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int count[27];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < 17 + 10; i++) {
        temp = count[i] + temp;  // Introduce RAW dependency: temp depends on previous temp
        count[i] = temp;         // WAW dependency on count[i], and loop-carried dependency via temp
    }
}
