#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int counts[17];
extern int prefixes[18];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= 16; i++) {
        int temp_sum = prefixes[i] + counts[i];
        if (temp_sum != 0)
            prefixes[i + 1] = temp_sum << 1;
        else
            prefixes[i + 1] = 0;
    }
}
