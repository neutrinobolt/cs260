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
            // Make sure val is present in tree

            // Get node

            // If node has no children:

            // If node has 1 child: 
        };

        void BinSTree::ioTraversal() {
            // Start at root
            travStep(this->root);
            cout << endl;
        };
        //Secondary private functions

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
        BinNode *BinSTree::findSuccessor(BinNode *checkNode) {
            BinNode *result = checkNode;
            // Do stuff
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

 