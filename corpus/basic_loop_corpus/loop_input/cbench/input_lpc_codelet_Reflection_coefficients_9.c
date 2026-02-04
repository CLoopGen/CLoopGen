#include <stdio.h>
#include <inttypes.h>

typedef long longword;
typedef short word;

longword *L_ACF;
int i;
word temp;
word ACF[9];

static longword L_ACF_data[9];

void init_vars() {
    temp = 8; 
    for (int j = 0; j < 9; j++) {
        L_ACF_data[j] = (longword)(j + 1) * 1000000LL;
    }
    L_ACF = L_ACF_data;
}