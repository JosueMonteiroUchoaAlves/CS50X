#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int size = 0, blanckSpaces, blocks;
    // on the left we count for the blank spaces
    // on the right, the blocks go first so we use them to count
    while (size > 8 || size < 1)
    {
        size = get_int("Height: ");
    }
    for (int i = 1; i <= size; i++) // 1-indexed to make it easier to think
    {
        blanckSpaces = size - i;
        blocks = i;
        // Lado direito
        for (int j = 0; j < size; j++)
        {
            if (blanckSpaces)
            {
                blanckSpaces -= 1;
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  ");
        // Lado esquerdo
        for (int j = 0; j < size; j++)
        {
            if (blocks)
            {
                blocks -= 1;
                printf("#");
            }
            else
            {
                continue;
            }
        }
        printf("\n");
    }

    return 0;
}
