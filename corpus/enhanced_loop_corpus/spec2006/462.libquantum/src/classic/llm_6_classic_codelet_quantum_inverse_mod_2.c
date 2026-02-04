#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 1;
    for (i = 1; (temp * c) % n != 1; i++) {
        temp = i;
    }
}
