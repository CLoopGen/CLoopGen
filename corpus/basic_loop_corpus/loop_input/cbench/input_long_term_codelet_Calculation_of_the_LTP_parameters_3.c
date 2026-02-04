#include <stdio.h>
#include <inttypes.h>

typedef short word;
typedef long longword;

word *dp;
int k;
word Nc;
longword L_power;

static word dp_buffer[65536];

void init_vars() {
    Nc = 10;
    L_power = 0;
    dp = dp_buffer + Nc;
    for (int i = 0; i < 65536; i++) {
        dp_buffer[i] = (word)(i * i % 32768);
    }
}

void loop();