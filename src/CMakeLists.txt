add_executable(main main.c main.h database.c preferences.c grocery_list.c calculations.c sort_shopping_list.c CreateMenu.c CreateMenu.h)
add_executable(database database.c database.h)
file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})