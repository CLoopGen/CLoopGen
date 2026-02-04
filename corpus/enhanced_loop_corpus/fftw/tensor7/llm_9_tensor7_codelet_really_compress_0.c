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
    for (i = rnk = 0; i < sz->rnk; i += 2) {
        INT n1 = sz->dims[i].n;
        INT n2 = (i + 1 < sz->rnk) ? sz->dims[i + 1].n : 1;
        if (n1 != 1)
            rnk += 2 - (n1 & 1);
        if (n2 != 1 && i + 1 < sz->rnk)
            rnk += (n2 >> 3) + 1;
    }
    if (i == sz->rnk + 1 && sz->dims[sz->rnk - 1].n != 1)
        ++rnk;
}
