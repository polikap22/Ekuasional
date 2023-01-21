#include <stdio.h>
#include <string.h>
#include "client.h"
#include "../include/io.h"
#include "config.h"

#define CHECK_CMD(str1, str2)                    \
    strncmp(str1, str2, INPUT_BUFFER_SIZE) == 0  \

#define COLOR_PRINT(msg, color) \
    set_text_color(color);      \
    printf("%s", msg);          \
    reset_color();

const char INITIAL_MSG[] = "|-----------------------------------|\n"
                           "|Kalkulator fungsi kuadrat sederhana|\n"
                           "|  Oleh PDIP SMANTI :D AWOKWOKWOK   |\n"
                           "|  Bu mega ditunggu yaa pensiun :)  |\n"
                           "|-----------------------------------|\n"
                      "https://www.youtube.com/watch?v=axnMYIfTvJY&t=10s\n";

const char INCORRECT_MSG[] = "Input salah. Ketik 'h' untuk membuka opsi bantuan.\n";

const char NUM_ERR_MSG[] = "Input salah. Harus ada 3 koefisien. Ketik 'h' untuk membuka opsi bantuan.\n";

const char OVERFLOW_MSG[]  = "Buffer overflow. Ulangi lagi. Ketik 'h' untuk membuka opsi bantuan.\n";

const char HELP_MSG[] = "------------------------------------------------------\n"
                        "'h' atau 'help'           - print this message.\n"
                        "'q' atau 'quit'           - exit.\n"
                        "Masukkan 3 koefisien (a b c) - mengkalkulasi ekuasi ax²+bx+c=0.\n"
                        "------------------------------------------------------\n"
                        "Buffer overflow error   - Input terlalu panjang (>28).\n"
                        "Error kesalahan input   - Input salah.\n"
                        "------------------------------------------------------\n";

const char INVITE_LINE[] = "[>] ";

int client_square_eq() {
    square_params    params    = {0};
    square_solutions solutions = {0};

    char input[INPUT_BUFFER_SIZE] = {0};
    int  n_chars_read = 0;

    COLOR_PRINT(INITIAL_MSG, YELLOW);

    size_t n_valid = 0;

    while (true) {
        COLOR_PRINT(INVITE_LINE, YELLOW);
        
        n_chars_read = getl(input, INPUT_BUFFER_SIZE, stdin);

        if (n_chars_read < 0) {
            COLOR_PRINT(OVERFLOW_MSG, RED);
        } else {
            n_valid = sscanf(input, "%lf%lf%lf", &params.a, &params.b, &params.c);

            if (CHECK_CMD(input, "q") || CHECK_CMD(input, "quit")) {
                return 0;
            } else if (CHECK_CMD(input, "h") || CHECK_CMD(input, "help")) {
                COLOR_PRINT(HELP_MSG, BLUE);
            } else if (n_valid == 3) {
                roots_state rs = solve_quadratic(params, &solutions);
                display_roots(rs, solutions);
            } else if (n_valid == 2) {
                COLOR_PRINT(NUM_ERR_MSG, RED);
            } else {
                COLOR_PRINT(INCORRECT_MSG, RED);
            }
        }
    }

    return 0;
}
