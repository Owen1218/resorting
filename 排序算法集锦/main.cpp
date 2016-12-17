//
//  main.cpp
//  排序算法集锦
//
//  Created by owen on 16/12/17.
//  Copyright © 2016年 owen. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstdlib>

#include<vector>
double random(double start, double end)
{
    return start+(end-start)*rand()/(RAND_MAX + 1.0);
}


vector<int> arr;

class DataList{
public:
    DataList(int total);
    bool DataDisplay();
    bool BoolResorting();
    bool InsertResorting();
};
    
DataList::DataList(int total){
    for(int ix=0;ix<total;++ix)
        arr.push_back(int(random(0,100)));
    
}

bool DataList::DataDisplay(){
    
    for(int ix=0;ix<arr.size();++ix)
        cout<<arr[ix]<<endl;
    return true;
}

bool DataList::BoolResorting(){
    
    int temp;
    cout<<"使用冒泡排序的结果执行如下："<<endl;
    
    for(int ix=1;ix<arr.size();++ix)
        for(int bx=int(arr.size())-1;bx>=ix;bx--)
            if(arr[bx-1]>arr[bx]){
                temp=arr[bx];
                arr[bx]=arr[bx-1];
                arr[bx-1]=temp;
            }
    for(int ix=0;ix<arr.size();++ix)
        cout<<arr[ix]<<endl;
    return true;
}

bool DataList::InsertResorting(){
    
    int temp;
    cout<<"使用插入排序的结果执行如下："<<endl;
    
    
    for(int ix=1;ix<int(arr.size());ix++)
        if(arr[ix-1]>arr[ix]){
            temp=arr[ix];
            int bx=ix-1;
            while(bx>=0 && arr[bx]>temp){
            
                arr[bx+1]=arr[bx];
                bx--;
            }
            arr[bx+1]=temp;
        }
    
    
    
    for(int ix=0;ix<arr.size();++ix)
        cout<<arr[ix]<<endl;
    
    
    
    return true;
}




int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int total;
    cout<<"输入总的数字个数"<<endl;
    cin>>total;
    
    DataList _datalist(total);
    _datalist.DataDisplay();
    
    cout<<"请选择使用何种排序方法"<<endl;
    cout<<"1. 冒泡 2. 插入"<<endl;
    
    int choose;
    
    cin>>choose;
    
    switch(choose){
        case 1: _datalist.BoolResorting();break;
        case 2: _datalist.InsertResorting();break;
            
        default: exit(0);
    }
    
    
    
    return 0;
}
