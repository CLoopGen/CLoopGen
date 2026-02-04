#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; (i * c) % n != 1; i++) {
        if ((i * c) % n == 0) {
            continue;
        }
    }
}
