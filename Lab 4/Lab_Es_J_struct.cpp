#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <set>

struct neighbors {
	long long int nei_1 = -1LL;
	long long int nei_2 = -1LL;
};

struct city_struct {
	std::string name;
	long long int x;
	long long int y;
};

//per cercare l'orientamento uso la citta nell angolo che sicuro e parte della strada
bool orientation(const long long int & k,const std::vector< neighbors > & road,const std::vector< city_struct > & cities){
	city_struct next_city = cities[road[k].nei_1];
	city_struct prev_city = cities[road[k].nei_2];
	city_struct current_city = cities[k];
	long long int cross = (next_city.x-current_city.x)*(prev_city.y-current_city.y) - (next_city.y-current_city.y)*(prev_city.x-current_city.x);

	//std::cout << next_city.name << current_city.name << prev_city.name << cross;
	if (cross>0){
		return true;
	} else {
		return false;
	}
}

int main() {
	long long int m,n;
	std::cin >> m >> n;
	std::map< std::pair<long long int,long long int>,long long int > links;
	std::vector< city_struct > cities(m);
	std::string name;
	long long int x,y,z;
	//carico le citta
	for (long long int i = 0;i<m;++i){
		std::cin >> name >> x >> y;
		cities[i].name = name;
		cities[i].x = x;
		cities[i].y = y;
		}
	//trovo la citta nell'angolo in basso a destra
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
	 		std::swap(y,z);
	 	}
		//std::cout << x << y << z << endl;
	 	links[{x,y}]+=1LL;
		links[{x,z}]+=1LL;
		links[{y,z}]+=1LL; 
	 	}

	std::vector< neighbors > road(m);
	long long int start,first,end,prev;

	std::multiset<std::pair<std::string,long long int>> visited_cities;
	std::pair<std::string,long long int> visited_city;

	//colleziono i link delle citta che hanno solo 1 territorio comune e credo una lista di start->end
	for (std::map<std::pair<long long int,long long int>,long long int>::iterator it = links.begin();it!=links.end(); ++it){
	 	if(it->second==1LL){
			start = std::get<0>(it->first);
			end = std::get<1>(it->first);
			//std::cout << start+1 << " " <<end+1;
			if (road[start].nei_1==-1LL) {
				road[start].nei_1 = end;
			} else {
				road[start].nei_2 = end;
			}
			if (road[end].nei_1==-1LL) {
				road[end].nei_1 = start;
			} else {
				road[end].nei_2 = start;
			}
			visited_cities.insert({cities[end].name,end});
			visited_cities.insert({cities[start].name,start});
			
		}
	
	 		//std::cout << "(" << i/m+1 << "," << i%m+1<< ")" << endl;
	}
	bool ori = orientation(corner_city_index,road,cities);
	
	//prendo la prima citta in ordine alfabetico e poi giro orario o antiorario a dipendenza del cross
	first = std::get<1>(*(visited_cities.begin()));
	start = corner_city_index;
	if (ori){
	end = road[start].nei_1;
	} else {
	end = road[start].nei_2;
	}
	while (end!=first){
		prev = start;
		start = end;
		end = road[end].nei_1+road[end].nei_2-prev;
	}
	prev = start;
	start = end;
	end = road[end].nei_1+road[end].nei_2-prev;

	while (end!=first){
		prev = start;
		std::cout << cities[start].name << std::endl;
		start = end;
		end = road[end].nei_1+road[end].nei_2-prev;
	}
	std::cout << cities[start].name << std::endl;	
	
	return 0;
}