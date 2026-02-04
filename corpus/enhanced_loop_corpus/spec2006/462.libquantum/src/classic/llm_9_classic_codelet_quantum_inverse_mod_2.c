#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int product = c % n;
    for (i = 1; (product != 1) && (i < n); i++) {
        product = (product + c) % n;
    }
}
