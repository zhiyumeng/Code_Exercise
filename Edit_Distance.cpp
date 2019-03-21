#include <iostream>
#include <string>
using namespace std;

int edit_distance(string str1,string str2){
    int const m = str1.length();
    int const  n = str2.length();
    int **dp = new int *[m+1];
    for(int i=0;i<m+1;i++) dp[i] = new int [n+1];

    for(int i=0;i<=m;i++) dp[i][0] = i;
    for(int j=0;j<=n;j++) dp[0][j] = j;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = min(dp[i-1][j] +1,dp[i][j-1]+1);
            int temp_dis = (str1[i-1]==str2[j-1]?0:1);
            dp[i][j] = min(dp[i][j],dp[i-1][j-1]+temp_dis);
           // cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<temp_dis<<" "<<str1[i-1]<<" "<<str2[j-1]<<endl;
        }
    }

    for(int i=0;i<m;i++) delete [] dp[i];
    delete  [] dp;

    return dp[m][n];

}
int main() {
    cout<<edit_distance("aac","bbb")<<endl;
    cout<<edit_distance("aac","abc")<<endl;
    return 0;
}