#include <stdio.h>
#include <stdlib.h>

struct Part {
    int m_val;
    int m_indexArr;
};

struct Part pop(struct Part *mass, int k);
void add(struct Part *mass, int k, struct Part val);


int main() {
    int K;
    scanf("%d", &K);

    int *arr = (int*)malloc(K * sizeof(int));
    int k2 = K;
    for (int i = 0, j = 0; i < k2; i++) {
        int l;
        scanf("%d", &l);

        if (l) {
            arr[j++] = l;
            continue;
        }
        --K;
    }

    int N = 0;
    for (int i = 0; i < K; i++) {
        N = N + arr[i];
    }

    struct Part *mass = (struct Part*)malloc(K * sizeof(struct Part));
    struct Part **table = (struct Part**)malloc(K * sizeof(struct Part *));

    int *intArray = (int*)malloc(K * sizeof(int));
    for (int i = 0; i < K; i++) {
        table[i] = (struct Part *)malloc(arr[i] * sizeof(struct Part));

        for (int j = 0; j < arr[i]; j++) {
            scanf("%d", &table[i][j].m_val);
            table[i][j].m_indexArr = i;
        }

        add(mass, i + 1, table[i][0]);
        intArray[i] = 1;
    }

    int nOutput = 0;
    while (N - K > nOutput) {
        struct Part tmp = pop(mass, K);

        int index = tmp.m_indexArr;
        while (intArray[index] == arr[index]) {
            index = (index + 1) % K;
        }
        add(mass, K, table[index][intArray[index]]);
        ++intArray[index];
        printf("%d ", tmp.m_val);
        ++nOutput;
    }

    for (int i = K; i > 0; i--) {
        printf("%d%c", pop(mass, i).m_val, ' ');
    }

    free(intArray);
    free(arr);
    free(mass);

    for (int i = 0; i < K; i++) {
        free(table[i]);
    }
    free(table);

    return 0;
}

void moveUp(struct Part *mass, int i) {
    if (i == 0) {
        return;
    }

    int tmp = (i - 1) / 2;
    if (mass[i].m_val < mass[tmp].m_val) {
        struct Part buf = *(mass + i);
        *(mass + i) = *(mass + tmp);
        *(mass + tmp) = buf;

        moveUp(mass, tmp);
    }
}

void moveDown(struct Part *mass, int k, int i) {
    if (k - 1 < i * 2 + 1) { return; }

    int i_min = i * 2 + 1;
    if (i * 2 + 2 <= k - 1 && mass[i * 2 + 2].m_val < mass[i_min].m_val) {
        i_min = i * 2 + 2;
    }

    if (mass[i].m_val > mass[i_min].m_val) {
        struct Part tmp = *(mass + i);
        *(mass + i) = *(mass + i_min);
        *(mass + i_min) = tmp;
        moveDown(mass, k, i_min);
    }
}

struct Part pop(struct Part *mass, int k) {
    struct Part res = mass[0];
    mass[0] = mass[k - 1];
    moveDown(mass, k - 1, 0);

    return res;
}

void add(struct Part *mass, int k, struct Part val) {
    mass[k - 1] = val;
    moveUp(mass, k - 1);
}