#include <stdint.h>
#include <string.h>

long num[5] = {0};
long den[4] = {0};
long quo[4] = {0};
int i;
int j;
unsigned long work;
unsigned long carry;
int num_hi_sig;
int den_hi_sig;
unsigned long quo_est;

void init_vars() {
    // Set up denominator to be non-zero and valid for division
    den_hi_sig = 3;  // Use full 4 elements of den[0..3]
    
    // Ensure den[den_hi_sig] != 0 to avoid division by zero in loop
    den[3] = 0x10000000UL;  // High digit of denominator
    den[2] = 0x23456789UL;
    den[1] = 0xABCD1234UL;
    den[0] = 0xEF000001UL;

    // Set up numerator with sufficient size and significance
    num_hi_sig = 4;  // Use full 5 elements of num[0..4]

    num[4] = 0xABCDEF00UL;  // Must be >= den[3] to allow quotient estimation
    num[3] = 0x12345678UL;
    num[2] = 0x98765432UL;
    num[1] = 0xABCDEF12UL;
    num[0] = 0x3456789AUL;

    // Zero out quotient array
    for (int k = 0; k < 4; k++) {
        quo[k] = 0;
    }

    // Initialize remaining scalar variables to safe values
    i = 0;
    j = 0;
    work = 0;
    carry = 0;
    quo_est = 0;
}