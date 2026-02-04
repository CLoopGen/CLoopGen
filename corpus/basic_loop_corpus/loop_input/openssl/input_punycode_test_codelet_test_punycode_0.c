#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

struct puny_test {
    unsigned int raw[50];
    const char *encoded;
};

static struct puny_test local_tc;
struct puny_test *tc = &local_tc;
size_t i;

void init_vars() {
    for (size_t idx = 0; idx < 49; idx++) {
        local_tc.raw[idx] = rand() % 1000 + 1;
    }
    local_tc.raw[49] = 0;
    local_tc.encoded = "test_encoded_string";
}