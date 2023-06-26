#include <iostream>
#include <string>
#include <map>
using namespace std;
const int MAXN = 105;
string names[MAXN * 2][MAXN];
string idx2men[MAXN], idx2women[MAXN];
int womenOrder[MAXN][MAXN];
map<string, int> men2idx;
map<string, int> women2idx;
int match[MAXN], color[MAXN], proposed[MAXN], women_select[MAXN], q[MAXN];
int n;
int main(){
	// Input the data
	cin >> n;
	for (int i = 1;  i <= 2 * n; i++)
		for (int j = 0; j <= n; j++)
			cin >> names[i][j];
	
	// Relate the men name to the index
	for (int i = 1; i <= n; i++){
		idx2men[i] = names[i][0];
		men2idx[names[i][0]] = i;
	}
		
	// Relate the women name to the index
	for (int i = n + 1; i <= 2 * n; i++){
		idx2women[i - n] = names[i][0];
		women2idx[names[i][0]] = i - n;
	}
		
	// Record the order of the favourate men for each women
	for (int i = n + 1;  i <= 2 * n; i++)
		for (int j = 1; j <= n; j++){
			int idx = men2idx[names[i][j]];
			womenOrder[i - n][idx] = j;
		}
		
	// Initialize all the men. color = 0 means no mathcing, color = 1 means there is a match
	// proposed value means the man propose to the women in order
	for (int i = 1; i <= n; i++){
		color[i] = 0;
		proposed[i] = 1;
		women_select[i] = 0;
	}
	
	// Continue the process unitl matching all the pairs
	int unmatched = n;
	while (unmatched > 0){
		// Push all the unmatched men into the queue q
		int m = 0;
		for (int i = 1; i <= n; i++)
			if (color[i] == 0){
				m = m + 1;
				q[m] = i;
			}
		unmatched = m;
		for (int i = 1; i <= m; i++){
			int idx = q[i];
			while (proposed[idx] <= n){
				string women_name = names[idx][proposed[idx]];
//				cout << idx << " " << women_name << endl;
				int women_idx = women2idx[women_name];
				// If women has no follower, she will agree.
				if (women_select[women_idx] == 0){
					women_select[women_idx] = idx;
					color[idx] = 1;
					break;
				} else {
					// If women has followers, she will select the better.
					int component_idx = women_select[women_idx];
					
					// If the former is better, the current man will propose to the next women
					if (womenOrder[women_idx][component_idx] < womenOrder[women_idx][idx])
						proposed[idx] += 1;
					else { // if the current is better, the former man will color 0 and propose to the next women
						proposed[component_idx] += 1;
						color[component_idx] = 0;
						
						color[idx] = 1;
						women_select[women_idx] = idx;
						break;
					}
				}
					
			}
		}
		
	}
	// Output the result
	for (int i = 1; i <= n; i++){
		string men_name = idx2men[i];
		string women_name = names[i][proposed[i]];
		cout << men_name << " " << women_name << endl;
	}	
	
}
