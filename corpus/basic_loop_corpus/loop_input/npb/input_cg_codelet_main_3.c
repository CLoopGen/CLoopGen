#include <stdio.h>

int firstcol = 1;
int lastcol = 10000;
double z[14003];
double p[14003];
double q[14003];
double r[14003];
int j;

void init_vars() {
    for (int i = 0; i < 14003; i++) {
        z[i] = 0.0;
        p[i] = 0.0;
        q[i] = 0.0;
        r[i] = 0.0;
    }
}