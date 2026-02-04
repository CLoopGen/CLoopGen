#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern float highest;
extern float workT[32];
extern int found_indx;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 32; i++) {
    if (workT[i] > highest) {
        highest = workT[i];
        found_indx = i;
    }
}

}
