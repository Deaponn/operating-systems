#include <stdio.h>

#ifndef DYNAMIC
#include "collatz.h"
#endif

#ifdef DYNAMIC
#include <dlfcn.h>
#endif

int main() {
    #ifndef DYNAMIC
    char message[] = "non-dynamic";
    #endif

    #ifdef DYNAMIC
    char message[] = "dynamic";

    void *libcollatz = dlopen("./libcollatz.so", RTLD_LAZY);
    if(!libcollatz){/*error*/}

    int (*test_collatz_convergence)();
    test_collatz_convergence = (int (*)())dlsym(libcollatz, "test_collatz_convergence");

    if(dlerror() != NULL){/*error*/}

    #endif

    printf("%s\n", message);

    int numbers[10] = {1, 2, 5, 10, 17, 19, 31, 33, 69, 97};

    for (int i = 0; i < 10; i++) {
        printf("Argument %d, converged after %d steps.\n", numbers[i], test_collatz_convergence(numbers[i], 100));
    }

    return 0;
}
