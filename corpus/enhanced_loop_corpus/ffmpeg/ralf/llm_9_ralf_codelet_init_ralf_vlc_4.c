#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int counts[17];
extern int prefixes[18];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= 16; i += 2) {
        int temp1 = prefixes[i] + counts[i];
        int temp2 = prefixes[i + 1] + counts[i + 1];
        prefixes[i + 1] = temp1 << 1;
        if (i + 1 < 17) {
            prefixes[i + 2] = temp2 << 1;
        }
    }
}
