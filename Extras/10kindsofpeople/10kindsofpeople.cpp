#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>

std::set<std::pair<int,int>> add_nei(std::set<std::pair<int,int>> currentzones,int c,int r,bool * map, int * zones, int zonenr){
    std::set<std::pair<int,int>> nextzones;
    int x,y;
    for (std::set<std::pair<int,int>>::iterator where = currentzones.begin();where != currentzones.end();++where){
    x = where->first;
    y = where->second;
    int a,b;
    if (x<r-1){
    a = x+1;
    b= y;
    if ( zones[b*r+a] == 0 && map[b*r+a] == map[y*r+x]){
        nextzones.insert({a,b});
        zones[b*r+a] = zonenr;
        //std::cout << a << " "<< b <<std::endl;
    }
    }
    if (y<c-1){
    a = x;
    b= y+1;
    if ( zones[b*r+a] == 0 && map[b*r+a] == map[y*r+x]){
        nextzones.insert({a,b});
        zones[b*r+a] = zonenr;
        //std::cout << a << " "<< b << std::endl;
    }
    }
    if (x>0){
    a = x-1;
    b= y;
    if ( zones[b*r+a] == 0 && map[b*r+a] == map[y*r+x]){
        nextzones.insert({a,b});
        zones[b*r+a] = zonenr;
        //std::cout << a << " "<< b << std::endl;
    }
    }
    if (y>0){
    a = x;
    b= y-1;
    if ( zones[b*r+a] == 0 && map[b*r+a] == map[y*r+x]){
        nextzones.insert({a,b});
        zones[b*r+a] = zonenr;
        //std::cout << a << " "<< b << std::endl;
    }
    }
    }
    return nextzones;
}

int main(){
    int r,c;
    std::cin >> c >> r;

    bool map[r*c] = {0};
    int zones[r*c] = {0};
    
    std::string row;
    for (int i = 0;i<c;++i){
        std::cin >> row;
        for (int j = 0;j<r;++j){
            if (row[j]=='1'){
                map[i*r+j]=true;
            } else {
                map[i*r+j]=false;
            }
        }
    }
    int zonenr = 0;
    for (int i = 0;i<c;++i){
        for (int j = 0;j<r;++j){
            if (zones[i*r+j] == 0){
                zonenr+=1;
                std::set<std::pair<int,int>> currentzones={{j,i}};
                zones[i*r+j] = zonenr;
                while (0 != currentzones.size()){
                    currentzones = add_nei(currentzones,c,r, map, zones,zonenr);
                }

    //             for (int i = 0;i<c;++i){
    //      for (int j = 0;j<r;++j){
    //          std::cout <<zones[i*r+j];
    //      }
    //      std::cout << std::endl;
    
    //  }

                // std::cout << currentzones.size() << "yay"<< std::endl ;       
            }
        }
    }
    int n;
    std::cin >> n;
    int r1,c1,r2,c2;
     for (int k = 0;k<n;++k){
        std::cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        c1--;
        r2--;
        c2--;
        if (zones[r1*r+c1] == zones[r2*r+c2]){
            if (map[r1*r+c1]){
                 std::cout << "decimal"<< std::endl;
            } else {
                std::cout << "binary"<< std::endl;
            }
        } else {
            std::cout << "neither" << std::endl;
        }
     }

    return 0;
}