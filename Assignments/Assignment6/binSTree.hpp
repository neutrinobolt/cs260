#pragma once

#include "binNode.hpp"

class BinSTree {

    public:
        //Constructor and destructor
        BinSTree();
        ~BinSTree();

        //BinTree functions
        void add();
        bool search();
        void remove();
        void ioTraversal();

        //root
        BinNode *root;

    private:
        //Secondary functions
        void addStep();
        bool searchStep();
        BinNode *findSuccessor();

};
