# Description
##Dynamic Programming

An implementation of the DP problem.Given the desired number of cola bottles and the available denominations of coins (1, 5, and 10), the algorithm calculates the minimum number of steps required to obtain the desired number of bottles.


#The algorithm works as follows:

Input: The user provides the number of test cases (n). For each test case, the user provides the desired number of cola bottles (c) and the number of available coins for each denomination: 1-coin (x), 5-coin (y), and 10-coin (z).

Dynamic Programming: The algorithm uses a dynamic programming approach to calculate the minimum number of steps required. It defines a recursive function dfs that takes the remaining number of cola bottles to be obtained (num) and the counts of available coins for each denomination (n1, n2, n3) as parameters. The function calculates the optimal transition by considering different cases and recursively calling itself with updated parameters. It keeps track of the minimum number of steps (sum) and memoizes the results using a dynamic programming array (dp) to avoid redundant calculations.

Output: For each test case, the algorithm calls the dfs function with the provided inputs and outputs the minimum number of steps required to obtain the desired number of cola bottles.