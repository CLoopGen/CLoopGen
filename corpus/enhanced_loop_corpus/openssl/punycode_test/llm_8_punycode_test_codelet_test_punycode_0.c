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
    size_t limit = sizeof(tc->raw) / sizeof((tc->raw)[0]);
    for (i = 0; i < limit; i += 2) {
        if (i + 1 < limit) {
            if (tc->raw[i] == 0 || tc->raw[i + 1] == 0)
                break;
        } else {
            if (tc->raw[i] == 0)
                break;
        }
    }
}
