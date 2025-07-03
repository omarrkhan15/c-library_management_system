#include "Library.h"
#include "Welcome.h"

int main() {
    Library byteCode;
    byteCode.loadBookData();
    Library::headMessage("Welcome to the library management system");
    Library::pause();
    byteCode.MainMenu(byteCode);
    byteCode.saveBookData();
}
