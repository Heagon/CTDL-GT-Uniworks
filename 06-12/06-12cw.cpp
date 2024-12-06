//(a+5*b/c-c^8+de^1/2)
#include <iostream>
using namespace std;

struct Node {
    char value;
    Node* left;
    Node* right;
};

Node* newNode(char value) {
    Node* node = new Node;
    node->value = value;
    node->left = node->right = nullptr;
    return node;
}

void preOrder(Node* root) {
    if (root) {
        cout << root->value << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->value << " ";
        inOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->value << " ";
    }
}

int main() {
    Node* root = newNode('+');
    root->left = newNode('-');
    root->left->left = newNode('+');
    root->left->left->left = newNode('a');
    root->left->left->right = newNode('/');
    root->left->left->right->left = newNode('*');
    root->left->left->right->left->left = newNode('5');
    root->left->left->right->left->right = newNode('b');
    root->left->left->right->right = newNode('c');
    root->left->right = newNode('^');
    root->left->right->left = newNode('c');
    root->left->right->right = newNode('8');
    root->right = newNode('+');
    root->right->left = newNode('*');
    root->right->left->left = newNode('d');
    root->right->left->right = newNode('e');
    root->right->right = newNode('^');
    root->right->right->left = newNode('1');
    root->right->right->right = newNode('/');
    root->right->right->right->left = newNode('2');
    root->right->right->right->right = newNode('1');

    cout << "Pre-order: ";
    preOrder(root);
    cout << endl;

    cout << "In-order: ";
    inOrder(root);
    cout << endl;

    cout << "Post-order: ";
    postOrder(root);
    cout << endl;

    return 0;
}
