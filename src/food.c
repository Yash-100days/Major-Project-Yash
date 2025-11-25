#include "food.h"

Food menu[] = {
    {1, "Pizza", 199},
    {2, "Burger", 99},
    {3, "Pasta", 149},
    {4, "French Fries", 79},
    {5, "Cold Coffee", 89}
};
int menuSize = 5;

CartItem cart[MAX_ITEMS];
int cartCount = 0;
