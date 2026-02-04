#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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

extern  tensor *sz;
extern int i;
extern int rnk;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = rnk = 0; i < sz->rnk; ++i) {
        INT n = sz->dims[i].n;
        for (INT j = 1; j < n && n != 1; j += 2) {
            rnk += (j * j + n) % 2;
        }
        if (n != 1)
            ++rnk;
    }
}
