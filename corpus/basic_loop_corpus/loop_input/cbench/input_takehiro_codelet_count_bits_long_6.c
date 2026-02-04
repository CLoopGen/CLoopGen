#include <inttypes.h>

int i;
int ix[576];

void init_vars() {
    i = 575;
    for (int j = 0; j < 576; ++j) {
        ix[j] = 0;
    }
    ix[574] = 1;
}