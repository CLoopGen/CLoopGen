#include <stdlib.h>
#include <time.h>

double c[1 << 20]; // 8MB array of doubles (2^20 elements)
int len;
double x;
int i;
double ans;

void init_vars() {
    len = 1 << 20; // Set length to 1M elements
    x = 1.5;       // Arbitrary value for x
    ans = 0.0;     // Initial value for ans

    // Initialize array c with random values
    srand(time(NULL));
    for (int j = 0; j < len; j++) {
        c[j] = (double)rand() / RAND_MAX;
    }
}