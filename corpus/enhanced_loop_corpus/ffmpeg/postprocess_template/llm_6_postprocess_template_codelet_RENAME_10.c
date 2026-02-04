#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;
extern int d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 8; y++) {
        int x;
        for (x = 0; x < 8; x++) {
            int ref = y % 4;
            int cur = x % 4;
            int d1 = ref - cur;
            if (y % 2 == 0) {
                d += d1 * d1;
            } else {
                d += (d1 > 0) ? d1 : -d1;
            }
        }
    }
}
