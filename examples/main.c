#include <kernaux/assert.h>

#include <stdio.h>
#include <stdlib.h>

void example_main();

static void assert_cb(const char *file, const int line, const char *msg)
{
    fprintf(stderr, "%s:%i:%s\n", file, line, msg);
    abort();
}

int main()
{
    kernaux_assert_cb = assert_cb;
    example_main();
    exit(EXIT_SUCCESS);
}
