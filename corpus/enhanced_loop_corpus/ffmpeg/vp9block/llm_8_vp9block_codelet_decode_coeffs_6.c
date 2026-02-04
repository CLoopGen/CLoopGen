#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int end_x;
extern int n;
extern uint8_t *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 2; i < end_x; i += 4) {
        if (i - 1 < end_x) a[i - 1] = a[i - 2];
        if (i + 1 < end_x) a[i + 1] = a[i];
    }
}
