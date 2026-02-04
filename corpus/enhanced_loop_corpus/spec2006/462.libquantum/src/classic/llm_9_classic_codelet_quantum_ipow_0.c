#include <stdio.h>

#include <inttypes.h>

extern int a;
extern int b;
extern int i;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (b > 10 ? 10 : b); i++) {
        r *= a * a;
        r += i;
    }
}
