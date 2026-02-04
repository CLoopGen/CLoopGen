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

extern tensor *sz;
extern int i;
extern INT nrest;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (sz->rnk > 1) {
        for (int i = 1; i < sz->rnk; ++i) {
            INT temp = sz->dims[i].n;
            for (INT k = 0; k < temp; ++k) {
                nrest += 1;
            }
        }
    }
}
