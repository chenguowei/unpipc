cmake_minimum_required(VERSION 3.8)
project(unpipc)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp my_rwlock/pthread_rwlock_trywrlock.c my_rwlock/pthread_rwlock_unlock.c my_rwlock_cancel/pthread_rwlock_rdlock.c my_rwlock_cancel/pthread_rwlock_wrlock.c lock/test2.c lock/lockopen.c lock/fcntltest.c pxsem/semcreate.c pxsem/semunlink.c pxsem/semgetvalue.c pxsem/semwait.c pxsem/sempost.cpp pxsem/prodcons1.c pxsem/prodcons2.c)
add_executable(unpipc ${SOURCE_FILES})