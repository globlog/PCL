#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> split(const string& str)
{
    vector<char> result;
    // For each character in the string
    for (char ch : str)
    {
        result.push_back(ch);
    }
	return result;
}

int main() {
	int N;
	std::cin >> N;
	string sigla, frase;
	std::getline(std::cin,sigla);
	for (int i = 0; i<N; ++i){
		std::getline(std::cin,sigla);
		std::getline(std::cin,frase);
		vector<char> split_sigla = split(sigla);
		vector<char> split_frase = split(frase);
		int j=0;
		int k=0;
		while(j<3 and k<split_frase.size() ){
			if (split_sigla[j]==split_frase[k]){
				j=j+1;
			}
			k=k+1;
		}
		if(j==3){
			std::cout << i+1 << std::endl;
		}
	}
	return 0;
}