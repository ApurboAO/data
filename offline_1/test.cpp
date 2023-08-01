#include<bits/stdc++.h>
using namespace std;
#define mod static_cast<int>(1e8 + 7)

// #define int long long
void solve(){
    int *ptr=(int *)malloc(sizeof(int)*5);
    for(int i=0;i<5;i++){
        ptr[i]=i;
    }
    for(int i=0;i<5;i++){
        cout<<ptr[i];
    }
    cout<<endl;
    ptr=(int *)realloc(ptr,sizeof(int)*10);
    for(int i=5;i<10;i++){
        ptr[i]=i;
    }
    for(int i=0;i<10;i++){
        cout<<ptr[i]<<endl;
    }


}
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
         solve ();
    }
return 0;
}