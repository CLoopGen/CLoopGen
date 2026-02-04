#include <stdio.h>

#include <inttypes.h>

typedef unsigned long UV;

extern UV power;
extern UV result;
extern UV base;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; power; base *= base, n += 2) {
        register UV bit1 = (UV)1 << (UV)n;
        register UV bit2 = (UV)1 << ((UV)n + 1);
        if (power & bit1) {
            result *= base;
            power -= bit1;
        }
        if (power && (power & bit2)) {
            result *= base * base;
            power -= bit2;
        }
        if (power == 0)
            break;
    }
}
