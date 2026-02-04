#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int counts[17];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 4; i++) {
        for (int j = 0; j <= 3; j++) {
            int idx = i * 4 + j;
            if (idx <= 16)
                counts[idx] = 0;
        }
    }
}
