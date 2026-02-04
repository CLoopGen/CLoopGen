#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int counts[17];
extern int codes[17];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp;
for (i = 0; i < 8; i++) {
    temp = (codes[i] + counts[i]) << 1;
    codes[i + 1] = temp;
    codes[i + 9] = (codes[i + 8] + counts[i + 8]) << 2;
}
}
