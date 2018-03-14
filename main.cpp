#include <iostream>
#define _INTSIZEOF(n) \
((sizeof(n)+sizeof(int)-1)&~(sizeof(int) - 1) )

int main() {
    va_list    ap;

    long b = 8;
    printf("%d\n", _INTSIZEOF(b));
    std::cout << "Hello, World!" << std::endl;
    return 0;
}