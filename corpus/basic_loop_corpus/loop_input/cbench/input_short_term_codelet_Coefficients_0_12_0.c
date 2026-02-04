#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef short word;
typedef long longword;
typedef unsigned long ulongword;

static word *LARpp_j_1_data;
static word *LARpp_j_data;
static word *LARp_data;

word *LARpp_j_1;
word *LARpp_j;
word *LARp;

int i;
longword ltmp;

void init_vars() {
    size_t data_size = 256 * 1024 * sizeof(word); // ~512KB total for three arrays (aiming for 0.01s runtime)
    size_t num_elements = data_size / sizeof(word);

    LARpp_j_1_data = (word*)calloc(num_elements, sizeof(word));
    LARpp_j_data = (word*)calloc(num_elements, sizeof(word));
    LARp_data = (word*)calloc(num_elements, sizeof(word));

    for (size_t idx = 0; idx < num_elements; idx++) {
        LARpp_j_1_data[idx] = (word)(idx % 32767);
        LARpp_j_data[idx] = (word)((idx * 3) % 32767);
        LARp_data[idx] = 0;
    }

    LARpp_j_1 = LARpp_j_1_data;
    LARpp_j = LARpp_j_data;
    LARp = LARp_data;

    i = 1;
    ltmp = 0;
}