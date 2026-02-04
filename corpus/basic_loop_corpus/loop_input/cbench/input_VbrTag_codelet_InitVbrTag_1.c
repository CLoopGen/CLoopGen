#include <inttypes.h>

long g_Position[100];
int i;

void init_vars() {
    for (int j = 0; j < 100; j++) {
        g_Position[j] = 0;
    }
    i = 0;
}