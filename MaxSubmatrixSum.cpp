/*
 * 
 * 1. Output observed:
 * 
 * 		Answer from DnQ Algorithm = 281863373004038
 *		Average time for DnQ Algorithm = 72.6093840000
 *
 *		Answer from Optimal Algorithm = 281863373004038
 *		Average time for Optimal algorithm = 15.2591290000
 *
 * 2. Time complexity:
 * 		
 * 		Divide and Conquer Algorithm = O((n^3)log(n))
 * 		Optimal Algorithm = O(n^3)
 * 
 */

#include <bits/stdc++.h>
#define ll long long int
#define fr(i,n) for(i=0;i<n;i++)
#define rng(i,a,b) for(i=a;i<b;i++)
#define T long long int T;cin>>T;while(T--)
#define ain(a,n) for(int zzz=0;zzz<n;zzz++){cin>>a[zzz];}
#define aout(a,n) for(int zzz=0;zzz<n;zzz++){cout<<a[zzz]<<" ";}cout<<"\n";
#define All(v) v.begin(),v.end()
#define dbg(v) cerr<<">-- "<<#v<<" = "<<v<<"\n";
#define PB push_back
#define MP make_pair
#define N "\n"
const int inf = ((int)1e9+3);
const int M97 = ((int)1e9+7);
using namespace std;

typedef vector<int> Vi;
typedef pair<int,int> Pii;

ll Max_Subarray_Sum_linear(vector<ll> &a)
{
	ll ans = 0;
	ll current_sum = 0;
	int i;
	fr(i,(int)a.size())
	{
		current_sum += a[i];
		current_sum = max(current_sum, (ll)0);
		ans = max(ans, current_sum);
	}
	return ans;
}

ll Max_Subarray_Sum_DnQ(vector<ll> &a, int l, int r)
{
	if(r-l <= 1)
		return max((ll)0, a[l]);
		
	int mid = l+((r-l)/2);
	
	ll left_sum = Max_Subarray_Sum_DnQ(a,l,mid);
	ll right_sum = Max_Subarray_Sum_DnQ(a,mid,r);
	
	ll cross_left = 0, cross_right = 0, sum = 0;
	
	int i;
	for(i = mid-1; i >= l; i--)
	{
		sum += a[i];
		cross_left = max(cross_left, sum);
	}
	
	sum = 0;
	for(i = mid; i < r; i++)
	{
		sum += a[i];
		cross_right = max(cross_right, sum);
	}
	
	return max({left_sum, right_sum, (cross_left + cross_right)});
}

ll Max_Submatrix_Sum(vector<vector<int>> a, int choice)
{
	int i,j,k, n = a.size(), m = a[0].size();
	vector<ll> prefix_sum[n];
	vector<ll> row_sum(n);
	
	for(i = 0; i < n; i++)
		prefix_sum[i].push_back(0);
		
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			prefix_sum[j].emplace_back((prefix_sum[j].back() + a[j][i]));
	
	ll ans = 0;
	for(i = 0; i < m; i++)
		for(j = i; j < m; j++)
		{
			for(k = 0; k < n; k++)
				row_sum[k] = prefix_sum[k][j+1] - prefix_sum[k][i];
			
			if(choice == 1)
				ans = max(ans, Max_Subarray_Sum_linear(row_sum));
			else if(choice == 2)
				ans = max(ans, Max_Subarray_Sum_DnQ(row_sum,0,n));
		}
	
	return ans;
}

ll i,j,k;

void solve()
{
	int t;
    t = 1;                           
    
    cout << setprecision(10) << fixed;
    int n = 1e3;
    // cin >> n;
    srand(time(0));
    vector<vector<int>> v(n);
    
    fr(i,n)
        fr(j,n)
        {
			int p = rand()%inf;
			if(rand()%5 == 0) p *= -1;
			v[i].push_back(p);
		}
    
    double total = 0;
    fr(i,t)
    {   
        clock_t start, end; 
        start = clock();
        
        cout << "Answer from DnQ Algorithm = " << Max_Submatrix_Sum(v,2) << N;
        
        end = clock(); 
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
        total += time_taken;
    }
    
    double times = t;
    
    cout<< "Average time for DnQ Algorithm = " << (double)(total / times) << N << N;

	total = 0;
	fr(i,t)
	{
		clock_t start, end; 
        start = clock();
        
        cout << "Answer from Optimal Algorithm = " << Max_Submatrix_Sum(v,1) << N;
        
        end = clock(); 
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
        total += time_taken;
	}
	
	times = t;
	
	cout<< "Average time for Optimal algorithm = " << (double)(total / times) << N << N;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	solve();
    
    return 0;
}
