#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

unsigned char cov_2char[64] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5'
};

static char *salt_storage;
static char **salt_p_ptr;

size_t saltlen;
size_t i;

void init_vars() {
    const size_t data_size = 512 * 1024; // ~512KB of data for ~0.01 sec runtime estimate

    saltlen = data_size;

    salt_storage = (char *)malloc(saltlen);
    if (!salt_storage) {
        exit(1);
    }

    salt_p_ptr = &salt_storage;

    for (size_t j = 0; j < saltlen; j++) {
        salt_storage[j] = (char)(j & 63); 
    }
}

unsigned char cov_2char[64];
char **salt_p = NULL;
size_t saltlen = 0;
size_t i = 0;

__attribute__((constructor))
static void constructor_init() {
    init_vars();
    salt_p = salt_p_ptr;
}