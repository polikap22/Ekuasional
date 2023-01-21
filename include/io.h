#ifndef IO_H_
#define IO_H_

#include <stdio.h>

enum color {
    RED = 1,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,
};

int set_text_color(color text);

int set_back_color(color background);

int reset_color(); 

int getl(char *buffer, const size_t size, FILE *stream);

#endif // IO_H_
