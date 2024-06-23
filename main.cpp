#include "node.hpp"
#include "tree.hpp"
#include <iostream>
#include <string>
#include "complex.hpp"

using namespace std;

int main() {
    Node<double> root_node = Node(1.1);
    Tree<double> tree;  // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<double> n1 = Node(1.2);
    Node<double> n2 = Node(1.3);
    Node<double> n3 = Node(1.4);
    Node<double> n4 = Node(1.5);
    Node<double> n5 = Node(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    cout << "DFS: ";
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        cout << node->get_value() << " ";
    }  // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << endl;

    cout << "Pre order: ";
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        cout << node->get_value() << " ";
    }  // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << endl;

    cout << "Post order: ";
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        cout << node->get_value() << " ";
    }  // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout << endl;

    cout << "In order: ";
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        cout << node->get_value() << " ";
    }  // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout << endl;

    cout << "BFS: ";
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        cout << node->get_value() << " ";
    }  // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;

    cout << "Min Heap: ";
    for (auto node = tree.begin_min_heap(); node != tree.end_min_heap(); ++node) {
        cout << node->get_value() << " ";
    }
    cout << endl;



    auto heapRange = tree.myHeap();
    cout << "Min Heap: ";
    for (auto node = heapRange.first; node != heapRange.second; ++node) {
        cout << node->get_value() << " ";
    }
    cout << endl;

    // for (auto node : tree)
    // {
    //     cout << node.get_value() << endl;
    // } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    // cout << tree; // Should print the graph using GUI.
    Tree<double, 3> three_ary_tree;  // 3-ary tree.
    three_ary_tree.add_root(root_node);
    three_ary_tree.add_sub_node(root_node, n1);
    three_ary_tree.add_sub_node(root_node, n2);
    three_ary_tree.add_sub_node(root_node, n3);
    three_ary_tree.add_sub_node(n1, n4);
    three_ary_tree.add_sub_node(n2, n5);

    cout << "Pre order-3ary: ";
    for (auto node = three_ary_tree.begin_pre_order(); node != three_ary_tree.end_pre_order(); ++node) {
        cout << node->get_value() << " ";
    }  // prints: 1.1, 1.2, 1.5, 1.3, 1.6, 1.4
    cout << endl;

       cout << "IN order-3ary: ";
    for (auto node = three_ary_tree.begin_in_order(); node != three_ary_tree.end_in_order(); ++node) {
        cout << node->get_value() << " ";
    }
    cout << endl;

    cout << "Post order-3ary: ";
    for (auto node = three_ary_tree.begin_post_order(); node != three_ary_tree.end_post_order(); ++node) {
        cout << node->get_value() << " ";
    } // prints: 1.1, 1.2, 1.5, 1.3, 1.6, 1.4
    cout << endl;

    // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */


    cout << " COMPLEX TREE: " << endl;
     Node<Complex> c_root = Node<Complex>(1.1, 2.0);
     Tree<Complex> complex_tree;  // Binary tree that contains doubles.
     complex_tree.add_root(c_root);
     Node<Complex> c1 = Node<Complex>(1.2,0.3); // 1.2 , 0.3
     Node<Complex> c2 = Node<Complex>(1.3,0.5); // 1.3 , 0.5
     Node<Complex> c3 = Node<Complex>(1.4,0.7); // 1.4 , 0.7
     Node<Complex> c4 = Node<Complex>(1.5);
     Node<Complex> c5 = Node<Complex>(1.6);

    complex_tree.add_sub_node(c_root, c1);
    complex_tree.add_sub_node(c_root, c2);
    complex_tree.add_sub_node(c1, c3);
    complex_tree.add_sub_node(c1, c4);
    complex_tree.add_sub_node(c2, c5);

    // The tree should look like:
    /**
     *      root =  1.1,2
     *          /          \
     *         1.2,0.3      1.3,0.5
     *        /  \          /
     *  1.4,0.7  1.5,0   1.6,0
     */

    cout << "DFS: ";
    for (auto node = complex_tree.begin_dfs_scan(); node != complex_tree.end_dfs_scan(); ++node) {
        cout << node->get_value() << " ";
    }  // prints: {1.1,2} {1.2,0.3} {1.4,0.7} {1.5,0} {1.3,0.5} {1.6,0}
    cout << endl;

    cout << "Pre order: ";
    for (auto node = complex_tree.begin_pre_order(); node != complex_tree.end_pre_order(); ++node) {
        cout << node->get_value() << " ";
    }  // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << endl;

    cout << "Post order: ";
    for (auto node = complex_tree.begin_post_order(); node != complex_tree.end_post_order(); ++node) {
        cout << node->get_value() << " ";
    }  // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout << endl;

    cout << "In order: ";
    for (auto node = complex_tree.begin_in_order(); node != complex_tree.end_in_order(); ++node) {
        cout << node->get_value() << " ";
    }  // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout << endl;

    cout << "BFS: ";
    for (auto node = complex_tree.begin_bfs_scan(); node != complex_tree.end_bfs_scan(); ++node) {
        cout << node->get_value() << " ";
    }  // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;

    cout << "Min Heap: ";
    for (auto node = complex_tree.begin_min_heap(); node != complex_tree.end_min_heap(); ++node) {
        cout << node->get_value() << " ";
    }
    cout << endl;

    cout << "Finished Complex Tree" << endl;
}