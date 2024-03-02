#pragma once

#include <iostream>

#include "binNode.hpp"

using std:: string;

class BinSTree {

    public:
        //Constructor and destructor
        BinSTree();
        ~BinSTree();

        //BinTree functions
        void add(int newVal);
        bool search(int searchVal);
        void remove();
        void ioTraversal();

        //root
        BinNode *root;

    private:
        //Secondary functions
        BinNode *addStep(BinNode *checkParent, BinNode *newNode);
        bool searchStep(int searchVal, BinNode *checkNode);
        BinNode *findSuccessor(BinNode *checkNode);
        void travStep(BinNode *step);

};