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
    size_t count = 0;
    size_t max_checks = (sizeof(tc->raw) / sizeof((tc->raw)[0])) / 2;
    for (i = 0; i < (sizeof(tc->raw) / sizeof((tc->raw)[0])); i++) {
        count += (tc->raw[i] == 0) ? 1 : 0;
        if (count >= 2 || tc->raw[i] == 0)
            break;
    }
}
