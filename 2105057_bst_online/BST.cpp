#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class node
{
public:
    int val;
    node *left;
    node *right;
    int cnt_node;

    node(int key)
    {
        val = key;
        left = nullptr;
        right = nullptr;
        cnt_node = 1;
    }
};

class binarySearchTree
{
private:
    node *root;
    node *rinsert(node *root, int _val)
    {
        if (root == nullptr)
        {
            node *temp = new node(_val);
            return temp;
        }

        if (_val < root->val)
        {
            root->left = rinsert(root->left, _val);
        }
        else if (_val > root->val)
        {
            root->right = rinsert(root->right, _val);
        }
        else
        {
            root->cnt_node++;
            return root;
        }
    }

    int findminimum(node *root)
    {
        if (root->left == nullptr)
        {
            return root->val;
        }
        return findminimum(root->left);
    }

    node *rdelete(node *root, int _val)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (_val < root->val)
        {
            root->left = rdelete(root->left, _val);
        }
        else if (_val > root->val)
        {
            root->right = rdelete(root->right, _val);
        }
        else
        {
            if (root->cnt_node == 1)
            {
                if (root->left == nullptr)
                {
                    node *temp = root->right;
                    delete root;
                    return temp;
                }
                else if (root->right == nullptr)
                {
                    node *temp = root->left;
                    delete root;
                    return temp;
                }

                int min_val = findminimum(root->right);
                root->val = min_val;
                root->right = rdelete(root->right, min_val);
            }
            else
            {
                root->cnt_node--;
            }
        }

        return root;
    }

    node *rfind(node *root, int _val)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        else if (root->val == _val)
        {
            return root;
        }
        else if (_val < root->val)
        {
            return rfind(root->left, _val);
        }
        else if (_val > root->val)
        {
            return rfind(root->right, _val);
        }
    }

    void inOrderTraversal(node *root, ofstream &outputFile)
    {
        if (root != nullptr)
        {
            inOrderTraversal(root->left, outputFile);
            outputFile << root->val << " ";
            inOrderTraversal(root->right, outputFile);
        }
    }
    void postOrderTraversal(node *root, ofstream &outputFile)
    {
        if (root != nullptr)
        {
            postOrderTraversal(root->left, outputFile);
            postOrderTraversal(root->right, outputFile);
            outputFile << root->val << " ";
        }
    }

    void preOrderTraversal(node *root, ofstream &outputFile)
    {
        if (root != nullptr)
        {
            outputFile << root->val << " ";
            preOrderTraversal(root->left, outputFile);
            preOrderTraversal(root->right, outputFile);
        }
    }
    string pre_show(node *root, ofstream &outputFile)
    {
        if (root == nullptr)
            return "";
        string result;
        if (root->cnt_node > 1)
        {
            result = to_string(root->val) + "[" + to_string(root->cnt_node) + "]";
        }
        else
        {
            result = to_string(root->val);
        }
        if (root->left == nullptr && root->right == nullptr)
            return result;
        result += "(" + pre_show(root->left, outputFile) + ",";
        result += pre_show(root->right, outputFile) + ")";
        return result;
    }

public:
    binarySearchTree()
    {
        root = nullptr;
    }
    void insert_node(int _val, ofstream &outputFile)
    {
        root = rinsert(root, _val);
        outputFile << "(" << pre_show(root, outputFile) << ")" << endl;
    }
    void delete_node(int _val, ofstream &outputFile)
    {
        root = rdelete(root, _val);
        outputFile << "(" << pre_show(root, outputFile) << ")" << endl;
    }
    void find_node(int _val, ofstream &outputFile)
    {
        node *found = rfind(root, _val);
        if (found != nullptr)
        {

            outputFile << "found  " << found->cnt_node << endl;
        }
        else
        {
            outputFile << "not found" << endl;
        }
    }
    void preorder(ofstream &outputFile)
    {
        preOrderTraversal(root, outputFile);
        outputFile << endl;
    }
    void postorder(ofstream &outputFile)
    {
        postOrderTraversal(root, outputFile);
        outputFile << endl;
    }
    void inorder(ofstream &outputFile)
    {
        inOrderTraversal(root, outputFile);
        outputFile << endl;
    }
};

int main()
{
    binarySearchTree bst;
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile || !outputFile)
    {
        std::cout << "Error opening files." << std::endl;
        return 1;
    }

    string input;
    while (getline(inputFile, input))
    {
        istringstream iss(input);
        string one, two;
        iss >> one >> two;

        if (one == "I")
        {
            bst.insert_node(stoi(two), outputFile);
        }
        if (one == "F")
        {
            bst.find_node(stoi(two), outputFile);
        }
        if (one == "D")
        {
            bst.delete_node(stoi(two), outputFile);
        }
        if (one == "T")
        {
            if (two == "Pre")
            {
                bst.preorder(outputFile);
            }
            if (two == "Post")
            {
                bst.postorder(outputFile);
            }
            if (two == "In")
            {
                bst.inorder(outputFile);
            }
        }
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
