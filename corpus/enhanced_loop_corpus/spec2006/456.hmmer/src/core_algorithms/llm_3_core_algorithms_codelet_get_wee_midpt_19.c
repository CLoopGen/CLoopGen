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
int *fwd_m_row = fwd->mmx[cur];
int *bck_m_row = bck->mmx[cur];
int *fwd_i_row = fwd->imx[cur];
int *bck_i_row = bck->imx[cur];
for (k = k1; k <= k3; k++) {
    int sc_m = fwd_m_row[k] + bck_m_row[k];
    int sc_i = fwd_i_row[k] + bck_i_row[k];
    if (sc_m > max) {
        k2 = k;
        t2 = 1;
        max = sc_m;
    }
    if (sc_i > max) {
        k2 = k;
        t2 = 3;
        max = sc_i;
    }
}
}
