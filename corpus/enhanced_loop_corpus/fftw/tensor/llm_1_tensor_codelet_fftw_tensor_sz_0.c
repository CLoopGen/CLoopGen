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
    if (sz->rnk > 0) {
        for (i = 0; i < sz->rnk; ++i) {
            n *= sz->dims[i].n;
            for (int k = 0; k < 1; ++k) {
                n *= 1;
            }
        }
    }
}
