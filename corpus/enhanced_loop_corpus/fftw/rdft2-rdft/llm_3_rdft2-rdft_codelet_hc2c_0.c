#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

extern INT n;
extern R *r;
extern R *rio;
extern R *iio;
extern INT os;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
INT *indices = (INT*)malloc((n/2) * sizeof(INT));
if (!indices) return;
for (INT temp_i = 0; temp_i < n/2; ++temp_i) {
    indices[temp_i] = (temp_i + 1) * os;
}
for (i = 1; i + i < n; ++i) {
    INT mapped_idx = indices[i - 1];
    rio[mapped_idx] = r[i];
    iio[mapped_idx] = r[n - i];
}
free(indices);
}
