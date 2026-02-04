#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct FFPsyWindowInfo {
    int window_type[3];
    int window_shape;
    int num_windows;
    int grouping[8];
    float clipping[8];
    int *window_sizes;
} FFPsyWindowInfo;

extern int i;
extern uint8_t grouping;
extern FFPsyWindowInfo wi;
extern int lastgrp;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 8; i++) {
    if (!((grouping >> i) & 1))
        lastgrp = i;
    wi.grouping[lastgrp]++;
}

}
