#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *in;
unsigned char *out;
unsigned char ivec[16];
int n;
int num;
unsigned char ovec[33];

void init_vars() {
    num = 1024 * 128; // 128KB of data to ensure ~0.01s runtime on modern CPU

    in = (unsigned char *)malloc(num);
    out = (unsigned char *)malloc(num);

    if (!in || !out) {
        // Avoid crashing, but ensure valid pointers even if malloc fails
        static unsigned char fallback_in[128 * 1024];
        static unsigned char fallback_out[128 * 1024];
        in = fallback_in;
        out = fallback_out;
    }

    // Initialize ivec with non-zero values for realistic xor behavior
    for (int i = 0; i < 16; ++i) {
        ivec[i] = (unsigned char)(i + 1);
    }

    // Initialize ovec (only up to 33 bytes as declared)
    for (int i = 0; i < 33; ++i) {
        ovec[i] = 0;
    }

    // Initialize input data
    for (int i = 0; i < num; ++i) {
        in[i] = (unsigned char)(i & 0xFF);
    }

    // Ensure that the loop uses safe bounds: n from 0 to num-1, and num <= 17 because ovec[16+n] must be valid
    // But ovec is only 33 bytes, so 16 + n < 33 => n < 17 => num <= 17
    // Therefore we must limit num to 17 to prevent out-of-bounds access in ovec
    num = 17;

    // Re-initialize in and out to match the corrected num
    if (in != (unsigned char*)(&((unsigned char*)0)[1])) { // avoid free on static fallback
        free(in);
        free(out);
    }

    in = (unsigned char *)malloc(num);
    out = (unsigned char *)malloc(num);

    if (!in || !out) {
        static unsigned char small_in[17];
        static unsigned char small_out[17];
        in = small_in;
        out = small_out;
    }

    for (int i = 0; i < num; ++i) {
        in[i] = (unsigned char)(i & 0xFF);
        out[i] = 0;
    }

    for (int i = 0; i < 16; ++i) {
        ivec[i] = (unsigned char)(i + 1);
    }
    for (int i = 0; i < 33; ++i) {
        ovec[i] = 0;
    }
}