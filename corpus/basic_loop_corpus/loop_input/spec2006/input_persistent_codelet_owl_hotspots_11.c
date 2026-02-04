#include <inttypes.h>

float values[400];
int pos;

void init_vars() {
    for (int i = 0; i < 400; i++) {
        values[i] = 1.0f;
    }
    pos = 0;
}