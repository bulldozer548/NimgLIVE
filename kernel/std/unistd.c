#include "unistd.h"
#include "types.h"

u32 syscall_0(u32 syscall){
    u32 retval;
    asm volatile(
        "int $0x80"
        : "=a" (retval)
        : "0" (syscall)
    );
    return retval;
}

u32 syscall_1(u32 syscall, u32 arg1){
    u32 retval;
    asm volatile(
        "int $0x80"
        : "=a" (retval)
        : "0" (syscall), "b" (arg1)
    );
    return retval;
}

u32 syscall_2(u32 syscall, u32 arg1, u32 arg2){
    u32 retval;
    asm volatile(
        "int $0x80"
        : "=a" (retval)
        : "0" (syscall), "b" (arg1), "c" (arg2)
    );
    return retval;
}

u32 syscall_3(u32 syscall, u32 arg1, u32 arg2, u32 arg3){
    u32 retval;
    asm volatile(
        "int $0x80"
        : "=a" (retval)
        : "0" (syscall), "b" (arg1), "c" (arg2), "d" (arg3)
    );
    return retval;
}

u32 syscall_4(u32 syscall, u32 arg1, u32 arg2, u32 arg3, u32 arg4){
    u32 retval;
    asm volatile(
        "int $0x80"
        : "=a" (retval)
        : "0" (syscall), "b" (arg1), "c" (arg2), "d" (arg3), "S" (arg4)
    );
    return retval;
}

u32 syscall_5(u32 syscall, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5){
    u32 retval;
    asm volatile(
        "int $0x80"
        : "=a" (retval)
        : "0" (syscall), "b" (arg1), "c" (arg2), "d" (arg3), "S" (arg4), "D" (arg5)
    );
    return retval;
}


unsigned sleep(unsigned secs){
    return syscall_2(0, secs, 's');
}

