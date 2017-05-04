#include "Test.h"

void test()
{
    BinaryTreeNode *na1 = new BinaryTreeNode(100);
    BinaryTreeNode *na2 = new BinaryTreeNode(90);
    BinaryTreeNode *na3 = new BinaryTreeNode(70);
    BinaryTreeNode *na4 = new BinaryTreeNode(80);
    BinaryTreeNode *na5 = new BinaryTreeNode(85);
    BinaryTreeNode *na6 = new BinaryTreeNode(65);
    BinaryTreeNode *na7 = new BinaryTreeNode(40);
    na1->left = na2; na1->right = na3;
    na2->left = na4; na2->right = na5;
    na3->left = na6; na3->right = na7;

    BinaryTreeNode *nb1 = new BinaryTreeNode(100);
    BinaryTreeNode *nb2 = new BinaryTreeNode(90);
    BinaryTreeNode *nb3 = new BinaryTreeNode(70);
    BinaryTreeNode *nb4 = new BinaryTreeNode(91);
    BinaryTreeNode *nb5 = new BinaryTreeNode(85);
    BinaryTreeNode *nb6 = new BinaryTreeNode(65);
    BinaryTreeNode *nb7 = new BinaryTreeNode(40);
    nb1->left = nb2; nb1->right = nb3;
    nb2->left = nb4; nb2->right = nb5;
    nb3->left = nb6; nb3->right = nb7;

    if(isMaxHeap(na1)
        && isMaxHeap(na3)
        && isMaxHeap(na7)
        && !isMaxHeap(nb1)
        && !isMaxHeap(nb2)
       )
    {
        cout<<"Test: Pass"<<endl;
    }else
    {
        cout<<"Test: Fail"<<endl;
    }

}
