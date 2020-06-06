#pragma once
#include <string>
using std::string;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(const int& k) : key(k), left(nullptr), right(nullptr), height(0) { }
};

class AVL {
private:
    static Node* root;

    void rDel(Node*& subNode, Node*& delNode);
    Node* getMax(Node* anode = root) const;
    Node* delMax(Node*& anode = root);

    string r_PreOrderTraversal(const Node* anode, string& output) const;
    string r_InOrderTraversal(const Node* anode, string& output) const;
    string r_PostOrderTraversal(const Node* anode, string& output) const;

    Node* leftRotation(Node*& anode);
    Node* rightRotation(Node*& anode);
    void fixHeight(Node*& anode);
    Node* rebalance(Node*& anode);

public:
    Node* add(const int& value, Node*& r = root); // recursive

    Node* remove(const int& value, Node*& anode = root);

    int getHeight(const Node* anode = root) const;

    int getBalance(const Node* anode = root) const;

    Node* find(const int& value, Node* anode = root) const;

    // NLR
    string preOrderTraversal(const Node* anode = root) const;

    // LNR
    string inOrderTraversal(const Node* anode = root) const;

    // LRN
    string postOrderTraversal(const Node* anode = root) const;

    string breadthTraversal(Node* anode = root) const;

    void clear();

    bool isEmpty() const;
};
