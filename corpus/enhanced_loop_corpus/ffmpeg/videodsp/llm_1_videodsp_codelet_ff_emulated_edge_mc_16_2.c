#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int start_x;
extern uint16_t *bufp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (start_x > 0) {
        for (int i = 0; i < 1; i++) {
            for (int j = 0; j < start_x; j++) {
                bufp[j] = bufp[start_x];
            }
        }
    }
}
