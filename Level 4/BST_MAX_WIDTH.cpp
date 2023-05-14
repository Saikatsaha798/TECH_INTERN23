#include <iostream>
#include <queue>
using namespace std;

// Structure for a BST node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new BST node
Node* createNode(int value) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to find the maximum width of the BST
int maxWidth(Node* root) {
    if (root == NULL)
        return 0;

    int maxWidth = 0;

    // Use a queue to perform BFS
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int count = q.size();
        maxWidth = max(maxWidth, count);

        while (count--) {
            Node* temp = q.front();
            q.pop();

            // Enqueue left and right children
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }

    return maxWidth;
}

int main() {
    // Create the BST
    Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    int width = maxWidth(root);
    cout << "Maximum width of the BST is: " << width << endl;

    return 0;
}#include <iostream>
#include <queue>
using namespace std;

// Structure for a BST node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new BST node
Node* createNode(int value) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to find the maximum width of the BST
int maxWidth(Node* root) {
    if (root == NULL)
        return 0;

    int maxWidth = 0;

    // Use a queue to perform BFS
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int count = q.size();
        maxWidth = max(maxWidth, count);

        while (count--) {
            Node* temp = q.front();
            q.pop();

            // Enqueue left and right children
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }

    return maxWidth;
}

int main() {
    // Create the BST
    Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    int width = maxWidth(root);
    cout << "Maximum width of the BST is: " << width << endl;

    return 0;
}
