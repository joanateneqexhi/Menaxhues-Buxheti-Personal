#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    int n;
    int score;
    cin >> t;
    vector<int> dp;
    int alt;
    vector<vector<int>> ans (t, vector<int>());
    for(int i = 0; i < t; i++){
        cin >> n;
        ans[i].resize(n);
        dp.resize(n, 0);
        for(int j = 0; j < n; j++){
            cin >> ans[i][j];
        }
        bool started;
        for(int j = 0; j < n; j++){
            if(!started){
                if(ans[i][j] == 1 || ans[i][j] == -1){
                    started = ture;
                    dp[j] = 1;
                }
            }
            if(started){
                if(ans[i][j] == 0){
                    if(alt > 0){
                        alt++
                    }
                    dp[j] = max(dp[j-1] + 1, alt)
                }
                if(ans[i][j] == 1){
                    
                }
            }
        }
        }
    }
    for(int i = 0; i < t; i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}