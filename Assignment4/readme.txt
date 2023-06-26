# Description
##Divide and Conquer problem

An implementation of the Sort and Count algorithm using the merge sort algorithm. It counts the number of inversions in an array, where an inversion occurs when two elements in the array are out of order.

The algorithm works as follows:

1. Divide the array into two halves recursively until each subarray contains only one element.
2. Merge the two sorted subarrays and count the inversions that occur across the two halves.
3. Repeat the merging and counting process until the entire array is sorted.
4. Return the total count of inversions found.

