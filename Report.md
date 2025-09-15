# Homework - C Practice Report

Completely answer the report questions below. Make sure to double check the final version to make sure it is easily readable on your github repository. 

1. What is the difference between a standard numeric type (int, float, double) and a pointer?
   > A standard numeric type stores  the value directly in the memory while a pointer stores a memory adress that points to where a value is located.
   
2. In your test file, we had the following code:
    
    ```c
    int* arr = create_array_of_ints_fib(5);
    int expected[] = {1, 1, 2, 3, 5};
    ```
    Later in the code we only `free(arr)` but not expected. Why is this? What is the difference in where they are stored in memory?

    > arr  was created with malloc is dynamically allocated on the heap while expected array is declared as a local array (int expected[]), which is allocated on the stack. We onl;y free(arr) because only the allocator knows how to free arr because it owns bookkeeping.

3. What is the difference between the heap and stack when related to memory allocation and management?
   > The stack is used for automatic/local variables, function parameters, and return addresses. It's managed automatically (LIFO - Last In First Out), has limited size, and memory is deallocated when variables go out of scope. The heap is used for dynamic memory allocation via malloc/calloc, has more available space, requires manual management with free, and memory persists until explicitly freed.

4. Take the following code:
   ```c
   #include <stdio.h>
   #include <stdlib.h>

   typedef struct {
     int x, y;
   } Point;

   Point * new_point(int x, int y) {
     Point pt = {x, y};
     return &pt;
   }

   int main() {
      Point* point = new_point(10, 10);
      printf("x: %d, y: %d", point->x, point->y);
      return 0;
   }
   ```
   Would the code run correctly? Even if it does compile, what would be some potential runtime issues? After answering your thoughts, put the output of a run below (you may need to run it a few times).
   > This code returns a pointer to a local variable. The Point pt is created on the stack inside new_point, and when the function returns, that stack memory becomes invalid. This causes undefined behavior. The code will not run correctly or reliably. While it might compile without errors, it invokes undefined behavior.

   ```text
   x: 32767, y: -18446744073709551615 (Run 1)
   x: 10, y: 10 (Run 2)
   ```

   Fix the code in the following block:
   ```c
   #include <stdio.h>
   #include <stdlib.h>

   typedef struct {
     int x, y;
   } Point;

   Point * new_point(int x, int y) {
      Point *pt = (Point *)malloc(sizeof(Point));
      pt-> = x;
      pt-> = y;
      return pt;
   }

   int main() {
      Point* point = new_point(10, 10);
      printf("x: %d, y: %d", point->x, point->y);
      return 0;
   }
   ```

5. When you use `malloc`, where are you storing the information?
> malloc allocates memory on the heap. The heap is a region of memory used for dynamic allocation during program runtime.

6. Speaking about `malloc` and `calloc`, what is the difference between the two (you may need to research it!)?
> malloc: Allocates a block of memory of specified size in bytes from the heap.
> calloc: Allocates memory for an array of elements and initializes all bytes to zero.
> malloc vs calloc - Key Differences 
   (1) Initialization: malloc returns uninitialized memory (contains garbage values), while calloc initializes all allocated memory to zero.
   (2) Parameters: malloc takes one parameter (total size in bytes), while calloc takes two parameters (number of elements and size of each element).

7. What are some common built in libraries used for C, list at least 3 and explain each one in your own words. Name a few (at least 3) functions in those libraries (hint: we used two of the most common ones in this assignment. There are many resources online that tell you functions in each library - you need to include at least 1 reference, but ideally for every library, you should have a reference to it)?
   - Example: stdlib.h - provides functions for general-purpose operations including
              memory management and random numbers [1].
     - void * malloc(size_t) - allocates memory specified in size on the heap and returns a pointer to that location
     - void * calloc(size_t num_elements, size_t element_size) - contiguous allocation for allocating arrays with the default value of 0. Slower than malloc. 
     - int rand(void) - returns a random integer between 0 and RAND_MAX. Seed should be set before hand. 
   1. stdio.h - Standard Input/Output library for file operations and console I/O
      * printf(const char *format, ...) - prints formatted output to stdout
      * scanf(const char *format, ...) - reads formatted input from stdin
      * fopen(const char *filename, const char *mode) - opens a file and returns a FILE pointer
   
   2. string.h - String manipulation and memory operations
      * strlen(const char *str) - returns the length of a string
      * strcpy(char *dest, const char *src) - copies a string from source to destination
      * memcpy(void *dest, const void *src, size_t n) - copies n bytes from source to destination memory
 
   3. math.h - Mathematical functions and constants
      * sqrt(double x) - returns the square root of x
      * pow(double x, double y) - returns x raised to the power of y
      * fabs(double x) - returns the absolute value of a floating-point number
 

