#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(void)
{
    float f = 156.34f;
    uint32_t bits;

    memcpy(&bits, &f, sizeof(f));

    printf("float = %.10f\n", f);
    printf("hex   = 0x%08X\n", bits);

    return 0;
}
