#include <iostream>
#include <list>
#include<vector>
using namespace std;
template<typename T1, typename T2>
class Tree {
private:
    class TNode {
    public:
        TNode() {
            TNode* origin = nullptr;
            TNode* left = nullptr;
            TNode* right = nullptr;
        }
        T1 key;
        T2 value;
        TNode* origin;
        TNode* left;
        TNode* right;
    };
    TNode* root = nullptr;
    TNode* find_node(T1 key) {
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
    list<TNode*> roam(TNode* start) {
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
public:
    Tree() {}
    void insert(T1 key, T2 value) {
        bool placed = false;
        TNode* curr = this->root;
        //initialize root
        if (this->root == nullptr) {
            this->root = new TNode();
            this->root->key = key;
            this->root->value = value;
        }
        // if root initialized
        else if (this->root != nullptr) {
            while (!placed) {
                if (key < curr->key) {
                    if (curr->left != nullptr) {
                        curr = curr->left;
                    }
                    else if (curr->left == nullptr) {
                        TNode* newNode = new TNode();
                        curr->left = newNode;
                        newNode->origin = curr;
                        newNode->key = key;
                        newNode->value = value;
                        placed = true;
                    }
                }
                else if (key > curr->key) {
                    if (curr->right != nullptr) {
                        curr = curr->right;
                    }
                    else if (curr->right == nullptr) {
                        TNode* newNode = new TNode();
                        curr->right = newNode;
                        newNode->origin = curr;
                        newNode->key = key;
                        newNode->value = value;
                        placed = true;
                    }
                }
                else if (key == curr->key) {
                    if (curr->left == nullptr) {
                        TNode* newNode = new TNode();
                        curr->left = newNode;
                        newNode->origin = curr;
                        newNode->key = key;
                        newNode->value = value;
                        placed = true;
                    }
                    else if (curr->left != nullptr) {
                        curr = curr->left;
                        while (curr->right != nullptr) {
                            curr = curr->right;
                        }
                        TNode* newNode = new TNode();
                        curr->right = newNode;
                        newNode->origin = curr;
                        newNode->key = key;
                        newNode->value = value;
                        placed = true;
                    }
                }
            }
        }
    }
    void exclude(T1 key) {
        TNode* nodeToDel = this->find_node(key);
        if (nodeToDel->left != nullptr) {
            TNode* curr = nodeToDel->left;
            while (curr->right != nullptr) {
                curr = curr->right;
            }
            T1 temp = curr->key;
            this->exclude(curr->key);
            nodeToDel->key = temp;
        }
        else if (nodeToDel->left == nullptr) {
            if (nodeToDel->right == nullptr){
                if (nodeToDel->origin->right == nodeToDel)
                    nodeToDel->origin->right = nullptr;
                else if (nodeToDel->origin->left == nodeToDel)
                    nodeToDel->origin->left = nullptr;
                delete nodeToDel;
            }
            else if (nodeToDel->right != nullptr) {
                TNode* curr = nodeToDel->right;
                while (curr->left != nullptr) {
                    curr = curr->left;
                }
                T1 temp = curr->key;
                this->exclude(curr->key);
                nodeToDel->key = temp;
            }
        }            
    }
    list<pair<T1, T2>> to_list() {
        list<TNode*> nodes = this->roam(this->root);
        list<pair<T1, T2>> pairs;
        pair<T1, T2> kv;
        kv.first = this->root->key;
        kv.second = this->root->value;
        pairs.push_back(kv);
        for (auto i = nodes.begin() ; i != nodes.end() ; i++)
        {
            kv.first = (*i)->key;
            kv.second = (*i)->value;
            pairs.push_back(kv);
        }
        return pairs;
    }
};


int main()
{
    srand(time(NULL));
    Tree<int, string> t1 = Tree<int, string>();
    t1.insert(100, "q");
    t1.insert(200, "w");
    t1.insert(300, "e");
    t1.insert(400, "r");
    t1.insert(500, "t");
    t1.insert(350, "y");
    t1.insert(330, "u");
    t1.insert(320, "i");
    t1.insert(335, "o");
    t1.insert(150, "p");
    t1.insert(175, "a");
    t1.insert(90, "s");
    t1.insert(96, "d");
    t1.insert(98, "f");
    t1.insert(99, "g");
    t1.insert(97, "h");
    t1.insert(94, "j");
    t1.insert(92, "k");
    t1.insert(93, "l");
    t1.insert(50, "z");
    t1.insert(51, "x");
    t1.insert(40, "c");
    t1.insert(45, "v");
    t1.insert(44, "b");
    auto res = t1.to_list();
    for (auto i = res.begin(); i != res.end(); i++)
    {
        cout << i->first<<"\t"<<i->second<< endl;
    }
}

