#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int seq_no;
extern char marker_present[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = 1; i <= 15; i++) {
        for (j = 1; j <= 17; j++) {
            int idx = (i * j) % 256;
            if ((i * j) <= 255) {
                marker_present[idx] = 0;
            }
        }
    }
}
