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

/**
 * Tests reverse_array with even size
*/
int test_reverse_array_even() {
    printf("5. test_reverse_array_even()\n");
    int arr[] = {1, 2, 3, 4};
    reverse_array(arr, 4);
    if (arr[0] == 4 && arr[1] == 3 && arr[2] == 2 && arr[3] == 1) {
        return 1;
    }
    return 0;
}

/**
 * Tests reverse_array with odd size
*/
int test_reverse_array_odd() {
    printf("6. test_reverse_array_odd()\n");
    int arr[] = {1, 2, 3, 4, 5};
    reverse_array(arr, 5);
    if (arr[0] == 5 && arr[1] == 4 && arr[2] == 3 && arr[3] == 2 && arr[4] == 1) {
        return 1;
    }
    return 0;
}

/**
 * Tests double_array_size normal case
*/
int test_double_array_size_normal() {
    printf("7. test_double_array_size_normal()\n");
    int arr[] = {1, 2, 3};
    int* result = double_array_size(arr, 3);
    if (result == NULL) {
        return 0;
    }
    
    // Check copied values
    for (int i = 0; i < 3; i++) {
        if (result[i] != arr[i]) {
            free(result);
            return 0;
        }
    }
    
    // Check zeros
    for (int i = 3; i < 6; i++) {
        if (result[i] != 0) {
            free(result);
            return 0;
        }
    }
    
    free(result);
    return 1;
}

/**
 * Tests double_array_size with NULL input
*/
int test_double_array_size_null() {
    printf("8. test_double_array_size_null()\n");
    int* result = double_array_size(NULL, 5);
    if (result == NULL) {
        return 1;
    }
    free(result);
    return 0;
}

/**
 * Tests copy_array_start_end_loop without wrap
*/
int test_copy_array_normal_range() {
    printf("9. test_copy_array_normal_range()\n");
    int arr[] = {1, 2, 3, 4, 5};
    int new_size;
    int* result = copy_array_start_end_loop(arr, 5, 1, 3, &new_size);
    
    if (result == NULL || new_size != 3) {
        if (result) free(result);
        return 0;
    }
    
    if (result[0] == 2 && result[1] == 3 && result[2] == 4) {
        free(result);
        return 1;
    }
    
    free(result);
    return 0;
}

/**
 * Tests copy_array_start_end_loop with wrap around
*/
int test_copy_array_wrap_around() {
    printf("10. test_copy_array_wrap_around()\n");
    int arr[] = {1, 2, 3, 4, 5};
    int new_size;
    int* result = copy_array_start_end_loop(arr, 5, 3, 1, &new_size);
    
    if (result == NULL || new_size != 4) {
        if (result) free(result);
        return 0;
    }
    
    if (result[0] == 4 && result[1] == 5 && result[2] == 1 && result[3] == 2) {
        free(result);
        return 1;
    }
    
    free(result);
    return 0;
}

/**
 * Tests copy_array_start_end_loop with invalid bounds
*/
int test_copy_array_invalid_bounds() {
    printf("11. test_copy_array_invalid_bounds()\n");
    int arr[] = {1, 2, 3, 4, 5};
    int new_size;
    
    // Test invalid start
    int* result = copy_array_start_end_loop(arr, 5, -1, 2, &new_size);
    if (result != NULL) {
        free(result);
        return 0;
    }
    
    // Test invalid end
    result = copy_array_start_end_loop(arr, 5, 0, 5, &new_size);
    if (result != NULL) {
        free(result);
        return 0;
    }
    
    return 1;
}

/**
 * Tests create_point with positive values
*/
int test_create_point_positive() {
    printf("12. test_create_point_positive()\n");
    Point* p = create_point(5, 10);
    if (p == NULL) {
        return 0;
    }
    
    if (p->x == 5 && p->y == 10) {
        free(p);
        return 1;
    }
    
    free(p);
    return 0;
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
