#include <stdio.h>

#include <inttypes.h>

typedef unsigned long UV;

typedef double NV;

extern UV power;
extern NV result;
extern NV base;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; power; base *= base, n++) {
        UV bit = (UV)1 << (UV)n;
        if (power & bit) {
            for (int i = 0; i < 1; i++) {
                result *= base;
                power -= bit;
                if (power == 0)
                    break;
            }
            if (power == 0)
                break;
        }
    }
}
