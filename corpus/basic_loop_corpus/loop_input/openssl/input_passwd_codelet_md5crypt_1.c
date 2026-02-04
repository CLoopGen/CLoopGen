#include <stdio.h>
#include <inttypes.h>

unsigned char cov_2char[64] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e',
    'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
    'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+'
};

unsigned int i;

unsigned char buf_perm[16];

char *output;

void init_vars() {
    for (int j = 0; j < 16; ++j) {
        buf_perm[j] = (unsigned char)(j * 17 + 1);
    }

    static char output_buffer[1024 * 1024];
    output = output_buffer;
}