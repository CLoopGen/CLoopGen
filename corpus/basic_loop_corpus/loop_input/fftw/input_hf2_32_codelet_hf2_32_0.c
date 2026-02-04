#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef double E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

R *cr;
R *ci;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP555570233;
E KP831469612;
E KP980785280;
E KP195090322;
E KP382683432;
E KP923879532;
E KP707106781;
INT m;

#define DATA_SIZE (1 << 20)

void init_vars() {
    KP555570233 = 0.55557023301959989;
    KP831469612 = 0.83146961230254524;
    KP980785280 = 0.98078528040323043;
    KP195090322 = 0.19509032201612825;
    KP382683432 = 0.38268343236508978;
    KP923879532 = 0.92387953251128674;
    KP707106781 = 0.70710678118654757;

    rs = malloc(32 * sizeof(INT));
    for (int i = 0; i < 32; i++) {
        rs[i] = i;
    }

    cr = calloc(DATA_SIZE, sizeof(R));
    ci = calloc(DATA_SIZE, sizeof(R));
    W = malloc(8 * DATA_SIZE * sizeof(R));

    for (INT i = 0; i < 8 * DATA_SIZE; i++) {
        W[i] = sin(i * 0.01);
    }

    mb = 1;
    me = DATA_SIZE - 1;
    ms = 1;

    m = mb;
}