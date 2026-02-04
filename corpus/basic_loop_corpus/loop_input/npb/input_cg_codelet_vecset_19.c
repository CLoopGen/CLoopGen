#include <stdio.h>

typedef int boolean;

double v[131072];
int iv[131072];
int nzv_storage = 131072;
int *nzv = &nzv_storage;
int i = 65536;
double val = 3.14159;
int k;
boolean set;

void init_vars() {
    for (int idx = 0; idx < 131072; idx++) {
        v[idx] = 0.0;
        iv[idx] = idx + 1;
    }
    i = 65536;
    val = 3.14159;
    set = 0;
}