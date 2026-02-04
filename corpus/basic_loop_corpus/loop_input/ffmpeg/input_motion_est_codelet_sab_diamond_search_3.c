#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Minima {
    int height;
    int x;
    int y;
    int checked;
} Minima;

Minima minima[64];
int minima_count = 64;
int j = 0;

void init_vars() {
    for (int i = 0; i < minima_count; i++) {
        minima[i].height = 0;
        minima[i].x = 0;
        minima[i].y = 0;
        minima[i].checked = 0;
    }
    j = 0;
}