/**
 * Student Name: Siddharth Kakked
 * Semester: Fall 2025
 * 
 * C Practice
 * This assignment is to help you practice using C. Is is setup to
 * a set of various functions that tests the ideas you are learning.
 * 
 * In addition to this file, you will need to create a test file, that tests
 * every function!
 * 
 * This is called a 'header' library, meaning it is a collection of functions
 * that can be used in other files. This is the standard way of creating
 * libraries in C. In this case, the functions are implemented in the header file (.h)
 * but sometimes they are separated between header declarations (.h) and source files (.c)
 * which  you will explore in other assignments. 
*/

#ifndef C_PRACTICE_H
#define C_PRACTICE_H

#include <stdio.h> // basic input and output
#include <stdlib.h> // standard library

/**
 * Basic struct to hold two coordinates
*/
typedef struct {
    int x;
    int y;
} Point;


/**
 * Basic struct to hold a list of points - this list could be a polygon, 
 * but no checking for complexity is done.
*/
typedef struct {
    Point **points;
    int size;
} Polygon;


/**
 * Swaps the values of a and b. Makes use of pointers to change the values
 * of the variables in the calling function. 
**/
void swap(int *a, int *b){
    int temp = *a; // Saving the value that 'a' points to in a temporary variable
    *a = *b; // Putting the value from b to a
    *b = temp; // put the saved value in b's location

}

