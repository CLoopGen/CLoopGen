#include <stdio.h>

#include <inttypes.h>

typedef unsigned long UV;

extern UV power;
extern UV result;
extern UV base;
extern int n;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (; power; base *= base , n++) {
    register UV bit = (UV)1 << (UV)n;
    if (power & bit) {
        result *= base;
        power -= bit;
        if (power == 0)
            break;
    }
}

}
