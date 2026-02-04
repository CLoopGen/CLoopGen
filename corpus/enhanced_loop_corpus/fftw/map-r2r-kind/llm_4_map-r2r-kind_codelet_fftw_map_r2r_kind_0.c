#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
enum fftw_r2r_kind_do_not_use_me {
    FFTW_R2HC = 0,
    FFTW_HC2R = 1,
    FFTW_DHT = 2,
    FFTW_REDFT00 = 3,
    FFTW_REDFT01 = 4,
    FFTW_REDFT10 = 5,
    FFTW_REDFT11 = 6,
    FFTW_RODFT00 = 7,
    FFTW_RODFT01 = 8,
    FFTW_RODFT10 = 9,
    FFTW_RODFT11 = 10
};


typedef enum fftw_r2r_kind_do_not_use_me fftw_r2r_kind;

typedef enum {
    R2HC00,
    R2HC01,
    R2HC10,
    R2HC11,
    HC2R00,
    HC2R01,
    HC2R10,
    HC2R11,
    DHT,
    REDFT00,
    REDFT01,
    REDFT10,
    REDFT11,
    RODFT00,
    RODFT01,
    RODFT10,
    RODFT11
} rdft_kind;

extern int rank;
extern  fftw_r2r_kind *kind;
extern int i;
extern rdft_kind *k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < rank; ++i) {
    rdft_kind m;
    if (kind[i] >= FFTW_R2HC && kind[i] <= FFTW_RODFT11) {
        m = (rdft_kind)(kind[i] == FFTW_R2HC ? R2HC00 :
                        kind[i] == FFTW_HC2R ? HC2R00 :
                        kind[i] == FFTW_DHT ? DHT :
                        kind[i] == FFTW_REDFT00 ? REDFT00 :
                        kind[i] == FFTW_REDFT01 ? REDFT01 :
                        kind[i] == FFTW_REDFT10 ? REDFT10 :
                        kind[i] == FFTW_REDFT11 ? REDFT11 :
                        kind[i] == FFTW_RODFT00 ? RODFT00 :
                        kind[i] == FFTW_RODFT01 ? RODFT01 :
                        kind[i] == FFTW_RODFT10 ? RODFT10 : RODFT11);
    } else {
        m = R2HC00;
    }
    k[i] = m;
}
}
