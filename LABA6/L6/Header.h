#pragma once
#include <iostream>
#include <list>
#include<vector>
using namespace std;
template<typename T1, typename T2>
class Tree {
private:
    class TNode {
    public:
        TNode();
        T1 key;
        T2 value;
        TNode* origin;
        TNode* left;
        TNode* right;
    };
    TNode* root = nullptr;
    TNode* find_node(T1 key);
    list<TNode*> roam(TNode* start);
public:
    Tree();
    void insert(T1 key, T2 value);
    void exclude(T1 key);
    list<pair<T1, T2>> to_list();
    static bool KeyUnique(pair<T1, T2> p1, pair<T1, T2> p2);
    void merge(Tree t);
};
void test1BuildTree();
void test2Exclude();
void test3UniteTrees();