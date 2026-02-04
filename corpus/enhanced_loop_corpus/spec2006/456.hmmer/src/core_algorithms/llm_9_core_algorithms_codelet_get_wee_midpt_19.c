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


extern int k1;
extern int k3;
extern struct dpmatrix_s *fwd;
extern struct dpmatrix_s *bck;
extern int k2;
extern char t2;
extern int cur;
extern int k;
extern int sc;
extern int max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step;
    for (k = k1, step = 0; k <= k3 && step < 16; k++, step++) {
        int mmx_val = fwd->mmx[cur][k];
        int bck_mmx_val = bck->mmx[cur][k];
        int imx_val = fwd->imx[cur][k];
        int bck_imx_val = bck->imx[cur][k];

        sc = mmx_val + bck_mmx_val;
        if (sc > max) {
            max = sc;
            k2 = k;
            t2 = 1;
        }

        sc = imx_val + bck_imx_val;
        if (sc > max) {
            max = sc;
            k2 = k;
            t2 = 3;
        }
    }
}
