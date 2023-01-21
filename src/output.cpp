#include <stdio.h>
#include "client.h"
#include <math.h>
#include "../include/compare.h"


const int OUT_DIGITS = (int) -log10(TOLERANCE);

void display_roots(const roots_state rs, const square_solutions solutions) {

    switch (rs) {
        case ZERO_RT:
            printf("Tidak ada akar asli\n");
            break;
        case ONE_RT:
            printf("%.*lf\n", OUT_DIGITS, solutions.x1);
            break;
        case TWO_RT:
            printf("%.*lf\n"
                   "%.*lf\n", OUT_DIGITS, solutions.x1,
                              OUT_DIGITS, solutions.x2);
            break;
        case INF_RT:
            printf("Bilangan asli apapun (jangan imajiner :D)\n");
            break;
        case ERR_INF:
            printf("Infinity...\n");
            break;
        default:
            printf("Sebuah kesalahan terjadi...\n");
    }
}
