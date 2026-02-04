#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double R;
typedef R E;
typedef ptrdiff_t INT;
typedef INT *stride;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

// Data size: aim for ~128MB of complex data (64MB real + 64MB imag)
// Each array has 16M elements (assuming typical use), so 16M * sizeof(double) = 128MB per array
#define N (1<<24)  // 16,777,216 elements

static R *R0_storage = NULL;
static R *R1_storage = NULL;
static R *Cr_storage = NULL;
static R *Ci_storage = NULL;

R *R0 = NULL;
R *R1 = NULL;
R *Cr = NULL;
R *Ci = NULL;

static stride rs_storage = NULL;
static stride csr_storage = NULL;
static stride csi_storage = NULL;

stride rs = NULL;
stride csr = NULL;
stride csi = NULL;

INT v = 1;
INT ivs = 1;
INT ovs = 1;

E KP1_028205488 = 1.028205488;
E KP1_715457220 = 1.715457220;
E KP1_606415062 = 1.606415062;
E KP1_191398608 = 1.191398608;
E KP1_940062506 = 1.940062506;
E KP485960359 = 0.485960359;
E KP293460948 = 0.293460948;
E KP1_978353019 = 1.978353019;
E KP831469612 = 0.831469612;
E KP555570233 = 0.555570233;
E KP855110186 = 0.855110186;
E KP1_807978586 = 1.807978586;
E KP1_481902250 = 1.481902250;
E KP1_343117909 = 1.343117909;
E KP1_883088130 = 1.883088130;
E KP673779706 = 0.673779706;
E KP098135348 = 0.098135348;
E KP1_997590912 = 1.997590912;
E KP980785280 = 0.980785280;
E KP195090322 = 0.195090322;
E KP580569354 = 0.580569354;
E KP1_913880671 = 1.913880671;
E KP942793473 = 0.942793473;
E KP1_763842528 = 1.763842528;
E KP1_111140466 = 1.111140466;
E KP1_662939224 = 1.662939224;
E KP1_268786568 = 1.268786568;
E KP1_546020906 = 1.546020906;
E KP196034280 = 0.196034280;
E KP1_990369453 = 1.990369453;
E KP390180644 = 0.390180644;
E KP1_961570560 = 1.961570560;
E KP382683432 = 0.382683432;
E KP923879532 = 0.923879532;
E KP707106781 = 0.707106781;
E KP765366864 = 0.765366864;
E KP1_847759065 = 1.847759065;
E KP1_414213562 = 1.414213562;
E KP2_000000000 = 2.000000000;

INT i = 0;

void init_vars() {
    // Allocate storage
    R0_storage = (R*)aligned_alloc(64, N * sizeof(R));
    R1_storage = (R*)aligned_alloc(64, N * sizeof(R));
    Cr_storage = (R*)aligned_alloc(64, N * sizeof(R));
    Ci_storage = (R*)aligned_alloc(64, N * sizeof(R));

    rs_storage = (stride)aligned_alloc(64, 65 * sizeof(INT));
    csr_storage = (stride)aligned_alloc(64, 65 * sizeof(INT));
    csi_storage = (stride)aligned_alloc(64, 65 * sizeof(INT));

    // Initialize pointers
    R0 = R0_storage;
    R1 = R1_storage;
    Cr = Cr_storage;
    Ci = Ci_storage;
    rs = rs_storage;
    csr = csr_storage;
    csi = csi_storage;

    // Initialize strides: assume unit stride for most, but set some pattern
    for (int idx = 0; idx < 65; idx++) {
        rs[idx] = idx;
        csr[idx] = idx;
        csi[idx] = idx;
    }

    // Set loop count v to a value that ensures memory safety
    // The maximum index used is 64, and we need at least 65 elements
    // We'll run the loop once per "frame" of data
    v = 100000;  // Adjust this to tune runtime (~0.01 sec target)

    // Initialize data arrays with non-zero values to avoid degenerate math
    for (INT j = 0; j < N; j++) {
        Cr[j] = sin(j * 0.0001);
        Ci[j] = cos(j * 0.0001);
        R0[j] = 0.0;
        R1[j] = 0.0;
    }
}