#include <cstdio>
#include <iostream>
using namespace std;
int arr[100005],tmp[100005];
int n, ans;
int mergsort(int l, int r)
{
    if (l == r)
		return 0;
	int ans = 0;
    int mid = (l + r) / 2;
    
    //Split to two part and sum up the numbers
    ans = ans + mergsort(l, mid) + mergsort(mid + 1,r);
    
	int i = l, j = mid + 1, k = l;
	// Combine two sorted sub-array and merge
	while (i <= mid && j <= r){
		if (arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else {
			tmp[k++] = arr[j++];
			// add the inversed numbers
			ans += mid - i + 1;
		}		
	}
	
	while (i <= mid) 
		tmp[k++] = arr[i++];
	while (j <= r) 
		tmp[k++] = arr[j++];
	
	// Get the sorted array
	for (i = l; i <= r; i++)
		arr[i] = tmp[i];
	return ans;
}
int main()
{
	//Read the data 
    cin >> n;
    for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	//Get the result	
    int ans = mergsort(1 , n);
    
	//Output
	cout << ans;
    return 0;
}
