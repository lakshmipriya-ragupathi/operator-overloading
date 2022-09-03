//
//  main.cpp
//  week_5
//
//  Created by Ragupathi on 30/08/2022.
//

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;
class coordinate{
private:
    float xnum;
    float ynum;
    
public:
    int num;
    
    void display(){
        cout << "(" << xnum << "," << ynum << ")" << endl;
    }
    
    coordinate operator ~(){
        coordinate c1;
        c1.xnum = float(abs(xnum));
        c1.ynum = float(abs(ynum));
        return c1;
    }
    //computing x1-x2 and y1-y2 = new coordinate
    coordinate operator - (coordinate c2){
        coordinate c3;
        c3.xnum = float(abs(this->xnum - c2.xnum));
        c3.ynum = float(abs(this->ynum - c2.ynum));
        return c3;
    }
    //squaring x1-x2 and y1-y2
    void operator * () {
        xnum = xnum * xnum;
        ynum = ynum * ynum;
    }
    int operator +(){
        num = xnum + ynum;
        return num;
    }
    
    void setPoint(float x, float y){
        xnum = x;
        ynum = y;
       
    }
    friend int displayLength( coordinate, coordinate);
    
};
int displayLength(coordinate num1, coordinate num2) {
    coordinate num3;
    float n;
    num3 = num1 - num2;
    *num3;
    n = +num3;
    return n;
}

void right(coordinate num1, coordinate num2, coordinate num3){
    //a^2 = b^2 + c^2;
    //length of x1 to x2 = a, length of x2 to x3 = b, length of x3 to x1 = c;
    int aSquared,bSquared,cSquared, a,b,c ;
    aSquared = displayLength(num1, num2);
    bSquared = displayLength(num2, num3);
    cSquared = displayLength(num3,num1);
    //check straight line
    a = sqrt(aSquared);
    b = sqrt(bSquared);
    c = sqrt(cSquared);
    
    if((a == (b+c)) || (b == (a+c)) || (c == (b+a))){
        cout << "The length of a is : "<< a << endl;
        cout << "The length of b is : "<< b << endl;
        cout << "The length of c is : " << c << endl;
        cout << "\nNo its not a right angle triangle but its a straight line\n";
    }
    else{
        cout << "The length of a^2 is : "<< aSquared << endl;
        cout << "The length of b^2 is : "<< bSquared << endl;
        cout << "The length of c^2 is : " << cSquared << endl;
    if((aSquared == (bSquared+cSquared)) || (bSquared == (aSquared+cSquared)) || (cSquared == (bSquared+cSquared))){
        cout << "\nYes its a right angle triangle\n";
    }
    else{
        cout << "\nNo its not a right angle triangle\n";
    }
    }
}

int main() {
    coordinate pt1, pt2, pt3;
    int choice = 6;
    float x, y;
    cout << "\nTo check if three points are at right angle triangle or not" << endl;
    while(choice != 5){
        cout << "\nTo:\nSet point: press 1\nDisplay Point: press 2\nDisplay Length: press 3\nCheck Right Triangle: press 4\nExit: press 5\n";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "\nTo set point:\nEnter the x coordinate: ";
                cin >> x;
                cout << "\nEnter the y coordinate: ";
                cin >> y;
                pt1.setPoint(x,y);
                pt1 = ~pt1;
                break;
            case 2:
                cout << "\nDisplay the point: " <<endl;
                pt1.display();
                break;
                
            case 3:
                int len;
                cout << "\nTo display the length:\nEnter the x coordinate of the first point: ";
                cin >> x;
                cout << "\nEnter the y coordinate of the first point: ";
                cin >> y;
                pt1.setPoint(x,y);
                pt1 = ~pt1;
                
                cout << "\nEnter the x coordinate of the second point: ";
                cin >> x;
                cout << "\nEnter the y coordinate of the second point: ";
                cin >> y;
                pt2.setPoint(x,y);
                pt2 = ~pt2;
                
                cout << "\nThe coordinates of the first point: ";
                pt1.display();
                cout << "\nThe coordinates of the second point: ";
                pt2.display();
                len = displayLength(pt1, pt2);
                cout << "The length is : "<< sqrt(len) << endl;
                break;
            case 4:
                cout << "\nTo check right triangle:\nEnter the x coordinate of the first point: ";
                cin >> x;
                cout << "\nEnter the y coordinate of the first point: ";
                cin >> y;
                pt1.setPoint(x,y);
                pt1 = ~pt1;
                
                cout << "\nEnter the x coordinate of the second point: ";
                cin >> x;
                cout << "\nEnter the y coordinate of the second point: ";
                cin >> y;
                pt2.setPoint(x,y);
                pt2 = ~pt2;
                
                cout << "\nEnter the x coordinate of the third point: ";
                cin >> x;
                cout << "\nEnter the y coordinate of the third point: ";
                cin >> y;
                pt3.setPoint(x,y);
                pt3 = ~pt3;
                cout << "\nThe coordinates of the first point: ";
                pt1.display();
                cout << "\nThe coordinates of the second point: ";
                pt2.display();
                cout << "\nThe coordinates of the third point: ";
                pt3.display();
                right(pt1,pt2,pt3);
                break;
            case 5:
                cout << "you've successfully exited the program :)\n";
                break;
            default:
                cout << "\nenter a choice between 1 to 5\n";
                break;
        }
    }
    
    return 0;
}
