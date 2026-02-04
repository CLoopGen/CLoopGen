#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *Rp;
extern R *Ip;
extern R *Rm;
extern R *Im;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP951056516;
extern  E KP587785252;
extern  E KP250000000;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb; m < me; m += 1) {
    E sum_real = 0.0, sum_imag = 0.0;
    INT idx;
    for (idx = 0; idx < 5; idx++) {
        E wr = W[idx * 2], wi = W[idx * 2 + 1];
        E rp_val = Rp[idx * rs[0]];
        E ip_val = Ip[idx * rs[0]];
        E rm_val = Rm[(4 - idx) * rs[0]];
        E im_val = Im[(4 - idx) * rs[0]];

        sum_real += wr * (rp_val + rm_val) - wi * (ip_val - im_val);
        sum_imag += wi * (rp_val + rm_val) + wr * (ip_val - im_val);
    }

    E temp_Rp = Rp[0];
    E temp_Im = Im[0];

    Rp[0] = sum_real;
    Ip[0] = sum_imag;
    Rm[0] = temp_Rp;
    Im[0] = temp_Im;

    Rp = Rp + ms;
    Ip = Ip + ms;
    Rm = Rm - ms;
    Im = Im - ms;
    W = W + 18;
}
}
