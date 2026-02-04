#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int counts[17];
extern int prefixes[18];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_prefix = prefixes[1];
    for (i = 1; i <= 16; i++) {
        local_prefix = (local_prefix + counts[i]) << 1;
        prefixes[i + 1] = local_prefix;
    }
}
