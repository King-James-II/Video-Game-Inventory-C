// Simulates a basic inventory system for a video game using pointers.
// Demonstrates the use of structures, arrays, pointers, and functions to manage and manipulate items in the inventory.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length for item names and the maximum number of items in the inventory
#define MAX_NAME_LENGTH 50
#define MAX_INVENTORY_SIZE 10

// Define a structure to represent an item
struct Item {
    char name[MAX_NAME_LENGTH];
    int quantity;
};

// Function to use an item by decrementing its quantity
void useItem(struct Item *item) {
    if (item->quantity > 0) {
        item->quantity--;
        printf("You used %s. Remaining quantity: %d\n", item->name, item->quantity);
    } else {
        printf("You don't have any %s left!\n", item->name);
    }
}

int main() {
    // Initialize the inventory as an array of Item structures
    struct Item inventory[MAX_INVENTORY_SIZE];

    // Add some items to the inventory
    strcpy(inventory[0].name, "Health Potion");
    inventory[0].quantity = 3;

    strcpy(inventory[1].name, "Mana Potion");
    inventory[1].quantity = 2;

    strcpy(inventory[2].name, "Sword");
    inventory[2].quantity = 1;

    // Print the initial inventory
    printf("Initial Inventory:\n");
    for (int i = 0; i < MAX_INVENTORY_SIZE; i++) {
        printf("%d. %s - Quantity: %d\n", i+1, inventory[i].name, inventory[i].quantity);
    }

    // Use some items in the inventory
    printf("\nUsing Health Potion:\n");
    useItem(&inventory[0]);

    printf("\nUsing Sword:\n");
    useItem(&inventory[2]);

    printf("\nUsing Health Potion again:\n");
    useItem(&inventory[0]);

    return 0;
}
