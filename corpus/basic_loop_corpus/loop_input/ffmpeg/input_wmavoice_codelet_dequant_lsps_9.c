#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *lsps;
int num = 1024;
uint16_t *values;
uint16_t *sizes;
int n_stages = 50;
uint8_t *table;
double *mul_q;
double *base_q;
int n;
int m;

void init_vars() {
    const size_t max_data_size = 64 * 1024 * 1024; // Aim for ~64 MB of data

    num = 1024;
    n_stages = max_data_size / (num * sizeof(uint8_t)) / 2; // Balance stages and table growth
    if (n_stages > 1000) n_stages = 1000;
    if (n_stages < 1) n_stages = 1;

    lsps = (double*)calloc(num, sizeof(double));
    values = (uint16_t*)malloc(n_stages * sizeof(uint16_t));
    sizes = (uint16_t*)malloc(n_stages * sizeof(uint16_t));
    mul_q = (double*)malloc(n_stages * sizeof(double));
    base_q = (double*)malloc(n_stages * sizeof(double));

    size_t total_table_size = 0;
    for (int i = 0; i < n_stages; i++) {
        values[i] = (i * 7919) % 128; // Prime mod to avoid zero clustering
        sizes[i] = (i * 97 + 1) % 256 + 1; // Ensure at least size 1
        mul_q[i] = 0.1 + (i * 0.03);
        base_q[i] = -5.0 + (i * 0.2);
        total_table_size += sizes[i] * num;
    }

    table = (uint8_t*)malloc(total_table_size * sizeof(uint8_t));
    for (size_t i = 0; i < total_table_size; i++) {
        table[i] = i % 256;
    }
}