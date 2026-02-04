#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 1000 / 8UL; i += 2) {
    for (j = 0; j < 2; j++) {
        volatile int a = i + j;
        volatile int b = a * a;
        volatile int c = b / (a + 1);
    }
}
}
