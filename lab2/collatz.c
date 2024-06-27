#include "collatz.h"

int collatz_conjecture(int input) {
    if (input % 2 == 0) {
        return input >> 1;
    }
    return 3 * input + 1;
}

int test_collatz_convergence(int input, int max_iter) {
    int argument = input;
    for (int i = 0; i < max_iter; i++) {
        if (argument == 1) {
            return i;
        }
        argument = collatz_conjecture(argument);
    }
    return -1;
}
