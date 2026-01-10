#include<iostream>
using namespace std;
void towersOfHanoi(int n, int x, int y, int z){   
    //把n 个碟子从塔x 移动到塔y，可借助于塔z
     if (n > 0) {
    towersOfHanoi(n-1, x,z,y);
    cout << "Move top disk from tower " << x <<" to top of  tower " << y << endl;
    towersOfHanoi(n-1, z, y, x);}
}
