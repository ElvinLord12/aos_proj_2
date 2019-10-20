// COMP 410 AOS Project 1

#include <bits/stdc++.h>
#include "RBTree.h"
#include "SplayTree.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <ctime>
#include <chrono>
using namespace std;

int * genRData(int size){
    int * rtnArray = new int[size];
    srand (time(NULL));
    for (int i = 0; i<size; i++){
        int randnum = rand() % 1000 + 1;
        rtnArray[i] = randnum;
    }
    return rtnArray;
}

int * genAscData(int size){
    int * data = new int[size]; //initializes the array
    int num = 0;
    for(int i = 1; i < size; i++){ //for loop to create array populated with data of size given
        data[i] = num;
        num ++;
        if(num >= 1000){
            num=0;
        }
    }
    return data;
}

int * genDescData(int size){
    int * data = new int[size]; //initializes the array
    int num = 999;
    for(int i = 1; i < size; i++){ //for loop to create array populated with data of size given
        data[i] = num;
        num --;
        if(num <= 0){
            num=999;
        }
    }
    return data;
}

int * loadFileToArray(string fileName, int size){
    ifstream data(fileName);
    int * array = new int[size];
    if(data.is_open()){
        int i = 0;
        string line;
        while (i<size){
            getline(data, line);

            array[i] = stoi(line);

            i++;

            if(i >= size){
                break;
            }
        }
        return array;
    }
    return nullptr;
}

auto insertIntoSplay(int * array, int size){
    SplayTree * sTree = new SplayTree();
    auto start = chrono::high_resolution_clock::now();
    for(int i = 0; i <= size; i++){
        sTree -> insert(array[i]);
    }
    auto end = chrono::high_resolution_clock::now();
    auto dur = end - start;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();


    return ms;

}

double insertIntoRB(int * array, int size){
    RBTree rbTree;
    auto start = chrono::high_resolution_clock::now();
    for(int i = 0; i<= size; i++){
        rbTree.insertValue(array[i]);
    }
    auto end = chrono::high_resolution_clock::now();
    auto dur = end - start;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();


    return ms;
}

auto time(char* type, int * data, int size){
    int total = 0;
    int avg;
    auto * array = new int[5];
    if(type == "rb"){
        for(int i = 0; i<5; i++) {
            array[i] = insertIntoRB(data, size);
        }

        for(int i = 0; i<5; i++){
            total += array[i];
        }

        avg = total/5;
        return avg;
    }
    else{
        for(int i = 0; i<5; i++) {
            array[i] = insertIntoSplay(data, size);
        }

        for(int i = 0; i<5; i++){
            total += array[i];
        }

        avg = total/5;
        return avg;
    }
}

