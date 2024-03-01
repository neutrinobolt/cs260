#pragma once

#include "binNode.hpp"

class BinSTree {

    public:
        //Constructor and destructor
        BinSTree();
        ~BinSTree();

        //BinTree functions
        void add(int newVal);
        bool search();
        void remove();
        void ioTraversal();

        //root
        BinNode *root;

    private:
        //Secondary functions
        BinNode *addStep(BinNode *checkParent, BinNode *newNode);
        bool searchStep();
        BinNode *findSuccessor(BinNode *checkNode);

};
