#include <stdio.h>
#include <inttypes.h>

typedef short word;
typedef long longword;
typedef unsigned long ulongword;

word *rrp;
word *v;
int i;
word sri;
word tmp1;
word tmp2;
longword ltmp;

static word rrp_data[8];
static word v_data[9];

void init_vars() {
    rrp = rrp_data;
    v = v_data;
    for (int j = 0; j < 8; ++j) {
        rrp[j] = (word)(j * 1000);
        v[j] = (word)(j * 500);
    }
    v[8] = 0;
    sri = 32767;
    tmp1 = 0;
    tmp2 = 0;
    ltmp = 0;
}