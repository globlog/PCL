#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>
#include <algorithm>


int main(){
    int n,D,M;
    std::cin >> n >> D >> M;
    std::set<int> visited[n+1];
    std::set<int> tovisit[n+1];
    int weights[n+1];
    std::set<int> changed;
    for(int i = 1; i<n+1; ++i){
        std::cin >> weights[i];
        visited[i].insert(weights[i]);
        changed.insert(i);
    }
    
    for(int i = 1; i<=n; ++i){
        for (int j = -D;j<=D;++j){
            if ((i+j)>=1 && (i+j)<= n && std::abs(weights[i+j]-weights[i]) <= M){
                tovisit[i].insert(i+j);
            }
        }
    }
    int pre = 0;
    while (changed.size()>0){
        std::set<int> new_changed;
        for (std::set<int>::iterator it = changed.begin() ; it!=changed.end();++it){
            for (std::set<int>::iterator at = tovisit[*it].begin() ; at!=tovisit[*it].end();++at){
                pre = visited[*at].size();
                visited[*at].insert(visited[*it].begin(),visited[*it].end() );
                if (visited[*at].size() > pre){
                    new_changed.insert(*at);
                }
            }
        }
        changed = new_changed;
    }
    unsigned int max_visits = (visited[1]).size();
    for (int i = 1;i<n+1;++i){
        max_visits = std::max<unsigned int>(max_visits,(visited[i]).size());
    }
    std::cout << max_visits << std::endl;


    return 0;
}