8. Looking at the struct Point and Polygon, we have a mix of values on the heap, and we make ample use of pointers. Take a moment to draw out how you think that looks after `create_triangle(2,3)` is called (see an example below). The important part of the drawing it to see that not everything is stored together in memory, but in different locations! Store the image file in your github repo and link it here. You can use any program to draw it such as [drawIO](https://app.diagrams.net/), or even draw it by hand and take a picture of it. 
> Memory diagram is here !['Memory drawing for create triangle(2,3)'](https://github.com/CS5008Fall2025/c-practice-skakked/blob/main/Files/Memory%20Diagram.jpeg) 


## Technical Interview Practice Questions
For both these questions, are you are free to use what you did as the last section on the team activities/answered as a group, or you can use a different question.

1. Select one technical interview question (this module or previous) from the [technical interview list](https://github.com/CS5008-khoury/Resources/blob/main/TechInterviewQuestions.md) below and answer it in a few sentences. You can use any resource you like to answer the question.
> What is the difference between git add and git commit?
> Git add adds items/files to a staging area or a temp holding area while git commit records those staged changes in the repository history with a unique commit ID. Added files remain staged until you commit them. 

2. Select one coding question (this module or previous) from the [coding practice repository](https://github.com/CS5008-khoury/Resources/blob/main/LeetCodePractice.md) and include a c file with that code with your submission. Make sure to add comments on what you learned, and if you compared your solution with others. 
> Picked Two sum: File is here: https://github.com/CS5008Fall2025/c-practice-skakked/blob/main/Files/Two_Sum.c

## Deeper Thinking
In Java and Python, do you think new objects are stored on the stack or the heap? Feel free to work through your thoughts as to why it would be better to store them on the stack or heap. You should consider pass by reference, and how that is similar to pointer in your answer. Feel free to use resources, but make sure to cite them, and include the citation below using ACM format. You will note LLMs are not valid references, but they can give you directions to valid references. Make sure to use your own words. 

Answer here using a paragraph (not just bullet points). 
> In both Java and Python, objects are stored on the heap, not the stack, and this design choice is fundamental to how these languages handle object-oriented programming and memory management. When you create an object with new in Java or create a class instance in Python, the actual object data resides on the heap while only the reference (essentially a managed pointer) exists on the stack. This heap allocation strategy enables several critical features: objects can have dynamic sizes determined at runtime, their lifetimes can extend beyond the scope where they were created, and they can be shared between different parts of the program through reference passing. It would be better to store them as a heap because this approach also facilitates automatic memory management through garbage collection in both languages, as the runtime can track reference counts or reachability to determine when objects are no longer needed, something that would be impossible with stack allocation where deallocation is deterministic and scope-based.   




## References
Add any references you use here. Use ACM style formatting, adding to the numbers as you add the reference. 

1. cppreference.com Contributors. 2025. Standard library header <stdlib.h>. cppreference.com. Retrieved May 1, 2025 from https://en.cppreference.com/w/c/header/stdlib

2. ...

## Resource/Help: Linking to images?
To link an image, you use the following code

```markdown
![alt text](path / link to image)
```
for example
```markdown
![my memory drawing](instructions/rectangle_points.png)
```


Here is a sample using: 
```c
void my_func() {
    Polygon* r = create_rectangle(5,5);
    printf("The area of the rectangle is %d\n", area(r));
}
```

![my memory drawing](instructions/rectangle_points.png)

Note: This is a simplified version. However, it helps illustrate why we need to use `free` on the pointers in the struct. If we do not, we will have memory leaks! (memory that is allocated, but not freed, and thus cannot be used by other programs). In the above example code, `r` is created, and then the variable is destroyed when the function ends. However, the memory allocated for the struct is not freed, and thus we have a memory leak.

When you work on your version for `create_triangle(2, 3)`, you do not have to be exact on the memory structure (the locations on the heap were randomly chosen). The idea is more to show how the memory is stored, and the pointers to different memory addresses. 

