#include <iostream>
#include <vector>

using namespace std;

// Node class to represent a chapter, section, or subsection
class Node {
public:
    string name;
    vector<Node*> children;

    Node(const string& nodeName) : name(nodeName) {}
};

// Function to print the nodes of the tree using depth-first traversal
void printNodes(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->name << endl;

    for (Node* child : root->children) {
        printNodes(child);
    }
}

int main() {
    // Create nodes for chapters, sections, and subsections
    Node* chapter1 = new Node("Chapter 1");
    Node* section1_1 = new Node("Section 1.1");
    Node* subsection1_1_1 = new Node("Subsection 1.1.1");
    Node* section1_2 = new Node("Section 1.2");
    Node* chapter2 = new Node("Chapter 2");
    Node* section2_1 = new Node("Section 2.1");
    Node* section2_2 = new Node("Section 2.2");
    Node* subsection2_2_1 = new Node("Subsection 2.2.1");
    Node* subsection2_2_2 = new Node("Subsection 2.2.2");

    // Build the tree by setting parent-child relationships
    chapter1->children.push_back(section1_1);
    section1_1->children.push_back(subsection1_1_1);
    chapter1->children.push_back(section1_2);
    chapter2->children.push_back(section2_1);
    chapter2->children.push_back(section2_2);
    section2_2->children.push_back(subsection2_2_1);
    section2_2->children.push_back(subsection2_2_2);

    // Print the nodes of the tree
    cout << "Nodes of the book:" << endl;
    printNodes(chapter1);
    printNodes(chapter2);

    // Deallocate memory
    delete chapter1;
    delete section1_1;
    delete subsection1_1_1;
    delete section1_2;
    delete chapter2;
    delete section2_1;
    delete section2_2;
    delete subsection2_2_1;
    delete subsection2_2_2;

    return 0;
}
