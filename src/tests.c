/**
 * Student Name: Siddharth Kakked
 * Semester: Fall 2025
 * 
 * This file is to test the functions in cpractice.h. You are to write at least *TWO* (maybe more) tests for every function. 
 * Some sample ones have been provided for you.
*/

#include <stdio.h>  // basic input and output
#include <stdlib.h> // standard library

#include "cpractice.h" // header file for cpractice.c


// this may help with some tests, as the array numbers match their index
int * create_simple_array(int size) {
    int * arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    return arr;
}

/**
 * Tests a basic swap
*/
int test_swap_one() {
    printf("1. test_swap_one()\n");
    int a = 5;
    int b = 10;
    swap(&a, &b);
    if (a == 10 && b == 5) {
        return 1;
    }
    return 0;
}

 /**
  * Tests swap with same values
**/
int test_swap_two(){
    printf("3. test_swap_two()\n");
    int a = 7;
    int b = 7;
    swap(&a, &b);
    if (a == 7 && b == 7) {
        return 1;
    }
    return 0;
}
 

/**
 * Tests the create_array_of_ints_fib function
*/
int test_create_array_of_ints_fib() {
    printf("2. test_create_array_of_ints_fib()\n");
    int* arr = create_array_of_ints_fib(5);
    int expected[] = {1, 1, 2, 3, 5};
    for (int i = 0; i < 5; i++) {
        if (arr[i] != expected[i]) {
            free(arr);
            return 0;
        }
    }
    free(arr); // note expected does not need freed.. why is that?
    // everything matched
    return 1;
}



/**
 * Tests the create_array_of_ints_fib function
*/
int test_create_array_of_ints_fib_2() {
    printf("3. test_create_array_of_ints_fib()\n"); // Test for Fibonacci sequence array creation
    int* arr = create_array_of_ints_fib(5);
    int expected[] = {1, 1, 2, 3, 5};
    for (int i = 0; i < 5; i++) {
        if (arr[i] != expected[i]) { // Compare each element with expected values
            free(arr);
            return 0;
        }
    }
    free(arr);
    return 1;
}

/**
 * Tests create_array_of_ints_fib with edge cases
*/
int test_create_array_of_ints_fib_edge() {
    printf("4. test_create_array_of_ints_fib_edge()\n");
    // Test size 1
    int* arr = create_array_of_ints_fib(1);
    if (arr == NULL || arr[0] != 1) {
        if (arr) free(arr);
        return 0;
    }
    free(arr);
    
    // Test negative size
    arr = create_array_of_ints_fib(-1);
    if (arr != NULL) {
        free(arr);
        return 0;
    }
    
    return 1;
}

// this is a list of all the unit tests
int (*unitTests[])() = {
        test_swap_one,
        test_create_array_of_ints_fib,
        // add more test function names here
};

int main(int argc, char const *argv[])
{
    int numTests = sizeof(unitTests) / sizeof(unitTests[0]);
    int numPassed = 0;

    for (int i = 0; i < numTests; i++) {
        if (unitTests[i]()) {
            numPassed++;
        } else {
            printf("Test %d failed\n", i);
        }
    }

    printf("Passed %d out of %d tests\n", numPassed, numTests);
    return 0;
}
