#include <stdio.h>
#include <inttypes.h>

typedef short word;

static word LARpp_j_array[10];
static word LARp_array[10];
word *LARpp_j = LARp_array;
word *LARp = LARp_array;
int i;

void init_vars() {
    for (int j = 0; j < 10; j++) {
        LARpp_j_array[j] = (word)(j + 1);
        LARp_array[j] = 0;
    }
    i = 1;
    LARp = &LARp_array[0];
    LARpp_j = &LARpp_j_array[0];
}