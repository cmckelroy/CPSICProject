#include "CPSICUser.h"

CPSICUser::CPSICUser()
{
}
string CPSICUser::get_name() {
    return firstName + " " + lastName;
}
