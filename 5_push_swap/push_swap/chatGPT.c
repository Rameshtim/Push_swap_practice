#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void swap(int *a, int *b);
void sa(int *a, int n);
void sb(int *b, int m);
void ss(int *a, int n, int *b, int m);
void pa(int *a, int *n, int *b, int *m);
void pb(int *a, int *n, int *b, int *m);
void ra(int *a, int n);
void rb(int *b, int m);
void rra(int *a, int n);
void rrb(int *b, int m);
int find_smallest_index(int *a, int n);
int find_largest_index(int *b, int m);
int is_sorted(int *a, int n);
void sort_stack(int *a, int *n, int *b, int *m);

int main() {
    // Seed the random number generator
    srand(time(0));

    // Initialize stack a with random numbers
    int n = 10; // Size of stack a
    int a[10] = {5, 55, -8, 15, 23, 88, 6, 3, 2, -7}; // Stack a
    printf("Stack a (unsorted): ");
    for (int i = 0; i < n; i++) {
        //a[i] = rand() % 100 - 50; // Random numbers between -50 and 49
        printf("%d ", a[i]);
    }
    printf("\n");

    int m = 0; // Size of stack b
    int b[10] = {0}; // Stack b

    // Sort stack a in ascending order
    sort_stack(a, &n, b, &m);

    // Print sorted stack a
    printf("Stack a (sorted): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sa(int *a, int n) {
    if (n >= 2) {
        swap(&a[0], &a[1]);
    }
}

void sb(int *b, int m) {
    if (m >= 2) {
        swap(&b[0], &b[1]);
    }
}

void ss(int *a, int n, int *b, int m) {
    sa(a, n);
    sb(b, m);
}

void pa(int *a, int *n, int *b, int *m) {
    if (*m > 0) {
        a[*n] = b[*m - 1];
        (*n)++;
        (*m)--;
    }
}

void pb(int *a, int *n, int *b, int *m) {
    if (*n > 0) {
        b[*m] = a[*n - 1];
        (*n)--;
        (*m)++;
    }
}

void ra(int *a, int n) {
    if (n > 1) {
        int temp = a[0];
        for (int i = 0; i < n - 1; i++) {
            a[i] = a[i + 1];
        }
        a[n - 1] = temp;
    }
}

void rb(int *b, int m) {
    if (m > 1) {
        int temp = b[0];
        for (int i = 0; i < m - 1; i++) {
            b[i] = b[i + 1];
        }
        b[m - 1] = temp;
    }
}

void rra(int *a, int n) {
    if (n > 1) {
        int temp = a[n - 1];
        for (int i = n - 1; i > 0; i--) {
            a[i] = a[i - 1];
        }
        a[0] = temp;
    }
}

void rrb(int *b, int m) {
    if (m > 1) {
        int temp = b[m - 1];
        for (int i = m - 1; i > 0; i--) {
            b[i] = b[i - 1];
        }
        b[0] = temp;
    }
}

int find_smallest_index(int *a, int n) {
    int smallest_index = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[smallest_index]) {
            smallest_index = i;
        }
    }
    return smallest_index;
}

int find_largest_index(int *b, int m) {
    int largest_index = 0;
    for (int i = 1; i < m; i++) {
        if (b[i] > b[largest_index]) {
            largest_index = i;
        }
    }
    return largest_index;
}

int is_sorted(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void sort_stack(int *a, int *n, int *b, int *m) {
    while (!is_sorted(a, *n)) {
        int smallest_index = find_smallest_index(a, *n);
        int largest_index = find_largest_index(b, *m);

        if (smallest_index <= (*n - 1) / 2) {
            for (int i = 0; i <= smallest_index; i++) {
                ra(a, *n);
                printf("ra ");
            }
        } else {
            for (int i = 0; i < *n - smallest_index; i++) {
                rra(a, *n);
                printf("rra ");
            }
        }

        if (largest_index <= (*m - 1) / 2) {
            for (int i = 0; i <= largest_index; i++) {
                rb(b, *m);
                printf("rb ");
            }
        } else {
            for (int i = 0; i < *m - largest_index; i++) {
                rrb(b, *m);
                printf("rrb ");
            }
        }

        if (a[0] < b[0]) {
            pa(a, n, b, m);
            printf("pa ");
        } else {
            pb(a, n, b, m);
            printf("pb ");
        }
    }

    // Move remaining elements from b to a
    while (*m > 0) {
        pa(a, n, b, m);
        printf("pa ");
    }
}
