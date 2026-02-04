#include <stdio.h>

#include <inttypes.h>

extern int a;
extern int b;
extern int i;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (b > 0) {
        r *= a;
        for (i = 1; i < b; i++) {
            r *= a;
        }
    }
}
