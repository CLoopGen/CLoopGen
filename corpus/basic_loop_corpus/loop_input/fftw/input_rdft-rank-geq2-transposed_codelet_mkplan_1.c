#include <stddef.h>
#include <stdint.h>

typedef ptrdiff_t INT;

typedef struct {
    INT n;
    INT is;
    INT os;
} iodim;

typedef struct {
    int rnk;
    iodim dims[1];
} tensor;

static iodim dim_data[8];
static tensor sz_storage = { .rnk = 8, .dims = { {0} } };
tensor *sz = &sz_storage;
int i;
INT nrest;

void init_vars() {
    sz = &sz_storage;
    sz->rnk = 8;
    for (int j = 0; j < 8; ++j) {
        dim_data[j].n = 4;
        dim_data[j].is = 1;
        dim_data[j].os = 1 << j;
    }
    // Copy dimensions into sz->dims (we use flexible array member, so overlay)
    __builtin_memcpy(sz->dims, dim_data, sizeof(dim_data));
    
    i = 1;
    nrest = 1;
}