int main() {
//    int data;
//    RBTree rbTree1, rbTree2;
//
//    cin >> data;
//    while (data != 0)
//    {
//        rbTree1.insertValue(data);
//        cin >> data;
//    }
//
//    rbTree1.preorder();
//
//    cin >> data;
//    while (data != 0)
//    {
//        rbTree2.insertValue(data);
//        cin >> data;
//    }
//
//    rbTree2.preorder();
//
//    rbTree1.merge(rbTree2);
//    rbTree1.preorder();

//    int * randomDArray = loadFileToArray("randomData.txt", 800000);
//    int * ascDArray = loadFileToArray("ascData.txt", 800000);
//    int * descDArray = loadFileToArray("descData.txt", 800000);

    int * array = genRData(1000000);
    int * arrayAsc = genAscData(1000000);
    int * arrayDsc = genDescData(1000000);

    cout << "Splay Trees" << endl;

    cout << "=====Splay Random=====" << endl;

    cout << time("splay", array, 10000) << endl;
    cout << time("splay", array, 50000) << endl;
    cout << time("splay", array, 100000) << endl;
    cout << time("splay", array, 200000) << endl;
    cout << time("splay", array, 300000) << endl;
    cout << time("splay", array, 400000) << endl;
    cout << time("splay", array, 500000) << endl;
    cout << time("splay", array, 600000) << endl;
    cout << time("splay", array, 700000) << endl;
    cout << time("splay", array, 800000) << endl;
    cout << time("splay", array, 900000) << endl;
    cout << time("splay", array, 1000000) << endl;

    cout << "=====Splay ASC=====" << endl;

    cout << time("splay", arrayAsc, 10000) << endl;
    cout << time("splay", arrayAsc, 50000) << endl;
    cout << time("splay", arrayAsc, 100000) << endl;
    cout << time("splay", arrayAsc, 200000) << endl;
    cout << time("splay", arrayAsc, 300000) << endl;
    cout << time("splay", arrayAsc, 400000) << endl;
    cout << time("splay", arrayAsc, 500000) << endl;
    cout << time("splay", arrayAsc, 600000) << endl;
    cout << time("splay", arrayAsc, 700000) << endl;
    cout << time("splay", arrayAsc, 800000) << endl;
    cout << time("splay", arrayAsc, 900000) << endl;
    cout << time("splay", arrayAsc, 1000000) << endl;

    cout << "=====Splay DESC=====" << endl;

    cout << time("splay", arrayDsc, 10000) << endl;
    cout << time("splay", arrayDsc, 50000) << endl;
    cout << time("splay", arrayDsc, 100000) << endl;
    cout << time("splay", arrayDsc, 200000) << endl;
    cout << time("splay", arrayDsc, 300000) << endl;
    cout << time("splay", arrayDsc, 400000) << endl;
    cout << time("splay", arrayDsc, 500000) << endl;
    cout << time("splay", arrayDsc, 600000) << endl;
    cout << time("splay", arrayDsc, 700000) << endl;
    cout << time("splay", arrayDsc, 800000) << endl;
    cout << time("splay", arrayDsc, 900000) << endl;
    cout << time("splay", arrayDsc, 1000000) << endl;

    cout << "RB Trees" << endl;
    cout << "=====RB Random=====" << endl;

    cout << time("rb", array, 10000) << endl;
    cout << time("rb", array, 50000) << endl;
    cout << time("rb", array, 100000) << endl;
    cout << time("rb", array, 200000) << endl;
    cout << time("rb", array, 300000) << endl;
    cout << time("rb", array, 400000) << endl;
    cout << time("rb", array, 500000) << endl;
    cout << time("rb", array, 600000) << endl;
    cout << time("rb", array, 700000) << endl;
    cout << time("rb", array, 800000) << endl;
    cout << time("rb", array, 900000) << endl;
    cout << time("rb", array, 1000000) << endl;

    cout << "=====RB ASC=====" << endl;

    cout << time("rb", arrayAsc, 10000) << endl;
    cout << time("rb", arrayAsc, 50000) << endl;
    cout << time("rb", arrayAsc, 100000) << endl;
    cout << time("rb", arrayAsc, 200000) << endl;
    cout << time("rb", arrayAsc, 300000) << endl;
    cout << time("rb", arrayAsc, 400000) << endl;
    cout << time("rb", arrayAsc, 500000) << endl;
    cout << time("rb", arrayAsc, 600000) << endl;
    cout << time("rb", arrayAsc, 700000) << endl;
    cout << time("rb", arrayAsc, 800000) << endl;
    cout << time("rb", arrayAsc, 900000) << endl;
    cout << time("rb", arrayAsc, 1000000) << endl;

    cout << "=====RB DESC=====" << endl;

    cout << time("rb", arrayDsc, 10000) << endl;
    cout << time("rb", arrayDsc, 50000) << endl;
    cout << time("rb", arrayDsc, 100000) << endl;
    cout << time("rb", arrayDsc, 200000) << endl;
    cout << time("rb", arrayDsc, 300000) << endl;
    cout << time("rb", arrayDsc, 400000) << endl;
    cout << time("rb", arrayDsc, 500000) << endl;
    cout << time("rb", arrayDsc, 600000) << endl;
    cout << time("rb", arrayDsc, 700000) << endl;
    cout << time("rb", arrayDsc, 800000) << endl;
    cout << time("rb", arrayDsc, 900000) << endl;
    cout << time("rb", arrayDsc, 1000000) << endl;

    return 0;
}


