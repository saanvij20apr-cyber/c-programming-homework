// x-------------------------------------------------------x

// HOMEWORK 32 --> Set 11 : d
// Search & find out which is better malloc( ) or calloc( ).

// --> MALLOC:
//          Allocates a raw block of memory.
//          Leaves memory uninitialized (contains garbage values).
//          Marginally faster because it does not clear memory.
//          Takes one argument: total bytes needed.
//          Use malloc if you plan to immediately overwrite the memory (e.g., in a loop).

// --> CALLOC:
//          Allocates memory and initializes all bytes to zero.
//          Marginally slower due to the clearing step.
//          Prevents bugs caused by uninitialized data.
//          Takes two arguments: number of elements and size of each.
//          Use calloc if you need the allocated memory to start at zero for safety.

// x-------------------------------------------------------x

// HOMEWORK 31 --> Set 11 : c
// Search about what is "memory leak" in C.

// --> A memory leak occurs when a program allocates memory on the heap dynamically using functions like malloc(), calloc(), or realloc(), but fails to release it back to the system using the free() function once it is no longer needed.
// --> Consequences:
//          GRADUAL PERFORMANCE DROP: The OS spends extra time swapping date to virtual memory disk space.
//          SOFTWARE INSTABILITY: The program may crash unexpectedly once the system runs entirely out of heap memory.
//          SEVERE LONG-TERM EXPOSURE: : Small leaks continuously pile up in long-running processes like network servers, inevitably killing the host application over time.

// x-------------------------------------------------------x

// HOMEWORK 30 --> Set 11 : b
// Allocate memomry for 500 integers using calloc and then store first 500 natural numbers in that space.

// #include<stdio.h>
// #include<stdlib.h>

// int main() {
//     int *ptr;
//     ptr = (int*) calloc(500, sizeof(int));

//     if(ptr == NULL) {
//         printf("Memory allocation failed!\n");
//     }

//     for(int i = 0; i < 500; i++) {
//         ptr[i] = i + 1;
//     }

//     printf("First number: %d\n", ptr[0]);
//     printf("Last number: %d\n", ptr[499]);

//     free(ptr);

//     return 0;
// }

// x-------------------------------------------------------x

// HOMEWORK 29 --> Set 11 : a
// Search about what is a "dangling pointer" in C.

// --> A dangling pointer in C programming is a pointer that points to a memory location that has been deallocated, freed, or gone out of scope. 
// --> The pointer variable still stores the address of that memory block, but the program no longer has the authorization to access or modify it. 
// --> Dereferencing a dangling pointer triggers undefined behavior, which can manifest as random garbage data, data corruption, or immediate program crashes (segmentation faults).

// x-------------------------------------------------------x
// CHAPTER 11 : DYNAMIC MEMORY ALLOCATION
// x-------------------------------------------------------x

// HOMEWORK 28 --> Set 10 : c
// Format the information of 5 students (name, marks, cgpa, course) in a table like structure in a file.

// #include <stdio.h>

// int main() {
//     FILE *fptr = fopen("Test.txt", "w");
//     if (fptr == NULL) return 1;

//     fprintf(fptr, "%-16s %-7s %-6s %-20s\n", "Name", "Marks", "CGPA", "Course");
//     fprintf(fptr, "---------------------------------------------------------\n");

//     fprintf(fptr, "%-16s %-7d %-6.1f %-20s\n", "Franck Ocean", 88, 8.9, "Computer Science");
//     fprintf(fptr, "%-16s %-7d %-6.1f %-20s\n", "Kanye West", 94, 9.5, "Data Science");
//     fprintf(fptr, "%-16s %-7d %-6.1f %-20s\n", "Kendall Jenner", 76, 7.8, "Mechanical Eng.");
//     fprintf(fptr, "%-16s %-7d %-6.1f %-20s\n", "Brad Pitt", 85, 8.6, "Electronics Eng.");
//     fprintf(fptr, "%-16s %-7d %-6.1f %-20s\n", "Santan Dave", 91, 9.2, "Information Tech.");

//     fclose(fptr);

