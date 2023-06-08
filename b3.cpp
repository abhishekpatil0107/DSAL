#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    bool isThreaded;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
        isThreaded = false;
    }
};

Node* createThreadedBinaryTree(Node* root) {
    if (root == NULL)
        return NULL;

    // Find the predecessor of the root node
    Node* pre = NULL;
    Node* current = root;
    if (current->left != NULL)
        pre = createThreadedBinaryTree(current->left);

    // Set threading link from predecessor to root
    if (pre != NULL) {
        pre->right = current;
        pre->isThreaded = true;
    }

    // Find the successor of the root node
    if (current->right != NULL)
        return createThreadedBinaryTree(current->right);

    // Return the current node as a predecessor for the next recursion
    return current;
}

void inorderTraversal(Node* root) {
    Node* current = root;

    while (current != NULL) {
        // Find the leftmost node in the current subtree
        while (current->left != NULL)
            current = current->left;

        // Print the data of the current node
        cout << current->data << " ";

        // If the node has a threading link, move to the threaded node
        if (current->isThreaded)
            current = current->right;
        else {
            // Otherwise, move to the right child
            current = current->right;
            if (current != NULL)
                cout << current->data << " ";
        }
    }
}

int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Convert the binary tree to a threaded binary tree
    createThreadedBinaryTree(root);

    // Perform inorder traversal on the threaded binary tree
    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
