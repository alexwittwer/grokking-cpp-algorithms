#include <iostream>
#include <queue>

template <typename T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;

    Node(T val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
class BinaryTree
{
private:
    Node<T>* root;

public:
    BinaryTree(T val)
    {
        root = new Node<T>(val);
    }

    ~BinaryTree()
    {
        deleteTree(root);
    }

    void buildTree(std::vector<T> arr)
    {
    }

    void deleteNode()
    {
    }

    void find(T val)
    {
    }

    void inorder()
    {
    }

    void printInorder()
    {
    }

    void preorder()
    {
    }

    void printPreorder()
    {
    }

    void postorder()
    {
    }

    void printPostorder()
    {
    }

    void levelorder()
    {
    }

    void printLevelOrder()
    {
    }

    void insert(T val)
    {
        Node<T>* node = root;
        Node<T>* current = node;

        while(true){
            if (val < current->data) {
                if (!current->left){
                    current->left = new Node<T>(val);
                    break;
                }
               current = current->left;
            } else if (val > current->data){
                if (!current->right){
                    current->right = new Node<T>(val);
                    break;
                }
                current = current->right;
            } else {
                std::cout << "Cannot insert value into tree.\n";
            }
        }
    }


    int height(Node<T> *node)
    {

        return 0;
    }

    int depth(T val) {

        return 0;
    }

    bool isBalanced() {

        return false;
    }

    void rebalance() {

    }

    void printHeight()
    {
    }

    void deleteTree(Node<T> *node)
    {
        if (node)
        {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    // Code was taken from The Odin Project's assignment on BST. 
    // Link: https://www.theodinproject.com/lessons/javascript-binary-search-trees
    void prettyPrint(Node<T> *node, const std::string &prefix = "", bool isLeft = true)
    {
        if (!node)
        {
            return;
        }
        if (node->right)
        {
            prettyPrint(node->right, prefix + (isLeft ? "│   " : "    "), false);
        }
        std::cout << prefix << (isLeft ? "└── " : "┌── ") << node->data << std::endl;
        if (node->left)
        {
            prettyPrint(node->left, prefix + (isLeft ? "    " : "│   "), true);
        }
    }

    void printTree()
    {
        prettyPrint(root);
    }
};

int main()
{
    BinaryTree<int> btree(5);

    btree.insert(4);
    btree.insert(3);
    btree.insert(6);
    btree.insert(9);
    btree.insert(10);

    btree.printTree();
    btree.insert(8);
    btree.printTree();

    return 0;
}