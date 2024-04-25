#include <iostream>
#include <queue>
#include <vector>

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
    Node<T> *root;

public:
    BinaryTree()
    {
        root = nullptr;
    }

    BinaryTree(T val)
    {
        root = new Node<T> *(val);
    }

    ~BinaryTree()
    {
        deleteTree(root);
    }

    void buildTree(std::vector<T> arr)
    {
        for (T val : arr)
        {
            insert(val);
        }
    }

    void deleteNode()
    {
    }

    auto find(T val)
    {
        Node<T> *current = root;

        while (true)
        {
            if (current->data == val)
            {
                return current;
            }

            if (current->data < val)
            {
                current = current->left;
            }
            else if (current->data > val)
            {
                current = current->right;
            }
            else
            {
                std::cout << "Could not find value.\n";
                Node<T> *emp_Node;
                return emp_Node;
            }
        }
    }

    auto inorder()
    {
    }

    void printInorder()
    {
    }

    auto preorder()
    {
    }

    void printPreorder()
    {
    }

    auto postorder()
    {
    }

    void printPostorder()
    {
    }

    auto levelorder()
    {
    }

    void printLevelOrder()
    {
    }

    void insert(T val)
    {
        if (!root)
        {
            root = new Node<T>(val);
            return;
        }

        Node<T> *node = root;
        Node<T> *current = node;

        while (true)
        {
            if (val < current->data)
            {
                if (!current->left)
                {
                    current->left = new Node<T>(val);
                    return;
                }
                current = current->left;
            }
            else if (val > current->data)
            {
                if (!current->right)
                {
                    current->right = new Node<T>(val);
                    return;
                }
                current = current->right;
            }
            else
            {
                // Fails
                std::cout << "Cannot insert value into tree: " << val << "\n";
                return;
            }
        }
    }

    // https://stackoverflow.com/questions/2597637/finding-height-in-binary-search-tree
    int height(Node<T> *node)
    {
        if (!node)
        {
            return -1;
        }

        int heightLeft = height(node->left);
        int heightRight = height(node->right);

        if (heightLeft > heightRight)
        {
            return 1 + heightLeft;
        }
        else
        {
            return 1 + heightRight;
        }
    }

    void printHeight()
    {
        std::cout << "Height of tree: " << height(root) << "\n";
    }

    int depth(T val)
    {
        int depth = 0;
        Node<T> *current = root;
        while (true)
        {
            if (current->data == val)
            {
                std::cout << "Value depth: " << depth << "\n";
                return depth;
            }

            if (val < current->data)
            {
                current = current->left;
                depth += 1;
            }
            else if (val > current->data)
            {
                current = current->right;
                depth += 1;
            }
        }

        // Could not find value
        std::cout << "Could not find value.\n";

        return 0;
    }

    bool isBalanced()
    {
        int depthRight = height(root->right);
        int depthLeft = height(root->left);

        return std::abs(depthRight - depthLeft) <= 1;
    }

    void rebalance()
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
    std::vector<int> buildArray = {1, 2, 3, 4, 5, 9, 8, 7, 6, 15, 15};
    BinaryTree<int> btree;

    btree.buildTree(buildArray);

    btree.printTree();

    btree.printHeight();

    btree.depth(5);

    std::string balance = btree.isBalanced() ? "True" : "False";

    std::cout << "Tree is balanced: " << balance << "\n";

    return 0;
}