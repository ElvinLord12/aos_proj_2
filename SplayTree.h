//
// Created by mrue on 10/9/19.
//

#ifndef PROJ_1_SPLAYTREE_H
#define PROJ_1_SPLAYTREE_H

struct TreeNode
{
    int key;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int key)
    {
        this -> key = key;
        this -> parent = NULL;
        this -> left = NULL;
        this -> right = NULL;
    }
};

class SplayTree
{
    TreeNode *root;

    void zig(TreeNode*);
    void zig_zig(TreeNode*);
    void zig_zag(TreeNode*);

    void splay(TreeNode*);

public:
    SplayTree();
    SplayTree(TreeNode*);
    TreeNode* find(int);
    void insert(int);
    void Delete(int);
    void inOrderPrint(bool);
};

#endif //PROJ_1_SPLAYTREE_H
