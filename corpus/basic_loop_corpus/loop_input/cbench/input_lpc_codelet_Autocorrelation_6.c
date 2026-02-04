#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

typedef long longword;
typedef short word;

static longword L_ACF_storage[9];
longword *L_ACF = L_ACF_storage;

int i;

static word sp_storage[168]; // sp needs to access up to index 159 and go back 8, so we need at least 168 elements (0..167)
word *sp = sp_storage + 8;   // pre-increment in loop uses ++sp, so initial sp must allow sp[-8] to be valid

word sl;

void init_vars() {
    // Initialize L_ACF array to zero
    for (int j = 0; j < 9; j++) {
        L_ACF_storage[j] = 0LL;
    }

    // Seed random number generator for realistic data
    srand(time(NULL));

    // Initialize sp array with sample data
    for (int j = 0; j < 168; j++) {
        sp_storage[j] = (word)(rand() % 65536 - 32768); // Random signed short values
    }

    // Initialize loop control variable
    i = 8;

    // Initialize sl
    sl = 0;
}