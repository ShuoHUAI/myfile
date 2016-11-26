/*************************************************************************
	>> File Name: mazerand.cpp
	>> Author:HuaiShuo 
	>> Created Time: 2016年11月26日 星期六 15时30分47秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
using namespace std;
int main(){
    srand((int)time(NULL));
    char filename []= "/home/huaishuo/workspace/randmaze.txt";
    ofstream fout(filename);
    int number;
    for(int i=0;i<81;i++){
        number = rand()%2;
        if(i%9==0&&i)
            fout<<"\n";
        fout<<number;
    }
    return 0;
}
