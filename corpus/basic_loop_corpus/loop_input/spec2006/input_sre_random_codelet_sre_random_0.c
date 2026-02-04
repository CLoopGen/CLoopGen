#include <stdio.h>
#include <inttypes.h>

long rnd1 = 123456789;
long rnd2 = 987654321;
long tbl[64];
long x;
long y;
int i;
long a1 = 48271;
long m1 = 2147483647;
long q1 = 44488;
long r1 = 3399;
long a2 = 40692;
long m2 = 2147483399;
long q2 = 52774;
long r2 = 3791;

void init_vars() {
    rnd1 = 123456789;
    rnd2 = 987654321;
    x = 0;
    y = 0;
    i = 0;
}