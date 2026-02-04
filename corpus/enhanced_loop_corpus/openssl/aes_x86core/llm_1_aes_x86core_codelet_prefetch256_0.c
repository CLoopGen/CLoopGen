#include <stdio.h>

#include <inttypes.h>

extern volatile unsigned long *t;
extern unsigned long sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (sum = 0, i = 0; i < 256 / sizeof(t[0]); ) {
        if (i % (32 / sizeof(t[0])) == 0) {  // Decreased effective depth: removed inner iteration logic, using condition
            sum ^= t[i];
        }
        i++;
    }
}
