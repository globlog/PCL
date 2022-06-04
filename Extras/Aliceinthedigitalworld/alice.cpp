#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>

int main(){
    int t;
    std::cin >> t;
    int n,m;
    for (int i = 0;i<t;++i){
        std::cin >> n >> m;
        int weights[n];
        for(int j = 0;j<n;++j){
            std::cin >> weights[j];
        }
    
        long unsigned int current_max = 0;
        long unsigned int first = 0;
        long unsigned int second = 0;
        bool two = false;
        for(int j = 0;j<n;++j){
            if (weights[j]>m){
                second += weights[j];
            } else if (weights[j]==m){
                current_max = std::max(current_max,first+second + (two ? m : 0));
                first = second;
                second = 0;
                two = true;
            } else {
                if (two){
                current_max = std::max(current_max,first+second+ (two ? m : 0));
                }
                first = 0;
                second = 0;
                two = false;
            }
        }
        if (two){
                current_max = std::max(current_max,first+second+ (two ? m : 0));
        }
        std:: cout << current_max << std::endl;
    }
    return 0;
}