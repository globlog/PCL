#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>
using namespace std;


struct city_struct {
	string name;
	long long int x;
	long long int y;
	long long int area = 0LL;
};

long long int coord_to_area(city_struct cityA,city_struct cityB,city_struct cityC){
	long long int area ;
	area =  cityA.x*(cityB.y-cityC.y);
	area +=  cityB.x*(cityC.y-cityA.y);
	area +=  cityC.x*(cityA.y-cityB.y);

	return std::llabs(area) ;
}


int main() {
	long long int m,n;
	std::cin >> m >> n;
	std::vector< city_struct > cities(m);
	string name;
	long long int x,y,z;

	for (long long int i = 0;i<m;++i){
		std::cin >> name >> x >> y;
		cities[i].name = name;
		cities[i].x = x;
		cities[i].y = y;
		}

	//std::cout << "grandezza" << cities.size() << endl;
	long long int area;
	for (long long int j = 0;j<n;++j){
		std::cin >> x >> y >> z;
		x--;
		y--;
		z--;
		area = coord_to_area(cities[x],cities[y],cities[z]);
		cities[x].area += area;
		cities[y].area += area;
		cities[z].area += area;
		}

	std::multiset< tuple<long long int,string> > top_cities;
	tuple<long long int,string> top_city;
	for (long long int k = 0;k<m;++k){
		top_city = make_tuple( -cities[k].area , cities[k].name );
		top_cities.insert(top_city);
	}
	long long int max_area = get<0>(*top_cities.begin());
	for(std::multiset< tuple<long long int,string>>::iterator it = top_cities.begin(); it != top_cities.end(); ++it) {
		if (max_area == get<0>(*it)){
  			std::cout << get<1>(*it) << endl;
		} else {
			break;
		}
	}
	return 0;
}