# niuke_linked_list
 This repository contains some linked list practice problems for Niuke exercises.

in this problem, the record of initial places before move is essential
need pay attention to the if (head->data == m), if m or n is not in the list, if n is before m
is_head = 1 if m is data of head
curr is for moving on linked list
next is for recording the curr->next before movement
prev is for identifying the place of the first one of list after move
temp is for remerbering the ele before m for relink the reversed sublist
last is for recording the place of the sublist's end in case of revers.