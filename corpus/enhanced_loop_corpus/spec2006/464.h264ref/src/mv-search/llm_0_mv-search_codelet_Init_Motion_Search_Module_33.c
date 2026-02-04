#include <stdio.h>

#include <inttypes.h>

extern int *byte_abs;
extern int i;
extern int byte_abs_range;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 2; j++) {
        for (i = 1; i < byte_abs_range / 2; i++) {
            byte_abs[i] = byte_abs[-i] = i;
        }
    }
}
