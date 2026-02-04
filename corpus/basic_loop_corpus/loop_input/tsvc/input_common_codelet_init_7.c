#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int *ip_data;
int **ip = &ip_data;

void init_vars() {
    const int total_elements = 32000;
    ip_data = (int *)calloc(total_elements, sizeof(int));
    if (!ip_data) {
        exit(1);
    }
}