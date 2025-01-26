// ===================================
// MinUnit test framework init
// ===================================

// Returns a string if the expression passed to it is false
#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
// Calls another test case and returns if that test case fails
#define mu_run_test(test) do { char *message = test(); tests_run++; \
                               if (message) return message; } while (0)


#include <stdio.h>
#include "types.h"

int tests_run = 0;

static char * test_tColorInit() {
    tColor testObj;
    tColorInit(&testObj);

    mu_assert(
        "error, tColor is not initializing propperly",
              (testObj.r == (float)0 && testObj.g == (float)0 &&
               testObj.b == (float)0));
    return 0;
}

static char * test_tColorSetFloat_1(){
    tColor testObj;
    tColorInit(&testObj);

    tColorSetFloat(&testObj, 1, 1, 1);
    mu_assert("error, tColor is not set propperly (test_tColorSetFloat_1)",
              (testObj.r == (float)1 && testObj.g == (float)1 &&
               testObj.b == (float)1));
    return 0;
}

static char * test_tColorSetFloat_2(){
    tColor testObj;
    tColorInit(&testObj);

    tColorSetFloat(&testObj, 0.5, 0.5, 0.5);
    mu_assert(
        "error, tColor is not set propperly (test_tColorSetFloat_2)",
              (testObj.r == (float)0.5 && testObj.g == (float)0.5 &&
               testObj.b == (float)0.5));
    return 0;
}

static char * test_tColorSetFloat_3(){
    tColor testObj;
    tColorInit(&testObj);

    tColorSetFloat(&testObj, 2, 2, 2);
    mu_assert("error, tColor is not set propperly (test_tColorSetFloat_3)",
              (testObj.r == (float)1 && testObj.g == (float)1 &&
               testObj.b == (float)1));
    return 0;
}

static char * test_tColorSetFloat_4(){
    tColor testObj;
    tColorInit(&testObj);

    tColorSetFloat(&testObj, -1, -1, -1);
    mu_assert("error, tColor is not set propperly (test_tColorSetFloat_4)",
              (testObj.r == (float)0 && testObj.g == (float)0 &&
               testObj.b == (float)0));
    return 0;
}

static char * test_tColorObjectSetHex_1(){
    tColor testObj;
    tColorInit(&testObj);

    tColorSetHex(&testObj, "000000");
    mu_assert("error, tColor is not set propperly (test_tColorObjectSetHex_1)",
              (testObj.r == (float)0 && testObj.g == (float)0 &&
               testObj.b == (float)0));
    return 0;
}

static char * test_tColorObjectSetHex_2(){
    tColor testObj;
    tColorInit(&testObj);

    tColorSetHex(&testObj, "FFFFFF");
    mu_assert("error, tColor is not set propperly (test_tColorObjectSetHex_2)",
              (testObj.r == (float)1 && testObj.g == (float)1 &&
               testObj.b == (float)1));
    return 0;
}

static char * test_tColorObjectSetHex_3(){
    tColor testObj;
    tColorInit(&testObj);

    tColorSetHex(&testObj, "999999");
    mu_assert(
        "error, tColor is not set propperly (test_tColorObjectSetHex_3)",
              (testObj.r == (float)0.6 && testObj.g == (float)0.6 &&
               testObj.b == (float)0.6));
    return 0;
}

static char * all_tests() {
    mu_run_test(test_tColorInit);
    mu_run_test(test_tColorSetFloat_1);
    mu_run_test(test_tColorSetFloat_2);
    mu_run_test(test_tColorSetFloat_3);
    mu_run_test(test_tColorSetFloat_4);
    mu_run_test(test_tColorObjectSetHex_1);
    mu_run_test(test_tColorObjectSetHex_2);
    mu_run_test(test_tColorObjectSetHex_3);
    return 0;
}
 
int main(void) {
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}