#include <stdio.h>

#include <inttypes.h>

extern int a;
extern int b;
extern int i;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 1;
    for (i = 0; i < b; i++) {
        temp *= a;
    }
    r = temp;
}
