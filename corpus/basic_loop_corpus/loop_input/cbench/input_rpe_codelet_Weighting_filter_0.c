#include <stdio.h>
#include <inttypes.h>

typedef short word;
typedef long longword;

word *e;
word *x;
longword L_result;
int k;

static word e_buffer[104];
static word x_buffer[40];

void init_vars() {
    e = e_buffer + 10;  // Offset to allow k+10 indexing starting from k=0
    x = x_buffer;
    for (int i = 0; i < 104; i++) {
        e_buffer[i] = (word)(i * 7 % 32767);
    }
    for (int i = 0; i < 40; i++) {
        x_buffer[i] = 0;
    }
    L_result = 0;
    k = 0;
}