//     printf("Success! The table has been saved inside Test.txt.\n");
//     return 0;
// }

// x-------------------------------------------------------x

// HOMEWORK 27 --> Set 10 : b
// Replace the data in file of the previous question with the number of vowels in the string.

// #include <stdio.h>

// int main() {
//     FILE *fptr;
//     char str[100];
//     int count = 0;

//     fptr = fopen("Test.txt", "r");
//     if (fptr == NULL) {
//         printf("Error: Could not open Test.txt for reading.\n");
//         return 1;
//     }

//     fgets(str, 100, fptr);
//     fclose(fptr); 
    
//     for (int i = 0; str[i] != '\0'; i++) {
//         if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
//             str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
//             count++;
//         }
//     }

//     fptr = fopen("Test.txt", "w");
//     if (fptr == NULL) {
//         printf("Error: Could not open Test.txt for writing.\n");
//         return 1;
//     }

//     fprintf(fptr, "%d", count);
//     fclose(fptr);

//     return 0;
// }

// x-------------------------------------------------------x

// HOMEWORK 26 --> Set 10 : a
// Write a program to read a string from a file and output to the user.

// #include<stdio.h>

// int main() {
//     FILE *fptr;
//     fptr = fopen("Test.txt", "r");

//     if(fptr == NULL) {
//         printf("Error: Could not open file Test.txt\n");
//     }

//     char str[100];

//     if (fgets(str, sizeof(str), fptr) != NULL) {
//         printf("Content from file: %s", str);
//     } else {
//         printf("The file is empty or could not be read.\n");
//     }

//     fclose(fptr);
//     return 0;
// }

// x-------------------------------------------------------x
// CHAPTER 10 : File I/O
// x-------------------------------------------------------x

// HOMEWORK 25 --> Set 9 
// Make a system that can store information of all students, teachers and staff of your college in the form of all structures.
// You can also make this into a C project with other functionalities like cgpa, calculation of students, storing attendence etc.

// #include <stdio.h>

// struct student {
//     char name[50];
//     int roll_number;
//     float sem1_gpa;
//     float sem2_gpa;
//     int total_classes;
//     int attended_classes;
// };

// struct teacher {
//     char name[50];
//     char subject[50];
// };

// struct staff {
//     char name[50];
//     char role[50];
// };

// int main() {
//     struct teacher t;
//     struct staff st;

//     struct student s = {"Saanvi", 56, 9.5, 9.3, 100, 84};
//     float final_cgpa = (s.sem1_gpa + s.sem2_gpa) / 2.0;

//     float attendance_percentage = ((float)s.attended_classes / s.total_classes) * 100;

//     printf("STUDENT REPORT: \n");
//     printf("Name: %s\n", s.name);
//     printf("Final CGPA: %.2f\n", final_cgpa);
//     printf("Attendance: %.1f%%\n", attendance_percentage);

//     if (attendance_percentage >= 75.0) {
//         printf("Exam Status: Eligible\n");
//     } else {
//         printf("Exam Status: Detained (Attendance below 75%%)\n");
//     }

//     printf("\n--- ENTER TEACHER DETAILS ---\n");
//     printf("Name (No spaces): ");
//     scanf("%s", t.name);
//     printf("Subject: ");
//     scanf("%s", t.subject);


//     printf("\n--- ENTER STAFF DETAILS ---\n");
//     printf("Name (No spaces): ");
//     scanf("%s", st.name);
//     printf("Role: ");
//     scanf("%s", st.role);

//     printf("COLLEGE RECORDS: \n");
//     printf("Student: %s | Roll No: %d | Final CGPA: %.2f | Attendance: %.1f%%\n", s.name, s.roll_number, final_cgpa, attendance_percentage);
//     printf("Teacher: %s | Subject: %s\n", t.name, t.subject);
//     printf("Staff:   %s | Role: %s\n", st.name, st.role);

//     return 0;
// }

// x-------------------------------------------------------x
// CHAPTER 9 : STRUCTURES
// x-------------------------------------------------------x

