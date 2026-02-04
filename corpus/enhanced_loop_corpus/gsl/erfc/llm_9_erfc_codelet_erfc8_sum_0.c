#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x;
extern double P[];
extern double num;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 8; i >= 0; --i) {
    num = x * num + (i % 2 == 0 ? P[i % 5] : 0);
}
}
