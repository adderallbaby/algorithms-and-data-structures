#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TYPE int

struct QMax {
    TYPE *qu, *dq;
    int qsi, dsi, qi, di;
} solver;

void init(struct QMax *ptr, int n) {
    ptr -> qu = (TYPE *) malloc((n + 5) * sizeof(TYPE));
    ptr -> dq = (TYPE *) malloc((n + 5) * sizeof(TYPE));
}

void enque(struct QMax *ptr, TYPE x) {
    if (ptr -> qsi == ptr -> qi) {
        *(ptr -> qu + ptr -> qi++) = x;
        *(ptr -> dq + ptr -> di++) = x;
    }
    else {
        *(ptr -> qu + ptr -> qi++) = x;
        while (ptr -> dsi != ptr -> di && *(ptr -> dq + ptr -> di - 1) < x)
            ptr -> di--;
        *(ptr -> dq + ptr -> di++) = x;
    }
}

void deque(struct QMax *ptr) {
    printf("%d\n", *(ptr -> qu + ptr -> qsi));
    if (*(ptr -> qu + ptr -> qsi) == *(ptr -> dq + ptr -> dsi))
        ptr -> qsi++, ptr -> dsi++;
    else ptr -> qsi++;
}

TYPE getmax(struct QMax *ptr) {
    return *(ptr -> dq + ptr -> dsi);
}

int main() {
    int n, tmp;
    char str[255];
    scanf("%d", &n);
    init(&solver, n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", str);
        if (strcmp(str, "ENQ") == 0)scanf("%d", &tmp), enque(&solver, tmp);
        else if (strcmp(str, "DEQ") == 0)deque(&solver);
        else if (strcmp(str, "MAX") == 0)printf("%d\n", getmax(&solver));
        else if (strcmp(str, "EMPTY") == 0)puts(solver.qsi == solver.qi ? "true" : "false");
    }
    free(solver.qu), free(solver.dq);
    return 0;
}