// HOMEWORK 24 --> Set 8 : d
// Write a program to replace lowercase letters with uppercase and vice versa in a string

// #include<stdio.h>

// int main() {
//     char str[100];
//     printf("enter a string : ");
//     fgets(str, 100, stdin);

//     for(int i = 0; str[i] != '\0'; i++) {
//     if(str[i] >= 'a' && str[i] <= 'z') {
//         str[i] = str[i] - 32;
//     } else if(str[i] >= 'A' && str[i] <= 'Z') {
//          str[i] = str[i] + 32;
//     }
// }
    
//     printf("Swapped Case: %s\n", str);
//     return 0;
// }

// x-------------------------------------------------------x

// HOMEWORK 23 --> Set 8 : c
// Write a program to remove blank spaces in a string.

// #include<stdio.h>
// #include<string.h>

// int main() {
//     char input[1000];
//     char output[1000];
//     int i = 0;
//     int j = 0;
    
//     printf("Enter a string : ");
//     fgets(input, 100, stdin);

//     for(int i = 0; input[i] != '\0'; i++) {
//         if(input[i] != ' ') {
//             output[j++] = input[i]; 
//         }
//     }
//     output[j] = '\0';
    
//     printf("String after removing spaces: %s\n", output);

//     return 0;
// }

// x-------------------------------------------------------x

// HOMEWORK 22 --> Set 8 : b
// Write a program to print the highest frequency character in a string.

// #include<stdio.h>
// #include<string.h>

// char highestFrequencyChar(char str[]);

// int main() {
//   char str[100];
//   printf("Enter a string: ");
//   fgets(str, 100, stdin);

//   char highestFreqChar = highestFrequencyChar(str);
//   printf("The highest frequency character is: %c\n", highestFreqChar);
//   return 0;
// }

// char highestFrequencyChar(char str[]) {
//     int freq[256] ={0}; // 256 integers (represeting all possible ASCII characters), initializes every single spot to 0
//     int maxFreq = 0; // Initializes a tracker variable to hold the highest count found so far
//     char maxChar; // Stores the actual character that has that maximum frequency
    
//     for(int i = 0; i < strlen(str); i++) {
//         freq[str[i]]++;
//     }

//     for(int i = 0; i < 256; i++) { // Loop to look through all 256 possible character frequency slots
//         if(freq[i] > maxFreq) { // Checks if the frequency of the current character index i is larger than the highest frequency we've seen so far
//             maxFreq = freq[i]; // If it is larger, update maxFreq with this new, higher number
//             maxChar= i; // Save the index i (which maps back to the ASCII character) as the current winner
//         }
//     }

//     return maxChar;
// }

// x-------------------------------------------------------x

// HOMEWORK 21 --> Set 8 : a
// Write a program to convert all lowercase vowels to uppercase in a string.

// #include<stdio.h>
// #include<string.h>

// int main() {
//     char str[100];
//     printf("enter a string : ");
//     fgets(str, 100, stdin);

//     for(int i = 0; str[i] != '\0'; i++) {
//         if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
//             str[i] = str[i] - 32;
//         }
//     }

//     printf("Swapped Case: %s\n", str);
//     return 0;
// }

// x-------------------------------------------------------x
// CHAPTER 8 : STRINGS
// x-------------------------------------------------------x

// HOMEWORK 20 --> Set 7 : c
// Write a program to insert an element at the end of an array.

// #include<stdio.h>

// int main() {
//     int arr[10];
//     int n;
//     int i; 
//     int element;

//     printf("Enter elements of the array : \n");
//     scanf("%d", &n);
   
//     for(i = 0; i < n; i++) { 
//         scanf(" %d", &arr[i]);
//     }

//     printf("Element to be inserted : \n");
//     scanf("%d", &element);

//     arr[i] = element; 

//     printf("Array after insertion : \n");

//     for(i = 0; i < n + 1; i++) { 
//         printf("%d ", arr[i]); 
//     }

//     printf("\n");

//     return 0;
// }

// x-------------------------------------------------------x

// HOMEWORK 19 --> Set 7 : b
// Write a program to print the largest number in an array.

