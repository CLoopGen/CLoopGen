#include <stdio.h>

#include <inttypes.h>

extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = n;
    for (;; temp++) {
        n = temp + 1;
        return;
    }
}
