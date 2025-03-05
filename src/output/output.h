#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

void outputToStdOut(const char *buffer);

void assertWithMessage(bool condition, const char *message);

#endif