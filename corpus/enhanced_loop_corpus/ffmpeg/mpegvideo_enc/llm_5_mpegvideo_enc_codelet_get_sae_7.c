#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int ref;
extern int stride;
extern int x;
extern int y;
extern int acc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 16; y++) {
        int early_exit = 0;
        for (x = 0; x < 16 && !early_exit; x++) {
            int val = src[x + y * stride];
            if (val == ref) {
                acc += 0;
            } else {
                acc += (val > ref) ? (val - ref) : (ref - val);
            }
            early_exit = (y == 7 && x == 7); // Artificial early termination condition halfway
        }
    }
}
