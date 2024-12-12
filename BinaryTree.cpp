#include <iostream>
class TreeNode {
    public:
        int data;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;

        TreeNode(int data) {
            this->data = data;
        }
};

bool search(TreeNode* root, int target){
    if (!root) {
        return false;
    }

    if (target > root->data) {
        return search(root->right, target);
    } else if (target < root->data) {
        return search(root->left, target);
    } else {
        return true;
    }
}

TreeNode* insert(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }

    if (val > root->data) { 
        root->right = insert(root->right, val);
    } else if (val < root->data) {
        root->left = insert(root->left, val);
    }
    return root;
}

TreeNode* minValueNode(TreeNode* root) {
    TreeNode* curr = root;
    while (curr && curr->left) {
        curr = curr->left;
    }
    return curr;
}

TreeNode* remove(TreeNode* root, int val) {
    if (!root) {
        return nullptr;
    }

    if (val > root->data) { 
        root->right = remove(root->right, val);
    } else if (val < root->data) {
        root->left = remove(root->left, val);
    } else {
        if (!root->left) {
            return root->right;
        } else if (!root->right) {
            return root->left;
        } else {
            TreeNode* minNode = minValueNode(root->right);
            root->data = minNode->data;
            root->right = remove(root->right, minNode->data);
        }
    }
    return root;
}

int main() {
    TreeNode* root = nullptr;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    std::cout << "Tree after insertion:\n";
    std::cout << "50, 30, 70, 20, 40, 60, 80\n";

    std::cout << "\nSearching for values:\n";
    std::cout << "Is 40 in the tree? " << (search(root, 40) ? "Yes" : "No") << std::endl;
    std::cout << "Is 90 in the tree? " << (search(root, 90) ? "Yes" : "No") << std::endl;

    std::cout << "\nRemoving values:\n";
    root = remove(root, 20);
    std::cout << "Removed 20. Is 20 in the tree? " << (search(root, 20) ? "Yes" : "No") << std::endl;

    root = remove(root, 30);
    std::cout << "Removed 30. Is 30 in the tree? " << (search(root, 30) ? "Yes" : "No") << std::endl;

    root = remove(root, 50);
    std::cout << "Removed 50. Is 50 in the tree? " << (search(root, 50) ? "Yes" : "No") << std::endl;

    return 0;
}