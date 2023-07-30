#include <stdio.h>

// Recursively find the greatest common divisor of a sequence of values  
int gcd(int a,int b){
    if (b==0){
        return a;
    } else {
        return gcd(b, a%b);
    }
}

int gcd_sequence(int a[],int n){
    if (n == 1){
        return a[0];
    } else {
        return gcd(a[n-1], gcd_sequence(a ,n-1));
    }
}

// Find the sum of a sequence of numbers recursively  

int sumR(int a[],int n){
    if (n == 1){
        return a[0];
    } else {
        return a[n-1] + sumR(a , n-1);
    }
}
//  Write a recursive function that determines whether an array is a palindrome, where the array and its size are given as parameters.
 
bool palindrome(int a[],int start, int end){
    if ( start >= end){
        return true;
    } else if ( a[start] != a[end]){
        return false;
    } else {
        return palindrome(a, start + 1, end - 1);
    }
} 

// Write a program in C to find the sum of digits of a number using recursion
int sum_of_digit(int a){
    if (a == 0){
        return 0;
    } else {
        return a % 10 + sum_of_digit(a/10);
    }
}

//Find recursive algorithm and function that sum up a series of N numbers.
int sumF(int a[],int n){
    int sum = 0;
    for (int i=0;i<n;i++){
        sum += a[i];
    }
    return sum;
}

//.Find recursive algorithm and function that look for minimal element in a series of N numbers.

int minF(int a[],int n){
    int min = a[0];
    for (int i=0;i<n;i++){
        if ( a[i] < min){
            min = a[i];
        }
    }
    return min;
}

int minR(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }
    int minimal_value = minR(arr, n - 1);
    return (arr[n - 1] < minimal_value) ? arr[n - 1] : minimal_value;

}
int main() {
    int number = 239;
    int sequence[] = {36, 24, 12, 4, 36};
    int length = sizeof(sequence) / sizeof(int);
    int start = 0, end = length - 1;
    printf("GCD: %d\n", gcd_sequence(sequence, length));
    printf("SumR: %d\n", sumR(sequence, length));
    printf("SumF: %d\n", sumF(sequence,length));
    if (palindrome(sequence, start, end)){
        printf("Palindrome\n");
    } else {
        printf("Not palindrome\n");
    }
    printf("Sum of digits of number: %d\n",sum_of_digit(number));
    printf("MinF: %d\n",minF(sequence,length));
    printf("MinR: %d\n",minR(sequence,length));
    return 0;
}