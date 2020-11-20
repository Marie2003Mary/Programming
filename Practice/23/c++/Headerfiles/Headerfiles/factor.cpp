#include "factor.h"
int factor(int x) {
    int n = 1;
    for (x; x > 0; x--) {
        n = n * x;
    } return n;
}