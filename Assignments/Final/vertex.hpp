#pragma once

struct vertex {
    char id;
    int distance;
    int degree;
    vertex *prev;
    vertex *listNext;
};
