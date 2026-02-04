#include <stdio.h>

#include <inttypes.h>

typedef unsigned long UV;

typedef double NV;

extern UV power;
extern NV result;
extern NV base;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    UV temp_power = power;
    int local_n = 0;
    NV local_result = result;
    NV local_base = base;

    for (; temp_power; local_n++) {
        UV bit = (UV)1 << (UV)local_n;
        if (temp_power & bit) {
            local_result *= local_base;
            temp_power -= bit;
            if (temp_power == 0)
                break;
        }
        local_base *= local_base;
    }

    result = local_result;
}
