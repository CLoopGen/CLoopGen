#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int end_x;
extern int n;
extern uint8_t *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 1; ++i) {
        for (n = 1; n < end_x; n += 8)
            a[n] = a[n - 1];
    }
}
