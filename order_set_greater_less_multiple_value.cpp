#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
///https://cses.fi/problemset/result/14172554/
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; ///greater hisabe kaj korbe 1 2 2 3 . 2 er jonno answer 1 karon shudhu 3
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds1;  ///lest than
int main() {
	pbds A;
	pbds1 A1;
	long long n,k;
	cin>>n>>k;
	long long arr[n+10],ans=0;
	for(int i=1;i<=n;i++)
    {
        long long x;
        cin>>x;
        A.insert(x);
        A1.insert(x);
        arr[i]=x;
        long long val=A.order_of_key(x);
        ans+=val;
        if(i>k)
        {

           val=A1.order_of_key(arr[i-k]);
           ans-=val;
           cout<<ans<<" ";
           A.erase(A.upper_bound(arr[i-k]));  ///specific element delete
           A1.erase(A1.upper_bound(arr[i-k]));
        }
        else if(i==k)
        {
            cout<<ans<<" ";
        }


    }
    cout<<endl;
    return 0;

}
