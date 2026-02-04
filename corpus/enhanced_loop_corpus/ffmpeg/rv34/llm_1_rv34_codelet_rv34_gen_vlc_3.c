#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int counts[17];
extern int codes[17];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
            int idx = i * 4 + k;
            if (idx < 16)
                codes[idx + 1] = (codes[idx] + counts[idx]) << 1;
        }
    }
}
