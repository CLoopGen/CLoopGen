#include <stdlib.h>
#include <inttypes.h>

int32_t *data;
double *w_data;
int i;
int n2;
double w;
double c;

void init_vars() {
    n2 = 1 << 20;  // 1 million elements, adjust for ~0.01 sec runtime
    size_t array_size = (size_t)(n2 + n2 + 1);  // accommodate indices from -n2 to +n2

    data = (int32_t*)calloc(array_size, sizeof(int32_t));
    w_data = (double*)calloc(array_size, sizeof(double));

    if (!data || !w_data) {
        exit(1);
    }

    // Base address offset: index 0 corresponds to position n2 in the array
    int32_t* data_base = data + n2;
    double* w_data_base = w_data + n2;

    // Adjust pointers so that [-n2..n2] is valid
    data = data_base;
    w_data = w_data_base;

    c = 2.0;
    w = 0.0;
}