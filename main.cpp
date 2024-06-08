#include <iostream>
#include <stdlib.h> 
#include <Windows.h>
#include "controller.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    controller ctrl;
    ctrl.execute();
}