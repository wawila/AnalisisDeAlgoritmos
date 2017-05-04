#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

class BinaryTreeNode
{
    public:
        BinaryTreeNode* left;
        BinaryTreeNode* right;
        int value;
        BinaryTreeNode(int value);
        virtual ~BinaryTreeNode();
    protected:
    private:
};

#endif // BINARYTREENODE_H
