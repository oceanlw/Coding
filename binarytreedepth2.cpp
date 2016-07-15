#include <iostream>

typedef struct BinaryTreeNode {
    int value;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int x) {
        value = x;
        left = NULL;
        right = NULL;
    }
} BinaryTreeNode;

int BinaryTreeDepth(BinaryTreeNode *root)
{
    if (root == NULL) {
        return 0;
    }
    int left = BinaryTreeDepth(root->left);
    int right = BinaryTreeDepth(root->right);

    return (std::max(left, right) + 1);
}

int main()
{
    BinaryTreeNode t0(1);
    BinaryTreeNode t1(2), t2(3), t3(4);
    t0.left = &t1; t0.right = &t2;
    t2.right = &t3;

    int depth = BinaryTreeDepth(&t0);
    printf("depth %d\n", depth);

    return 0;
}
