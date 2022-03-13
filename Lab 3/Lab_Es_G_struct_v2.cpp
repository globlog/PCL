#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>
#include <algorithm>
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


bool by_more_than_1_field( city_struct const &lhs, city_struct const &rhs )
{
    return lhs.area > rhs.area ||
           lhs.area == rhs.area && lhs.name <= rhs.name;
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

	std::sort( cities.begin(), cities.end(), by_more_than_1_field );

	long long int max_area = cities[0].area;
	for (long long int i = 0;i<m;++i){
		if (max_area == cities[i].area){
  			std::cout << cities[i].name << endl;
		} else {
			break;
		}
	}
	return 0;
}