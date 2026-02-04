#include <stdio.h>

#include <inttypes.h>

extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i = 0;
    for (;; i++) {
        if (i >= n) {
            n = i;
            return;
        }
    }
}
