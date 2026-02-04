#include <stdio.h>

#include <inttypes.h>

extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; n < 0; n++) {
    if (n % 2 == 0) return;
}
}
