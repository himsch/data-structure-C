#include <stdio.h>

void test(int a) {
    if (a <= 0)
        return;

    printf("test(%d)\n", a);
    return test(a - 1);
}

int main() {
    test(5);
    return 0;
}
