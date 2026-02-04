#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int shift = 1000000;
int seg = 5;
int seg2 = 3;
int t;
int val = 100;
int val_add = 64;
int x = 2000;

void init_vars() {
    // No dynamic data or arrays requiring malloc/init, all scalars already initialized at file scope
}