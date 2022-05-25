#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

int move(long unsigned int & ll,int startpoint,std::multimap<int,std::pair<long unsigned int,bool>>::iterator ut,std::multimap<int,std::pair<long unsigned int,bool>> * railroads){ 
    std::multimap<int,std::pair<long unsigned int,bool>>::iterator it,at;
    int current = startpoint;
    int next = ut->first;
    (ut->second).second = false;
    while (railroads[next].size() == 2 && next != startpoint){
        it = railroads[next].begin();
        at = ++(railroads[next].begin());
        (it->second).second = false;
        (at->second).second = false;
        if (it->first == current){
            ll+=(it->second).first;
            current = next;
            next = at->first;
        } else {
            ll+=(at->second).first;
            current = next;
            next = it->first;
        }
    }
    it = railroads[next].find(current);
    while((it->second).second == false){
            ++it;
        }
    ll+=(it->second).first;
    (it->second).second = false;
    return next;
}


int main() {
	int T,N,M,next,current;
	int a,b;
	long unsigned int l,ll;
	std::cin >> T;
	int startpoint,endpoint;
	std::multimap<int,std::pair<long unsigned int,bool>>::iterator it,at,ut;
	for (int i = 0;i<T;++i){
        std::multiset<std::tuple<int,int,long unsigned int>> paths;
		std::cin >> N >> M;
		std::multimap<int,std::pair<long unsigned int,bool>> railroads[2*N+1];
		for (int j =0;j<M;++j){
			std::cin >> a >> b >> l;
            if (a!=b){
			railroads[a].insert({b,{l,true}});
			railroads[b].insert({a,{l,true}});
            }
            else {
            railroads[a].insert({N+a,{l,true}});
			railroads[N+a].insert({a,{l,true}});
            railroads[N+a].insert({N+a,{0,true}});
            railroads[a].insert({N+a,{0,true}});
            }
		}
		for(int i =1;i<N+1;++i){
            ll = 0;
            startpoint = i;

            if (railroads[i].size() == 2){
                ut = railroads[i].begin();
                if ((ut->second).second){
                    ll = 0;
                    next = move(ll,startpoint,ut,railroads);
                    a = startpoint;
                    b = next;
                    if (next != startpoint){
                        ++ut;
                        next = move(ll,startpoint,ut,railroads);
                    }
                    a = next;
                    paths.insert(std::make_tuple(std::min(a,b),std::max(a,b),ll));
                } 
            } else {
                for (ut = railroads[i].begin(); ut != railroads[i].end() ;ut++){
                    if ((ut->second).second){
                        ll = 0;
                        next =  move(ll,startpoint,ut,railroads);
                        paths.insert(std::make_tuple(std::min(i,next),std::max(i,next),ll));
                    }
                }
            }   
		}
        std::cout << paths.size() << std::endl;
        for (std::multiset<std::tuple<int,int,long unsigned int>>::iterator it = paths.begin();it !=paths.end();++it){
            std::cout << std::get<0>(*it) << " " << std::get<1>(*it) << " " << std::get<2>(*it) << std::endl; 
        }
	}
	
	return 0;
}