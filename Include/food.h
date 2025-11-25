#ifndef FOOD_H
#define FOOD_H

#define MAX_ITEMS 50

typedef struct {
    int id;
    char name[50];
    float price;
} Food;

typedef struct {
    char name[50];
    float price;
    int quantity;
} CartItem;

extern Food menu[];
extern int menuSize;
extern CartItem cart[];
extern int cartCount;

#endif
