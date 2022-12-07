# BargainHunting
A program that streamlines the process of saving money on groceries, include entire shopping trips in such a way that the user would not need to visit other stores or employ the use of other programs

## Features
1. Get your entire shopping list done in one go!
2. Always get the cheapest and best deals!

## Contribute to a great open source project making your and others lives much better in the process!


# Documentation

## main.c


## search.c
search.c has a function called ProductSearch that searches a given database of products and tags for a search term entered by the user. The function first prompts the user to input a search term, and continues to do so until a valid search term is entered (i.e. a search term that results in at least one product being found). If the user inputs the string "q", the function will return -1, indicating that the user has decided to go back to the previous menu.

The function uses three helper functions to search the database: SearchProduct, SearchTag, and BroadSearch. The SearchProduct function searches for products whose names exactly match the search term. The SearchTag function searches for tags whose names exactly match the search term, and then returns any products that are associated with those tags. The BroadSearch function searches for products whose names contain the search term, and then searches for tags whose names contain the search term, returning any products that are associated with those tags.

After the search is completed, the function returns the result of calling the SearchMenu function, which displays the search results to the user and allows them to interact with the found products.


## database.c
This code is a C program that reads a file named "data/data.txt" and loads it into memory as a data_t data structure. data_t is a user-defined type that is defined in the file "database.h", which is included in this code. The file "data/data.txt" contains information about products in the following format:

name,price,pricePerKilo,weight,store,tags
"Product1",10.0,20.0,5.0,"Store1","Tag1,Tag2"
"Product2",5.0,15.0,2.5,"Store1","Tag2,Tag3"
...

The code begins by opening the file for reading and checking that the file pointer is not NULL. If the file pointer is NULL, the program exits with an error code of -1. Otherwise, the code allocates memory for a data_t data structure and initializes its members.

Next, the code reads the file line by line and counts the number of lines in the file, excluding the first line (which contains the column names). This value is stored in the productSize member of the data_t data structure. The code then rewinds the file pointer to the beginning of the file so that it can be read again from the beginning.

Next, the code allocates enough memory to store the products by allocating an array of product_t structures with a size equal to the number of products in the file. product_t is another user-defined type that is defined in "database.h". Each product_t structure contains the following members:

    name: a string containing the name of the product
    price: a floating-point value containing the price of the product
    pricePerKilo: a floating-point value containing the price per kilogram of the product
    weight: a floating-point value containing the weight of the product
    store: a string containing the name of the store where the product is sold
    tags: an array of tag_t structures containing the tags associated with the product

The code then reads the file line by line, parsing each line and extracting the values for each member of the product_t structure. The values are then stored in the product_t structure, and the structure is added to the products array in the data_t data structure.

As the code reads the file, it also extracts the tags for each product and stores them in the tags array of the data_t data structure. The tags array is an array of tag_t structures, each of which contains the following members:

    name: a string containing the name of the tag

The code also creates a link_table_t structure for each tag, which contains the following members:

    indexOfProduct: the index of the product in the products array
    indexOfTag: the index of the tag in the tags array

These link_table_t structures are stored in the linkTable array of the data_t data structure.

Once all the products have been read and stored in the data_t data structure, the code returns a pointer to the data_t data structure.


## listeditor.c
This code is a simple list editor that allows users to create and edit shopping lists. The ListEditor function first calls GetExistingLists, which scans the ./data/shopping_list/ directory for existing lists and presents the user with a menu of options to either create a new list, go back, or select an existing list. If the user selects an existing list, the name of the list is returned in the test argument, which is then used to construct the path to the file containing the list.

The ListEditor function then opens the file and reads its contents line by line, printing each line to the screen. It also creates an options menu with the following options: "exit", "search", and "adding an item". If the user selects the "exit" option, the program exits the loop and ends. If the user selects the "search" option, the ListSearch function is called, which is not defined in this code. If the user selects the "adding an item" option, the program prompts the user for the name of an item to add, appends it to the file, and adds it to the list of options in the menu.

Finally, if the user selects any other option in the menu, it is assumed to be the name of an item in the shopping list. The program then removes that item from the file and the list of options in the menu. This process continues until the user selects the "exit" option, at which point the program returns.


## CreateMenu.c
This code defines a function CreateMenu() that takes in a 2D array of strings as an argument and generates a numbered menu from the strings. The user is then prompted to input a number corresponding to their desired option from the menu, and the function returns the selected option as an integer.

For example, if the options array contains the following strings:
```c
{
"Option 1",
"Option 2",
"Option 3"
}
```
then calling CreateMenu(options) would generate the following menu:
```
-------------------------------------------------
1) Option 1
-------------------------------------------------
2) Option 2
-------------------------------------------------
3) Option 3
-------------------------------------------------
```
The user would be prompted to input a number (e.g. "Please input the number corresponding to your desired option: "), and the function would return the selected option as an integer (e.g. 1, 2, or 3).

The code also defines two helper functions: Draw() and ScanInput(). The Draw() function is responsible for generating the menu by printing each string in the options array to the screen, along with a number corresponding to its position in the array. The ScanInput() function prompts the user to input a number and then checks that the input is valid (i.e. a positive integer no greater than the number of items in the menu) before returning it.


This documentation was written with the help of OpenAi's [chatGPT](https://chat.openai.com/chat). 