// #include<stdio.h>

// int printLargest(int arr[], int n);

// int main() {
//     int arr[] = {1, 2, 3, 4, 5, 6};
//     printLargest(arr, 6);
//     printf("Largest number is : %d", printLargest(arr, 6));
//     return 0;
// }

// int printLargest(int arr[], int n) {
//     int max = arr[0];
//     for(int i = 0; i < n; i++) {
//         if(arr[i] > max) {
//             max = arr[i];
//         }
//     }
//     return max;
// }

// x-------------------------------------------------------x

// HOMEWORK 18 --> Set 7 : a
// In an array of numbers, find how many times does a number 'x' occurs.

// #include<stdio.h>

// int countX(int arr[], int n);

// int main() {
//     int arr[] = {1, 8, 3, 6, 8, 8};
//     countX(arr, 6);
//     printf("%d", countX(arr, 6));
//     return 0;
// }

// int countX(int arr[], int n) {
//     int x = 8;
//     int count = 0;
//     for(int i = 0; i < n; i++) {
//         if(arr[i] == x) {
//             count++;
//         }
//     }
//     return count;
// }

// x-------------------------------------------------------x
// CHAPTER 7 : ARRAYS
// x-------------------------------------------------------x

// HOMEWORK 17 --> Set 6 : c
// Write a program in C to print all the letters in english alphabet using a pointer.

// #include<stdio.h>
// int main() {
//     char ch;
//     char *ptr = &ch;

//     for(*ptr = 'A'; *ptr <= 'Z'; (*ptr)++) {
//         printf("%c\n", *ptr);
//     }
//     return 0;
// }

// x-------------------------------------------------------x

// HOMEWORK 16 --> Set 6 : b 
// Write a program in C to print the elements of an array in reverse order.

// #include<stdio.h>

// void reverse(int arr[], int n);
// void printArr(int arr[], int n);

// int main() {
//     int arr[] = {1, 2, 3, 4, 5};
//     reverse(arr, 5);
//     printArr(arr, 5);

//     return 0;
// }

// void reverse(int arr[], int n) {
//     for(int i = 0; i < n/2; i++) {
//     int firstVal = arr[i];
//     int secondVal = arr[n - i - 1];
//     arr[i] = secondVal;
//     arr[n - i - 1] = firstVal;
//     }
// }

// void printArr(int arr[], int n) {
//     for(int i = 0; i < n; i++) {
//         printf("%d \t", arr[i]);
//     }
// }

// x-------------------------------------------------------x

// HOMEWORK 15 --> Set 6 : a
// Write a program in C to find the maximum number between two numbers using a pointer.

// #include<stdio.h>

// int main() {
//     float num1, num2;
//     float *ptr1 = &num1, *ptr2 = &num2;

//     printf("Enter first number : \n");

//     if (scanf("%f", &num1) != 1) {
//         printf("Error: That's not a valid number!\n");
//         return 0;
//     }

//     printf("Enter second number : \n");

//     if (scanf("%f", &num2) != 1) {
//         printf("Error: That's not a valid number!\n");
//         return 0;
//     }

//     if(*ptr1 > *ptr2) {
//         printf("Maximum number is : %f \n", *ptr1);
//     } else if (*ptr1 < *ptr2) {
//         printf("Maximum number is : %f \n", *ptr2);
//     } else {
//         printf("Both the numbers are equal.");
//     }

//     return 0;
// }

// x-------------------------------------------------------x
// CHAPTER 6 : POINTERS
// x-------------------------------------------------------x

// HOMEWORK 14 --> Set 5 : d
// Make your own pow function.

// #include<stdio.h>
// #include<math.h>

// void calcPow(float value);

// int main() {
//     float base;
//     printf("enter a base value : \n");
//     scanf("%f", &base);
//     int exp;
//     printf("enter an exponent value : \n");
//     scanf("%d", &exp);

//     printf("%f", pow(base,exp));

//     return 0;
// }
// void calcCube(float value){

// }

// x-------------------------------------------------------x

