#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int end_x;
extern int n;
extern uint8_t *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 1; i < end_x; i += 4) {
        for (n = i; n < i + 2 && n < end_x; n += 1) {
            a[n] = a[n - 1];
        }
    }
}
