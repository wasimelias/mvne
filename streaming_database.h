//
// Created by wasim on 21/05/2023.
//

#ifndef WET1_STREAMING_DATABASE_H
#define WET1_STREAMING_DATABASE_H
#include "Group.h"


class streaming_database{

    BinaryTree<int,User> users_tree ;
    BinaryTree<std::shared_ptr<Movie>,int> comedy_tree;
    BinaryTree<std::shared_ptr<Movie>,int> drama_tree ;
    BinaryTree<std::shared_ptr<Movie>,int> fantasy_tree;
    BinaryTree<std::shared_ptr<Movie>,int> action_tree;
    BinaryTree<int,Movie> none_tree_by_id;
    BinaryTree<std::shared_ptr<Movie>,int> none_tree_by_rating;
    BinaryTree<int,Group> group_tree;
    BinaryTree<int,Group> empty_groups_tree;


public:


    streaming_database() = default;

    virtual ~streaming_database();

    StatusType add_movie(int movieId , Genre genre , int views , bool vipOnly);

    StatusType remove_movie(int movieId);

    StatusType add_user(int userId, bool isVip);

    StatusType remove_user(int userId);

    StatusType add_group(int groupId);

    StatusType remove_group(int groupId);

    StatusType add_user_to_group(int userId, int groupId);

    StatusType user_watch(int userId, int movieId);

    StatusType group_watch(int groupId, int movieId);

    output_t < int > get_all_movies_count(Genre genre);

    StatusType get_all_movies(Genre genre, int* const output);

    output_t < int > get_num_views(int userId, Genre genre);

    StatusType rate_movie(int userId, int movieId, int rating);

    output_t < int > get_group_recommendation(int groupId);


};

class removeUserFromGroup{
    Group& usersGroup;
public:
    explicit removeUserFromGroup(Group& grp) : usersGroup(grp){}
    void operator()(Node<int,User>* user_to_remove){
        std::shared_ptr<User> RemoveUser = user_to_remove->get_data();
        int* group_views_array = usersGroup.get_views_array();
        RemoveUser->nullify(group_views_array);
    }
};


#endif //WET1_STREAMING_DATABASE_H