// HOMEWORK 13 --> Set 5 : c
// Write a function to print "Hot" or "Cold" depending on the temperature user enters.

// #include<stdio.h>

// void printHot();
// void printCold();

// int main() {
//     int n;
//     printf("enter a temperature : \n");
//     scanf("%d", &n);
//     if(n >= -100 && n <=0) {
//         printCold();
//     }
//     else if (n > 0 && n <= 100) {
//         printHot();
//     }
//     else {
//         printf("The entered value isn't vaild for this program. \n");
//     }
//     return 0;

// }

// void printHot() {
//     printf("Hot \n"); 
// }

// void printCold() {
//     printf("Cold \n");
// }

// x-------------------------------------------------------x

// HOMEWORK 12 --> Set 5 : b
// Write a function to find square root of a number.

// #include<stdio.h>
// #include<math.h>

// float findSquareRoot(float number) {
//     return sqrt(number); 
// }
// int main(){ 
//     float number; float result;
    
//     printf("enter a number : ");
//     scanf("%f", &number);

//     if (number < 0) { printf("Error! Square root such a number isn't valid. \n");
//     } else {
//         result = findSquareRoot(number);
//         printf("The square root of %f is %f\n", number, result);
//     }
        
//     return 0;
// }

// x-------------------------------------------------------x

// HOMEWORK 11 --> Set 5 : a
// Write a function to find sum of digits of a number.

// #include<stdio.h>

// int main() {
//     int number = 0;
//     int sum = 0;
//     int digit = 0;

//     printf("enter a number : ");
//     scanf("%d", &number);
    
//     while (number != 0) {
//         digit = number % 10;
//         sum += digit;
//         number = number / 10;
//     }

//     printf("sum : %d \n", sum);

//     return 0;
// }

// x-------------------------------------------------------x
// CHAPTER 5 : FUNCTIONS & RECURSION 
// x-------------------------------------------------------x

// HOMEWORK 10 --> Set 4 : c
// Write a program to print prime numbers in a range.


// #include<stdio.h>
// int main () {
//     int n1;
//     printf("enter a start number : \n");
//     scanf("%d", &n1);

//     int n2;
//     printf("enter an end number : \n");
//     scanf("%d", &n2);
    
//     for (int i = n1; i <= n2; i++) {
//         int isPrime = 1;
//         if (i <= 0) {
//             isPrime = 0;
//         } else {
//             for (int j = 2; j < i; j++) {
//                 if (i % j == 0) {
//                     isPrime = 0;
//                     break;
//                 } 
//             }

//         }
//         if (isPrime == 1) {
//             printf("%d \n", i);
//         }
//     }
//     return 0;
// }

// x-------------------------------------------------------x

// HOMEWORK 9 --> Set 4 : b
// Write a program to check if a number is prime or not.

// #include<stdio.h>
// int main() {
//     int n;
//     printf("enter a number : ");
//     scanf("%d", &n);

//     int isPrime = 1;        // 1 means true, 0 means false
//     if (n <= 1) {
//         isPrime = 0;
//     } else {
//         for (int i = 2; i < n; i++) {       // to check for factors from 2 upto n - 1
//             if (n % i == 0) {
//                 isPrime = 0;
//                 break;
//             }
//         }
//     }

//     if (isPrime == 1) {
//         printf("It is a prime number \n");
//     } else {
//         printf("It is not a prime number \n");
//     }
//         return 0;
//     }

// x-------------------------------------------------------x

// HOMEWORK 8 --> Set 4 : a
// Write a program to print the following pattern : (nested loops)
// *****
// *****
// *****
// *****

// #include<stdio.h>
// int main() {
//     for(int i = 1; i <= 4; i++) {
//        for (int j = 1; j <= 5; j++) {
//            printf("*");
//        }
//        printf("\n");
        
//     }
//     return 0;
// }

// x-------------------------------------------------------x
// CHAPTER 4 : LOOP CONTROL STATEMENTS
// x-------------------------------------------------------x

// HOMEWORK 7 --> Set 3 : b
// Write a program to check if a given number is a natural number or not. 

