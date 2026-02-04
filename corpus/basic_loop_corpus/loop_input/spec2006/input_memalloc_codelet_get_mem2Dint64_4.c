#include <stdlib.h>
#include <stdint.h>

typedef int64_t int64;

static int64 **_array2D;
int64 ***array2D;
int rows = 100000;
int columns = 100;
int i;

void init_vars() {
    _array2D = (int64 **)calloc(rows, sizeof(int64 *));
    if (!_array2D) exit(1);

    for (int r = 0; r < rows; r++) {
        _array2D[r] = (int64 *)calloc(columns, sizeof(int64));
        if (!_array2D[r]) exit(1);
    }

    array2D = &_array2D;
}