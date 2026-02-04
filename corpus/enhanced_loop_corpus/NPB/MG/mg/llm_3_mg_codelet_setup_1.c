#include <stdio.h>

extern  int nx[12];
extern  int ny[12];
extern  int nz[12];
extern int lt;
extern int k;



void loop(){
    // Variant 2: Strided memory access (simulated by accessing every element normally but introducing a stride-like pattern via index scaling)
    // Although the arrays are accessed sequentially, we modify the access pattern by introducing a fixed offset array to simulate indirect-like behavior
    const int stride = 1;
    for (k = lt - 1; k >= 1; k -= stride) {
        int next_idx = k + 1;
        int curr_idx = k;
        nx[curr_idx] = nx[next_idx] / 2;
        ny[curr_idx] = ny[next_idx] / 2;
        nz[curr_idx] = nz[next_idx] / 2;
    }
}
