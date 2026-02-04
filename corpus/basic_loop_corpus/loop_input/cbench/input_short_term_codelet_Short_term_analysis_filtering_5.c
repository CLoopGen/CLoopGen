#include <stdio.h>
#include <inttypes.h>

typedef short word;
typedef long longword;
typedef unsigned long ulongword;

word *rp;
int k_n;
word *s;
word *u;
int i;
word di;
word zzz;
word ui;
word sav;
word rpi;
longword ltmp;

#define DATA_SIZE (1 << 20)  // Approximately 1MB of data

static word rp_data[8];
static word s_data[DATA_SIZE];
static word u_data[8];

void init_vars() {
    rp = rp_data;
    s = s_data;
    u = u_data;
    k_n = DATA_SIZE;

    for (int idx = 0; idx < 8; idx++) {
        rp[idx] = (word)(idx * 3);
        u[idx] = (word)(idx * 5 + 1);
    }

    for (int idx = 0; idx < DATA_SIZE; idx++) {
        s[idx] = (word)(idx % 32767);
    }

    di = 0;
    zzz = 0;
    ui = 0;
    sav = 0;
    rpi = 0;
    ltmp = 0;
    i = 0;
}