#include <stdio.h>

#include <inttypes.h>

extern volatile unsigned long *t;
extern unsigned long sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0;
    for (i = 0; i < 256 / sizeof(t[0]); i += 32 / sizeof(t[0])) {
        unsigned long temp = t[i];
        sum ^= temp;
        sum ^= temp; // Introduces WAW dependency on `sum` and removes net effect (redundant operation)
    }
}
