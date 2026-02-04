#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int end_y;
extern int n;
extern uint8_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (end_y > 1) {
        n = 1;
        for (int outer = n; outer < end_y; outer += 4) {
            l[outer] = l[outer - 1];
            for (int inner = 0; inner < 1 && (outer + 4) < end_y; inner++) {
                l[outer + 4] = l[outer + 3];
            }
        }
    }
}
