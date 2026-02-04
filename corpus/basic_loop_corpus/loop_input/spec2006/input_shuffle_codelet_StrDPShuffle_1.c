#include <inttypes.h>

int x;
char Z[26];

void init_vars() {
    x = 0;
    for (int i = 0; i < 26; i++) {
        Z[i] = 0;
    }
}