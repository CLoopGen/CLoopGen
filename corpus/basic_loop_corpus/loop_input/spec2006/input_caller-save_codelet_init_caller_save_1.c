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

int target_flags = 33554432;
char call_fixed_regs[53] = {0};
HARD_REG_ELT_TYPE call_fixed_reg_set = 0;
enum machine_mode regno_save_mode[53][5];
int reg_save_code[53][59];
int i = 0;
int j = 0;

void init_vars() {
    for (i = 0; i < 53; i++) {
        for (j = 0; j < 5; j++) {
            regno_save_mode[i][j] = (j == 0) ? VOIDmode : (enum machine_mode)(j % MAX_MACHINE_MODE);
        }
        for (j = 0; j < 59; j++) {
            reg_save_code[i][j] = (i * 59 + j) % 7 ? -1 : 0;
        }
    }
    target_flags = 33554432;
    call_fixed_reg_set = 0;
    for (i = 0; i < 53; i++) {
        call_fixed_regs[i] = 0;
    }
    i = 0;
    j = 0;
}