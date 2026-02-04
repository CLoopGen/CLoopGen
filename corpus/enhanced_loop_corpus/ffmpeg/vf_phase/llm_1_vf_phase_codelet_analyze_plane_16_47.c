#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint16_t *nptr;
extern  uint16_t *optr;
extern  int w;
extern int64_t bdif;
extern int64_t tdif;
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < w / 2; outer++) {
        for (int inner = 0; inner < 2; inner++) {
            int idx = outer * 2 + inner;
            uint16_t *nidx = nptr + idx;
            uint16_t *oidx = optr + idx;
            uint16_t *nrend = nptr + w;
            if (nidx >= nrend) break;
            int t_val;
            pdif += (t_val = ((*nidx - nidx[ns]) << 2) + nidx[(ns) << 1] - nidx[-ns], t_val * t_val);
            bdif += (t_val = ((*nidx - oidx[os]) << 2) + nidx[(ns) << 1] - oidx[-os], t_val * t_val);
            tdif += (t_val = ((*oidx - nidx[ns]) << 2) + oidx[(os) << 1] - nidx[-ns], t_val * t_val);
        }
    }
    // Handle odd w if needed, using a final single pass
    if (w % 2 == 1) {
        uint16_t *nidx = nptr + w - 1;
        uint16_t *oidx = optr + w - 1;
        int t_val;
        pdif += (t_val = ((*nidx - nidx[ns]) << 2) + nidx[(ns) << 1] - nidx[-ns], t_val * t_val);
        bdif += (t_val = ((*nidx - oidx[os]) << 2) + nidx[(ns) << 1] - oidx[-os], t_val * t_val);
        tdif += (t_val = ((*oidx - nidx[ns]) << 2) + oidx[(os) << 1] - nidx[-ns], t_val * t_val);
    }
}
