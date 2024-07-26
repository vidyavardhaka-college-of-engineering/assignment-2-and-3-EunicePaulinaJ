#include <stdio.h>
#define M 11
int h1(int key) {
    int x = (key + 7) * (key + 7);
    x = x / 16;
    x = x + key;
    x = x % M;
    return x;
}
void insert(int key, int hash_table[]) {
    int home_slot = h1(key);
    int probe_slot = home_slot;
    while (hash_table[probe_slot] != -1) {
        probe_slot = (probe_slot + 1) % M;
        if (probe_slot == home_slot) {
            printf("Hash table is full!\n");
            return;
        }
    }
    hash_table[probe_slot] = key;
}
void print_hash_table(int hash_table[]) {
    printf("Slot: ");
    for (int i = 0; i < M; i++) {
        printf("%d ", i);
    }
    printf("\nContents: ");
    for (int i = 0; i < M; i++)
 printf("%d ", hash_table[i]);
    }
    printf("\n");
}

int main() {
    int hash_table[M];
    for (int i = 0; i < M; i++) {
        hash_table[i] = -1;
    }

    int keys[] = {43, 23, 1, 0, 15, 31, 4, 7, 11, 3};
    for (int i = 0; i < 10; i++) {
        int key = keys[i];
        int home_slot = h1(key);
        printf("Inserting key %d, home slot %d\n", key, home_slot);
        insert(key, hash_table);
    }

    print_hash_table(hash_table);

    return 0;
}
