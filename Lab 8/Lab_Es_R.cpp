#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

int main() {
	int T,N,M;
	int a,b;
	long unsigned int l,ll;
	std::cin >> T;
	int startpoint,endpoint;
	std::map<int,long unsigned int>::iterator it,at;
	for (int i = 0;i<T;++i){
		std::cin >> N >> M;
		std::map<int,long unsigned int> railroads[N+1];
		for (int j =0;j<M;++j){
			std::cin >> a >> b >> l;
			railroads[a].insert({b,l});
			railroads[b].insert({a,l});
		}
		for(int i =1;i<N+1;++i){
			if (railroads[i].size()==2){
				ll = 0;
				it = railroads[i].begin();
				ll += it->second;
				startpoint = it->first; 
				++it;
				ll+= it->second;
				endpoint = it->first;
				at = railroads[startpoint].find(endpoint);
				if (at!=railroads[startpoint].end()){
					at->second = ll;
				} else {
					railroads[startpoint].insert({endpoint,ll});
				}
				//at = railroads[startpoint].find(i);
  				//railroads[startpoint].erase(at);  

				at = railroads[endpoint].find(startpoint);
				if (at!=railroads[endpoint].end()){
					at->second = ll;
				} else {
					railroads[endpoint].insert({startpoint,ll});
				}
				//at = railroads[endpoint].find(i);
  				//railroads[endpoint].erase(at);
				
				
			}
		}
		for(int i =1;i<N+1;++i){
			for (it = railroads[i].begin(); it != railroads[i].end() ;it++){
				std::cout << i << " " << it->first << " " << it->second << std::endl; 
			}
			
		}
	}
	
	return 0;
}