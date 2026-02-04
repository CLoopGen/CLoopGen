#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int *x;
int *y;
int b;

static int x_storage;
static int y_storage;

void init_vars() {
    i = 0x12345678; 
    x = &x_storage;
    y = &y_storage;
    b = 0;
    *x = 0;
    *y = 0;
}