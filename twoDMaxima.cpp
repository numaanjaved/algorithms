#include<iostream>
#include<stack>
using namespace std;

class Point{
    int x;
    int y;
    public:
        void setX(int X){
            this->x = X;
        }
        void setY(int Y){
            this->y = Y;
        }
        Point(int X, int Y){
            this->setX(X);
            this->setY(Y);
        }
        Point(){

        }
        int getX(){
            return this->x;
        }
        int getY(){
            return this->y;
        }
};
void Maxima(int n, Point* input){
    for(int i = 0; i < n; ++i){
        bool maximal = true;
        for(int j = 0; j < n; ++j){
            bool condition1 = input[i].getX() < input[j].getX();
            bool condition2 = input[i].getY() < input[j].getY();
            if(i != j && (condition1 || condition2)){
                // cout << i << " " << j << " " << input[i].getX() << " " << input[i].getY() << " vs " << input[j].getX() << " " << input[j].getY() << " ";
                maximal = false;
                break;
            }  
        }
        cout << i << " " << input[i].getX() << " " << input[i].getY();
        cout << endl << "maximal = " << maximal << endl; 
        // if(maximal == true){
        //     cout << endl << input[i].getX() << " " << input[i].getY();
        // }
    }
}
void displayAll(int n, Point* input){
    cout << "All the Points are given in order as follows " << endl;
    for(int i = 0; i < n; ++i){
        cout << "Point no " << i << " : " << input[i].getX() << " " << input[i].getY() << endl;
    }
}
void sortByX(int n, Point* input){
    for(int i = 0; i < n - 1; ++i){
        for(int j = 0; j < n - i - 1; ++j){
            if(input[j].getX() > input[j+1].getX()){
                int tempX = input[j].getX();
                input[j].setX(input[j+1].getX());
                input[j+1].setX(tempX);
                int tempY = input[j].getY();
                input[j].setY(input[j+1].getY());
                input[j+1].setY(tempY);
            }
        }        
    }
}
void plainSweepMaxima(int n, Point* input){
    sortByX(n, input);
    stack<Point> Sweeped;
    for(int i = 0; i < n; ++i){
        while(!Sweeped.empty() && Sweeped.top().getY() <= input[i].getY()){
            Point topped = Sweeped.top();
            Sweeped.pop();
        }
        Sweeped.push(input[i]);
    }
    cout << "The maxima points are as follows" << endl;
    while(!Sweeped.empty()){
        Point topped = Sweeped.top();
        cout << endl << topped.getX() << " " << topped.getY() << endl;
        Sweeped.pop();
    }   
}
int main(){
    cout << "How many set of Numbers do you need ? " << endl;
    int n;
    cin >> n; 
    Point* ArrayOfPoints = new Point[n];
    for(int i = 0; i < n; ++i){
        int x; int y; 
        cout << "Enter the value of x for Point " << i + 1 << " : ";
        cin >> x;
        cout << "Enter the value of y for Point " << i + 1 << " : ";
        cin >> y;
        ArrayOfPoints[i].setX(x);
        ArrayOfPoints[i].setY(y);
    }
    plainSweepMaxima(n, ArrayOfPoints);
    return 0;
}