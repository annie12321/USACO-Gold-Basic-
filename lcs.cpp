#include <iostream>
#include <string>
using namespace std;

int dp[1001][1001];

int main(int argc, const char * argv[]) {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    if (a[0] == b[0]) dp[0][0] = 1;
    for (int i = 1; i < b.length(); i ++) {
        dp[0][i] = dp[0][i-1];
        if (a[0] == b[i] and dp[0][i-1] == 0) dp[0][i] ++;
    }
    for (int i = 1; i < a.length(); i ++) {
        dp[i][0] = dp[i-1][0];
        if (a[i] == b[0] and dp[i-1][0] == 0) dp[i][0] ++;
    }
    for (int i = 1; i < a.length(); i ++) {
        for (int j = 1; j < b.length(); j ++) {
            if (a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[a.length() - 1][b.length() - 1];
    return 0;
}
