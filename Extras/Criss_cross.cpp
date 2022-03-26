#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <set>
#include <bits/stdc++.h>

long int sq_dist(long int x1,long int y1,long int x2,long int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main (){
    unsigned int n;
    std::cin >> n;
    std::vector<std::pair<long int,long int>> coords(2*n);
    long int x1,y1,x2,y2,x3,y3,x4,y4, x_intersect, y_intersect,x_norm,y_norm,dis_x,dis_y,sign_d;
    for(int i = 0;i<n;++i){
        std::cin >> x1 >> y1 >> x2 >> y2;
        coords[2*i]={x1,y1};
        coords[2*i+1]={x2,y2};
    }

    std::set<std::tuple<long int,long int,long int,long int>> intersection_points;
    std::vector<std::pair<long int,long int>> test_set1(2);
    std::vector<std::pair<long int,long int>> test_set2(2);

    for(int i =0;i<n;++i){
        x1=std::get<0>(coords[2*i]);
        x2=std::get<0>(coords[2*i+1]);
        y1=std::get<1>(coords[2*i]);
        y2=std::get<1>(coords[2*i+1]);
        for(int j =0;j<n;++j){
            x3=std::get<0>(coords[2*j]);
            x4=std::get<0>(coords[2*j+1]);
            y3=std::get<1>(coords[2*j]);
            y4=std::get<1>(coords[2*j+1]);
            if (i!=j){
                long int discriminant = (x1-x2)*(y3-y4)-(y1-y2)*(x3-x4);
                if (discriminant == 0){
                    int added = 0;
                    long int segment = sq_dist(x4,y4,x3,y3);
                    long int segment2 = sq_dist(x1,y1,x2,y2);
                    //std::cout << "parallel";
                    if (sq_dist(x1,y1,x3,y3) < segment & sq_dist(x1,y1,x4,y4) < segment){
                        added=2;
                    } else if (sq_dist(x2,y2,x3,y3) < segment & sq_dist(x2,y2,x4,y4) < segment){
                        added = 2;
                    } else if (sq_dist(x3,y3,x1,y1) < segment2 & sq_dist(x3,y3,x2,y2) < segment2){
                        added = 2;
                    } else if (sq_dist(x4,y4,x1,y1) < segment2 & sq_dist(x4,y4,x2,y2) < segment2){
                        added = 2; 
                    } else if (sq_dist(x1,y1,x3,y3) == 0 || sq_dist(x1,y1,x4,y4) == 0){
                        intersection_points.insert(std::make_tuple(x1,1,y1,1));
                        added+=1;
                    } 
                    
                    if (sq_dist(x2,y2,x3,y3) == 0 || sq_dist(x2,y2,x4,y4) == 0){
                        intersection_points.insert(std::make_tuple(x2,1,y2,1));
                        added+=1;
                        
                    }
                    if (added >=2){
                        std::cout << -1 << std::endl;
                        return 0;
                    }

                    

                } else {
                    if(discriminant>0){sign_d = 1;} else {sign_d=-1;}
                    x_intersect = ((x1*y2-y1*x2)*(x3-x4)-(x1-x2)*(x3*y4-y3*x4));
                    x_norm = sign_d*x_intersect/(std::gcd(x_intersect,discriminant));
                    dis_x = sign_d*discriminant/(std::gcd(x_intersect,discriminant));
                    y_intersect = ((x1*y2-y1*x2)*(y3-y4)-(y1-y2)*(x3*y4-y3*x4));
                    y_norm = sign_d*y_intersect/(std::gcd(y_intersect,discriminant));
                    dis_y = sign_d*discriminant/(std::gcd(y_intersect,discriminant));

                    if ((x1*discriminant- x_intersect)*(x2*discriminant- x_intersect)<=0 && (y1*discriminant- y_intersect)*(y2*discriminant- y_intersect)<=0 && (x3*discriminant- x_intersect)*(x4*discriminant- x_intersect)<=0 && (y3*discriminant- y_intersect)*(y4*discriminant- y_intersect)<=0 ){
                    intersection_points.insert(std::make_tuple(x_norm,dis_x,y_norm,dis_y));
                    //std::cout << ((double) x_intersect) / ((double) discriminant) << " " << ((double) y_intersect) / ((double) discriminant) << std::endl; 
                    }
                }
                
            }
        }

    }
    std::cout << intersection_points.size() << std::endl;
    return 0;
}