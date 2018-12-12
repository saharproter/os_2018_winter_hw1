#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>


int is_changeable(pid_t pid){
    int res;
    __asm__(
    "int $0x80;"
    : "=a" (res)
    : "0" (243), "b" (pid)
    :"memory"
    );
    if ((res) < 0) {
        errno = -(res);
        return -1;
    }
    return res;
}

int make_changeable(pid_t pid){
    int res;
    __asm__(
    "int $0x80;"
    : "=a" (res)
    : "0" (244), "b" (pid)
    :"memory"
    );
    if ((res) < 0) {
        errno = -(res);
        return -1;
    }
    return res;
}

int change(int val){
    int res;
    __asm__(
    "int $0x80;"
    : "=a" (res)
    : "0" (245), "b" (val)
    :"memory"
    );
    if ((res) < 0) {
        errno = -(res);
        return -1;
    }
    return res;
}

int get_policy(pid_t pid){
    int res;
    __asm__(
    "int $0x80;"
    : "=a" (res)
    : "0" (246), "b" (pid)
    :"memory"
    );
    if ((res) < 0) {
        errno = -(res);
        return -1;
    }
    return res;
}
