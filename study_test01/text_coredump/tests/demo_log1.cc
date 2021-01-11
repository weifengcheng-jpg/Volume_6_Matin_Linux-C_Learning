#include <stdio.h>
#include <signal.h>
#include <execinfo.h>
#include <stdlib.h>

//信号钩子函数, 获取栈信息, 然后打印
void handle_segv(int signum) {
    void* array[100];
    size_t size;
    char** strings;
    size_t i;

    signal(signum, SIG_DFL);

    size = backtrace(array, 100);
    strings = (char**)backtrace_symbols(array, size);

    printf("Launchar received SIG: %d Stack trace: \n", signum);

    for (i = 0; i < size; i++) {
        fprintf(stderr, "%d %s\n", i, strings[i]);
    }

    free(strings);
}

int func(int* p) {
    int y = *p;

    return y;
}

int main() {
    int* p = NULL;
    signal(SIGSEGV, handle_segv);
    signal(SIGABRT, handle_segv);

    return func(p);
}

