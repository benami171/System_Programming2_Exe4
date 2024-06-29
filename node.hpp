#pragma once

#include <iostream>
#include <type_traits>
#include <vector>

#include "complex.hpp"

using namespace std;

template <typename T>
class Node {
   public:
    T value;
    vector<Node<T>*> children;

    // Constructor
    Node(T value) : value(value) {}

    void add_child(Node<T>* child) {
        children.push_back(child);
    }

     void delete_children() {
         for (auto child : children) {
             child->delete_children();  // Recursively delete grandchildren
             cout << "Deleting node with value " << child->value << endl;
             delete child;  // Delete the child node
         }
         children.clear();  // Clear the vector of child pointers
     }

     T& get_value() { 
        return value; 
        }

    const vector<Node<T>*>& get_children() const { return children; }


    bool operator<(const Node<T>& other) const { return value < other.value; }
    bool operator>(const Node<T>& other) const { return value > other.value; }
    bool operator==(const Node<T>& other) const { return value == other.value; }
    bool operator!=(const Node<T>& other) const { return !(*this == other); }

    string to_string() const {
        return value_to_string(value);
    }

   private:
    template <typename U>
    string value_to_string(const U& val) const {
        ostringstream oss;
        oss << val;  // Relying on the stream operator for non-Complex types
        return oss.str();
    }

    string value_to_string(const Complex& val) const {
        return val.to_string();
    }
};