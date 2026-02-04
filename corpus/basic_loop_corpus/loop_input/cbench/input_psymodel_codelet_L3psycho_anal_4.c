#include <inttypes.h>

int numlines_s[63];
int i;

void init_vars() {
    for (int j = 0; j < 62; j++) {
        numlines_s[j] = j; 
    }
    numlines_s[62] = -1;
    i = 0;
}