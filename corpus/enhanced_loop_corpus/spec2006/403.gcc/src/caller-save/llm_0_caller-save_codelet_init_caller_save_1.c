#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

enum machine_mode {
    VOIDmode,
    BImode,
    QImode,
    HImode,
    SImode,
    DImode,
    TImode,
    OImode,
    PQImode,
    PHImode,
    PSImode,
    PDImode,
    QFmode,
    HFmode,
    TQFmode,
    SFmode,
    DFmode,
    XFmode,
    TFmode,
    QCmode,
    HCmode,
    SCmode,
    DCmode,
    XCmode,
    TCmode,
    CQImode,
    CHImode,
    CSImode,
    CDImode,
    CTImode,
    COImode,
    V2QImode,
    V2HImode,
    V2SImode,
    V2DImode,
    V4QImode,
    V4HImode,
    V4SImode,
    V4DImode,
    V8QImode,
    V8HImode,
    V8SImode,
    V8DImode,
    V16QImode,
    V2SFmode,
    V2DFmode,
    V4SFmode,
    V4DFmode,
    V8SFmode,
    V8DFmode,
    V16SFmode,
    BLKmode,
    CCmode,
    CCGCmode,
    CCGOCmode,
    CCNOmode,
    CCZmode,
    CCFPmode,
    CCFPUmode,
    MAX_MACHINE_MODE
};


extern int target_flags;
extern char call_fixed_regs[53];
extern HARD_REG_ELT_TYPE call_fixed_reg_set;
extern enum machine_mode regno_save_mode[53][5];
extern int reg_save_code[53][59];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 53; i++) {
    int factor = (target_flags & 33554432) ? 8 : 4;
    for (j = 1; j <= (16 / factor); j++) {
        if (reg_save_code[i][regno_save_mode[i][j]] == -1) {
            regno_save_mode[i][j] = VOIDmode;
            if (j == 1) {
                call_fixed_regs[i] = 1;
                call_fixed_reg_set |= (HARD_REG_ELT_TYPE)1 << i;
            }
        }
    }
}
}
