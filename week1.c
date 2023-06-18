#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct HashTable {
    int keys[SIZE];
    int values[SIZE];
};
void initHashTable(struct HashTable* ht) {
    for (int i = 0; i < SIZE; i++) {
        ht->keys[i] = -1; // -1 indicates an empty slot
        ht->values[i] = 0;
    }
}
int hash(int key) {
    return key % SIZE; // Division method
}
void linearProbing(struct HashTable* ht, int key, int value) {
    int index = hash(key);
    int i = index;
    while (ht->keys[i] != -1) {
        i = (i + 1) % SIZE; // Move to the next slot
        if (i == index) {
            printf("Hash table is full. Cannot insert key %d\n", key);
            return;
        }
    }
    ht->keys[i] = key;
    ht->values[i] = value;
    printf("Key %d inserted at index %d\n", key, i);
}
void quadraticProbing(struct HashTable* ht, int key, int value) {
    int index = hash(key);
    int i = 0;
    while (ht->keys[index] != -1) {
        i++;
        index = (index + i * i) % SIZE; // Move to the next slot using quadratic formula
        if (i == SIZE) {
            printf("Hash table is full. Cannot insert key %d\n", key);
            return;
        }
    }
    ht->keys[index] = key;
    ht->values[index] = value;
    printf("Key %d inserted at index %d\n", key, index);
}
int hash2(int key) {
    return 7 - (key % 7); // Second hash function
}
void doubleHashing(struct HashTable* ht, int key, int value) {
    int index = hash(key);
    int index2 = hash2(key);
    int i = 0;
    while (ht->keys[index] != -1) {
        i++;
        index = (index + i * index2) % SIZE; // Move to the next slot using double hashing
        if (i == SIZE) {
            printf("Hash table is full. Cannot insert key %d\n", key);
            return;
        }
    }
    ht->keys[index] = key;
    ht->values[index] = value;
    printf("Key %d inserted at index %d\n", key, index);
}
void printHashTable(struct HashTable* ht) {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (ht->keys[i] != -1) {
            printf("Index %d: Key = %d, Value = %d\n", i, ht->keys[i], ht->values[i]);
        }
    }
}
int main() {
    struct HashTable ht;
    initHashTable(&ht);
    linearProbing(&ht, 5, 50);
    linearProbing(&ht, 15, 150);
    linearProbing(&ht, 25, 250);
    quadraticProbing(&ht, 7, 70);
    quadraticProbing(&ht, 17, 170);
    quadraticProbing(&ht, 27, 270);
    doubleHashing(&ht, 9, 90);
    doubleHashing(&ht, 19, 190);
    doubleHashing(&ht, 29, 290);
    printHashTable(&ht);
    return 0;
}
