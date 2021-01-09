#include "speak.h"

void say_hello(const char* str) {
    static int count = 0;
    count++;
    printf("Hello %s.\n", str ? str : "NULL");
    printf("count: %d\n", count);
    return;
}
