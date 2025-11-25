#include <stdio.h>
#include <string.h>
#include "food.h"
#include "utils.h"

void displayMenu() {
    printf("\n--------- MENU ----------\n");
    for (int i = 0; i < menuSize; i++) {
        printf("%d. %s - Rs %.2f\n",
               menu[i].id,
               menu[i].name,
               menu[i].price);
    }
    printf("-------------------------\n");
}

void addToCart(int id, int qty) {
    if (id < 1 || id > menuSize) {
        printf("Invalid item ID!\n");
        return;
    }

    strcpy(cart[cartCount].name, menu[id - 1].name);
    cart[cartCount].price = menu[id - 1].price;
    cart[cartCount].quantity = qty;
    cartCount++;

    printf("%s (×%d) added to cart!\n", menu[id - 1].name, qty);
}

void viewCart() {
    if (cartCount == 0) {
        printf("\nYour cart is empty!\n");
        return;
    }

    printf("\n--------- YOUR CART ---------\n");
    float subtotal = 0;

    for (int i = 0; i < cartCount; i++) {
        float itemTotal = cart[i].price * cart[i].quantity;
        printf("%s (×%d) - Rs %.2f\n",
               cart[i].name,
               cart[i].quantity,
               itemTotal);
        subtotal += itemTotal;
    }

    printf("------------------------------\n");
    printf("Subtotal: Rs %.2f\n", subtotal);
}

void checkout() {
    if (cartCount == 0) {
        printf("\nCart is empty! Cannot checkout.\n");
        return;
    }

    float subtotal = 0;
    for (int i = 0; i < cartCount; i++) {
        subtotal += cart[i].price * cart[i].quantity;
    }

    float gst = subtotal * 0.05f;
    float total = subtotal + gst;

    printf("\n--------- BILL ----------\n");
    printf("Subtotal: Rs %.2f\n", subtotal);
    printf("GST (5%%): Rs %.2f\n", gst);
    printf("TOTAL: Rs %.2f\n", total);
    printf("-------------------------\n");
    printf("\nThank you for ordering!\n");
}
