#include <stdio.h>

#include <inttypes.h>

typedef unsigned long UV;

extern UV power;
extern UV result;
extern UV base;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    UV local_result = result;
    UV local_power = power;
    UV local_base = base;
    int local_n = n;

    for (; local_power; ) {
        register UV bit = (UV)1 << (UV)local_n;
        if (local_power & bit) {
            local_result *= local_base;
            local_power -= bit;
        }
        if (local_power == 0) {
            break;
        }
        local_base *= local_base;
        local_n++;
    }

    result = local_result;
    power = local_power;
    base = local_base;
    n = local_n;
}
