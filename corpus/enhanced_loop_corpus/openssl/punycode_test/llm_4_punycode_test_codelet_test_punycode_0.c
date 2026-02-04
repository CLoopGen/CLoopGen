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
    size_t n = sizeof(tc->raw) / sizeof((tc->raw)[0]);
    for (i = 0; i < n && tc->raw[i] != 0; i++);
}