/**
 * Prints an array of integers to the screen. Has a space after each value, and new line at the end
 * so an array of [1, 3, 2] would be
 * 1 3 2 
 * (notice there is a hidden space at the end of the 2 before the \n )
*/
void print_array(int *arr, int size)
{
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * Creates an array based on the fibonacci sequence.
 * The size is the number of elements in the array.
 *
 * For example, if size is 5, then the array should be [1, 1, 2, 3, 5]
 * if the size is 1, then the array should be [1]
 * if the size is <= 0, then NULL should be returned.
 *
 * As a reminder, the fibonacci sequence is:
 * is the value of the two previous values added together.
 *
 * So the first two values [0], [1] are 1, 1.
 * The third value is 1 + 1 = 2
 * The fourth value is 1 + 2 = 3
 * The fifth value is 2 + 3 = 5
 *
 * This means, you can set the first two values of the array to 1, 1,
 * and then start your loop forward.
 *
 * You can assume the size is less than 95, so you don't have to worry about
 * integer overflow.
 *
 * here is a quick list of numbers: https://www.math.net/list-of-fibonacci-numbers
 **/
int* create_array_of_ints_fib(int size){
    if (size <= 0) {
        return NULL; // Return NULL for non-positive sizes
    }
    int *arr = (int *)malloc(size * sizeof(int)); // Allocate memory for the array
    if (!arr) {
        return NULL; // Return NULL if memory allocation fails
    }
    arr[0] = 1; // First Fibonacci number
    if (size >=2) arr [1] = 1; // Second Fibonacci number
    for (int i = 2; i < size; i++) {
        arr[i] = arr[i - 1] + arr[i - 2]; // Calculate Fibonacci numbers
    }
    return arr; // Return the pointer to the array
}

/**
 * Reverses an array *in place* (meaning you don't copy into another array)
 * 
 * For example, if the array is [1, 2, 3, 4, 5] then the array should be
 * [5, 4, 3, 2, 1]
 * 
 * To receive full points, you should only loop through *half* of the array. (size/2). 
 * Consider using swap. 
*/
void reverse_array(int *arr, int size){
    if (!arr || size <= 1) {
        return; // No need to reverse if array is NULL or has 0 or 1 element
    }
    for (int i = 0; i < size / 2; i++) {
        swap(&arr[i], &arr[size - 1 - i]); // Swap elements from start and end
    }
    
}

 
/**
 * Doubles the size of an array, and copies all previous values into the new array.
 * All other values should be set to 0. Returns a pointer to the new array
 * 
 * You may want to look at calloc to help with this, to confirm all values are set to 0.
 * though you don't have to, if you want to loop through and set them to 0 yourself.
 * 
*/
int* double_array_size(int *arr, int size){
    if (!arr || size <= 0) {
        return NULL; // Return NULL if input array is NULL or size is non-positive
    }
        int new_size = size * 2;
        int *out = (int*)calloc(new_size, sizeof(int)); // Allocate and zero-initialize new array
        if (!out) {
            return NULL; // Return NULL if memory allocation fails
        }
            for (int i = 0; i < size; i++) {
                out[i] = arr[i]; // Copy old values to new array
            }
        return out; // Return the pointer to the new array
        }

/**
 * Copies elements of an array from start to end (inclusive) into a new array.
 *
 * Returns the new array. However, if end is less than start, it loops around copying
 * elements from the beginning of the array.. (thus picture your array as a circle).
 *
 * if start or end are invalid (less than 0, or greater than or equal to size), then
 * return NULL.
 *
 * Example: assume an array is [1, 2, 3, 4, 5]
 * if make start = 1, and end = 3, then the new array should be [2, 3, 4]
 * if make start = 3, and end = 1, then the new array should be [4, 5, 1, 2]
 *
 * Notice, new_size is a pointer, so you can set the size of the new array in your function. This
 * is commonly done in C, as a way to have multiple return values. (both the return, and the modified parameter)
 *
 * In the two examples above, new_size would be set to 3, and then 4 respectively.
 *
 * You will want to remember pointer arithmetic here. You can't say something like new_size = steps (where steps
 * is your new calculated size based on start to end), instead you have to say *new_size = steps+1)
 *
 * Make sure to test this function, this is probably the hardest of the batch, and easy
 * to get an OB1 error!
 */
int* copy_array_start_end_loop(int *arr, int size, int start, int end, int *new_size) {
    if (!arr || size <=0 || !new_size)
        return NULL; // Return NULL if input array is NULL or size is non-positive
    if (start < 0 || start >= size || end < 0 || end >= size)
        return NULL; // Return NULL if start or end are out of bounds
    int count;
    if (end >= start) {
        count = end - start + 1; // Calculate number of elements to copy
    } else {
        count = (size - start) + (end + 1); // Wrap around case
    }
    *new_size = count; // Set the new size
    int *out = (int *)malloc(count * sizeof(int)); // Allocate memory for the new array
    if (!out)
        return NULL; // Return NULL if memory allocation fails
        int idx = 0;
        int i = start;
        while (1) {
            out[idx++] = arr[i]; // Copy element
            if (i == end) break; // Stop if we've reached the end
            i = (i + 1) % size; // Move to the next index, wrapping around if necessary
        }

    return out;
}

/* 
Practice with struts 
*/

/**
 * Creates a point with the given x and y values. Allocates it on the heap. (malloc)
 * and returns the new point
*/
Point* create_point(int x, int y){
    Point *p = (Point *)malloc(sizeof(Point)); // Allocate memory for a Point
    if (!p) {
        return NULL; // Return NULL if memory allocation fails
    }
    p->x = x; // Set the x coordinate
    p->y = y; // Set the y coordinate
    return p; // Return the pointer to the new Point
}

/**
 * Creates a polygon with the given size. Allocates it on the heap. (malloc)
 * and returns the new polygon
 * 
 * For the points, you are creating the array of points, but you do not have to allocate
 * the point values. it is just a polygon of eventual size, and an array of empty points. 
*/
Polygon* create_polygon(int size) {
    if (size <= 0) {
        return NULL; // Return NULL for non-positive sizes
    }
    Polygon *poly = (Polygon *)malloc(sizeof(Polygon)); // Allocate memory for Polygon
    if (!poly) {
        return NULL; // Return NULL if memory allocation fails
    }
    poly->size = size; // Set the size
    poly->points = (Point **)malloc(size * sizeof(Point *)); // Allocate memory for points array
    if (!poly->points) {
        free(poly); // Free previously allocated memory if points allocation fails
        return NULL;
    }
    return poly; // Return the pointer to the new Polygon
}


/**
 * Frees the memory used by the polygon, make sure to loop through
 * all the points, to free them, free the array, and then free the polygon itself.
*/
void free_polygon(Polygon *p){
    if (!p) {
        return; // Nothing to free if polygon is NULL
    }
    if (p->points) {
        for (int i = 0; i < p->size; i++) {
            free(p->points[i]); // Free each Point
        }
        free(p->points); // Free the points array
    }
    free(p); // Free the Polygon itself
}

/**
 * Creates a rectangle of width and height, using the polygon struct and returns it.
 * 
 * You can assume the following order of points
 * 0, 0
 * width, 0
 * width, height
 * 0, height
*/
Polygon* create_rectangle(int width, int height){
    Polygon *poly = create_polygon(4); // Create a polygon with 4 points
    if (!poly) {
        return NULL; // Return NULL if polygon creation fails
    }
    poly->points[0] = create_point(0, 0);
    poly->points[1] = create_point(width, 0);
    poly->points[2] = create_point(width, height);
    poly->points[3] = create_point(0, height);
    return poly; // Return the pointer to the new rectangle polygon
}


/**
 * Creates a (right) triangle of width and height, using the polygon struct and returns it.
 * 
 * You can assume the following order of points
 * 0, 0
 * width, 0
 * width, height
*/
Polygon* create_triangle(int width, int height){
    Polygon *poly = create_polygon(3); // Create a polygon with 3 points
    if (!poly) {
        return NULL; // Return NULL if polygon creation fails
    }
    poly->points[0] = create_point(0, 0);
    poly->points[1] = create_point(width, 0);
    poly->points[2] = create_point(width, height);
    return poly; // Return the pointer to the new triangle polygon
}

/**
 * Prints the point in the format "(x, y) "
*/
void print_point(Point *p){
    printf("(%d, %d)", p->x, p->y);
}

/**
 * Prints the polygon in the format "(x, y) (x, y) (x, y) \n"
*/
void print_polygon(Polygon *p){
    for(int i = 0; i < p->size; i++){
        print_point(p->points[i]);
        printf(" ");
    }
    printf("\n");
}

/**
 * Calculates the area of the polygon using the shoestring formula.
 * 
 * The shoestring formula will loop through every point, and calculates the area by
 * 
 * area +=  i->x * i+1->y - i+1->x * i->y
 * 
 * however, when i+1 is greater than size, you will need to loop back around to the beginning (so think of
 * setting i+1 to j, where j= (i+1) % p->size before running the calculations)
 * 
 * after area is summed across all points, divide by 2.0 and return the area.
*/
double calculate_polygon_area(Polygon *p){
    if (!p || p->size < 3) {
        return 0.0; // Return 0 for NULL polygon or polygons with less than 3 points
    }
    long long sum = 0; // Use long long to prevent overflow
    for (int i = 0; i < p->size; i++) {
        int j = (i + 1) % p->size; // Next index, wrapping around
        Point *a = p->points[i];
        Point *b = p->points[j];
        long long cross = (long long)a->x * b->y - (long long)b->x * a->y;
        sum += cross;
    }
    if (sum < 0) sum = -sum; // Ensure area is non-negative
    return sum / 2.0; // Return the area
}

#endif // C_PRACTICE_H