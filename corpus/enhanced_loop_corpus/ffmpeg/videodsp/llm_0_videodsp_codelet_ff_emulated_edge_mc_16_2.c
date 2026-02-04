#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int start_x;
extern uint16_t *bufp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < start_x; i++) {
        for (int j = 0; j < 1; j++) {
            bufp[i] = bufp[start_x];
        }
    }
}
