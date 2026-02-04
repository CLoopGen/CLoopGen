#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char Intersection;

Intersection shadow[400];
char active[400];
int k;

void init_vars() {
    for (int i = 0; i < 400; i++) {
        shadow[i] = (Intersection)(i & 0xFF);
        active[i] = 0;
    }
    k = 0;
}