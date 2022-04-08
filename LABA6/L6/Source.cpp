#include <iostream>
#include <list>
#include<vector>
#include"Header.h"
using namespace std;
template<typename T1, typename T2>
Tree<T1, T2>::TNode::TNode() {}
template<typename T1, typename T2>
Tree<T1, T2>::TNode*Tree<T1, T2>:: find_node(T1 key) {
    bool found = false;
    TNode* curr = this->root;
    while (!found) {
        if (key < curr->key) {
            if (curr->left != nullptr) {
                curr = curr->left;
            }
            //exceprion
        }
        else if (key > curr->key) {
            if (curr->right != nullptr) {
                curr = curr->right;
            }
            //exception
        }
        else if (key == curr->key) {
            return curr;
        }
    }
}
template<typename T1, typename T2>
list<Tree<T1, T2>::TNode*> Tree<T1, T2>::roam(TNode* start) {
    list<TNode*> nodes;
    if (start->left != nullptr) {
        nodes.push_back(start->left);
        list<TNode*>res = this->roam(start->left);
        for (auto i = res.begin(); i != res.end(); i++)
        {
            nodes.push_back(*i);
        }
    }
    if (start->right != nullptr) {
        nodes.push_back(start->right);
        list<TNode*>res = this->roam(start->right);
        for (auto i = res.begin(); i != res.end(); i++)
        {
            nodes.push_back(*i);
        }
    }
    return nodes;
}