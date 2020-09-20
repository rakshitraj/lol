#include <iostream>
using namespace std;

struct Binary{
    int data;
    Binary *left, *right;
    Binary(int data): data{data}, left{nullptr}, right{nullptr} {}
};

void print_dfs(Binary * root) {
    if(root == nullptr){
        return;
    }
    cout << root->data;
    print_dfs(root->left);
    print_dfs(root->right);
}

void del_tree(Binary * root){
    if (root == nullptr)
        return;
    del_tree(root->left);
    del_tree(root->right);
    delete(root);
}

int main()
    {
        Binary *root = new Binary(1);
        Binary *left = new Binary(2);
        Binary *right = new Binary(3);
        Binary *left_left = new Binary(4);
        Binary *left_right = new Binary(5);
        Binary *right_left = new Binary(6);
        Binary *right_right = new Binary(7);

        // Connecting nodes
        root->left = left;
        root->right = right;
        left->left = left_left; left->right = left_right;
        right->left = right_left; right->right = right_right;

        // Printing Binary Tree
        print_dfs(root);

        // Deleting nodes
        del_tree(root);

    return 0;
    }
