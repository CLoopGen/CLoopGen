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
extern INT n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    n = 1;
    for (int i = sz->rnk - 1; i >= 0; --i) {
        n *= sz->dims[i].n;
        n += sz->dims[i].is;
        n -= sz->dims[i].os;
    }
}
