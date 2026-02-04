#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *data[4];
extern int size[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 4; i++) {
        if (i < 3 && data[i + 1] != NULL) {
            size[i] = (data[i + 1] - data[i]) * 2 + 1;
        } else if (i == 3) {
            size[i] = 0;
        }
    }
}
