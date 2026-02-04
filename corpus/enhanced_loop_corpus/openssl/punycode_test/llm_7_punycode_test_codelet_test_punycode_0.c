#include <stdio.h>

#include <inttypes.h>

struct puny_test {
    unsigned int raw[50];
    const char *encoded;
};


extern  struct puny_test *tc;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    volatile unsigned int prev = 0;
    size_t count = 0;
    size_t limit = sizeof(tc->raw) / sizeof((tc->raw)[0]);
    for (i = 0; i < limit; i++) {
        unsigned int curr = tc->raw[i];
        if ((curr == 0) || (curr < prev)) { // Introduce RAW dependency: curr depends on prev
            count++; // WAW: multiple writes to count in loop
            break;
        }
        prev = curr; // Loop-carried dependency: prev used in next iteration
    }
    if (count == 0) {
        tc->raw[0] = 0; // Additional write after loop (WAR: write after read in loop)
    }
}