// #include<stdio.h>
// int main() {
//     int n;
//     printf("enter a number : ");
    
//     if (scanf("%d", &n) != 1) {
//         printf("Invalid input. Please enter a valid integer.\n");
//         return 0;
//     }
//     if(n >= 1) {
//         printf("natural number \n");
//     } else {
//         printf("not a natural number \n");
//     } 
//     return 0; 
// }

// x-------------------------------------------------------x

// HOMEWORK 6 --> Set 3 : a
// Write a program to check if a given number is Armstrong number or not. (Search what is an Armstrong number and then write the program)

// #include<stdio.h>
// int main() {
//     int n, originalN, remainder, result = 0;
//     printf("enter a number : ");
//     scanf("%d", &n);

//     originalN = n;

//     while (originalN != 0) {
//         remainder = originalN % 10;                    -->  // to get the last digit
//         result += remainder * remainder * remainder;   -->  // to calculate the cube of the last digit and add it to the result
//         originalN /= 10;                               -->  // to remove the last digit from the original number
//     }
//     if (result == n) {
//         printf("%d is an Armstrong number.\n", n);
//     } else {
//         printf("%d is not an Armstrong number.\n", n);
//     }
//     return 0;
// }

// x-------------------------------------------------------x
// CHAPTER 3 : CONDITIONAL STATEMENTS
// x-------------------------------------------------------x

// HOMEWORK 5 --> Set 2 : c
// Write a program to print the smallest number of two.

// #include <stdio.h>

// int main() {
//     float num1, num2;

//     printf("Enter the first number: ");
//     if (scanf("%f", &num1) != 1) {
//         printf("Error: That's not a valid number!\n");
//         return 1;
//     }

//     printf("Enter the second number: ");
//     if (scanf("%f", &num2) != 1) {
//         printf("Error: That's not a valid number!\n");
//         return 1; 
//     }

//     if (num1 < num2) {
//         printf("The smallest number is: %.2f\n", num1);
//     } 
//     else if (num2 < num1) {
//         printf("The smallest number is: %.2f\n", num2);
//     } 
//     else {
//         printf("Both numbers are equal.\n");
//     }

//     return 0;
// }

// x-------------------------------------------------------x


// HOMEWORK 4 --> Set 2 : b
// Write a program to check if given character is a digit or not.

// #include<stdio.h>
// int main() {
//     char c;
//     printf("enter a character");
//     scanf("%c", &c);
//     printf("%d", c >= '0' && c <= '9');

//     return 0;
// }

// x-------------------------------------------------------x

// HOMEWORK 3 --> Set 2 : a
// Write a program to print the average of 3 numbers. Take the numbers from the user.

// #include<stdio.h>
// int main() {
//     int a, b, c;
//     printf("enter a");
//     scanf("%d", &a);
//     printf("enter b");
//     scanf("%d", &b);
//     printf("enter c");
//     scanf("%d", &c);
//     printf("average of a, b and c is %d", (a+b+c)/3);
    
//     return 0;
// }

// x-------------------------------------------------------x
// CHAPTER 2 : INSTRUCTIONS & OPERATORS
// x-------------------------------------------------------x

// HOMEWORK 2 --> Set 1 : b
// Take a number(n) from user & output its cube(n*n*n).

// # include<stdio.h>
// int main() {
//     int n;
//     printf("enter n");
//     scanf("%d", &n);
//     printf("cube of n is %d", n*n*n);

//     return 0;
// }

// x-------------------------------------------------------x

// HOMEWORK 1 --> Set 1 : a
// Write a program to calculate perimeter of rectangle. Take sides, a & b, from the user.

// # include<stdio.h>
// int main() {
//     int a = 10, b = 20;
//     printf("enter a");
//     //scanf("%c", &a);
//     printf("enter b");
//     // scanf("%c", &b);
//     printf("perimeter of rectangle is %d", 2*(a+b));
//     printf("A+B");

//     return 0;
// }

// x-------------------------------------------------------x
// CHAPTER 1 : VARIABLES, DATA TYPES & INPUT/OUTPUT
// x-------------------------------------------------------x
