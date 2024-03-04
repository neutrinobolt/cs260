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
        void remove(int remVal);
        void ioTraversal();
        bool search(int searchVal);

        //root
        BinNode *root;

    private:
        //Secondary functions
        BinNode *addStep(BinNode *checkParent, BinNode *newNode);
        BinNode *getNode(int nodeVal);
        BinNode *getHelper(BinNode *checkNode, int nodeVal);
        BinNode *findSuccessor(BinNode *checkNode);
        BinNode *succHelp(BinNode *checkNode);
        bool searchStep(int searchVal, BinNode *checkNode);
        void travStep(BinNode *step);


};
