#include <stdio.h>
#include <inttypes.h>

float delta_territory_cache[400];
int ii;

void init_vars() {
    // Initialize the array to a known state if needed
    for (int i = 0; i < 400; i++) {
        delta_territory_cache[i] = 0.0f;
    }
    ii = 0;
}