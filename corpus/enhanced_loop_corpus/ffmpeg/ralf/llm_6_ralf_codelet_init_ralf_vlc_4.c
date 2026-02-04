#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int counts[17];
extern int prefixes[18];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[17];
    for (i = 1; i <= 16; i++) {
        temp[i] = counts[i] << 1;
        prefixes[i + 1] = prefixes[i] + temp[i];
    }
}
