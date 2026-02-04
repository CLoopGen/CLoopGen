#include <stdio.h>

#include <inttypes.h>

typedef unsigned long UV;

extern UV power;
extern UV result;
extern UV base;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    UV temp_result = result;
    UV temp_power = power;
    UV temp_base = base;
    int temp_n = n;

    for (; temp_power; temp_base *= temp_base, temp_n++) {
        register UV bit = (UV)1 << (UV)temp_n;
        if (temp_power & bit) {
            temp_result *= temp_base;
            temp_power -= bit;
            if (temp_power == 0)
                break;
        }
    }

    result = temp_result;
    power = temp_power;
    base = temp_base;
    n = temp_n;
}
