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

const char INITIAL_MSG[] = 
  "______ _                    _                   _ \n"
 "|  ____| |                  (_)                 | |\n"
 "| |__  | | ___   _  __ _ ___ _  ___  _ __   __ _| |\n"
 "|  __| | |/ / | | |/ _` / __| |/ _ \| '_ \ / _` | |\n"
 "| |____ | <| |_| | (_ | \__ \ | (_) | | | | (_| | |\n"
 "|______|_|\_\\__,_|\__,_|___/_|\___/|_| |_|\__,_|_|\n"
    "Kalkulator rumus kuadratik sederhana. By Smanti Suharto :D"

const char INCORRECT_MSG[] = "Input salah, Ketik 'h' untuk bantuan.\n";

const char NUM_ERR_MSG[] = "Input salah. harus ada 3 angka. Ketik 'h' untuk bantuan.\n";

const char OVERFLOW_MSG[]  = "Luapan Buffer. Ulangi lagi. Ketik 'h' untuk bantuan.\n";

const char HELP_MSG[] = "------------------------------------------------------\n"
                        "'h' atau 'help'           - Bantuan.\n"
                        "'q' atau 'quit'           - exit.\n"
                        "Masukkan 3 angka (a b c) - Mengkalkulasi perhitungan ax²+bx+c=0.\n"
                        "------------------------------------------------------\n"
                        "Error luapan buffer   - Jeda input terlalu panjang (>28).\n"
                        "Error kesalahan input   - Input salah.\n"
                        "------------------------------------------------------\n";

const char INVITE_LINE[] = "[quadratic] ";

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
