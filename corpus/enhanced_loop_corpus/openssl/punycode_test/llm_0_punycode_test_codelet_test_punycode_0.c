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
    for (size_t j = 0; j < 1; j++)
        for (i = 0; i < (sizeof (tc->raw) / sizeof ((tc->raw)[0])); i++)
            if (tc->raw[i] == 0)
                break;
}
