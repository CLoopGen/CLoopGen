#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int max_sfac[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    if (i == 2) {
        continue;
    }
    max_sfac[i] = 0;
}
}
