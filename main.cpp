/* 
 * File:   main.cpp
 * Author: user
 *
 * Created on January 14, 2014, 4:35 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <sys/time.h>

using namespace std;
long int fibonacci(long int number);
long int fibonacciRecursive(long int number);
void fiboTesting();
int binarySearch(int array[], int size, int elementToSearch);
int normalSearch(int array[], int size, int elementToSearch);
/*
 * 
 */
int main(int argc, char** argv) {
    
    int size = 10, resultPosition, elementToSearch = 16;
    int array[size];
    
    array[0] = 10;
    array[1] = 11;
    array[2] = 12;
    array[3] = 13;
    array[4] = 14;
    array[5] = 15;
    array[6] = 16;
    array[7] = 17;
    array[8] = 18;
    array[9] = 19;
    
    resultPosition = normalSearch(array, size, elementToSearch);
    
    printf("Position of element %d is: %d\n\n", elementToSearch, resultPosition);

    return 0;
}

/*linear search*/
int normalSearch(int array[], int size, int elementToSearch){
    int position = 0;
    while(position < size){
        if( elementToSearch == array[position]){
            return position;
        }else{
            position++;
        }
    }//end while
    return -1;
}


/*binary Search over an array*/
int binarySearch(int array[], int size, int elementToSearch){
    int lower = 0, upper = size - 1, middle;
    
    while(lower <= upper){
        middle = (upper + lower) / 2;
        
        if(elementToSearch < array[middle]){
            upper = middle - 1;
        }else if(elementToSearch == array[middle]){
            return middle;
        }else{
            lower = middle + 1;
        }
    }//end while
    return -1;
}


/*fibonacci's testing*/
void fiboTesting(){
    long int number = 40, result = 0, resultRecur;
    double elapsedTime, elapsedTimeRecur;
    
    /****************************************/
    timeval initTime, finishTime, initTimeRecur, finishTimeRecur;
    gettimeofday(&initTime, NULL);
    result = fibonacci(number);                                 //proof that this is lineal
    gettimeofday(&finishTime, NULL);
    
    gettimeofday(&initTimeRecur, NULL);
    resultRecur = fibonacciRecursive(number);
    gettimeofday(&finishTimeRecur, NULL);
    
    elapsedTime = (finishTime.tv_sec - initTime.tv_sec) * 1000.0;
    elapsedTime += (finishTime.tv_usec - initTime.tv_usec) / 1000.0;
    
    elapsedTimeRecur = (finishTimeRecur.tv_sec - initTimeRecur.tv_sec) * 1000.0;
    elapsedTimeRecur += (finishTimeRecur.tv_usec - initTimeRecur.tv_usec) / 1000.0;
    
    printf("Fibonacci(%ld): %ld\n",number, result);
    printf("Algorithm's duration: %lf ms\n", elapsedTime);
    printf("Algorithm's duration(Recursive): %lf ms\n\n", elapsedTimeRecur);
}


/*calculates fibonacci number*/
long int fibonacci(long int number){
    //variables
    long int accumulator = 1, add = 0, previousNumber = 0;
    
    for(int k = 1; k <= number; k++ ){
        add = previousNumber + accumulator;
        previousNumber = accumulator;
        accumulator = add;
    }
    
    return accumulator;
}


/*fibonacci's implementation but recursively*/
long int fibonacciRecursive(long int number){
    if(number < 2){
        return number;
    }else{
        return fibonacciRecursive(number - 1) + fibonacciRecursive(number - 2);
    }
}

