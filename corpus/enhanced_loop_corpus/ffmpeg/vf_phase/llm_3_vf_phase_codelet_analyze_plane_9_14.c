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
    // Variant 2: Strided memory access — process every 'os' step in optr and 'ns' in nptr
    // Assume ns and os are positive strides; adjust loop bound accordingly
    int stride = (ns > 1) ? ns : 1;
    uint16_t *strided_end = nptr + (w / stride) * stride;  // Align to full strides

    for (rend = strided_end; nptr < rend; nptr += stride, optr += os) {
        // Access nptr with fixed stride, using local window
        int base_n = *(nptr);
        int n_ns = nptr[ns];
        int n_2ns = nptr[(ns) << 1];
        int n_mns = nptr[-(ns)];

        t = ((base_n - n_ns) << 2) + n_2ns - n_mns;
        pdif += t * t;

        int o_os = optr[os];
        int o_mos = optr[-(os)];
        t = ((base_n - o_os) << 2) + n_2ns - o_mos;
        tdif += t * t;

        int base_o = *(optr);
        int o_2os = optr[(os) << 1];
        t = ((base_o - n_ns) << 2) + o_2os - n_mns;
        bdif += t * t;
    }

    // Final pass: handle trailing elements with unit increment if needed
    rend = nptr + w;
    for (; nptr < rend; nptr++, optr++) {
        t = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)];
        pdif += t * t;
        t = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)];
        tdif += t * t;
        t = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)];
        bdif += t * t;
    }
}
