// Needs to be downloaded
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name;
    // Its a function exclusive to the CS50 library
    name = get_string("What's your name? ");
    printf("hello, %s\n", name);
    return 0;
}
