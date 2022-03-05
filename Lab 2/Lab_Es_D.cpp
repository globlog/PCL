#include <iostream>
#include <string>
#include <set>
#include <tuple>
using namespace std;

int main() {
	int N;
	std::cin >> N;
	std::set< tuple<double,string> > automobili;
	string person,car;
	double consumption;
	double gallon = 3.785;
	double mile = 1.609;
	tuple<double,string> nomecar;
	for (int i = 0;i<N;++i){
		std::cin >> person >> car >> consumption;
		if (person == "Bob"){
			consumption=gallon*100.0/(consumption * mile);
		}
	nomecar = make_tuple(consumption,car);
	automobili.insert(nomecar);
	}
	for(std::set< tuple<double,string>>::iterator it = automobili.begin(); it != automobili.end(); ++it) {
  	std::cout << get<1>(*it) << endl;
	}
return 0;
}