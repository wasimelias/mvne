//
// Created by wasim on 20/05/2023.
//

#include <iostream>
#include <vector>
#include <ostream>
#include <random>
#include <chrono>
#include <algorithm>
#include <memory>
#include <cassert>
#include "streaming_database.h"

int main(){

   /* BinaryTree<int,int> test_tree;
    int* a = new int(1);
    int* b = new int(5);
    int* c = new int(23);
    int* d = new int(69);
    int* e = new int(96);
    int* f = new int(119);
    int* g = new int(90);
    int* h = new int(200);


    Node<int,int>* node1 = new Node<int,int> (*a,*a);
    Node<int,int>* node2 = new Node<int,int> (*b,*b);
    Node<int,int>* node3 = new Node<int,int> (*c,*c);
    Node<int,int>* node4 = new Node<int,int> (*d,*d);
    Node<int,int>* node5 = new Node<int,int> (*e,*e);
    Node<int,int>* node6 = new Node<int,int>(*f,*f);
    Node<int,int>* node7 = new Node<int,int>(*g,*g);
    Node<int,int>* node8 = new Node<int,int>(*h,*h);

    test_tree.add_node(node1);
    test_tree.add_node(node3);
    test_tree.add_node(node2);
    test_tree.add_node(node5);
    test_tree.add_node(node4);
    test_tree.add_node(node6);
    test_tree.add_node(node7);
    test_tree.add_node(node8);

    test_tree.Delete(90);

    std::cout << "hi" ;
    PrintNode<int,int> print_func;
    print_func(test_tree.get_root());
    std::cout << "why";
    test_tree.postOrder<PrintNode<int,int>>(print_func,test_tree.get_root());
    test_tree.DestroyTree();
    return 0;
    */

   streaming_database s1;
   s1.add_movie(1,Genre::COMEDY,0,true);
   s1.add_movie(2,Genre::ACTION,1,false);
   s1.add_movie(4,Genre::FANTASY,2,false);
   s1.add_movie(3,Genre::FANTASY,3,true);
   s1.add_user(20,true);
   s1.add_user(19,true);
   s1.add_user(18,false);
   s1.add_user(20,true);
   s1.remove_movie(1);
   s1.remove_user(4);
   s1.add_group(212);
   s1.add_user_to_group(20,212);
   s1.add_user_to_group(19,212);
   if(s1.user_watch(20,4) == StatusType::ALLOCATION_ERROR) return 20;
   s1.user_watch(19,3);
   s1.user_watch(19,2);
   s1.group_watch(212, 3);
   int* const movies = new int[3]();
   std::cout << s1.get_all_movies_count(Genre::NONE).ans() << std::endl;
   std::cout << s1.get_all_movies_count(Genre::COMEDY).ans() << std::endl;
   std::cout << s1.get_all_movies_count(Genre::FANTASY).ans() << std::endl;
   s1.get_all_movies(Genre::NONE , movies);
   s1.rate_movie(19,2,100);
   for(int i=0 ; i<3 ;i++){
       std::cout << movies[i] << "  ";
   }
}