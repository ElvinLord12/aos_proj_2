// COMP 410 AOS Project 1

#include <bits/stdc++.h>
#include "RBTree.h"
#include "SplayTree.h"
#include "Tries.cpp"
#include "HashTable.cpp"

#include <unordered_map>

#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include <iostream>
#include <fstream>
#include <iterator>
#include <ctime>
#include <chrono>
#include <string>
using namespace std;

vector<string> loadFileToArray(std::string &fileName, int size) {
    std::ifstream data(fileName);
    std::string line;
    vector<string> siteList;
    // Strings in c++ suck, so lets use this vector dude. basically an array for strings
    if (data.is_open()) {
        int i = 0;
        while (i < size) {
            getline(data, line);
            if(i>0){ //this is to skip row one which is column names
                int start = line.find(","); //this is to skip the rank and read only the site name
                std::string templine = line.substr(start+1);
                siteList.push_back(templine); //push just the site name to the vector

                i++;

                if (i >= size) {
                    break;
                }
            }
            else{
                i++;
            }
        }
        return siteList;
    }
    std::cout<<"file failed to open"<<std::endl;
    quick_exit(100);
}

int lineCount(string &fileName)
{
    char newLine = '.';
    int numLines = 0;
    string text;
    ifstream openFile(fileName.c_str());



    if(!openFile)
    {
        cerr << "Error, file does not exist. " << endl;
        exit(EXIT_FAILURE);
    }

    while(getline(openFile, text, '\n'))
    {
        for(unsigned int i=0; i< text.length(); i++)
        {
            if(text.at(i) == newLine)
            {
                numLines++;
            }
        }
    }

    return numLines;
}

auto load_rb(vector<string> list){
    RBTree * rbTree = new RBTree();
    auto start = chrono::high_resolution_clock::now();
    for( int i = 0; i<list.size(); i++){
        rbTree->insertValue(list[i]);
    }

    auto end = chrono::high_resolution_clock::now();
    auto dur = end - start;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();

//    std::cout << ms << std::endl;
    return ms;
}

auto load_splay(vector<string> list){
    SplayTree * splayTree = new SplayTree();
    auto start = chrono::high_resolution_clock::now();
    for( int i = 0; i<list.size(); i++){
        splayTree->insert(list[i]);
    }
    auto end = chrono::high_resolution_clock::now();
    auto dur = end - start;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
//
//    std::cout << ms << std::endl;
    return ms;
}

auto load_trie(vector<string> list){
    Trie * trie = new Trie();
    auto start = chrono::high_resolution_clock::now();
    for( int i = 0; i<list.size(); i++){
        trie->insert(list[i]);
    }
    auto end = chrono::high_resolution_clock::now();
    auto dur = end - start;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();

//    std::cout << ms << std::endl;

    return ms;
}

auto load_hashmap(vector<string> list){
    unordered_map<string, string> hashmap;
    auto start = chrono::high_resolution_clock::now();
    for( int i = 0; i<list.size(); i++){
        hashmap.emplace(std::to_string(i), list[i]);
    }
    auto end = chrono::high_resolution_clock::now();
    auto dur = end - start;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();

//    std::cout << ms << std::endl;

    return ms;
}

auto time_rb(RBTree *rbTree, string file){
    int size = lineCount(file);

    vector<string> lookupList = loadFileToArray(file, size);

    auto start = chrono::high_resolution_clock::now();
    for(int i = 0; i<= lookupList.size(); i++){
        rbTree->find(lookupList[i]);
    }
    auto end = chrono::high_resolution_clock::now();
    auto dur = end - start;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();

    return ms;
}

auto time_splay(SplayTree *splayTree, string file){
    int size = lineCount(file);

    vector<string> lookupList = loadFileToArray(file, size);

    auto start = chrono::high_resolution_clock::now();
    for(int i = 0; i<= lookupList.size(); i++){
        splayTree->find(lookupList[i]);
    }
    auto end = chrono::high_resolution_clock::now();
    auto dur = end - start;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();

    return ms;
}

auto time_trie(Trie * trie, string file){
    int size = lineCount(file);

    vector<string> lookupList = loadFileToArray(file, size);

    auto start = chrono::high_resolution_clock::now();
    for(int i = 0; i<= lookupList.size(); i++){
        trie->search(lookupList[i]);
    }

    auto end = chrono::high_resolution_clock::now();
    auto dur = end - start;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();

    return ms;
}

auto time_hashmap(unordered_map<string, string> hashmap, string file){
    int size = lineCount(file);

    vector<string> lookupList = loadFileToArray(file, size);

    auto start = chrono::high_resolution_clock::now();
    for(int i = 0; i<= lookupList.size(); i++){
        __detail::_Node_iterator<pair<const basic_string<char>, basic_string<char>>, 0, 1> test = hashmap.find(lookupList[i]);
    }

    auto end = chrono::high_resolution_clock::now();
    auto dur = end - start;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();

    return ms;
}


int main() {

//    SplayTree * sTree = new SplayTree();
//    sTree -> insert("Hello");
//
//    RBTree rbTree;
//
//    rbTree.insertValue("Hello");
//
//    Trie* head = new Trie();
//
//    head->insert("Hello");
//
//    unordered_map<string, string> hashtable;
//    hashtable.emplace("hello", "hello");

    string path = "/home/mrue/aos/proj_2/weightedRandom.csv";
    string path1 = "/home/mrue/aos/proj_2/multiAccess.csv";
    string path2 = "/home/mrue/aos/proj_2/alphabeticalData.csv";

    int line_count = lineCount(path);
    int line_count1 = lineCount(path1);
    int line_count2 = lineCount(path2);

    std::cout << line_count << std::endl;
    std::cout << line_count1 << std::endl;
    std::cout << line_count2 << std::endl;

    vector<string> siteList = loadFileToArray(path1, 700000);

//    for( int i = 0; i<siteList.size(); i++){
//        std::cout << siteList[i] << std::endl;
//    }

    std::cout << "--RB Tree--" << std::endl;

    int total = 0;

for(int i = 0; i< 10; i++){
    total += load_rb(siteList);
}

cout << total/10 << std::endl;

    std::cout << "--Splays--" << std::endl;

total = 0;

for(int x = 0; x< 10; x++){
    total += load_splay(siteList);
}

    cout << total/10 << std::endl;

total = 0;

std::cout << "--Hashmap--" << std::endl;

for(int t = 0; t< 10; t++){
    total += load_hashmap(siteList);
}

    cout << total/10 << std::endl;

std::cout << "--Tries--" << std::endl;

total = 0;

//for(int r = 0; r < 10; r++){
//    total = load_trie(siteList);
//    }
total = load_trie(siteList);

    cout << total << std::endl;





//    auto ms_splay = time_splay(splayTree, path);
//    cout << ms_splay << std::endl;
//
//    auto ms_trie = time_trie(trie, path);
//    cout << ms_trie << std::endl;
//
//    auto ms_hash = time_hashmap(hashmap, path);
//    cout << ms_hash << std::endl;

}


