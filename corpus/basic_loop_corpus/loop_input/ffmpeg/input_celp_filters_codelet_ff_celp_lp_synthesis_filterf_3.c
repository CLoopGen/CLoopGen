#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *out;
float *filter_coeffs;
float *in;
int buffer_length;
int filter_length;
int i;
int n;
float out0;
float out1;
float out2;
float out3;
float old_out0;
float old_out1;
float old_out2;
float old_out3;
float a;
float b;
float c;

void init_vars() {
    // Define data sizes to achieve ~0.01 seconds runtime
    // Based on typical CPU performance and loop complexity, aim for ~16-32 million operations
    buffer_length = 1048576; // 1MB of floats (4-byte): 1M / 4 = 262144 elements -> use 1<<18
    filter_length = 65;      // Moderate FIR/IIR filter length

    // Allocate aligned memory to prevent issues and allow optimization
    in = aligned_alloc(32, sizeof(float) * buffer_length);
    out = aligned_alloc(32, sizeof(float) * buffer_length);
    filter_coeffs = aligned_alloc(32, sizeof(float) * filter_length);

    // Initialize filter coefficients: use decaying random-like values
    a = 0.1f;
    b = 0.05f;
    c = 0.025f;

    for (int j = 0; j < filter_length; ++j) {
        filter_coeffs[j] = (float)(0.1 * ((j + 1) % 7) / 7.0);
    }

    // Initialize input with non-zero data
    for (int j = 0; j < buffer_length; ++j) {
        in[j] = (float)((j % 100) - 50) / 100.0f;
    }

    // Initialize state variables
    old_out0 = 0.0f;
    old_out1 = 0.0f;
    old_out2 = 0.0f;
    old_out3 = 0.0f;

    // Ensure the loop runs only where memory accesses are valid
    // The inner loop uses out[-i], so we must have at least (filter_length) padding before current out
    // Shift 'out' pointer forward by filter_length to allow negative indexing
    float *original_out = out;
    out += filter_length;

    // Similarly, ensure input is long enough to cover buffer_length + padding if needed
    // But since we only read in[0..3], just make sure buffer_length is multiple of 4 and in bounds

    // Adjust buffer_length to be multiple of 4 and leave room for safe output access
    buffer_length -= (buffer_length % 4);
    buffer_length -= filter_length; // reserve space for filter delay line

    // Final safeguard
    if (buffer_length <= 0) {
        buffer_length = 4;
    }
}