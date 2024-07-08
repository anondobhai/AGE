#include "core/logger.h"
#include "core/asserts.h"

int main()
{
    AGEFATAL("HELLO %d", 3);
    AGEASSERT(1==0);

    return 0;
}
