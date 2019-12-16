//
// Red Black Tree Definition
//

#ifndef RED_BLACK_TREE_RBTREE_H
#define RED_BLACK_TREE_RBTREE_H

enum Color {RED, BLACK, DOUBLE_BLACK};

struct Node
{
    std::string data;
    int color;
    Node *left, *right, *parent;

    explicit Node(std::string);
};

class RBTree
{
    private:
        Node *root;
    protected:
        void rotateLeft(Node *&);
        void rotateRight(Node *&);
        void fixInsertRBTree(Node *&);
        void fixDeleteRBTree(Node *&);
        void inorderBST(Node *&);
        void preorderBST(Node *&);
        int getColor(Node *&);
        void setColor(Node *&, int);
        Node *minValueNode(Node *&);
        Node *maxValueNode(Node *&);
        Node* insertBST(Node *&, Node *&);
        Node* deleteBST(Node *&, std::string);
        int getBlackHeight(Node *);
    public:
        RBTree();
        std::string find(std::string);
        void insertValue(std::string);
        void deleteValue(std::string);
        void merge(RBTree);
        void inorder();
        void preorder();
};


#endif //RED_BLACK_TREE_RBTREE_H
