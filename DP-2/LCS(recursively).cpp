#include<iostream>
#include<cstring>
using namespace std;

int lcs(string s1,string s2,int i,int j)
{
    int ans,ans1,ans2;
    if(i==s1.size() || j==s2.size())
        return 0;
    if(s1[i]==s2[j])
        ans=1+lcs(s1,s2,i+1,j+1);
    else
        {
            ans1=lcs(s1,s2,i+1,j);
            ans2=lcs(s1,s2,i,j+1);
            ans=max(ans1,ans2);
        }
    return ans;
}
int main()
{
    string s1;
    string s2;
    cout<<"enter string 1"<<endl;
    cin >> s1;
    cout<<"enter string 2"<<endl;
    cin >> s2;
    int ans=lcs(s1,s2,0,0);
    cout<<"length of LCS = "<<ans;

}
