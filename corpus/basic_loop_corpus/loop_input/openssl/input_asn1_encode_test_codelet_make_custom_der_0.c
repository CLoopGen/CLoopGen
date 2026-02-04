#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *bytes1;
    size_t nbytes1;
    unsigned char *bytes2;
    size_t nbytes2;
} TEST_CUSTOM_DATA;

static unsigned char *g_bytes2;
TEST_CUSTOM_DATA *custom_data;
size_t i;

void init_vars() {
    size_t data_size = 512 * 1024; // 512 KB to target ~0.01 sec runtime

    g_bytes2 = (unsigned char *)malloc(data_size);
    if (!g_bytes2) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    memset(g_bytes2, 0, data_size);

    g_bytes2[data_size - 1] = 1;

    custom_data = (TEST_CUSTOM_DATA *)malloc(sizeof(TEST_CUSTOM_DATA));
    if (!custom_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    custom_data->bytes1 = NULL;
    custom_data->nbytes1 = 0;
    custom_data->bytes2 = g_bytes2;
    custom_data->nbytes2 = data_size;
}