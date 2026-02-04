#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int end_y;
extern int n;
extern uint8_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 1; i < end_y; i++) {
        for (n = i; n < i + 1 && n < end_y; n += 4) {
            l[n] = l[n - 1];
        }
    }
}
