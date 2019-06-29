#include <iostream>
#include <chrono>
#include <algorithm>
#include <sort.hpp>

using namespace std;

void testSort(){
    cout<<"--------------------------------"<<endl;
    cout<<"Test sorting algorithms..."<<endl;

    //initialize testing arrays
    vector<int> numArray({10,100,1000,10000,100000});

    vector<vector<int>> tests(numArray.size());
    for(int i=0;i<numArray.size();++i){
        tests[i]=vector<int>(numArray[i],0);
        for(int& a:tests[i])
            a=random();
    }

    //execution time for all methods
    vector<vector<double>> time(9,vector<double>(numArray.size()));

    //testing std
    vector<vector<int>> test0=tests;
    for(int i=0;i<numArray.size();++i){
        std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
        std::sort(test0[i].begin(),test0[i].end());
        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
        double t_track= std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1).count();
        time[0][i]=t_track;
    }
    cout<<"std done!"<<endl;

    //testing InsertSort
    vector<vector<int>> test1=tests;
    for(int i=0;i<numArray.size();++i){
        std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
        Sort::insertionSort(test1[i]);
        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
        double t_track= std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1).count();
        time[1][i]=t_track;
        if(test1[i]!=test0[i])
            cerr<<"Insertion sort error!!!!"<<endl;
    }
    cout<<"insertion done!"<<endl;

    //testing binarySort
    vector<vector<int>> test2=tests;
    for(int i=0;i<numArray.size();++i){
        std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
        Sort::binarySort(test2[i]);
        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
        double t_track= std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1).count();
        time[2][i]=t_track;
        if(test2[i]!=test0[i])
            cerr<<"Binary sort error!!!!"<<endl;
    }
    cout<<"binarySort done!"<<endl;

    //testing bubbleSort
    vector<vector<int>> test3=tests;
    for(int i=0;i<numArray.size();++i){
        std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
        Sort::bubbleSort(test3[i]);
        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
        double t_track= std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1).count();
        time[3][i]=t_track;
        if(test3[i]!=test0[i])
            cerr<<"Bubble sort error!!!!"<<endl;
    }
    cout<<"bubbleSort done!"<<endl;

    //testing selectionSort
    vector<vector<int>> test4=tests;
    for(int i=0;i<numArray.size();++i){
        std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
        Sort::selectionSort(test4[i]);
        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
        double t_track= std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1).count();
        time[4][i]=t_track;
        if(test4[i]!=test0[i])
            cerr<<"Selection sort error!!!!"<<endl;
    }
    cout<<"selectionSort done!"<<endl;

    //compare results
    cout<<"\nExecution time"<<endl;
    cout<<"methods ";
    for(int i : numArray)
        cout<<i<<" ";
    cout<<"\nstd ";
    for(int i=0;i<numArray.size();++i)
        cout<<time[0][i]<<" ";
    cout<<"\ninsertion ";
    for(int i=0;i<numArray.size();++i)
        cout<<time[1][i]<<" ";
    cout<<"\nBinary ";
    for(int i=0;i<numArray.size();++i)
        cout<<time[2][i]<<" ";
    cout<<"\nBubble ";
    for(int i=0;i<numArray.size();++i)
        cout<<time[3][i]<<" ";
    cout<<"\nSelection ";
    for(int i=0;i<numArray.size();++i)
        cout<<time[4][i]<<" ";

}

int main() {
    std::cout << "This project is built for training my coding skills and learning normal algorithms." << std::endl;

    testSort();

    return 0;
}