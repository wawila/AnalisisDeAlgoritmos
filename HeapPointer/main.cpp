#include "Test.h"
#include <iostream>
using namespace std;


bool isMaxHeap(BinaryTreeNode* root, int value)
{
    if(root->value > value)
        return false;

    if(root->left != 0)
        return isMaxHeap(root->left, root->value);

    if(root->right != 0)
        return isMaxHeap(root->right, root->value);

    return true;
}

bool isMaxHeap(BinaryTreeNode* root)
{
    return isMaxHeap(root, root->value);
}

int main ()
{
    test();
    return 0;
}
