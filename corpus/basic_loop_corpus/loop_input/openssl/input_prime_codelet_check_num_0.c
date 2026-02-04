#include <inttypes.h>

char *s;
int i;

static char data[1024 * 128]; // 128KB buffer

void init_vars() {
    // Initialize the data array with hexadecimal characters to ensure long loop execution
    for (int j = 0; j < sizeof(data) - 1; j++) {
        int val = j % 22; // Cycle through 0-9, A-F, a-f and some terminating non-hex chars at boundaries
        if (val < 10) {
            data[j] = '0' + val;
        } else if (val < 16) {
            data[j] = 'A' + (val - 10);
        } else if (val < 22) {
            data[j] = 'a' + (val - 16);
        } else {
            data[j] = 'X'; // Ensure most are valid hex
        }
    }
    // Null terminate just in case, though not strictly needed
    data[sizeof(data) - 1] = '\0';

    // Point s to the data array
    s = data;

    // Initialize loop index
    i = 0;
}