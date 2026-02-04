#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef char *OPENSSL_STRING;

int i;
OPENSSL_STRING row[6];
OPENSSL_STRING *irow;

static char **mock_data_pool;
static int data_block_size = 131072; // 128KB

void init_vars() {
    mock_data_pool = (char **)calloc(6, sizeof(char *));
    for (int idx = 0; idx < 6; idx++) {
        mock_data_pool[idx] = (char *)malloc(data_block_size);
        memset(mock_data_pool[idx], 'A' + idx, data_block_size);
        row[idx] = mock_data_pool[idx];
    }

    irow = (OPENSSL_STRING *)calloc(6, sizeof(OPENSSL_STRING));
}