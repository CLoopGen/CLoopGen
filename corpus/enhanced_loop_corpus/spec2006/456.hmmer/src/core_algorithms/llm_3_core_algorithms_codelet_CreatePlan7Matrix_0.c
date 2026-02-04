#include <stdio.h>

#include <inttypes.h>

struct dpmatrix_s {
    int **xmx;
    int **mmx;
    int **imx;
    int **dmx;
    void *xmx_mem;
    void *mmx_mem;
    void *imx_mem;
    void *dmx_mem;
    int maxN;
    int maxM;
    int padN;
    int padM;
};


extern int N;
extern int M;
extern struct dpmatrix_s *mx;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed iteration and indirect indexing via temporary array
    int **xmx_ptr = mx->xmx;
    int **mmx_ptr = mx->mmx;
    int **imx_ptr = mx->imx;
    int **dmx_ptr = mx->dmx;
    int *xmx0 = mx->xmx[0];
    int *mmx0 = mx->mmx[0];
    int *imx0 = mx->imx[0];
    int *dmx0 = mx->dmx[0];
    int stride = M + 2;
    int x_stride = 5;

    // Reverse loop to alter access pattern (still valid and deterministic)
    for (i = N; i >= 1; i--) {
        int idx = i;  // Use index indirectly (could be extended for more complex indirection)
        xmx_ptr[idx] = xmx0 + (idx * x_stride);
        mmx_ptr[idx] = mmx0 + (idx * stride);
        imx_ptr[idx] = imx0 + (idx * stride);
        dmx_ptr[idx] = dmx0 + (idx * stride);
    }
}
