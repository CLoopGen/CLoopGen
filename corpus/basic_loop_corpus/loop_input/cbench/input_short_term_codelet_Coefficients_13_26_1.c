#include <stdio.h>
#include <inttypes.h>

typedef short word;
typedef long longword;
typedef unsigned long ulongword;

static word LARpp_j_1_data[10];
static word LARpp_j_data[10];
static word LARp_data[10];

word *LARpp_j_1 = LARpp_j_1_data;
word *LARpp_j = LARpp_j_data;
word *LARp = LARp_data;
int i;
longword ltmp;

void init_vars() {
    for (int idx = 0; idx < 10; idx++) {
        LARpp_j_1_data[idx] = (word)(idx * 1000);
        LARpp_j_data[idx] = (word)(idx * 1500);
        LARp_data[idx] = 0;
    }
    i = 1;
    ltmp = 0;
}