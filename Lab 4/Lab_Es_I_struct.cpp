#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>
using namespace std;

struct forw_list {
	long long int next = -1LL;
	long long int prev = -1LL;
};

struct city_struct {
	string name;
	long long int x;
	long long int y;
};


bool orientation(const long long int & k,const std::vector< forw_list > & road,const std::vector< city_struct > & cities){
	city_struct next_city = cities[road[k].next];
	city_struct prev_city = cities[road[k].prev];
	city_struct current_city = cities[k];
	long long int cross = (current_city.x-next_city.x)*(current_city.y-prev_city.y) - (current_city.y-next_city.y)*(current_city.x-prev_city.x);
	if (cross>0){
		return true;
	} else {
		return false;
	}
}

int main() {
	long long int m,n;
	std::cin >> m >> n;
	std::vector< long long int > links(m*m,0LL);
	std::vector< city_struct > cities(m);
	string name;
	long long int x,y,z;
	
	for (long long int i = 0;i<m;++i){
		std::cin >> name >> x >> y;
		cities[i].name = name;
		cities[i].x = x;
		cities[i].y = y;
		}
	city_struct corner_city = cities[0];
	long long int corner_city_index = 0;
	for (long long int i = 0;i<m;++i){
		if(cities[i].y < corner_city.y || (cities[i].y == corner_city.y && cities[i].x>corner_city.x)){
			corner_city = cities[i];
			corner_city_index =i;
		}
	}
	//std::cout << "grandezza" << cities.size() << endl;
	 for (long long int j = 0;j<n;++j){
	 	std::cin >> x >> y >> z;
	 	x--;
	 	y--;
	 	z--;
	 	if (x>=y){
	 		std::swap(x,y);
	 	}
	 	if (x>=z){
	 		std::swap(x,z);
	 	}
	 	if (y>=z){
	 		std::swap(y,z)
	 	;}
		//std::cout << x << y << z << endl;
	 	links[m*x+y]+=1;
	 	links[m*x+z]+=1;
	 	links[m*y+z]+=1;
	 	}

	std::vector< forw_list > road(m);
	long long int start,first,end;

	std::multiset<tuple<string,long long int>> visited_cities;
	tuple<string,long long int> visited_city;
	for (long long int i = 0;i<m*m;++i){
	 	if(links[i]==1){
			start = i/m;
			end = i%m;
			if(road[start].next==-1){
				road[start].next=end;
				road[end].prev=start;
				visited_city = make_tuple(cities[start].name,start);
				visited_cities.insert(visited_city);
			} else {
				road[end].next=start;
				road[start].prev=end;
				visited_city = make_tuple(cities[end].name,end);
				visited_cities.insert(visited_city);
			}
		}
	 		//std::cout << "(" << i/m+1 << "," << i%m+1<< ")" << endl;
	}
	bool ori = orientation(corner_city_index,road,cities);
	



	first = get<1>(*(visited_cities.begin()));
	start = first;
	if (ori){
	while (road[start].next!=first){
		std::cout << cities[start].name << endl;
		start = road[start].next;
	}
	std::cout << cities[start].name << endl;
	} else {
	while (road[start].prev!=first){
		std::cout << cities[start].name << endl;
		start = road[start].prev;
	}
	std::cout << cities[start].name << endl;	
	}
	return 0;
}