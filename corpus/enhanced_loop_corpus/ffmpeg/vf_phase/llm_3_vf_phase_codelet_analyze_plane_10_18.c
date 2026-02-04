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
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
ptrdiff_t *indices = malloc(w * sizeof(ptrdiff_t));
if (!indices) return;
for (int i = 0; i < w; i++) indices[i] = i;
for (int i = 0; i < w; i++) {
    uint16_t *n_idx = nptr + indices[i];
    uint16_t *o_idx = optr + indices[i];
    if (n_idx + ns < nptr || n_idx - ns < nptr || o_idx + os >= optr + w) continue;
    pdif += ((t) = ((*n_idx - n_idx[ns]) << 2) + n_idx[(ns) << 1] - n_idx[-ns], (t) * (t));
    bdif += ((t) = ((*o_idx - n_idx[ns]) << 2) + o_idx[(os) << 1] - n_idx[-ns], (t) * (t));
}
free(indices);
}
