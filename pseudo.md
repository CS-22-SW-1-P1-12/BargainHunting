# Needed top-level functions

## load database

* Opens the text file containing the data
* Makes program able to search the data

## load preferences

* asks the user to recall saved preferences from a text file

## save preferences

* asks the user to save preferences to a text file

## settings function

* Input certain preferences (like any or choose certain products)
  * Absolute price vs price per kg

## preferences function

* Lets you input brands or stores or such to filter 
* Ability to limit preferences to certain products per store

## grocery list input function
    
* Input name of product or q to end input phase
* If not q shows possible products with first one being "any"
* If no products are found, return an error

## one store calculation function

* Uses the grocery list and searches the database
* This function is called for each store to calculate the price of the list
* Also calculated how many products can be found in the store

## shopping list sorting

* Sorts the output of the calculation from the cheapest total 

## print resulting options

* Uses the output of the calculation to print to the user
* Starts with cheapest
* Shows the price of each product and how many are available in the store

## multi-store calculation function

* Calculates the cheapest products across stores
* Returns a list of products with their stores


# Wanted top-level functions

## Distance preference

* Lets the user input their location
* Lets them input a maximum distance
* Filters out any stores too far away