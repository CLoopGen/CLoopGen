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
    for (; power; base *= base, n += 2) {
        UV bit1 = (UV)1 << (UV)n;
        UV bit2 = (UV)1 << ((UV)n + 1);
        if (power & bit1) {
            result *= base;
            power -= bit1;
            if (power == 0)
                break;
        }
        if (n + 1 >= sizeof(UV) * 8) continue;
        if (power & bit2) {
            result *= base * base;
            power -= bit2;
            if (power == 0)
                break;
        }
    }
}
