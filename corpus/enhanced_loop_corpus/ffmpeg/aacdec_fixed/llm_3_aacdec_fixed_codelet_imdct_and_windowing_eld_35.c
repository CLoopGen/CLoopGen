#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT *out;
extern INTFLOAT *saved;
extern INTFLOAT *buf;
extern int i;
extern  int n;
extern  int n2;
extern  int n4;
extern  INTFLOAT * window;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int *indices = (int*)alloca(n2 * sizeof(int));
for (int j = 0; j < n2; j++) {
    indices[j] = j;
}

for (int j = 0; j < n2; j++) {
    int i = indices[j]; // Indirect access via index array
    int base_out = n4 + i;
    int base_win_1 = i + n2 - n4;
    int base_win_2 = i + n2 + n - n4;
    int base_win_3 = i + n2 + 2 * n - n4;
    int base_win_4 = i + n2 + 3 * n - n4;
    int rev_saved_1 = n - 1 - i;
    int rev_saved_2 = n + i;
    int rev_saved_3 = 3 * n - 1 - i;

    out[base_out] = (int)(((int64_t)(buf[i]) * window[base_win_1] + 1073741824) >> 31) +
                    (int)(((int64_t)(-saved[rev_saved_1]) * window[base_win_2] + 1073741824) >> 31) +
                    (int)(((int64_t)(-saved[rev_saved_2]) * window[base_win_3] + 1073741824) >> 31) +
                    (int)(((int64_t)(saved[rev_saved_3]) * window[base_win_4] + 1073741824) >> 31);
}
}
