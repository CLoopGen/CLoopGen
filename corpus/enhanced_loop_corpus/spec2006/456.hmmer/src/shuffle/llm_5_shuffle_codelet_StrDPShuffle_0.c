#include <stdio.h>

#include <inttypes.h>

extern int x;
extern int *iE;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < 26; x++) {
    if (x == 10) {
        continue;
    }
    iE[x] = 0;
}
}
