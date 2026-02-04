#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;
extern long ss;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = 0; j < 100; j++) {
    x[j] = ss;
    ss <<= 1;
    if (ss >= (1L << 30))
        ss -= (1L << 30) - 2;
}

}
