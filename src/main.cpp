#include "App.hpp"

int main(int argc, char** argv) {

    App* app;

    if (argc == 2) {
        app = new App(atoi(argv[1]));
    } else {
        app = new App();
    }
    app->run();

    delete app;

    return 0;
}