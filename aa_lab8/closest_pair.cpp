#include<bits/stdc++.h>
using namespace std;

class Point{
    public:
    int x, y;
    Point(){}
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
};

void closest_pair(vector<Point> p){
    int n = p.size();

    double dmin = INT_MAX;
    int in1, in2;
    for(int i=0; i < n-1; i++){
        for(int j=i+1; j < n; j++){
            double _x = (double) (p[i].x - p[j].x) * (p[i].x - p[j].x);
            double _y = (double) (p[i].y - p[j].y) * (p[i].y - p[j].y);

            double d = sqrt(_x + _y);
            if(d < dmin){
                dmin = d;
                in1 = i;
                in2 = j;
            }
        }
    }

    cout << "Closest Pair Ponits : {" << p[in1].x << ", " << p[in1].y << "} and {" << p[in2].x << ", " << p[in2].y << "}\nDistance : " << dmin << endl;
}


int main(){
    
    vector<Point> p = {
        {2, 2},
        {4, 4},
        {5, 6}
    };

    closest_pair(p);
    
    return 0;
}
