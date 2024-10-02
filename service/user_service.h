#ifndef HYPRSYNC_BACKEND_USER_SERVICE_H
#define HYPRSYNC_BACKEND_USER_SERVICE_H

#include "../model/user.h"

int add_user(User *user);
int remove_user_by_id(int userid);
int remove_user(User *user);
int update_user(User *user);
int get_user_by_id(int id, User **user);
int get_users_as_array(User** users, size_t users_size);

#endif //HYPRSYNC_BACKEND_USER_SERVICE_H
