#include <inttypes.h>

long den[4];
int i;
int den_hi_sig;

void init_vars() {
    // Initialize the den array with all zeros except the first element
    // This ensures the loop will iterate from 3 down to 0 and break at 0
    den[0] = 1;
    den[1] = 0;
    den[2] = 0;
    den[3] = 0;
    
    // Ensure loop starts correctly: i is initialized to 3 in loop (4-1)
    // No need to initialize i here since it's assigned in loop
    // den_hi_sig will be set by the loop
}