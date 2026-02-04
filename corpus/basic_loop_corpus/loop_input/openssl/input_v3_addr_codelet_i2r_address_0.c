#include <inttypes.h>

unsigned char addr[1024 * 128]; // 128KB of data
int n;

void init_vars() {
    // Initialize the array with zeros except for a non-zero sentinel value near the beginning
    // to prevent the loop from underflowing and ensure it terminates safely.
    for (int i = 0; i < sizeof(addr); i++) {
        addr[i] = 0;
    }
    // Place a non-zero value at index 1 to break the condition when n becomes 2
    // so that when n=2, addr[1]==non-zero, preventing further iteration and underflow
    addr[1] = 1;

    // Initialize n to the size of the data, but capped at maximum safe initial value
    // Since loop uses addr[n-1] and addr[n-2], n must be <= sizeof(addr)
    n = sizeof(addr) > 16 ? sizeof(addr) : 16;
}