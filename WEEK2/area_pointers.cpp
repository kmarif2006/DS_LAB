#include<bits/stdc++.h>
using namespace std;

double circle_area(int *radius_ptr){
    return M_PI* (double)(*radius_ptr)* (double)(*radius_ptr);
}
double square_area(int *side_ptr){
    return *side_ptr* *side_ptr;
}
double rectangle_area(int *length_ptr,int* breadth_ptr){
    return *length_ptr* *breadth_ptr;
}

int main(){
    char ch;
    while(true){
        cout<<"a) Circle\nb) Square\nc) Rectangle\nd) Exit\nEnter Your Choice: ";
        cin>>ch;
        switch(ch){
                case 'a':{
                int radius;
                cout << "Enter the radius of the circle: ";
                cin >> radius;
                cout << "Area of the circle: " << circle_area(&radius) << endl;
                break;
        }
        case 'b':{
                int side;
                cout << "Enter the side length of the square: ";
                cin >> side;
                cout << "Area of the square: " << square_area(&side) << endl;
                break;
        }
        case 'c':{
                int length, breadth;
                cout << "Enter the length of the rectangle: ";
                cin >> length;
                cout << "Enter the breadth of the rectangle: ";
                cin >> breadth;
                cout << "Area of the rectangle: " << rectangle_area(&length, &breadth) << endl;
                break;
        }
        case 'd':
                cout << "Exiting program." << endl;
                return 0;}
        
    }
    return 0;
}