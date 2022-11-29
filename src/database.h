//
// Created by manta on 21/11/2022.
//

#ifndef BARGAINHUNTING_DATABASE_H
#define BARGAINHUNTING_DATABASE_H
typedef struct {
    char* name;
}tag_t;
//struct for products - first five vars are expected to always be included, with an optional number of tags also points to next product or null if it is the last one
typedef struct {
    char* name;
    double price;
    double pricePerKilo;
    double weight;
    char* store;
}product_t;
typedef struct {
    int indexOfTag;
    int indexOfProduct;
}link_table_t;

//a combined struct to access all data includes a pointer to first product
typedef struct {
    product_t * products;
    int productSize;
    tag_t* tags;
    int tagSize;
    link_table_t * linkTable;
    int linkTableSize;
}data_t;
/***
 * function that load the data in and returns in
 * @return returns data_t struct which includes all data each child of data_t is a product linking to the next one
 */
data_t*  LoadDatabase();
int GetStrLength(const char* data);
#endif //BARGAINHUNTING_DATABASE_H
