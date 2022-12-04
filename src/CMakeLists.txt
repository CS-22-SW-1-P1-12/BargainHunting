add_executable(main main.c main.h database.c preferences.c grocery_list.c calculations.c sort_shopping_list.c CreateMenu.c CreateMenu.h search.c search.h)
add_executable(database database.c database.h)
add_executable(search search.c search.h database.c)
file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})