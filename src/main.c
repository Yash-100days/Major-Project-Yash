#include <stdio.h>
#include <string.h>
#define MAX_ITEMS 50
struct Food {
    int id;
    char name[50];
    float price;
};
struct CartItem {
    char name[50];
    float price;
    int quantity;
};
struct Food menu[] = {
    {1, "Pizza", 199},
    {2, "Burger", 99},
    {3, "Pasta", 149},
    {4, "French Fries", 79},
    {5, "Cold Coffee", 89}
};
int menuSize = 5;
struct CartItem cart[MAX_ITEMS];
int cartCount = 0;
void displayMenu() {
    printf("\n--------- MENU ----------\n");
    for (int i = 0; i < menuSize; i++) {
        printf("%d. %s - Rs %.2f\n", menu[i].id, menu[i].name, menu[i].price);
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
        printf("%s (×%d) - Rs %.2f\n", cart[i].name, cart[i].quantity, itemTotal);
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
    float gst = subtotal * 0.05;   // 5% GST
    float total = subtotal + gst;
    printf("\n--------- BILL ----------\n");
    printf("Subtotal: Rs %.2f\n", subtotal);
    printf("GST (5%%): Rs %.2f\n", gst);
    printf("TOTAL: Rs %.2f\n", total);
    printf("-------------------------\n");
    printf("\nThank you for ordering!\n");
}
int main() {
    int choice, id, qty;
    while (1) {
        printf("\n===== ONLINE FOOD ORDERING =====\n");
        printf("1. View Menu\n");
        printf("2. Add Item to Cart\n");
        printf("3. View Cart\n");
        printf("4. Checkout\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayMenu();
                break;
            case 2:
                printf("Enter item ID: ");
                scanf("%d", &id);
                printf("Enter quantity: ");
                scanf("%d", &qty);
                addToCart(id, qty);
                break;
            case 3:
                viewCart();
                break;
            case 4:
                checkout();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }        
    return 0;
}
