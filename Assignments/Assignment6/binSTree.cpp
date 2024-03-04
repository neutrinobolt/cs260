#include <iostream>

#include "binSTree.hpp"

using std::cout;
using std::endl;


        
        //Constructor and destructor
        BinSTree::BinSTree() {
            this->root = nullptr;
            cout << "Tree constructed successfully." << endl;
        };

        BinSTree::~BinSTree() {
            while (this->root != nullptr) {
                cout << "deleting node: " << this->root->value << endl;
                remove(this->root->value);
                cout << "Node deleted" << endl;
                cout << "Current root: " << this->root->value << endl;
                cout << "root.right: " << this->root->right->value << endl;
                cout << "root.left: " << this->root->left->value << endl;
                this->ioTraversal();
            }
            delete this->root;
            cout << "Tree destroyed successfully." << endl;
        };

        //BinTree functions

        void BinSTree::add(int newVal) {
            // Create new node
            BinNode *newNode = new BinNode;
            newNode->value = newVal;

            // If root is nullptr, set root to newNode
            if (this->root == nullptr) {
                this->root = newNode;
            }  else {

                // Find parent to add under
                BinNode *addParent = addStep(this->root, newNode);

                // Properly connect addParent and newNode
                newNode->parent = addParent;
                if (addParent->value > newNode->value) {
                    addParent->left = newNode;
                } else {
                    addParent->right = newNode;
                };
            }
            // cout << "New node of value " << newVal << " added." << endl; // Debug
        };

        bool BinSTree::search(int searchVal) {
            // Run searchStep on root, return result
            bool result = searchStep(searchVal, this->root);
            return result; 
        };

        void BinSTree::remove(int remVal) {
            // cout << "Attempting to delete node of value " << remVal << endl; // debug
            // Make sure val is present in tree
            // cout << "Searching for node: " << remVal << endl; // debug
            if (this->search(remVal) == false) {
                cout << "ERROR, node of value " << remVal << " does not exist in this tree." << endl;
            }
            else {
                // cout << "Found node of value" <<remVal << endl; // debug
                // Get node
                BinNode *remNode = this->getNode(remVal);
                // cout << "Collected data for node of value: " << remNode->value << endl; // debug

                // [Megamind meme] "No children???"
                BinNode *remParent = remNode->parent;
                if (remNode->left == nullptr && remNode->right == nullptr) {
                    // cout << "Deleting node with no children..." << endl;
                    if (remParent->value > remVal) {
                        remParent->left = nullptr;
                    } else {
                        remParent->right = nullptr;
                    }
                    // Root deletion catcher
                    if (remNode == this->root) {
                        this->root = nullptr;
                    } 
                    // cout << "Node removed from tree." << endl;
                    delete remNode;
                    // cout << "Node destroyed." << endl;
                    // cout << "Deleted node with no children of value: " << remVal << endl;
                }

                // If node has 1 spoiled brat of a child: 
                // Child on left
                else if (remNode->right == nullptr) {
                    // Set left child to child of parent, delete remNode
                    if (remParent->value > remVal) {
                        remParent->left = remNode->left;
                    }
                    else {
                        remParent->right = remNode->left;
                    }
                    // Root deletion catcher
                    if (remNode == this->root) {
                        this->root = remNode->left;
                    }
                    delete remNode;
                    // cout << "Deleted node with one left child of value: " << remVal << endl;
                }
                // Child on right
                else if (remNode->left == nullptr) {
                    // Set left child to child of parent, delete remNode
                    if (remParent->value > remVal) {
                        remParent->left = remNode->right;
                    }
                    else {
                        remParent->right = remNode->right;
                    }
                    // Root deletion catcher
                    if (remVal == this->root->value) {
                        // cout << "Deleting root node." << endl;
                        this->root = remNode->left;
                        // cout << "Root node replaced." << endl;
                    }
                    delete remNode;
                    // cout << "Deleted node with one right child of value: " << remVal << endl;
                }
                // If node has 2 children (The hard one): 
                else {
                    // Find successor
                    BinNode *successor = findSuccessor(remNode);
                    // Replace remNode with successor
                    // cout << "Changing node paths:" << endl;

                    // Pointers to succ:
                    remNode->left->parent = successor;
                    remNode->right->parent = successor;
                    // cout << "Updated child paths to new node" << endl;
                    // White out pointer from old parent
                    if (successor != remNode->right) {
                        successor->parent->left = successor->right;
                    } 
                    // cout << "Updated parent path to new node" << endl;
                    // Point remParent to successor
                    if (remParent != nullptr) {
                        if (remParent->value > remVal) {
                            remParent->left = successor;
                        } else {
                            remParent->right = successor;
                        // cout << "Pointed parent to successor." << endl;
                        }
                    }
                    // Pointers from succ:
                    // cout << "Changing successor pointers:" << endl;
                    successor->parent = remParent;
                    successor->left = remNode->left;
                    if (successor != remNode->right) {
                        successor->right = remNode->right;
                    }
                    // cout << "Node paths deleted." << endl;
                    // Root deletion catcher
                    if (remNode == this->root) {
                        // cout << "Deleting root node." << endl;
                        this->root = successor;
                        // cout << "Root node replaced." << endl;
                    }
                    // Delete remNode
                    // cout << "deleting node:" << endl;
                    delete remNode;
                    // cout << "Node deleted." << endl;
                    // cout << "Successfully deleted node of value " << remVal;
                    // cout << " and replaced with successor of value " << successor->value << endl;
                }

            }

        };

        void BinSTree::ioTraversal() {
            // Start at root
            travStep(this->root);
            cout << endl;
        };
        ////////////////////////////////////////////////////////////////
        //Secondary private functions
        ////////////////////////////////////////////////////////////////

        // Find parent to add node under
        BinNode *BinSTree::addStep(BinNode *checkParent, BinNode *newNode) {
            BinNode *result = checkParent;

            // if check > new:
            if (checkParent->value > newNode->value) {
                if (checkParent->left != nullptr) {
                    result = addStep(checkParent->left, newNode);
                }
            }
            // if new >= check:
            else {
                if (checkParent->right != nullptr) {
                    result = addStep(checkParent->right, newNode);
                }
            }
            // cout << "Parent result: " << result->value << endl; // Debug
            return result;
        };
        bool BinSTree::searchStep(int searchVal, BinNode *checkNode) {
            bool result = false;
            // If nodeVal == search, return true

            if (checkNode->value == searchVal) {
                result = true;
            }
            else {
                // Move to proper child node
                if (checkNode->value > searchVal && checkNode->left != nullptr) {
                    result = searchStep(searchVal, checkNode->left);
                }
                else if (checkNode->right != nullptr) {
                    result = searchStep(searchVal, checkNode->right);
                }
            }
            //
            return result;
        };

        /* Return node of input value. If multiple nodes of value are present,
        only the first appearing node of that value be returned. Does not work
        if there is no node in tree of value.*/
        BinNode *BinSTree::getNode(int nodeVal) {
            return this->getHelper(this->root, nodeVal);
        };

        BinNode *BinSTree::getHelper(BinNode *checkNode, int nodeVal) {
                // cn vs nv
                if (checkNode->value == nodeVal) {
                    return checkNode;
                }
                else if (checkNode->value > nodeVal) {
                    return getHelper(checkNode->left, nodeVal);
                }
                else {
                    return getHelper(checkNode->right, nodeVal);
                }
        };

        // Return successor to replace remNode.
        /*Initially set successor to right child
        - run succHelp*/
        BinNode *BinSTree::findSuccessor(BinNode *checkNode) {
            BinNode *result = checkNode->right;
            result = succHelp(result);
            return result;
        };

        BinNode *BinSTree::succHelp(BinNode *checkNode) {
            BinNode *result = checkNode;
            if (result->left != nullptr) {
                result = succHelp(result->left);
            }
            return result;
        };

        void BinSTree::travStep(BinNode *step) {
            string result = "";
            //Left, View, Right: run travStep on left child, view this node,
            // Run on right child
            if (step != nullptr) {
                travStep(step->left);
                cout << step->value << ", " ;
                travStep(step->right);
            }
        };
 