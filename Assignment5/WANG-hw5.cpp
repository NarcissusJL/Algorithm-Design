/*
Assignment 5 Problem 4
Zuoyu Wang
3/24/2023

*/
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN = 10005;
// NY and SF array record the cost in each month of operating in NY and SF
int NY[MAXN], SF[MAXN];
// f[i] record the minimum cost at month i staying NY(0) or SF(1)
// Sol[i] reocrd which location in month i-1 comes from
int f[MAXN][2], sol[MAXN][2];
// City[i] record the optimal result.
int city[MAXN];
int n, cost;

//Translate the index to city name
string trans(int x){
	if (x == 0)
		return "NY";
	else
		return "SF";
}
// The dynamic programming complexity is O(n).
int main(){
	cin >> n;
	cin >> cost;
	for (int i = 1; i <= n; i++)
		cin >> NY[i];
	for (int i = 1; i <= n; i++)
		cin >> SF[i];

	// The first month initialization
	f[1][0] = NY[1];
	f[1][1] = SF[1];
	// Dynamic for the following days
	for (int i = 2; i <= n; i++){
		// Check i-1 month come from NY or SF, then stay at NY
		if (f[i - 1][0] < f[i - 1][1] + cost){
			f[i][0] = f[i - 1][0];
			sol[i][0] = 0;
		} else {
			f[i][0] = f[i - 1][1] + cost; // Need the moving cost
			sol[i][0] = 1;
		}
		f[i][0] += NY[i]; // Add operation cost in the city NY

		// Check i-1 month come from NY or SF, then stay at SF
		if (f[i - 1][1] < f[i - 1][0] + cost){
			f[i][1] = f[i - 1][1];
			sol[i][1] = 1;
		} else {
			f[i][1] = f[i - 1][0] + cost; // Need the moving cost
			sol[i][1] = 0;
		}
		f[i][1] += SF[i]; // Add operation cost in the city SF
	}

	// Judge the last city to stay
	if (f[n][0] < f[n][1])
		city[n] = 0;
	else
		city[n] = 1;
	// Backtrack to get the results
	for (int i = n - 1; i >= 1; i--)
		city[i] = sol[i + 1][city[i + 1]];

	for (int i = 1; i < n; i++)
		cout << trans(city[i]) << " ";
	cout << trans(city[n]) << endl;
}
