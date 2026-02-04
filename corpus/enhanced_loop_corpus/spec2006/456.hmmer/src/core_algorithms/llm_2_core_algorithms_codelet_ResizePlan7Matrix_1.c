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


extern struct dpmatrix_s *mx;
extern int N;
extern int M;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using pointer arithmetic
    // Instead of calculating offsets based on row index, we make access consecutive by iterating directly over pointers
    int **x_base = mx->xmx;
    int **m_base = mx->mmx;
    int **i_base = mx->imx;
    int **d_base = mx->dmx;
    int *x_data = mx->xmx[0];
    int *m_data = mx->mmx[0];
    int *i_data = mx->imx[0];
    int *d_data = mx->dmx[0];
    const int m_plus_2 = M + 2;

    for (i = 1; i <= N; i++) {
        x_base[i] = x_data + (i * 5);
        m_base[i] = m_data + (i * m_plus_2);
        i_base[i] = i_data + (i * m_plus_2);
        d_base[i] = d_data + (i * m_plus_2);
    }
}
