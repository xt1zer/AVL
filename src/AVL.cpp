#include <queue>
#include "AVL.hpp"

Node* AVL::root;

void AVL::rDel(Node*& subNode, Node*& delNode) {
    if (subNode->right)
        rDel(subNode->right, delNode);
    else {
        delNode->key = subNode->key;
        delNode = subNode;
        subNode = subNode->left;
        delete delNode;
    }
}

Node* AVL::getMax(Node* anode /* = root */) const {
    if (!anode->right) return anode;
    return anode->right;
}

Node* AVL::delMax(Node*& anode /* = root */) {
    if (!anode->right) return anode->left;
    anode->right = delMax(anode->right);
    return rebalance(anode);
}

int AVL::getHeight(const Node * anode /* = root */) const {
    if (!anode)
        return -1;
    return anode->height;
}

void AVL::fixHeight(Node*& anode) {
    int lHeight = getHeight(anode->left),
            rHeight = getHeight(anode->right);
    anode->height = (lHeight > rHeight ? lHeight : rHeight) + 1;
}

Node* AVL::leftRotation(Node*& anode) {
    Node* q = anode->right;
    anode->right = q->left;
    q->left = anode;
    fixHeight(anode);
    fixHeight(q);
    if (anode == root)
        root = q;
    return q;
}

Node* AVL::rightRotation(Node*& anode) {
    Node* q = anode->left;
    anode->left = q->right;
    q->right = anode;
    fixHeight(anode);
    fixHeight(q);
    if (anode == root)
        root = q;

    return q;
}

int AVL::getBalance(const Node* anode /* = root */) const {
    return getHeight(anode->right) - getHeight(anode->left);
}

Node* AVL::rebalance(Node*& anode) {
    fixHeight(anode);

    if (getBalance(anode) == 2) {
        if (getBalance(anode->right) < 0)
            anode->right = rightRotation(anode->right);
        return leftRotation(anode);
    }

    if (getBalance(anode) == -2) {
        if (getBalance(anode->left) > 0)
            anode->left = leftRotation(anode->left);
        return rightRotation(anode);
    }
    return anode;
}

Node* AVL::add(const int& value, Node*& r /* = root */) {
    if (!r) {
        r = new Node(value);
        return r;
    }

    if (value < r->key)
        r->left = add(value, r->left);
    else if (value > r->key)
        r->right = add(value, r->right);

    return rebalance(r);
}

Node* AVL::remove(const int& value, Node*& anode /* = root */) {
    if (!anode) return nullptr; // not found or tree is empty
    if (value < anode->key)
        anode->left = remove(value, anode->left);
    else if (value > anode->key)
        anode->right = remove(value, anode->right);
    else {
        Node* l = anode->left, *r = anode->right;
        delete anode;
        if (!l) {
            if (anode == root)
                root = r;
            return r;
        }

        Node* max = getMax(l);
        max->left = delMax(l);
        max->right = r;
        if (anode == root)
            root = max;
        return rebalance(max);
    }
    return rebalance(anode);
}

Node* AVL::find(const int& value, Node* anode /* = root */) const {
    if (!anode)
        return nullptr;

    if (anode->key == value)
        return anode;
    else if (value < anode->key)
        return find(value, anode->left);
    else
        return find(value, anode->right);
}

// NLR

string AVL::r_PreOrderTraversal(const Node* anode /* = root */,
        string& output) const {
    if (anode) {
        output += std::to_string(anode->key) + " ";
        r_PreOrderTraversal(anode->left, output);
        r_PreOrderTraversal(anode->right, output);
    }
    return output;
}

string AVL::preOrderTraversal(const Node* anode /* = root */) const {
    if (!anode) return "";
    string output = "";
    return r_PreOrderTraversal(anode, output);
}

// LNR

string AVL::r_InOrderTraversal(const Node* anode /* = root */,
        string& output) const {
    if (anode) {
        r_InOrderTraversal(anode->left, output);
        output += std::to_string(anode->key) + " ";
        r_InOrderTraversal(anode->right, output);
    }

    return output;
}

string AVL::inOrderTraversal(const Node* anode /* = root */) const {
    if (!anode) return "";
    string output = "";
    return r_InOrderTraversal(anode, output);
}

// LRN

string AVL::r_PostOrderTraversal(const Node* anode /* = root */,
        string& output) const {
    if (anode) {
        r_PostOrderTraversal(anode->left, output);
        r_PostOrderTraversal(anode->right, output);
        output += std::to_string(anode->key) + " ";
    }
    return output;
}

string AVL::postOrderTraversal(const Node* anode /* = root */) const {
    if (!anode) return "";
    string output = "";
    return r_PostOrderTraversal(anode, output);
}

string AVL::breadthTraversal(Node * anode /* = root */) const {
    if (!anode) return "";
    string output = "";
    std::queue<Node*>* nodeQueue = new std::queue<Node*>;
    nodeQueue->push(anode);

    while (!nodeQueue->empty()) {
        if (nodeQueue->front()->left)
            nodeQueue->push(nodeQueue->front()->left);
        if (nodeQueue->front()->right)
            nodeQueue->push(nodeQueue->front()->right);
        output += std::to_string(nodeQueue->front()->key) + " ";
        nodeQueue->pop();
    }
    return output;
}

void AVL::clear() {
    while (root)
        remove(root->key);
}

AVL::~AVL() {
    clear();
}

bool AVL::isEmpty() const {
    return !root;
}
